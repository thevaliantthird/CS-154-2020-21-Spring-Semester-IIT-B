//code by Prof. R.K.Joshi, CSE, IIT Bombay
// Code Completed by Shubh Kumar, 200050134
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//fourth solution: more secure.. globals are gone, they are wrapped into classes
// and no more passing references to object's implementation.. that is automatic
// but we have a receiver object
//third solution: structure the body elements... neater and safer,, encapsulating elements in one structure
//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..


class Stack {

  int S[100]; // S[45] is 46th element!
  int top=0; // current position in stack which is empty, position indicator
  int cardinality=0; // cardinality, no. of elements in the stack

public:

  void push (int elem) ;// add an element on top of stack
  int pop ();  // note the value at the top, remove the top and return the value
  int card(); // cardinality, how many elements in stack

};


void Stack::push( int elem ) {

    if( card >= 100 ) {                 //Handling Error if the Stack is full

      cout << "The Stack is Full!" << endl;

    } else {

      S[top] = elem;                    //Setting the Top empty element as the element to be added

      top++;                            //Incrementing the next empty element's index
      cardinality++;                           //Incrementing Cardinality

    }

};

int Stack::pop () {

  if ( card == 0 ) {

      cout << "The Stack is Empty!" << endl;
      return -1;

  } else {

      top--;                              //Now the top element would be the one before
      cardinality--;                             //Cardinality of Stack would decrease

      return S[top];                      //Returning the Top Element
  }

};

int Stack::card () {
  // Getting the Cardinality of the Stack
  return cardinality;

}

//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...

  Stack s1, s2;
  int e;

  s1.push (10);
  s1.push(12);
  s1.push (14);

  e=s1.pop();
  cout << e << endl;

  e=s1.pop();
  cout << e << endl;

  s2.push (10);
  s2.push(12);
  s2.push (14);

  e=s2.pop();
  cout << e << endl;

  e=s2.pop();
  cout << e << endl;


}
