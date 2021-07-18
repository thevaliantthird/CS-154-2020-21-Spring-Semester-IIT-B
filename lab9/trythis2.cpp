/*
CS 154 Lab 9

Studing the code for order of evaluation of arguments passed to a function in C++

Modified by: Shubh Kumar, 200050134
*/

#include <iostream>

using namespace std;

void f(int x, int y, int z) {

 cout << x << " " << y << " " << z << endl;
}

int main () {
int i=10;
int x = 0;
 f(i, i++, (++i)+x);

//i = 100;

 f(++i, i++, (++i)+x);

cout << i << endl;

}
