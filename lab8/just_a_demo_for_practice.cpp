#include <iostream>
//#define NDEBUG  // uncomment to turn off Assertions

#include <cassert>
using namespace std;

int main () {
  string s;
 int n;
 cin >> n;
 cin>>s;
 cout<<s[0];
 int a[n];

 for (int i=0;i<=n; i++) {

	assert(i<n);
	assert(i>-1);
  cout<<"Done!"<<endl;
//	a[i] =i;
 }

}
