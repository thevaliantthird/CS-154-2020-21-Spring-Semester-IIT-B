/*
CS 154 Lab 9

Analyzing Right to left and left to Right Evaluation of Expressions in C++

Author: Shubh Kumar, 200050134

*/

#include <iostream>

using namespace std;

class A {
 int id;
 public:
	A (int v) {id=v;}
	A &operator = (A &a) {
		cout << "executing " << id << "=" << a.id << endl;
    id = a.id;
		return *this;
	}
  A &operator - () {
    cout<<"Negating from "<<id<<" to "<<-id<<endl;
    id = -id;
    return *this;
  }

};

int main () {
  int a=1, b=2, c=3;
	a = (++b) = c++;
 //  (a++) = (b++)=c; Will give error, as we can't assign anything to a++ or b++
  cout << a << b << c << endl;
  A a1(1), a2(2), a3(3);
	a1=a2=a3;
  A b1(1),b2(2),b3(3),b4(4),b5(5),b6(6), b7(7), b8(8);
  -b1=-b2=-b3 = b4 = -b5 = -b6 = -b7 = -b8;
}
