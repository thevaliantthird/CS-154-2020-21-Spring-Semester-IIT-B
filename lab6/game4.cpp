
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <bits/stdc++.h>
#define te 10
#define G 10
#define afac 20
#define WINDOWX 600
#define WINDOWY 800






class Object : public Fl_Widget  {

    bool completed = false;

  	protected:
	     int x, y, w, h;
       double vx, vy;
	  public:
		    Object (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			          this->x=x; this->y=y;
			          this->w=w; this->h=h;
                this->vx = 0;
                this->vy = 0;
                this->w = 0;
		    }
        virtual void wipe() = 0;
        virtual void refresh()=0;

        void runObject() {
          wipe();
          x+=(vx*te);
          y+=(vy*te);

          if (x < w || (x > (WINDOWX - w)) ) {
            vx = -vx;
            if( y < 20 || y>(WINDOWY-20)){
              completed = true;
            }
          }
          if(y < h || (y > (WINDOWY-h))){
            vy = -vy;
          }
          refresh();
        };



        void accelerate(double xr, double yr ) {
          double ax = (x-xr)*afac;
          double ay = (y-yr)*afac;
          vx+=(ax*te);
          vy+=(ay*te);
        };

        void GravityEnact () {
          vy+=(G*te);
        };

        bool ifEnd () {
          return completed;
        }
};

class MyCircle : public Object {
 public:
   MyCircle (int x,int y,int w) : Object (x,y,w+100, w+20) { }
    virtual void draw() {
	     fl_color(fl_rgb_color(130));
	      fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
	fl_color(FL_WHITE);
	fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh() {


	resize(x,y,w,h);

	fl_color(fl_rgb_color(130));
	fl_pie (x,y,w,h,0,360);

   }
};
//
// class Elliptic : public Object {
//
// public:
//
//   Elliptic (double x, double y, double w, double h)
//   : Object (x,y,w,h) {
//
//   }
//
//   virtual void draw() {
//
//     fl_color(fl_rgb_color(130));
//     fl_pie (x,y,w,h,0,360);
//  }
//
//  virtual void refresh () {
//
//     resize(x,y,w,h);
//  	  fl_color(fl_rgb_color(130));
//  	  fl_pie (x,y,w,h,0,360);
//
//  }
//
//   virtual void wipe() {
//     fl_color(FL_WHITE);
//   	fl_pie (x,y,w,h,0,360);
//   }
//
//
// };
//
// class Rectangle : public Object {
// public:
//
//   Rectangle (double x, double y, double w, double h)
//   : Object (x,y,w,h) {
//
//   }
//
//   virtual void refresh () {
//     resize(x,y,w,h);
//   	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
//   }
//
//   virtual void wipe() {
//      fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
//   }
//
//   virtual void draw() {
//
//     fl_color(fl_rgb_color(120));
//     fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
//
//  }
//
// };

//
// class GameControl: public Fl_Window {
//
//
//
// public:
//
//   GameControl(int w, int h, const char *title=0) : Fl_Window (w, h,title) {
//
//       score = 0;
//       color(FL_WHITE);
//       InitializeObject();
//
//   };
//
//   void InitializeObject () {
//
//
//
//   }
//
//   virtual int handle(int e) {
//     if (e==FL_PUSH) {
//
//       int x = Fl::event_x();
//       int y = Fl::event_y();
//       myObject->accelerate(x,y);
//     }
//     return 1;
//   };
//
//   void runGame() {
//
//
//
//     end();
//     show();
//     redraw();
//
//     myObject->GravityEnact();
//     myObject->runObject();
//
//     if(myObject->ifEnd()) {
//       score+=10;
//       delete myObject;
//       InitializeObject();
//     }
//     Fl::check();
//     Fl::run();
//   }
//
//
// };
//




int main(int argc, char *argv[]) {



  Fl_Window *window;
  window = new Fl_Window (WINDOWX,WINDOWY,"DEMO");
  window->color (FL_WHITE);

  int score = 0;
  Object *myObject;
  // int t = rand()%2;
  // int xs = rand() % WINDOWX;
  // int ys  = rand() % WINDOWY;
  //
  // if(xs<=100) xs+=100;
  // if(xs>=WINDOWX-100)xs-=100;
  // if(ys<=100) ys+=100;
  // if(ys>=WINDOWY-100)ys-=100;
  //
  // if(t==0) {
  //   myObject = new Rectangle (xs,ys, 20, 20);
  // }else {
  //   myObject = new Elliptic (xs,ys,20,20);
  // }
  MyCircle c(5,10,20);
  MyCircle d(WINDOWX-5,10,20);
  window->end();
  window->show();
  return (Fl::run());
  //window->runGame();

    	  // the process waits from here on for events
}
