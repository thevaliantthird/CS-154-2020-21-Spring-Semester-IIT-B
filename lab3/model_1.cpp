//code by Prof. R.K.Joshi, CSE, IIT Bombay
// Code Completed by Shubh Kumar, 200050134
//part of CS 152/154 2021

#include <iostream>
using namespace std;


//--------------- section 1 ---- interface of the abstraction
//declarations give us the abstraction (interface)

void push (int elem); // add an element on top of stack
int pop ();  // note the value at the top, remove the top and return the value
int card(); // cardinality, how many elements in stack

//-----------section 2 --- implementation of the abstraction--
// definitions give us the implementation of the abstraction (bodies)


int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int cardinality=0; // cardinality, no. of elements in the stack

void push(int elem) {

  if ( card >= 100 ) {                      // Handling Errors, if stack is full!

    cout << "Stack is Full!" << endl;

  } else {

    S[top] = elem;            // The Top-most element is added

    cardinality++;                   //Cardinality of Stack has increased
    top++;                    //top is incremented so that next element could be added after current

  }

};

int pop() {

  if( card == 0 ) {
    //Indication for Error

    cout << "The Stack doesn't have any element!" << endl;
    return -1;

  } else {

      top--;          //Reducing top as now the last empty would be the element before it
      cardinality--;         // One element taken out

      return S[top];
  }

};

int card() {

  return cardinality;                          // Returning Number of Elements

};

//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...
  int e;

  push (10);
  push(12);
  push (14);

  e=pop();
  cout << e << endl;

  e=pop();
  cout << e << endl;

}
