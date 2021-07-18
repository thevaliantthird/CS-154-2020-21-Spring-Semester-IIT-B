/*
CS 154 Lab 9

Analyzing the compile time error occuring due to a syntactical error due to precedence of operators

Modified by: Shubh Kumar, 200050134
*/

#include <iostream>
using namespace std;


// why is there a compile time error?!

int main () {

bool a = true, b = true;

cout << a || b << endl;

}
