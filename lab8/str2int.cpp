/*
CS 154 Lab 8
Using Assertions to debug and Improve a code to convert
a string to an integer

Author: Shubh Kumar, 200050134

*/


#include<iostream>
#include <string>
#include <cassert>
#include <climits>

using namespace std;


int str2int (string s) {

	int v;
	int i = s.size()-1;
	int a = 0;
	long long z = 0;
	long long j = 1;
	long long k;

 // define your other needed variables

    // add assertions here first

  // Ensuring the String neither empty, nor too long
	assert(i>=0 && i<=15);

	//Ensuring the string has only numbers and no other characters
	if (s[0]=='-') a = 1;
	for(;a<s.size();a++) assert((s[a]<='9') && (s[a]>='0'));

  // the logic, which does not check for any condition, can be buggy

	for( ; i >= 0 ; i-- ) {
		z += ( (long long) (s[i]-'0') ) * j ;
		j *= 10 ;
	}


 // add assertions for postcondition
 //Checking if whatever we did was indeed correct!
	k = z;
	i = s.size()-1;
	while ( k != 0 && i >= 0 ) {

		assert(k%10==s[i]-'0');
		k/=10;
		i--;

	}
 //Ensuring the String wasn't too long that it can't fit in string

 assert((z<INT_MAX) && (z>INT_MIN));
 v = z;

 return v;
};

int main() {

// develop main which catches errors through assertions
// report bugs

	cout<<"Welcome to this str to int (int!, not long long)"<<endl;
	cout<<"Enter the String you want to convert to int:";
	string s;
	cin>>s;

	int result = str2int(s);
	cout<<"No errors occured, the int is:"<<result<<endl;

}
