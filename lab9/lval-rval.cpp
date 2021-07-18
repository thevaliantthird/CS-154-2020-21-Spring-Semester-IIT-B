/*
CS 154 Lab 9
Observing and explaining why we couldn't assign to post-fixed increment operator's return value.

Modified by : Shubh Kumar, 200050134
*/

#include <iostream>

using namespace std;

int main () {

int x=10;

 ++x = x++;  // this is acceptable
 cout << x << endl;
 ++x = 20;  //Will set the value of x to 20
 cout << x << endl;

// x++ = x++;    This Won't work!
//x++ = 50;      This won't work!


}
