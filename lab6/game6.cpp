#include <FL/Fl_Button.H>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <bits/stdc++.h>

#define WINDOWX 600
#define WINDOWY 800

using namespace std;



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

class Elliptic : public Shape {
  int type;
 public:
   Elliptic (int x,int y,int w, int type) : Shape (x,y,w, w) { }
    virtual void draw() {
        this->type = type;
        if(type==0) fl_color(FL_RED);
        else fl_color(fl_rgb_color(130));
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
        if(type==0) fl_color(FL_RED);
        else fl_color(fl_rgb_color(130));
        fl_pie (x,y,w,h,0,360);
   }
};


class Collectible {
  int type;
  int x,y;
  Elliptic *rep;
  bool ifCollected = false;
public:

  Collectible (int x, int y, int type) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->rep = new Elliptic(x,y,12,type);
  }

  int CheckInRadar(int _x, int _y) {
    if((x-_x)*(x-_x) + (y-_y)*(y-_y) <= 30) {
      return (2*type)-1;
      ifCollected = true;
    }else {
      return 0;
    }
  }
};


class CollectorAndCollections : public Shape {

  Collectible* array[100];
  time_t TimeToEnd;
  int score;

 public:
   CollectorAndCollections (int x,int y,int w, int PlayTime) : Shape (x,y,w, w) {
     score = 0;
     int it;
     for (it = 0 ;it < 100; it ++) {
       array[it] = new Collectible( rand() % (WINDOWX-100) + 50, rand() % (WINDOWY-100) + 50 , rand() % 2);
     }
     TimeToEnd = time(0)+PlayTime;
   }

    virtual void draw() {

        fl_color(FL_GREEN);

        fl_pie (x,y,w,h,0,270);


   }
   virtual void wipe() {

        fl_color(FL_BLACK);
        fl_pie (x,y,w,h,0,360);

   }

   virtual void refresh(int dx, int dy) {
        x=x+dx;y=y+dy;
        resize(x,y,w,h);
        fl_color(FL_GREEN);
        fl_pie (x,y,w,h,0,360);

   }

   int SONAR() {
      int j,sum = 0;
      for (j = 0;j<100;j++) {
        sum+=array[j]->CheckInRadar(x,y);
      }
      return sum;
    }

    virtual int handle(int e) {

          if (e==FL_KEYBOARD){

            if(time(0) < TimeToEnd){

              if (Fl::event_key()==FL_Up) {
                      wipe();
                      refresh(0,-10);
              }else if(Fl::event_key()==FL_Enter){
                score+=SONAR();
              }
              else if(Fl::event_key()==FL_Down){
                wipe();
                refresh(0,10);
              }
              else if(Fl::event_key()==FL_Right){
                wipe();
                refresh(10,0);

              }
              else if(Fl::event_key()==FL_Left){
                wipe();
                refresh(-10,0);

              }

            }
            else {
              cout<<"Time Up!"<<endl;
              cout<<"You Score was: "<<score<<endl;
              window()->hide();
            }

          }
          return 1;
  }

};



int main(int argc, char *argv[]) {

        cout<<"This is the Game of Collect! \n In how many seconds, Do you think you could collect them all ?"<<endl;
        int PlayForTime;
        cin>>PlayForTime;
        Fl_Window *window;
        window = new Fl_Window(WINDOWX, WINDOWY, "Collect!");

        new CollectorAndCollections(WINDOWX/2, WINDOWY/2 ,20, PlayForTime);

        window->color(FL_BLACK);

        window->end();
        window->show();


        return(Fl::run());
}
