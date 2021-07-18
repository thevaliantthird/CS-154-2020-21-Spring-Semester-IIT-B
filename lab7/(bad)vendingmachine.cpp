/*
CS 154 Lab 3 by Shubh Kumar, 200050134
Abstracting the Design of A Vending Machine.

*/

#include <iostream>
#include <vector>

using namespace std;

class Drink{              //Class Describing a particular drink
public:
  string Name;
  int ID;
  double Price;
};


class VendingMachine {      //Class Describing the Vending Machine

  double currBalance = 0.0;   //Current Balance
  vector<Drink> drinks;       //Drinks available as choices
  bool accountOn = false;     // Whether an account is already started or not

public:

  VendingMachine(int x);      // Constructor
	void insertMoney ();        // Inserting Money into the Machine
	void selectdrink (int drinkid); // returns true if successful
  void PrintChoices();            // Printing the Choices of Drinks Available
  void PrintAccountStatus();      //Printing Account Balance
  void EjectChange();             //Eject all Balance and end account
  void PrintGeneralInstructions();  //Print Instructions
  void StartAccount(double money);   //Start an Account by inserting some money
  void PlaySimulation();              //Moving on the Transition

};

VendingMachine::VendingMachine(int x){              //Enables the user to add drinks

    cout << "Welcome to the Vending Machine!" << endl;
    cout << "Let's set it up Together!" << endl;
    cout << "Add Drinks in the format <Name> <Price>" << endl;
    cout << "How many Drinks would you like to Add?" << endl;

    int ind = 1;
    int n;
    cin>>n;

    Drink ToBeAdded;          // Buffer instance

    for( ; ind <= n ; ind++ ) {

      ToBeAdded.ID = ind;
      cin>>ToBeAdded.Name;
      cin>>ToBeAdded.Price;

      drinks.push_back(ToBeAdded);
      //Adding Drinks
    }

    cout << "----------------------------------"<<endl << endl << endl;                         //Marking Boundaries
};

void VendingMachine::PrintChoices () {              //Print Available Choices of Drinks

  cout << "We have the following Drinks available with us: " << endl;

  for ( int i = 0; i < drinks.size() ; i++ ) {

    cout << drinks[i].ID << ". " << drinks[i].Name << " for Rs. " << drinks[i].Price << endl;

  }

    cout<<"----------------------------------"<<endl<<endl<<endl;               //Marking Boundaries

};

void VendingMachine::PrintGeneralInstructions () {            //General Instructions of the Simulation
  //Whether or not an account is already active
  if ( accountOn ) {

    PrintAccountStatus();
    PrintChoices();

    cout << "What would you want to do?" << endl;
    cout << "Press 1 and enter to Select A Drink to Buy" << endl;
    cout << "Press 2 and enter to add more Money" << endl;
    cout << "Press 3 and enter to eject all your money and end the Account." << endl;
    cout << "Press Any Other Key and enter to End The Game" << endl;

  } else {
    cout << "Insert Some Money to start an Account!" << endl;

    PrintChoices();

  }

  cout << "----------------------------------" << endl;                     //Marking Boundaries

};

void VendingMachine::StartAccount ( double money ) {                // Starting a new Acount

  currBalance = money;
  accountOn = true;

  PrintAccountStatus();
  PrintChoices();

};

void VendingMachine::PrintAccountStatus () {                  //Printing Balance for that account

  cout << "You currently have an account started!" << endl;
  cout << "You currently have Rs. " << currBalance << ", in your account!" << endl;
  cout << "----------------------------------" << endl;           //Marking Boundaries

};

void VendingMachine::insertMoney () {                             //Adding Money to the account

  cout << "How much money are you adding to your Account?" << endl;

  double sum;
  cin>>sum;
  currBalance += sum;

  cout << "----------------------------------" << endl<< endl;      //Marking Boundaries

};

void VendingMachine:: EjectChange() {                               // Ejecting All Change and ending the account

  cout << "Are you sure you want to eject all your money and close the account?[Y/N]" << endl;
  char command;
  cin >> command;
  // Keep asking until a valid input is given
  while ( command != 'Y' || command != 'N' ) {

      cout << "Are you sure you want to eject all your money and close the account?[Y/N]" << endl;

  }

  if ( command == 'Y' ) {
    cout << "Thanks for using the Vending Machine!" << endl;
    //Closing the Account
    currBalance = 0.0;
    accountOn = false;

  }

  cout << "----------------------------------" << endl << endl;       //Marking Boundaries

};

void VendingMachine::selectdrink ( int drinkid ) {

  if ( drinkid < 1 || drinkid > drinks.size() ) {         //Handling invalid queries

    cout << "Invalid Drink ID!" << endl;

  } else {

    if ( drinks[drinkid-1].Price <= currBalance ) {

      cout << "Thanks for buying " + drinks[drinkid-1].Name << "!" << endl;

      currBalance -= drinks[drinkid-1].Price;
      //Closing Account if in case balance becomes zero
      if( currBalance <= 1e-5 ) {

        currBalance = 0;
        accountOn = false;

      }

    } else {

      cout << "You don't have enough balance!" << endl;         // If Balance isn't enough

    }

  }

  cout << "----------------------------------" << endl << endl;     //Marking Boundaries

};

void VendingMachine::PlaySimulation() {         //Running the Simulation (Controlling Function!)

  bool end = false;   //Deciding whether or not to end the game

  while ( !end ) {

    int inp;      //Buffer for input

    PrintGeneralInstructions();       //Print Instructions before taking input
    // Take Input according to whether or not an account is active
    if ( accountOn ) {

      cin>>inp;

      switch ( inp ) {

        case 1:
          // Buying a Drink
          int choice;
          cout<<"Enter the ID of Drink you'd like to buy!"<<endl;
          cin>>choice;

          selectdrink(choice);

          break;
        case 2:
          //Adding Money
          insertMoney();

          break;

        case 3:
          //Ejecting All Balance and Ending Account
          EjectChange();

          break;

        default:
          //Ending the Simulation
          end = true;
          break;

      }
    } else {
      //Starting an account, if it isn't already started
      cout<< "How much Money you would like to insert and start an Account?" << endl;
      cout<< "(Enter a Non-positive amount if you want to end the simulation!)" << endl;

      double amount;
      cin>>amount;

      if ( amount < 1e-5 ) {

        end = true;

      } else {

          StartAccount(amount);

      }

    }

    cout<<"----------------------------------"<<endl<<endl<<endl;     //Marking Boundaries

  }

};

int main (int argc, char *argv[]) {

  VendingMachine myMachine(0);
  myMachine.PlaySimulation();

}
