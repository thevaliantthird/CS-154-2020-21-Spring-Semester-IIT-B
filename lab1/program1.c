#include <stdio.h>
#include <stdlib.h>

struct Dice{
  int N;
  int count[7];
  long double probs[7];
};

void InitializeDie(struct Dice *d, int N){
  d->N = N;
  for(int i = 0;i<7;i++){
    d->count[i] = 0;
  }
}
void ThrowDices(struct Dice *d){
  for(int i = 0;i<d->N;i++){
    int x = (rand()%6)+1;
    d->count[x]++;
  }
}
void CalculateProbs(struct Dice *d){
  for(int i = 1;i<7;i++){
    d->probs[i] = ((long double)d->count[i])/((long double)d->N);
  }
}
void PrintProbs(struct Dice *d){
  for(int i = 1;i<7;i++){
    printf("The Probability for %d to come up is %Lf. \n",i,d->probs[i]);
  }
}


int main(int argc, char *argv[]){
  struct Dice *myDice = new struct Dice();
  InitializeDie(myDice,atoi(argv[1]));
  ThrowDices(myDice);
  CalculateProbs(myDice);
  PrintProbs(myDice);
}
