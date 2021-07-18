#include <iostream>
#include <cstdlib>

using namespace std;

class Dice{
  int N;
  int count[7];
  long double probs[7];
  public:
    Dice(int _N){
      N = _N;
      for(int i = 0;i<7;i++)count[i]=0;
    }
    void ThrowDices(){
      for(int i = 0;i<N;i++){
        int x = (rand()%6)+1;
        count[x]++;
      }
    }
    void CalculateProbs(){
      for(int i = 1;i<=6;i++){
        probs[i] = ((long double)count[i])/((long double)N);
      }
    }
    void PrintProbs(){
      for(int i = 1;i<=6;i++){
        cout<<"Probability for "<<i<<" to come up is "<<probs[i]<<'.'<<endl;
      }
    }
};

int main(int argc, char *argv[]){
  Dice myDice(atoi(argv[1]));
  myDice.ThrowDices();
  myDice.CalculateProbs();
  myDice.PrintProbs();
}
