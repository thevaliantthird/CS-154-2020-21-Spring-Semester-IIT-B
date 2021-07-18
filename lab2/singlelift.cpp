/*
Lab 2: CS 154
Author: Shubh Kumar, 200050134
This Program helps you to simulate one Elevator
The Problem Statement needed it for only 6 floors,
but here you could do it for as many floors as you like

*/


#include <iostream>
#include <vector>
#include <set>        //Required to catalogue the Requests from various floors
#include <queue>      //Required to catalogue the different people waiting on each floor to get aboard the lift


using namespace std;

//Predeclaring all Global Variables

int TotalNumberofFloors;    //Excluding Ground Floor
int NumPassenger;           //Buffer to keep track on number of passengers added over-time
int Steps;                  //Buffer to keep track of time-steps to move the elevators


multiset<int> requestsUp;     //The Floors from which Up request is there
multiset<int> requestsDown;   //The Floors from which Down Request is there


//Pre-declaring classes
class Lift;
class Person;
class Floor;
class Controller;

//Pre-declaring pointers to arrays of Floors and the Elevator
Floor *floors;
Lift *Elevator;

class Person {
  float weight;         //The Weight of the passenger
  int BoardingFloor;    // The Index of floor from where he/she boards
  int DestinationFloor; //The Index of Floor where he/she gets off

public:

  //Constructor
  Person (float _weight, int _BoardingFloor, int _DestinationFloor) {
    weight = _weight;
    BoardingFloor = _BoardingFloor;
    DestinationFloor = _DestinationFloor;
  }

  //Public Functions to get Various attributes of the function

  float getWeight() {
    return weight;
  }

  int getDestination() {
    return DestinationFloor;
  }

};



class Floor {

  int FloorNum;                               //The Index of the Floor
  vector<Person> PeopleWhoGotOffHere;         //The People who got off at this floor

public:

  queue<Person> PeopleWaitingToBoardUp;       //Queue of people waiting to go Up from this floor
  queue<Person> PeopleWaitingToBoardDown;     //Queue of peole waiting to go down from this floor

  Floor(){}

  Floor (int Floor) {
    FloorNum = Floor;

  }

  int GetFloorNum() {                      //Function to get Floor Index
    return FloorNum;
  }

  int People_WaitingUp() {                 //Function to know no. of peole waiting to go UP
    return PeopleWaitingToBoardUp.size();
  }

  int People_WaitingDown() {               //Function to know no. of people waiting to go down
    return PeopleWaitingToBoardDown.size();
  }

  int People_got_off() {                   //Getting to know the number of people who got off to this floor.
    return PeopleWhoGotOffHere.size();
  }

  void Reached(Person x) {                 //Whenever some person reaches this floor
    PeopleWhoGotOffHere.push_back(x);
  }

  void AddPassengerUp(Person x) {          //Adding New Passengers who want to go up
    PeopleWaitingToBoardUp.push(x);
  }

  void AddPassengerDown(Person x) {        //Adding New Passengers who want to go down
    PeopleWaitingToBoardDown.push(x);
  }

};

class Lift {

  int currFloor;                             //Current Floor of the Lift
  float Capacity;                            //Total Weight Capacity
  float currWeight;                          //Current Weight
  bool dir;                                  //0 means up, 1 means down
  vector<Person> *GettingOffOnFloor;         //Keeping Track of passengers of each floor

public:
  //Constructors
  Lift() {}

  Lift (int currfloor) {
    dir = 0;
    currFloor = currfloor;
    Capacity = 600;
    currWeight = 0;
    GettingOffOnFloor = new vector<Person>[TotalNumberofFloors+1];
  }

  Lift (int currfloor, float capacity) {
    dir = 0;
    currFloor = currfloor;
    Capacity = capacity;
    currWeight = 0;
    GettingOffOnFloor = new vector<Person>[TotalNumberofFloors+1];
  }

  //Functions to get certain attributes
  float getCapacity() {
    return Capacity;
  }

  float getWeight() {
    return currWeight;
  }

  bool getDirection() {
    return dir;
  }

  int getCurrentFloor() {
    return currFloor;
  }

  //Getting Total Number of Passengers currently on the lift
  int getTotalPassengerCount() {
    int j = 0;
    for (int i = 0;i<=TotalNumberofFloors;i++) {
      j += GettingOffOnFloor[i].size();
    }
    return j;
  }

  //Getting the Passengers who want to move UP
  void GetPassengerUp() {
    while (!floors[currFloor].PeopleWaitingToBoardUp.empty()
    && currWeight<Capacity) {
      if (floors[currFloor].PeopleWaitingToBoardUp.front().getWeight()
      +currWeight<=Capacity) {
        currWeight += floors[currFloor].PeopleWaitingToBoardUp.front().getWeight();
        requestsUp.erase (requestsUp.find(currFloor));
        GettingOffOnFloor[floors[currFloor].PeopleWaitingToBoardUp.front().
        getDestination()].push_back(floors[currFloor].PeopleWaitingToBoardUp.front());
        floors[currFloor].PeopleWaitingToBoardUp.pop();
      }else {
        break;
      }
    }
  }

  //Getting the Passengers who want to move Down
  void GetPassengerDown() {
    while (!floors[currFloor].PeopleWaitingToBoardDown.empty()
    && currWeight<Capacity) {
      if (floors[currFloor].PeopleWaitingToBoardDown.front().getWeight()
      + currWeight <= Capacity) {
        currWeight += floors[currFloor].PeopleWaitingToBoardDown.front().getWeight();
        requestsDown.erase (requestsDown.find(currFloor));
        GettingOffOnFloor[floors[currFloor].PeopleWaitingToBoardDown.front().
        getDestination()].push_back(floors[currFloor].PeopleWaitingToBoardDown.front());
        floors[currFloor].PeopleWaitingToBoardDown.pop();
      }else{
        break;
      }
    }
  }

  //The Function which moves the Lift and Runs the game
  void NextMove (int steps) {
    for (int i = 0;i < steps;i++) {

      if (currWeight < 1e-2 && requestsUp.empty() && requestsDown.empty()) {
        break;      //Nowhere to go
      }else if (currWeight > 1e-2) {      //There are passengers
        if (dir) {
          if (currFloor==0) {         //Dealing lower bound on floors
            dir = false;
            currFloor++;
          }else {
            currFloor--;
          }
        }else {
          if (currFloor==TotalNumberofFloors) {   //Dealing with upper bound on floors
            dir = true;
            currFloor--;
          }else {
            currFloor++;
          }
        }

        //Loading Off People at a particular floor
        if ( GettingOffOnFloor[currFloor].size() != 0 ) {

          while ( !GettingOffOnFloor[currFloor].empty() ){
            floors[currFloor].Reached (*(--GettingOffOnFloor[currFloor].end()));   //Interacting with an object of Floor class
            currWeight -= (--GettingOffOnFloor[currFloor].end())->getWeight();      //Changing the current Weight of Lift
            GettingOffOnFloor[currFloor].pop_back();                              //Getting the perso off the lift
          }

        }

        //Getting People to Go Down
        if (dir) {
          GetPassengerDown();
        }else {

          //Getting People to Go Up
          GetPassengerUp();
        }

      }else {

        //When Lift is empty and we need to respond to closest requests
        int x = 0;
        for ( int k = 1; k<TotalNumberofFloors; k++ ) {
          if (requestsUp.find(currFloor+k)!=requestsUp.end() ||
           requestsDown.find(currFloor+k)!=requestsDown.end() ) {
            x = 1;
            break;
          }
          if ( requestsDown.find(currFloor-k)!=requestsDown.end() ||
           requestsUp.find(currFloor-k)!=requestsUp.end() ) {
            x = -1;
            break;
          }
        }

        //Control Abstractions to get to know directions in which it should progress!
        if ( x==1 ) {
          dir = false;
          currFloor++;
        }else {
          dir = true;
          currFloor--;
        }

        //Getting Passengers to an empty lift(UP)
        if ( requestsUp.find(currFloor)!=requestsUp.end() ) {
          GetPassengerUp();
        }else {
          //Getting Passengers to an empty lift(DOWN)
          GetPassengerDown();
        }
      }
    }
  }
};

class Controller {
  
public:

  // Getting New Passengers
  void GetPassenger() {
    cin>>NumPassenger;        //Number of Passengers to be added
    while (NumPassenger--) {
      float w;  //weight
      int b;    //Boarding Point
      int d;    //Destination
      cin>>b>>d>>w;

      //Handling Wrong inputs
      while( (b<0) || (d<0) || (b>TotalNumberofFloors) || (d>TotalNumberofFloors) ||
       (w>Elevator->getCapacity()) || b==d) {
        cout<<"Entered Data Not Feasible, Please Re-enter"<<endl;
        cin>>b>>d>>w;
      }

      Person x(w,b,d);     //Initializing the Person
      //Adding the Person to its appropriate place and updating requests!
      if (d-b>0) {
        requestsUp.insert(b);
        floors[b].AddPassengerUp(x);
      }else {
        requestsDown.insert(b);
        floors[b].AddPassengerDown(x);
      }
    }
  }

  //Printing Instructions
  void PrintInstructions() {

    cout<<"What would you want to do?"<<endl;
    cout<<"1. Get to know the status of the Elevator"<<endl;
    cout<<"2. Get to know the status of All the Floors"<<endl;
    cout<<"3. Move the Elevator for a given Number of TimeSteps"<<endl;
    cout<<"4. Add More Passengers"<<endl;
    cout<<"5. End the Simulation"<<endl;
    cout<<"Please Enter what you would want to do?(As one of the numbers 1...5)\n";

  }

  //Printing Elevator Status
  void PrintElevatorStatus() {

      cout<<"Current Weight is "<<Elevator->getWeight()<<
      ", Total Passenger Count is "<<Elevator->getTotalPassengerCount()<<
      ", The Lift is currently on Floor "<<Elevator->getCurrentFloor()<<
      ", And the Lift is moving ";
      if( Elevator->getDirection() )cout<<"down\n";
      else cout<<"up \n";

  }

  //Printing Status of Different Floors

  void PrintFloorStatus() {

    for ( int i = 0; i<=TotalNumberofFloors; i++ ) {
      cout<<i<<": "<<floors[i].People_got_off()<<" have reached here, "<<
      floors[i].People_WaitingUp()<<" people are waiting to go up and "<<
      floors[i].People_WaitingDown()<<" people are waiting to go down!\n";
    }

  }

  //Guidelines to Add New Passengers
  void PrintPassengerAddingInstructions(){

    cout<<"Now, You will be asked to enter details of \n";
    cout<<"passengers in a given format: \n";
    cout<<"1) Enter the Number of Passengers, you'll be entering"<<endl;
    cout<<"2) For Each Passenger, enter in the following format: \n";
    cout<<"<Boarding Floor> <Destination Floor> <Weight>"<<endl;
    cout<<"Please, don't enter any case, where any floor is > Max No. or <0"<<endl;
    cout<<"Also Please do not enter passengers with the same boarding and Destination Floor"<<endl;

  }
  //Initializing The Elevator
  void Initialize() {

    cout<<"Welcome to the Elevator!"<<endl;
    cout<<"Kindly Enter the Number of Floors(Excluding Ground Floor) you'd like to have:"<<endl;
    cin>>TotalNumberofFloors;
    floors = new Floor[TotalNumberofFloors+1];
    for ( int i = 0; i<=TotalNumberofFloors; i++) {
      floors[i] = Floor(i);
    }
    float c;          //Capacity
    int curfloor;     //Initial Floor
    cout<<"Kindly Enter the capacity of the Elevator:"<<endl;
    cin>>c;

    //Handling Wrong inputs
    while ( c<0 ) {
      cout<<"Please Enter Positive Capacity!Please re-enter:"<<endl;
      cin>>c;
    }

    cout<<"Kindly Enter the initial floor of the Elevator"<<endl;
    cin>>curfloor;

    //Handling Wrong inputs
    while ( curfloor>TotalNumberofFloors || curfloor<0 ) {
      cout<<"You entered infeasible data for initial floor!Please re-enter:"<<endl;
      cin>>curfloor;
    }

    Elevator = new Lift(curfloor,c);      //Constructing the Lift
  }

  //Running the Simulation
  void Play() {
    bool play = true;             //Deciding when to end the Simulation
    while (play) {
      PrintInstructions();        //Print Instructions at all Beginnings
      int what;                   //To Store whatever the user wants to do
      cin>>what;
      switch (what) {
        case 1:

          //Printing Elevator Status
          PrintElevatorStatus();
          break;

        case 2:

          //Printing Floor-wise Status
          PrintFloorStatus();
          break;

        case 3:

          //Running the Simulation for a few steps
          cout<<"For How many steps would you want to move: "<<endl;
          cin>>Steps;
          Elevator->NextMove(Steps);

          //Then Printing the Status after that run
          cout<<"The Elevator is now like: "<<endl;
          PrintElevatorStatus();

          cout<<"The Floors now look like:"<<endl;
          PrintFloorStatus();
          break;

        case 4:

          //Adding New Passengers on certain floors
          cout<<"How many passengers would you want to add?"<<endl;
          GetPassenger();
          break;

        case 5:

          //Ending Game
          play = false;
          break;

        default:

          //If infeasible key is pressed
          cout<<"Wrong Key Entered\n";
          break;
      }
    }
  }
};


int main(){

  //Initializing the Simulation Controller
  Controller myController;
  myController.Initialize();                                                  //Initializing
  myController.PrintPassengerAddingInstructions();                            //Printing Guidelines for adding Passengers
  cout<<"How many passengers would you want to add in the first batch?"<<endl;//Getting first batch of Passengers
  myController.GetPassenger();
  myController.Play();                                                        //Running the Game Play

}
