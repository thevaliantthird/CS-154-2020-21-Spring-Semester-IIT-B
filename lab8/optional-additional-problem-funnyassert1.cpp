// #include <iostream>
// using namespace std;
//
// // explain how this code will behave. there is no assert here but
// // an attempt is made by the programmer to define one's own assert
// //if you can do a better job and give some meaning to it, rewrite, and
// //explain
//
// #define codeassert(arg) switch(arg) { case 0:break; case 1: cout<<"Y"<<endl; break;}
//
//
// int main() {
//
// int i, j;
// cin >> i;
// cin >> j;
//
// codeassert(i==j);
// //codeassert(true);
// //codeassert(false);
//
// }

#include <iostream>
using namespace std;

// explain how this code will behave. there is no assert here but
// an attempt is made by the programmer to define one's own assert
//if you can do a better job and give some meaning to it, rewrite, and
//explain

#define codeassert(arg) switch(0){case 0:case arg:;}


int main() {

int i, j;
cin >> i;
cin >> j;

codeassert(i==j);
//codeassert(true);
//codeassert(false);

}
