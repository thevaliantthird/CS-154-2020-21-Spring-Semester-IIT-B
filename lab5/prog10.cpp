#include<iostream>
using namespace std;
class A {
  int x;
  public:
        A(int v) {x=v;}
	virtual void f() {cout << x << "A::f\n"; g(); }
	virtual void g() { cout << x << "A::g\n";}
};
class B : public A {
 int y;
 public:
        B(int v):A(v+10) {y=v;}
	virtual void f(){cout << y << "B::f\n";}
        virtual void g() {cout << y << "B::g\n";}
};

class C: public A, public B{
  int z;
public:
  C(int y):A(y+20),B(y+10) {
    z = y;
  }
};
int main (int argc, char *argv[]) {
 C *cp = new C(200);
 cp->f();
 cp->g();

 }
