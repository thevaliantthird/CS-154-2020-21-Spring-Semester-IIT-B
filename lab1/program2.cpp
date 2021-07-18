#include <iostream>
#include <cstdlib>

using namespace std;

class Counter{
  FILE *myFile;
  char text[5000000];
  int charcount[256];
  int N;
  public:
    Counter(char *filename){
      myFile = fopen(filename,"r");
      N = 0;
      for(int i = 0;i<256;i++)charcount[i] = 0;
    }
    void ReadText(){
      int i = 0;
      while(fread(&text[i],sizeof(char),1,myFile)){
        i++;
      }
      N = i;
    }
    void Count(){
      for(int i = 0;i<N;i++){
        charcount[text[i]]++;
      }
    }
    void PrintCount(){
      for(int i = 0;i<256;i++){
        if(charcount[i]!=0 && i!=10){
          char d = i;
          cout<<"The Character '"<<d<<"' appeared "<<charcount[i]<<" times.\n";
        }
      }
    }
};



int main(int argc, char *argv[]){
  Counter myCounter(argv[1]);
  myCounter.ReadText();
  myCounter.Count();
  myCounter.PrintCount();
}
