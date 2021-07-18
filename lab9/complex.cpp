/* CS154, IIT Bombay Lab 9
Testing user-defined operators for associativity and precedence

Author: Shubh Kumar, 200050134

*/
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;


class Complex {
 float i, j;
 public:
	 Complex (float x, float y) {
		i = x; j=y;
	 }

   Complex conjugate () {
     return Complex(i,-j);
   }

	 Complex operator + (Complex c) {
	 	cout << '(' << i << "+(" << j << ")i) + (" << c.i << "+(" << c.j << ")i)" << endl;
		return Complex (i+c.i,j+c.j);
	 }

	 void prn() { cout << i << "+(" << j << ")i" <<endl;}

   Complex operator -() {
     cout<<"Negating the Complex Number given by ";
     prn();
     return Complex(-i,-j);
   }

   Complex operator - (Complex c) {
     cout << '(' << i << "+(" << j << ")i) - (" << c.i << "+(" << c.j << ")i)" << endl;
     return Complex(i-c.i,j-c.j);
   }

   Complex operator * (Complex c) {
     cout << '(' << i << "+(" << j << ")i) * (" << c.i << "+(" << c.j << ")i)" << endl;
     return Complex (i*c.i-j*c.j,i*c.j+j*c.i);
   }

   Complex operator /= (float s) {
     return Complex (i/s,j/s);
   }

   float mod2 () {
     return (i*i)+(j*j);
   }

   Complex operator / (Complex c) {
     assert(c.mod2()>0);
     cout << '(' << i << "+(" << j << ")i) / (" << c.i << "+(" << c.j << ")i)" << endl;
     return (*this)*c.conjugate() /= c.mod2();
   }

   float arg () {
     float res = atan2(j,i);
     cout<<"arg("<<i<<"+"<<j<<"i) = "<<res;
     return res;
   }

};

int main () {

  Complex c1(10,10), c2(20,20), c3(5,6), c4(0,0);
  Complex c0(0,0);

  c0 = c1+c2-c3+c4;
  cout << "Testing Addition and Subtraction" << endl;
  c0 = c1+c2+c3+c4;
  c0.prn();
  c0.prn();
  c0 = c1-c2+c3+c4;
  c0.prn();
  c0 = -c1-c2-c3+c4;
  c0.prn();
  c0 = -c1-c3+c4-c2;
  c0.prn();

  cout<<"----------------------------------------------"<<endl;

  cout << "Testing Multiplication and Division" << endl;

  c0 = c1*c2*c3*c4;
  c0.prn();
  c0 = c2*(-c3)*c4;
  c0.prn();
  c0 = c1/c2*c3;
  c0.prn();
  c0 = c1*c2/c3;
  c0.prn();
  c0 = Complex(1,0)/c1/c2/c3;
  c0.prn();
  c0 = c2*c1/c3;
  c0.prn();



  cout<<"----------------------------------------------"<<endl;

  cout<<"Capturing the Precedence upon mixing the + and * operators"<<endl;

  c0 = c1+c2+c3*c4;
  c0.prn();
  c0 = c1+c2+c4/c3;
  c0.prn();
  c0 = (c1+c2+c3)*c4;
  c0.prn();
  c0 = c1-c2/c3;
  c0.prn();
  c0 = (c1-c4)*c3;
  c0.prn();

  cout<<"----------------------------------------------------";



  cout<<"Erroneous Operations"<<endl;
  c0 = c1/c4;
  c0.prn();

}
