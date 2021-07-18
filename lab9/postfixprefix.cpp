/*  CS154 Lab 9
Completing the Post-fix and pre-fix increment functions and analyzing the expressions used
Modified by : Shubh Kumar, 200050134        */

#include <iostream>
using namespace std;

class A {

    int v;
    int z;
	public:
		A(int x) { v = x;}
		A &operator ++() {
			cout << "prefix operator called \n";
      v++;
      return *this;
		}
	  const A &operator ++(int) {
			cout << "postfix operator called \n";
      v++;
      const A *res = new A(v-1);      //As this memory is futile, except for any lvalue assignment from it
      return *res;
		}
    void prn() {cout<<v<<endl;}
};

int main () {

 A a(10), b (20), c(0);
  ++a;
  a.prn();
	++a = b;
  a.prn();
	c =  a++;
  c.prn();
  //a++ = b      will give error
  a.prn();
}
