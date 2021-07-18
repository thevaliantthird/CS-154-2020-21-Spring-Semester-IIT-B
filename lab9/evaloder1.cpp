/*
CS 154 Lab 9
Modified Program for Playing with Function arguments to get to know about the order in which they are evaluated

Modified by : Shubh Kumar. 200050134
*/

#include <iostream>

using namespace std;


int p=1;

int f(int i, int j) { p=p+i+j; return p; }

int main () {
  int j = 3;
  cout << f(p,++j) << ' ' << f(p,p+j) << ' ' << f(p,p+(j++)) << ' ' << f(++p,(++j)+(p++)) << endl;


}
