/*
CS 154 Lab 8 by Shubh Kumar, 200050134

Using Assertions to improve the Abstraction design of a telephone

*/


#include <iostream>
#include <string>
#include <random>
#include <unistd.h>

using namespace std;



class CallLog {

public:

  string number;
  double connectDuration;                  // Time Taken to connect
  double DialDuration;                     // Time taken for other side to pick up the call
  double duration;                         // Duration of call in seconds, if call was connected

  CallLog(string _number, double _connectDuration, double _DialDuration, double _duration){

    number = _number;
    connectDuration = _connectDuration;
    DialDuration = _DialDuration;
    duration = _duration;
  }

};

class Telephone {

  vector<CallLog> Logs;
  int state; // 0 == idle, 1 == receiverup,2 ==  in conversation,3 ==  dialing,4 == connecting

 public:
  Telephone(int _state){
    state = _state;
  }
	void receiverup();                          // Get the Receiver Up
	void receiverdown();                        // Put the Receiver Down
	void dialdigit ();                           // if number is dialed, randomly choose connected, timeout, number does not exist state
  void PlaySimulation();                       // Playing the Simulation forward
  void PrintLogs();                             // Printing the Logs of past Calls and stuff


};

#define codeDialassert(condition) \
      if (!(condition)) \
      { \
          cout<<"In File :"<<__FILE__<<", Line: "<< __LINE__<<", The Condition: "<<#condition<<" has failed!"<<endl; \
          dialdigit(); \
      } \

void Telephone::receiverup () {

  state = 1;          //Receiver is up now

};

void Telephone::receiverdown () {

  state = 0;          //Receiver is Down Now

};

void Telephone::dialdigit () {                //Dialing a Number

  string num;

  cout << "What number would you want to dial?(10 Digt!)" << endl;


  cin>>num;                                     //Getting the Number

  codeDialassert(num.size()==10);

  for(int v = 0;v<num.size();v++) codeDialassert(num[v]<='9' && num[v]>='0');

  CallLog log (num, 0,0, 0);                    //Constructing the CallLog

  double ConnectTime;
  ConnectTime = ( ( (double) rand() ) / ( (double) RAND_MAX ) ) * 5.0;      //Getting the time for connecting (random)

  state = 4;                                              //Changing States
  cout << "Connecting to Tower...." << endl;

  sleep( ConnectTime );                                       //Keeping the system idle for that time
  log.connectDuration = ConnectTime;

  if( rand() % 2 == 0 ) {                                   //Randomly deciding whether to connect or cut

    cout << "Successfully Connected To Tower..."<<endl;

    state = 3;                                             //Changing States
    cout<<"Now Dialing...."<<endl;

    double DialTime = ( ( (double) rand() ) / ( (double) RAND_MAX )) * 5.0;          //Getting the Random Time which it'll keep dialing for
    sleep(DialTime);                                                         //Keeping the system idle till its dialing

    log.DialDuration = DialTime;

    if( rand() % 2 == 0 ) {                                //Randomly deciding whether the call will be picked up

      cout<< "Now Speaking with the Dialed Person...." << endl;

      state = 2;                                                                            //Changing States
      double CallDuration = ( ( (double) rand() ) / ( (double) RAND_MAX ) ) *60.0;                //Random Call Duration


      cout << "You talked for " << CallDuration << " seconds." << endl;
      state = 1;                                                                    //Changing States

      log.duration = CallDuration;
      Logs.push_back(log);                                                      //Adding to Call Log

    }else {

      cout<< "The Person dialed didn't pick up...Try again Later" << endl;

      Logs.push_back(log);                                              //Adding to Call Log
      state = 1;                                                        //Changing State
      return;

    }

  } else {

    cout << "Unable to Reach Tower...Please try later!" << endl;

    Logs.push_back(log);                                              //Adding to Call Log
    state = 1;                                                        //Changing State
    return;
  }

  cout<<"----------------------------------"<<endl<<endl<<endl;         // Marking Boundaries

};

//For Printing the Call Logs
void Telephone::PrintLogs () {

  if ( Logs.empty() ) {                       //Dealing with the case, when the Logs are empty

    cout << "No Logs to be printed!" << endl;

  } else {

    for( int i = 0 ; i < Logs.size() ; i++ ) {

      cout << (i+1) << "." << endl;

      cout << "Number Called: "<< Logs[i].number << endl;

      cout << "Connecting Duration: " << Logs[i].connectDuration << endl;

      if ( Logs[i].DialDuration > 1e-5 ) {                              //Printing DialDuration, only if it connected to tower

        cout << "Dialing Duration: " << Logs[i].DialDuration << endl;

        if ( Logs[i].duration > 1e-5 ) {                                //Printing Call Duration only if it was picked up

          cout << "Call Duration:" << Logs[i].duration << endl;

        }

      }
      cout<<"----------------------------------"<<endl;         // Marking Boundaries

    }

  }


};

void Telephone::PlaySimulation () {

  bool end = false;                 //Deciding when to end the Simulation

  while (!end) {

    int inp;                      //To take Input from user

    if ( state == 0 ) {             //If the receiver is currently down
          //Instructions
      cout << "What would you want to Do?" << endl;
      cout << "Press 1 and enter to Pick Up the Receiver." << endl;
      cout << "Press 2 and enter to Print Logs." << endl;
      cout << "Press any other key and enter to end the Simulation!" <<endl;


      cin>>inp;                       //Getting Command

      switch (inp) {
        case 1 :
        // Pick up the receiver
          receiverup();
          break;

        case 2 :
        //Print Logs
          PrintLogs();
          break;

        default :
          //End the Simulations
          cout << "Ending Simulation" << endl;
          end = true;
          break;


      }

    } else if ( state == 1 ) {              //If the receiver is currently up
      //Instructions
      cout << "The Receiver is Up, What would you want to Do?" << endl;
      cout << "Press 1 and enter to Dial a Number" << endl;
      cout << "Press 2 and enter to Put the Receiver Down." << endl;
      cout << "Press any other key and enter to end the Simulation!" <<endl;

      cin>>inp;                         //Getting Input

      switch (inp) {
        case 1 :
          //Dialing Someone
          dialdigit();
          break;

        case 2 :
          //Putting Down the Receiver
          receiverdown();
          break;

        default :
          //Ending the Simulation
          cout << "Ending Simulation" << endl;
          end = true;
          break;


      }

    }
    cout<<"----------------------------------"<<endl<<endl<<endl;         // Marking Boundaries
  }

};

int main (int argc, char *argv[]) {

  Telephone myTelephone(0);                 //Declaring a Telephone
  myTelephone.PlaySimulation();             //Running its simulation



}
