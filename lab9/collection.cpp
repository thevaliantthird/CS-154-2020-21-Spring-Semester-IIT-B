/*
CS 154 Lab 9
Defining Operators to make a Stack

Author: Shubh Kumar, 200050134

*/

#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Collection {

 int *array, card, maxsize; // storage and cardinality

 public:

	 Collection (int sz) {
		array = new int [sz];
		card = 0;
		maxsize = sz;
	 }

	 Collection &operator << (int elem) {
		if (card < maxsize) array [card++] = elem;
		return *this;
	 }

   void operator << (Collection &sub) {       // Bulk Insertion Operator
     //Getting data from the given collection
     int x = sub.maxsize;
     int y = sub.card;
     int *newarray = new int[maxsize+x];                //New Larger Array
     int i;

     for(i = 0;i<card;i++) {                           // Adding the first stack into our new one
       newarray[i] = array[i];
     }

     for(;i<card+y;i++) {
       newarray[i] = sub.array[i-card];                //Adding the Second stack to our new one
     }

     delete array;
     array = newarray;                                //Setting the new one to be the former
     maxsize = maxsize+x;                             //Adjusting the attributes
     card = i;
   }

   void operator >> (int &x) {                  //popping the last inserted element
     if (card<=0)x =  -1;
     else  x = array[--card];
   }

	 void prn() {

		for (int i=0; i<maxsize; i++)
			cout << array[i] << " ";
		cout << endl;

	}
};

int main () {

	Collection c1 (5);
  //Inserting into the first collection
	c1 << 1;
	c1 << 2;
	c1 << 3;
	c1 << 4;
	c1 << 5;
	c1.prn();

	Collection c2(3);
  // Inserting into the second collection
	c2 << 1 << 2 << 3;
	c2.prn();
  //Merging the second collection into the first
  c1<<c2;
  c1.prn();

  int x;
  for (int i = 0;i<8;i++) {
    c1>>x;                          //Popping out a single element from the merged collection
    cout<<x<<' ';
  }
  cout<<endl;

}
