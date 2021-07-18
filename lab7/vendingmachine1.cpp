/*
CS 154 Lab 7 by Shubh Kumar, 200050134

Better Structuring the Design and Abstractions of A
Vending Machine, made in Lab 3.

*/

#include <iostream>
#include <vector>

using namespace std;


struct Drink{              //Struct Describing a particular drink

  string Name;
  int ID;
  int Stock;
  double Price;
  Drink (string name, int id, int stock, double price) {
    Name = name;
    ID = id;
    Stock = stock;
    Price = price;
  }

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


class Error {

protected:
  string err;
public:

  void PrintError();
  virtual void ProcessError() = 0;
};

class DrinkError : public Error {
  string DrinkName;
  int type;
public:

  DrinkError(string er, int ty) {
    DrinkName = er;
    ty = type;
  }

  virtual void ProcessError();

};

class InputError : public Error {
  int type;
public:

  InputError(int ty) {
    type = ty;
  }

  virtual void ProcessError();

};


void Error:: PrintError() {
  cout<<err<<endl;
}

void InputError::ProcessError() {

  switch(type) {
    case 0:       //If number of drinks is incorrectly entered!
      err = "DrinkNumberError: Please Input positive number of drinks to add!";
      break;
    case 1:       // Drink Name wasn't entered
      err = "DrinkNameError: Kindly enter a valid (non-empty!) name for the drink!";
      break;
    case 2:       // Drink Price was non-positive
      err = "DrinkPriceError: Kindly enter non-zero price for the drink!";
      break;
    case 3:       //Drink Stock was non-positive
      err = "DrinkStockError: Kindly enter positive stock for the concerned Drink!";
      break;
    case 4:       // Adding Negative balance, not good
      err = "BalanceAddingError: Kindly Enter a positive amount to add to your account!";
      break;
    case 5:       //Entered Anything else for the Binary Decision making
      err = "BinaryCommandError: Please Enter either 'Y' or 'N' only!";
      break;
    case 6:       //Invalid Drink ID
      err = "DrinkID_Error: Please input a valid Drink ID!";
      break;
    default:
      err = "Alas! Unknown error occured !";
      break;
  }

}

void DrinkError::ProcessError() {
  switch (type) {
    case 0 :        //Insufficient Balance
      err = "DrinkError: You don't have enough balance to buy "+ DrinkName + "!";
      break;
    case 1:         // We don't have stock
      err = "DrinkError: Sorry, We don't have enough stock of "+ DrinkName + "!";
      break;
    default:
      err = "Alas! Unknown Drink Error occured!";
      break;
  }
}


VendingMachine::VendingMachine(int x){              //Enables the user to add drinks

    cout << "Welcome to the Vending Machine!" << endl;
    cout << "Let's set it up Together!" << endl;
    cout << "Add Drinks in the format <Name> <Price> <Stock>" << endl;
    cout << "How many Drinks would you like to Add?" << endl;

    int ind = 1;
    int n = 0;

    while (true) {        //Taking Input, with exception Handling
      try{
        cin>>n;
        if (n <= 0) {
          throw InputError(0);
        }else break;
      }catch (InputError e){
        e.ProcessError();
        e.PrintError();
      }
    }


    for( ; ind <= n ; ind++ ) {

      //Buffer variables!
      string name;
      int stock = 0;
      double price = -1;

      while (true) {          //Taking Input, with exception Handling
        try{
          cin>>name>>price>>stock;
          if (name.size() == 0) {
            throw InputError(1);
          }else if (price <= 1e-5) {
            throw InputError(2);
          }else if (stock <=0) {
            throw InputError(3);
          }else break;
        }catch (InputError e){
          e.ProcessError();
          e.PrintError();
          stock = 0;
          price = -1;
        }
      }


      drinks.push_back(Drink(name,ind,stock,price));
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
    cout << "Press Any Other Key or no other key and enter to End The Game" << endl;

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

  double sum = -1;

  while(true) {               //Taking Input, with exception Handling
    try {
      cin>>sum;
      if(sum<=1e-5) {
        throw InputError(4);
      }else break;
    } catch(InputError e) {
      e.ProcessError();
      e.PrintError();
    }
  }

  currBalance += sum;

  cout << "----------------------------------" << endl<< endl;      //Marking Boundaries

};

void VendingMachine:: EjectChange() {                               // Ejecting All Change and ending the account

  cout << "Are you sure you want to eject all your money and close the account?[Y/N]" << endl;
  char command;

  while(true) {               //Taking Input, with exception Handling
    try{
      cin>>command;
      if(command != 'Y' && command != 'N') {
        throw InputError(5);
      }else break;
    }catch (InputError e) {
      e.ProcessError();
      e.PrintError();
    }
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

    if ( drinks[drinkid-1].Stock == 0){
      throw DrinkError(drinks[drinkid-1].Name, 1);
    }

    if ( currBalance < drinks[drinkid-1].Price ){
      throw DrinkError(drinks[drinkid-1].Name,0);
    }

    cout << "Thanks for buying " + drinks[drinkid-1].Name << "!" << endl;

    currBalance -= drinks[drinkid-1].Price;

    //Closing Account if in case balance becomes zero
    if( currBalance <= 1e-5 ) {

      currBalance = 0;
      accountOn = false;

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

        case 1: {
          // Buying a Drink
          int choice = 0;
          cout<<"Enter the ID of Drink you'd like to buy!"<<endl;

          while(true) {         //Taking Input, with exception Handling
            try {
              cin>>choice;
              if(choice < 1 || choice > drinks.size()) {
                throw InputError(6);
              }else break;
            }catch(InputError e) {
              e.ProcessError();
              e.PrintError();
              choice = 0;
            }
          }

          try{
            selectdrink(choice);
          }catch (DrinkError e){
            e.ProcessError();
            e.PrintError();
          }

          break;
        }
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

      double amount = -1;


      while(true) {       //Taking Input, with exception Handling
        try {
          cin>>amount;
          if( amount < 1e-5){
            throw InputError(4);
          }else break;
        }catch (InputError e) {
          e.ProcessError();
          e.PrintError();
          amount = -1;
        }
      }
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
