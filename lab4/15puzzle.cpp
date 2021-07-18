/*
CS 154 Lab 4

The Puzzle of 15
Author: Shubh Kumar, 200050134

The Program has additional features to checks whether or not a particular
setting of numbers is solvable as per the specifications on

https://en.wikipedia.org/wiki/15_puzzle

*/


#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> //needed to use Fl_Button
#include <bits/stdc++.h>  // All other C++ Libraries

using namespace std;

//Declaring Classes
class Controller;
class myButton;

class myButton : public Fl_Button {

  int i,j;
  Controller *parent;     //To Enable the parent class, the Game Controller to control it

public:

  myButton (int x, int y, int w, int h, const char *l, int _i, int _j,Controller *par);
  int handle(int e);

};

//The Game's interface
class Controller {

  int numsInArray[4][4];              //The Array containing the Numbers
  Fl_Window *window;                  // The Window
  pair<int,int> blank;                //The current position of the blank
  Fl_Button *completed;               //The TextBox indicating Completion
  Fl_Button *Move;                    // The Textbox indicating the most recent move
  Fl_Button *cells[4][4];             // The 2D array of buttons GUI
  char *arr[4][4];                    // The Strings labels of those buttons
  char *MoveLabel;                    // The Label of the Most-recent move Box

public:

  Controller();                               // Constructor
  bool CheckSolved();                         // To Check if the Puzzle is solved
  void move(int i,  int j, int mov);          // To move a particular number
  bool CheckFeasible(vector<int> *numbers);   // Check if a particular setting of the Grid could be solved
  void InitializeNumbers();                   // Initializing Numbers keeping feasibility in mind
  bool ifBlank(int i, int j);                 // To check if the cell indicated is a blank one

};


Controller:: Controller() {

  // Initializing the Numbers's Grid
  InitializeNumbers();

  //Allocating the Window
  window = new Fl_Window(600,600,"The Puzzle of 15");
  window->color(FL_YELLOW);
  //The Labels' Buttons
  MoveLabel = new char[20];
  Move = new Fl_Button(400,200,100,50, MoveLabel);
  completed = new Fl_Button(250,50,100,50,"Unsolved");
  Move->color(FL_WHITE);
  completed->color(FL_GREEN);

  // Creating the 2D Buttons' array
  for ( int i = 0 ; i < 4 ; i++ ) {
    for ( int j = 0 ; j < 4 ; j++ ) {

      if ( numsInArray[i][j] == 0 ) {     //Dealing with the Blank
        //Allocating for the button and setting the blank pair
        arr[i][j] = new char[20];
        cells[i][j] = new myButton(50*(j+1) ,100+50*(i+1) , 50 , 50 , NULL , i , j , this);
        blank.first = i;
        blank.second = j;

      } else {
        //Allocating for the button
        arr[i][j] = new char[20];
        strcpy(arr[i][j],std::to_string(numsInArray[i][j]).c_str());
        cells[i][j] = new myButton(50*(j+1),100+50*(i+1),50,50,arr[i][j],i,j, this);

      }
      cells[i][j]->color(FL_CYAN);
    }
  }

  //Ending the Window
  window->end();
  //Showing it to the user
  window->show();

}

bool Controller :: ifBlank (int i, int j) {

  if(blank.first==i && blank.second==j)return true;

  else return false;

}

bool Controller::CheckSolved() {

  for ( int i = 0 ; i < 4 ; i++ ) {

    for ( int j = 0 ; j<4 ; j++ ) {

      if ( i!=3 || j !=3 ) {

          if ( numsInArray[i][j] != ((4*i)+j+1) ) {

            return false;

          }
      }

    }

  }

  return true;

}


myButton :: myButton (int x,int y, int w, int h, const char *l, int _i, int _j, Controller *par)
  : Fl_Button (x,y,w,h,l) {

  i = _i;
  j = _j;
  parent = par;

}

// mov will be 1 for right, 2 for up, 3 for left, 4 for down
void Controller::move (int i, int j, int mov) {

  int _i, _j;

  switch (mov) {

    case 1:
      _i = i;
      _j = j+1;
      break;

    case 2:
      _i = i-1;
      _j = j;
      break;

    case 3:
      _i = i;
      _j = j-1;
      break;

    case 4:
      _i = i+1;
      _j = j;
      break;

    default:
      Move->label("Invalid Move!");
      return;
      break;

  }

  blank.first = i;
  blank.second = j;
  int tmp = numsInArray[i][j];
  numsInArray[i][j] = numsInArray[_i][_j];
  numsInArray[_i][_j] = tmp;

  //Setting Cells the Screen
  strcpy(arr[_i][_j],to_string(numsInArray[_i][_j]).c_str());
  cells[i][j]->label(" ");
  cells[_i][_j]->label(arr[_i][_j]);

  //Setting the Move Label
  string Msg = to_string(numsInArray[_i][_j])+" moved!";
  strcpy(MoveLabel,Msg.c_str());
  Move->label(MoveLabel);

  // Checking if the step solves the Grid
  if(CheckSolved())completed->label("Solved!");

}

int myButton :: handle (int e) {

	if ( e == FL_PUSH ) {

    if ( j < 3  && parent -> ifBlank(i,j+1) ) {      //If right

      color(FL_RED);
      parent->move(i,j,1);

    } else if ( j > 0  && parent -> ifBlank(i,j-1) ) {    //If Left

      color(FL_RED);
      parent->move(i,j,3);

    } else if ( i < 3 && parent -> ifBlank(i+1,j) ) {    //If Down

      color(FL_RED);
      parent->move(i,j,4);

    } else if ( i > 0 && parent -> ifBlank(i-1,j) ) {    //If Up

      color(FL_RED);
      parent->move(i,j,2);

    } else {

      parent->move(i,j,-1);                     //Invalid

    }
  } else if ( e == FL_LEAVE ) {                        //Coloring covered ones

    color(FL_WHITE);

  }

  return 1;

};

//Checking if the Number Initializing proposed is feasible, by calculating no. of inverses
//and checking if they are odd or even.

bool Controller::CheckFeasible ( vector<int> *numbers ) {
  int Invcount = 0;

  for ( int i = 0; i < 16 ; i++ ) {
    for ( int j = i+1 ; j < 16 ; j++ ) {
      if ( numbers->operator[](i) != 0 && numbers->operator[](j) != 0 ) {
        if ( numbers->operator[](i) > numbers->operator[](j) ) Invcount++;
      }
    }
  }

  return (1-( Invcount % 2 ) );
}

void Controller::InitializeNumbers() {

  srand ( (unsigned) time(0) );     //Getting the seed from time
  vector<int> num;

  //0 means blank
  for( int i = 0 ; i<16 ; i++ ) {
    num.push_back(i);
  }

  random_shuffle(num.begin(),num.end());      //Randomly shuffling the numbers

  // Keep Shuffling until a favourable arrangement is reached!
  while ( !CheckFeasible(&num) ) random_shuffle ( num.begin() , num.end() ) ;

  // Getting the Numbers into the array
  for (int i = 0 ; i < 4 ; i++ ) {

    for ( int j = 0 ; j < 4 ; j++ ) {

      numsInArray[i][j] = num[num.size()-1];

      num.pop_back();

    }

  }

}

int main() {

  Controller *myControl;
  myControl = new Controller();

  return(Fl::run());  // the process waits from here on for events
}
