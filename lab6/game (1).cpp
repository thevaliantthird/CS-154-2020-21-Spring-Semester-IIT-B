
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

int counter=0;
int score=0;
int key_max;
//int lives=3;
//Fl_Button* ur_score;
//Fl_Button* score_count;

char *int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
};


class Shape : public Fl_Widget  {
        protected:
        int x, y, w, h;
        public:
                Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
                        this->x=x; this->y=y;
                        this->w=w; this->h=h;
                }
                virtual void wipe()=0;
                virtual void refresh(int dx, int dy)=0;
};

class MyCircle : public Shape {
 public:
   MyCircle (int x,int y,int w) : Shape (x,y,w, w) { }
    virtual void draw() {
        fl_color(fl_rgb_color(130));
        fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
        fl_color(FL_WHITE);
        fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh(int dx, int dy) {
        x=x+dx;y=y+dy;
        resize(x,y,w,h);
        fl_color(fl_rgb_color(130));
        fl_pie (x,y,w,h,0,360);
   }
};

class MyCircle_bomb : public Shape {
 public:
   MyCircle_bomb (int x,int y,int w) : Shape (x,y,w, w) { }
    virtual void draw() {
        fl_color(FL_RED);
        fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
        fl_color(FL_WHITE);
        fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh(int dx, int dy) {
        x=x+dx;y=y+dy;
        resize(x,y,w,h);
        fl_color(FL_RED);
        fl_pie (x,y,w,h,0,360);
   }
};


struct Food{

  int x,y;
  MyCircle* food;

  Food(int x, int y){
    this->x=x; this->y=y;
    this->food= new MyCircle(x,y,10);
  }

};


struct Bomb{

  int x,y;
  MyCircle_bomb* bomb;

  Bomb(int x, int y){
    this->x=x; this->y=y;
    this->bomb= new MyCircle_bomb(x,y,15);
  }
};


Food* fd[50];
Bomb* bm[10];

class PacMan : public Shape {
 public:
   PacMan (int x,int y,int w) : Shape (x,y,w, w) { }
    virtual void draw() {
        fl_color(FL_YELLOW);
        fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
        fl_color(FL_BLACK);
        fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh(int dx, int dy) {
        x=x+dx;y=y+dy;
        resize(x,y,w,h);
        fl_color(FL_YELLOW);
        fl_pie (x,y,w,h,0,360);
   }

   virtual bool check_food(){

    for (int i; i<50; i++){
      if (fabs(fd[i]->x-this->x)<=10 && fabs(fd[i]->y==this->y)<=10){
        return(true);
      }
    }
    return(false);

   }

   virtual bool check_bomb(){

    for (int i; i<10; i++){
      if (fabs(bm[i]->x-this->x)<=30 && fabs(bm[i]->y-this->y)<=30){
        return(true);
      }
    }
    return(false);

   }

   virtual int handle(int e) {

                        if (e==FL_KEYBOARD){
                          counter++;
                          if(counter<key_max){
                            if (Fl::event_key()==FL_Up) {
                                    wipe();
                                    refresh(0,-10);
                            }
                            else if(Fl::event_key()==FL_Down){
                              wipe();
                              refresh(0,10);
                            }
                            else if(Fl::event_key()==FL_Left){
                              wipe();
                              refresh(-10,0);
                            }
                            else if(Fl::event_key()==FL_Right){
                              wipe();
                              refresh(10,0);
                            }
                            else if(Fl::event_key()==FL_Enter){
                              if(check_food()){
                                score++;
                              }
                              /*else if(check_bomb()){
                                lives--;
                                if(lives==0){
                                  window()->hide();
                                }
                              }*/
                            }
                          }
                          else {
                            window()->hide();
                          }

                        }
                        return 1;
                }

};



int main(int argc, char *argv[]) {
  int choice;

  cout<<"WELCOME!!\n";
  cout<<"Difficulty level: (1/2/3) ";
  cin>>choice;
  if (choice==1) key_max=500;
  else if(choice==2) key_max=250;
  else if(choice==3) key_max=125;

Fl_Window *window;
window = new Fl_Window (600,600,"PACMAN_Lite"); // outer window
        //for (int i=0; i<3; i++) {
          // new MyRectangle(10+i*100,10+i*100,70,70);
           //new MyCircle(300,300+i*100, 35);
        //}

/*
        ur_score = new Fl_Button(450,0,100,50,"Your Score: ");
        ur_score->color(FL_WHITE);
        ur_score->labelcolor(FL_BLACK);
*/
        int x, y;

        srand(time(0));

        for (int i=0; i<50; i++){
          x=rand()%500+50;
          y=rand()%500+50;
          fd[i]=new Food(x,y);
        }
/*
        for (int i=0; i<10; i++){
          x=rand()%500+50;
          y=rand()%500+50;
          bm[i]=new Bomb(x,y);
        }
*/
        new PacMan(300,300,20);
        window->color(FL_BLACK);

        window->end();
        window->show();
        int s=Fl::run();

        cout<<"***********GAME OVER*********\n";
        cout<<"Score: "<<score<<"\n";
        cout<<"Key Counter: "<<counter<<"\n";
        /*<<" "<<lives */;
        return(s);  // the process waits from here on for events
}
