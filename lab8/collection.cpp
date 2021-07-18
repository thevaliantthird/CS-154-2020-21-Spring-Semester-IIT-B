/*
CS 154 Lab 8

Using Assertions to debug and Improve a code to model a
collection of integers

Author: Shubh Kumar, 200050134

*/


#include <iostream>
#include <cassert>

using namespace std;


// A program which is not correct
class Collection {

  int *S;
  int cap, card;

  public:
	Collection(int sz) {

    //Negative Size of Collection makes no sense
    assert(sz>=0);

    S = new int [sz];
		//card=0;
    card = min(0,sz-1);
    cap = sz;
  //... add assertion(s)...

    /* The current empty index needs to be feasible
    and hence less than cap(considering 0-based indexing)*/

    assert(card<cap);
	}

	void push_back(int elem) {
  //... add assertion(s)...

    //Making Sure adding elements will be possible
    assert(card<cap);
    assert(card>=0);

  //... add logic
    //card++;
    S[card] = elem;
    card++;

  //... add assertion(s)...

    //Making Sure, the right element is ejected!
    assert(S[card-1]==elem);

	}

	int pop_back() {
  //... add assertion(s)...

    //Making Sure something is there to eject
    assert(card > 0);


  //... add logic
    card--;
    int res = S[card];
    //card--;

  //... add assertion(s)...

    //Making Sure, the right element is ejected!
    assert((card>0) && (card<cap) && S[card]==res);

    return res;


	};

};

void PrintInstructions() {      //For Prinitng the Instructions to run the simulation
  cout<<"Press 1 to add an element."<<endl;
  cout<<"Press 2 to pop the top element."<<endl;
  cout<<"Press any other key and enter to quit!"<<endl;
}

int main () {

   // add code that tests the class above and fails it, which gets caught by assertions
   cout<<"Welcome to the Collection!"<<endl;
   cout<<"Please under the max-size (cap) of your collection:";
   int size;
   cin>>size;

   Collection *C = new Collection(size);
   bool cont = true;
   while(cont) {

     PrintInstructions();
     int inp;
     cin>>inp;

     switch(inp) {

       case 1:

        cout<<"What Element do you want to add?"<<endl;
        int e;
        cin>>e;
        C->push_back(e);
        break;

       case 2:

        cout<<C->pop_back()<<endl;
        break;


       default:

        cont = false;
        break;
     }
     cout<<"Congratualations! This command was successfully run without errors!"<<endl;
     cout<<"---------------------------------------------------------------------"<<endl;
   }

}
