/*
CS154 Lab 8 Optional program

Writing an assert statement of your own and test it

Author: Shubh Kumar,200050134

*/



#include <iostream>
#include <random>

using namespace std;

// explain how this code will behave. there is no assert here but
// an attempt is made by the programmer to define one's own assert
//if you can do a better job and give some meaning to it, rewrite, and
//explain


void Continue();            //Function to give next chance to people who fail!


#define codeassert(condition) \
      if (!(condition)) \
      { \
          cout<<"In File :"<<__FILE__<<", Line: "<< __LINE__<<", The Condition: "<<#condition<<" has failed!"<<endl; \
          Continue(); \
      } \



int main() {

  cout<<"Do you think you are a MathGeni? [y/n]"<<endl;

  char inp;
  cin>>inp;

  codeassert(inp=='y' || inp=='n');

  if(inp=='y') {
    int x,y,z;
    x = rand() % 100;
    y = rand() % 100;

    cout<<"Tell me, What is "<<x<<" times "<<y<<"?"<<endl;
    cin>>z;

    codeassert(z==x*y);
    cout<<"You are a brilliant Math-Guy!"<<endl;

  } else {
    cout<<"Why did you waste my resources then! Come prepared next time!"<<endl;
  }

}

void Continue() {
  cout<<"--------------------------------------------------------------------"<<endl;
  cout<<"You're getting Another Chance as you gave wrong inputs on your end!"<<endl;
  main();
  exit(0);
}
