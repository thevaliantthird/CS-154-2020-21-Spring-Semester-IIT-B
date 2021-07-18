#include <stdio.h>
#include <stdlib.h>

struct Counter{
  FILE *f;
  char text[5000000];
  int charcount[256];
  int N;
};

void Initialize(struct Counter *c, char *filename){
  c->f = fopen(filename, "r");
  c->N = 0;
  for(int i = 0;i<256;i++)c->charcount[i] = 0;
}

void ReadText(struct Counter *c){
  int i = 0;
  while(fread(&c->text[i],sizeof(char),1,c->f)){i++;}
  c->N = i;
}
void Count(struct Counter *c){
  for(int i = 0;i<c->N;i++){
    c->charcount[c->text[i]]++;
  }
}
void PrintCount(struct Counter *c){
  for(int i = 0;i<256;i++){
    if(c->charcount[i]!=0 && i!=10){
      char d = i;
      printf("The Character '%c' appeared %d times.\n",d,c->charcount[i]);
    }
  }
}
int main(int argc, char *argv[]){
  struct Counter *myCounter = new struct Counter();
  Initialize(myCounter,argv[1]);
  ReadText(myCounter);
  Count(myCounter);
  PrintCount(myCounter);
}
