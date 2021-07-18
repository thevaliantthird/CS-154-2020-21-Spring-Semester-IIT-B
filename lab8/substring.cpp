/*
CS 154 Lab 8
Using Assertions to debug and Improve a code to find
the position of a substring in a particular string

Author: Shubh Kumar, 200050134

*/



#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int find(string str, string sub) {

// add precondition assertions

  // Checking if string size is strictly greater than the substring size
  //This implicitly checks for str.size()>0
  assert(str.size()>sub.size());


// add logic
  int pos = -1;
  for(int i = 0;i<str.size();i++){
    bool IsSub = true;               //If the substring start from here!
    for(int j = 0 ; j<sub.size() && ( i+j < str.size() ) ;j++) {
      IsSub = IsSub && (str[i+j]==sub[j]);
    }
    if(IsSub) pos = i;
  }

// add postcondition assertions
  if (pos != -1) {

    /*Should be true as the portion of
    substring present in the string needs to be greater than
    or equal to substring length*/

    assert(str.size()-pos>=sub.size());
  }
  return pos;
}

int main () {

// add testing code here which fails the above function and that failure
//gets caught by the assertions that you have
  string str,sub;

  cout<<"Welcome to Identifying substrings in strings!"<<endl;

  cout<<"Enter the String:";
  cin>>str;

  cout<<"Enter the Substring:";
  cin>>sub;
  cout<<"The substring wasn't part of the string"<<endl;

  int res = find(str,sub);

  cout<<"The Program ran successfully without any errors!"<<endl;

  if(res==-1){
  }else{
    cout<<"The last occurence of the Substring is present from the "<<res+1<<"th position to the "
    <<res+sub.size()<<"th position!"<<endl;
  }

}
