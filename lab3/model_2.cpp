//code by Prof. R.K.Joshi, CSE, IIT Bombay
// Code Completed by Shubh Kumar, 200050134
//part of CS 152/154 2021

#include <iostream>
using namespace std;

//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..

//--------------- section 1 ---- interface of the abstraction
//declarations give us the abstraction (interface)

void push (int elem, int *S, int *top, int *card); // add an element on top of stack
int pop (int *S, int *top, int *card);  // note the value at the top, remove the top and return the value
int card (int *S, int *card); // cardinality, how many elements in stack

//-----------section 2 --- implementation of the abstraction--
// definitions give us the implementation of the abstraction (bodies)


int S1[100]; // S[45] is 46th element!
int top1=0; // current position in stack which is empty, position indicator
int card1=0; // cardinality, no. of elements in the stack

int S2[100]; // S[45] is 46th element!
int top2=0; // current position in stack which is empty, position indicator
int card2=0; // cardinality, no. of elements in the stack


void push (int elem, int *S, int *top, int *card) {

  if (*card >= 100) {            // Handling Errors if stack is full

    cout<<"Stack is Full!"<<endl;

  } else {

    S[*top] = elem;            // The Top-most element is added in the stack provided

    (*card) = (*card) + 1;                   //Cardinality of Stack has increased for the stack provided
    (*top) = (*top) +1;                    //For the stack considered ,top is incremented so that next element could be added after current

  }

};

int pop (int *S, int *top, int *card) {

  if ( *card == 0 ) {
    //Indication for Error,as for this stack is empty

    cout << "The Stack doesn't have any element!" << endl;
    return -1;

  } else {

      *top = (*top) -1;          //For the stack considered, Reducing top as now the last empty would be the element before it
      *card = (*card)-1;         // Removing the top element for the considered stack

      return S[*top];

  }
};

int card (int *S, int *card) {

  //Getting the Cardinality of the Stack
  return *card;

};


//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction...
  int e;

  push (10, S1, &top1, &card1);
  push(12, S1, &top1, &card1);
  push (14, S1 , &top1, &card1);

  e=pop(S1 , &top1, &card1);
  cout << e << endl;

  e=pop(S1 , &top1, &card1);
  cout << e << endl;

  push (10, S2, &top2, &card2);
  push(12, S2, &top2, &card2);
  push (14, S2, &top2, &card2);

  e=pop(S2, &top2, &card2);
  cout << e << endl;

  e=pop(S2, &top2, &card2);
  cout << e << endl;


}
