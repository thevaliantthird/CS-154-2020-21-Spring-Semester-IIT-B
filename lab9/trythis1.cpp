/*
CS 154 Lab 9

Studing the code for order of evaluation of arguments passed to a function in C++

Modified by: Shubh Kumar, 200050134
*/

#include <iostream>

using namespace std;

void f(int x, int y, int z, int a, int b) {

 cout << x << " " << y << " " << z << " " << a << " " << b << endl;
}

int main () {

  int i=10;
  int j = 20;


  f(i, i++,(++j)+i,(++j)*(++i),++j);


}
