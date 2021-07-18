//code by Prof. R.K.Joshi, CSE, IIT Bombay
// Code Completed by Shubh Kumar, 200050134
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//third solution: structure the body elements... neater and safer,, encapsulating elements in one structure
//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..


struct Stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack
};

 void push (int elem, struct Stack *myStack ) ;// add an element on top of stack
 int pop (struct Stack *myStack);  // note the value at the top, remove the top and return the value
 int card(struct Stack *myStack); // cardinality, how many elements in stack



void push (int elem, struct Stack *myStack ) {

  if(myStack -> card >= 100) {                      // Handling Error if stack is full!

    cout <<"Stack is Full!"<< endl;

  }else {

    myStack -> S[ myStack -> top ] = elem ;         //Adding the element to the empty position in the stack

    myStack -> top++;                               //Incrementing the next empty position!
    myStack -> card++;                              // Incrementing the Cardinality
  }

};

int pop ( struct Stack *myStack ) {

  if ( myStack -> card == 0 ) {                       //Handling Errors if stack is empty

    cout << "Stack is empty!" << endl;
    return -1;

  }else{

    myStack -> top --;                                //Decrementing the top empty index as now it would be the one before last
    myStack -> card --;                               // Decrementing Cardinality as one element is removed

    return myStack -> S[ myStack -> top ];

  }

};


int card ( struct Stack *myStack ) {                // Getting Cardinality

  return myStack -> card;

}


//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...

  struct Stack s1, s2;
  int e;
  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;

  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;


}
