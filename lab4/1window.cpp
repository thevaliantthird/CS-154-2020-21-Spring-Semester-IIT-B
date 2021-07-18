#include <iostream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Button.H> //needed to use Fl_Button

int main(int argc, char *argv[]) {
    	Fl_Window *window;

      window = new Fl_Window (900,500,"Demo1"); // outer window

      Fl_Button *button1 = new Fl_Button(0,0,100,100,"Button1");

      Fl_Button *button2 = new Fl_Button(300,300,100,100, "Button2");
      window->end();

    	window->show();

    	return(Fl::run());  // the process waits from here on for events

}
