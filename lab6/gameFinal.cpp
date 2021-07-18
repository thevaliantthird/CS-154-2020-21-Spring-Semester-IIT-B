// CS 154 Lab 6
//Developing a Game using FLTK
// The First few lines (the Commented Section) contain my first and
// unsuccessful attempt at developing the game.




// #include <FL/Fl.H> // needed in every fltk program
// #include <FL/Fl_Window.H> // needed to use the Fl_Window class
// #include <FL/Fl_Box.H>
// #include <FL/fl_draw.H>
// #include <bits/stdc++.h>
// #define te 0.1
// #define G 10
// #define afac 0.1
// #define WINDOWX 600
// #define WINDOWY 800
//
//
//
// using namespace std;
//
// class GameExit: public Fl_Widget {
//   int x, y, w, h;
// public:
//
//   GameExit (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
//     this->x=x; this->y=y;
//     this->w=w; this->h=h;
//   }
//
//   virtual void draw() {
//     fl_color(fl_rgb_color(130));
//     fl_pie(x,y,w,h,0,360);
//     // set_visible();
//     // show();
//   }
// };
//
//
// class Object : public Fl_Widget  {
//
//     bool completed = false;
//
//   	protected:
// 	     int x, y, w, h;
//        double vx, vy;
// 	  public:
// 		    Object (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
// 			          this->x=x; this->y=y;
// 			          this->w=w; this->h=h;
//                 this->vx = 0;
//                 this->vy = 0;
// 		    }
//         virtual void wipe() = 0;
//         virtual void draw() = 0;
//         virtual void refresh()=0;
//
//         void runObject() {
//
//
//
//           x+=(vx*te);
//           y+=(vy*te);
//
//           if (x < w || (x > (WINDOWX - w)) ) {
//             vx = -vx;
//             if( y < 20 || y>(WINDOWY-20)){
//               completed = true;
//             }
//
//           }
//           if(y < h || (y > (WINDOWY-h))){
//             vy = -vy;
//           }
//
//
//         };
//
//
//
//         void accelerate(int xr, int yr ) {
//           double ax = (x-xr);
//           double ay = (y-yr);
//           double n = ((ax*ax)+(ay*ay));
//           ax/=n;
//           ay/=n;
//           vx+=(ax*te);
//           vy+=(ay*te);
//
//         };
//
//         void GravityEnact () {
//           vy+=(G*te);
//         };
//
//         bool ifEnd () {
//           return completed;
//         }
// };
//
//
// class Elliptic : public Object {
//
// public:
//
//   Elliptic (int x, int y, int w, int h)
//   : Object (x,y,w,h) {
//     fl_color(FL_WHITE);
//   }
//
//   virtual void draw() {
//
//     fl_color(fl_rgb_color(130));
//     fl_pie (x,y,w,h,0,360);
//
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
//     resize(x,y,w,h);
//     fl_color(FL_WHITE);
//     cout<<x<<' '<<y<<endl;
//   	fl_pie (x,y,w,h,0,360);
//   }
//
//
// };
//
// class Rectangle : public Object {
// public:
//
//   Rectangle (int x, int y, int w, int h)
//   : Object (x,y,w,h) {
//     fl_color(FL_WHITE);
//   }
//
//   virtual void refresh () {
//     resize(x,y,w,h);
//   	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
//   }
//
//   virtual void wipe() {
//
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
//
// class GameControl: public Fl_Window {
//
//   int score;
//   Object *myObject;
//
// public:
//
//   GameControl(int w, int h, const char *title=0) : Fl_Window (w, h,title) {
//
//       score = 0;
//       color(FL_WHITE);
//       fl_color(FL_WHITE);
//       InitializeObject();
//
//   };
//
//   void InitializeObject () {
//
//     int t = rand()%2;
//     int xs = rand() % WINDOWX;
//     int ys  = rand() % WINDOWY;
//
//     if(xs<=100) xs+=100;
//     if(xs>=WINDOWX-100)xs-=100;
//     if(ys<=100) ys+=100;
//     if(ys>=WINDOWY-100)ys-=100;
//
//     if(t==0) {
//       myObject = new Rectangle (xs,ys, 20, 20);
//     }else {
//       myObject = new Elliptic (xs,ys,20,20);
//     }
//
//   }
//
//   virtual int handle(int e) {
//     if (e==FL_PUSH) {
//
//       int x = Fl::event_x();
//       int y = Fl::event_y();
//
//       myObject->accelerate(x,y);
//     }
//     return 1;
//   };
//
//   void runGame() {
//
//     GameExit g1(5,10,5,20);
//     GameExit g2(WINDOWX-10,10,5,20);
//
//     end();
//     show();
//       Fl::wait(1000);
//     while(true){
//
//       myObject->GravityEnact();
//
//       myObject->runObject();
//
//
//       if(myObject->ifEnd()) {
//         score+=10;
//         myObject->clear_visible();
//         delete myObject;
//         InitializeObject();
//       }
//
//       myObject->redraw();
//       cout<<score<<endl;
//       Fl::check();
//
//     }
//
//     Fl::run();
//   }
//
//
// };
//
//
//
//
//
// int main(int argc, char *argv[]) {
//
//   GameControl *window;
//   window = new GameControl (WINDOWX,WINDOWY,"DEMO");
//
//   window->runGame();
//
//
// }


// The Real Code of the Game "Collect!" begins!

#include <FL/Fl_Button.H>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include <bits/stdc++.h>

#define WINDOWX 600
#define WINDOWY 800

using namespace std;


//The Parent Class of all, The Abstract class which all other classes implement
class Object : public Fl_Widget  {

    protected:

        int x, y, w, h;

    public:
        Object (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){

                this->x=x; this->y=y;
                this->w=w; this->h=h;
        }

        //The Abstract and dynamically bound Virtual Functions
        virtual void wipe()=0;
        virtual void refresh(int dx, int dy)=0;
};


class Elliptic : public Object {
  int type;
 public:
   Elliptic (int x,int y,int w, int type) : Object (x,y,w, w) {
          this->type = type;
    }

    virtual void draw() {


        if(type==0) fl_color(FL_RED);
        else fl_color(fl_rgb_color(130));

        //Drawing the Structure according to Color
        fl_pie (x,y,w,h,0,360);
   }

   virtual void wipe() {          //By Default Wipe function for all its descendents (never used!)

        fl_color(FL_GREEN);
        fl_pie (x,y,w,h,0,360);

   }

   virtual void refresh (int dx, int dy) {
        x=x+dx;             //Changing Co-ordinates
        y=y+dy;

        resize(x,y,w,h);    //Resizing the Widget to Fit

        //Differentiating between Bombs and normal!
        if(type==0) fl_color(FL_RED);
        else fl_color(fl_rgb_color(130));

        fl_pie (x,y,w,h,0,360);       //Creating the Collector
   }

};


class Collectible {

  int type;                    // 0 for bomb, 1 for Normal
  int x,y;                     //Co-ordinates
  Elliptic *rep;               // The Circle Represeting this collectble
  bool ifCollected = false;    // Whether or not its collected

public:

  Collectible (int x, int y, int type) {

    this->x = x;
    this->y = y;
    this->type = type;
    this->rep = new Elliptic(x,y,12,type);

  }

  int CheckInRadar(int _x, int _y) {
    //Distance
    if( (x-_x)*(x-_x) + (y-_y)*(y-_y) <= 30) {

      return (2*type)-1;
      ifCollected = true;

    } else {
      return 0;
    }

  }
};


// The Main Class which runs it all
class CollectorAndCollections : public Object {

  Collectible* array[100];              // The array over which to iterate to get to the Bombs/Coins!
  time_t TimeToEnd;                     // To get the Time at which we're supposed to end
  int score;                            //Score of the Player

 public:
   CollectorAndCollections (int x,int y,int w, int PlayTime) : Object (x,y,w, w) {

     score = 0;

     int it;
     for (it = 0 ;it < 10; it ++) {
       int col = rand() % (WINDOWX-10*(it+1)) + 50;
       for (int x = 0 ; x < 10 ; x++ ) {

         array[it*10 + x] = new Collectible(col , rand() % (WINDOWY-100) + 50 , rand() % 2);

       }
     }

     TimeToEnd = time(0)+PlayTime;

   }

    virtual void draw() {

        fl_color(FL_BLACK);
        fl_pie (x,y,w,h,0,270);


   }
   virtual void wipe() {

        fl_color(FL_GREEN);
        fl_pie (x,y,w,h,0,270);

   }

   virtual void refresh ( int dx, int dy ) {

        x=x+dx;y=y+dy;

        resize(x,y,w,h);

        fl_color(FL_BLACK);
        fl_pie (x,y,w,h,0,270);

   }

   int SONAR() {

      int j,sum = 0;

      for ( j = 0 ; j < 100 ; j++ ) {
        sum += array[j] -> CheckInRadar (x,y);
      }

      return sum;

    }

    // This Function lies at the soul, as it is the one being called repeatedly whenever a key is pressed!
    virtual int handle(int e) {

          if ( e == FL_KEYBOARD ) {

            if ( time(0) < TimeToEnd ) {

              if ( Fl :: event_key() == FL_Up ) {

                      wipe();
                      refresh(0,-10);
              }
              else if ( Fl :: event_key() == FL_Enter ) {

                score+=SONAR();

              }

              else if ( Fl::event_key() == FL_Down ) {

                wipe();

                refresh(0,10);
              }
              else if ( Fl::event_key() == FL_Right ) {

                wipe();
                refresh(10,0);

              }
              else if ( Fl::event_key() == FL_Left ) {

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

        //The Main Console is thus Initialized!
        new CollectorAndCollections(WINDOWX/2, WINDOWY/2 ,20, PlayForTime);

        window->color(FL_GREEN);

        window->end();
        window->show();


        return(Fl::run());
}
