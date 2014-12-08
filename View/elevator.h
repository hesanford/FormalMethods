// generated by Fast Light User Interface Designer (fluid) version 1.0303

#ifndef elevator_changes_h
#define elevator_changes_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Floor {
private:
    int numPassengers;
    vector<bool> buttons;
    
public:
    Floor(int passengers, vector<bool> btns);
    int getNumPass();
    vector<bool> getButtons();
    void setNumPass(int passengers);
    void setButtons(vector<bool> btns);
    
};

class Lift {
    int currentFloor;
    int numPassengers;
    int direction;
    vector<bool> buttons;
    
public:
    Lift(int floor, int passengers, int dir, vector<bool> btns);
    int getCurFLoor();
    int getNumPass();
    int getDir();
    vector<bool> getButtons();
    void setCurFloor(int floor);
    void setNumPass(int passengers);
    void setDir(int dir);
    void setButtons(vector<bool> btns);
    
};

class View {
private:
    int NUMFLOORS;
    int NUMLIFTS;
    vector<Lift> lifts;
    vector<Floor> floors;
    
public:
    vector<Fl_Value_Slider*> sliders;
    vector<Fl_Value_Output*> passengersPerFloor;
    vector<Fl_Round_Button*> upButtons;
    vector<Fl_Round_Button*> downButtons;
    vector<Fl_Round_Button*> floorButtons;
    vector<Fl_Value_Output*> passengersPerLift;
    
public:
    View(int numfloors, int numlifts, vector<int> liftpass, vector<int> liftstartfloor, vector<int> liftstartdir, vector<int> floorpass, vector<vector<bool> > liftbut, vector<vector<bool> > floorbut);
    int main();
    
private:
    Fl_Window* make_window();
    static void loadFile(Fl_Widget* obj, void*);
    static void startSim(Fl_Widget* obj, void*);
    static void stopSim(Fl_Widget* obj, void*);
    static void stepFor(Fl_Widget* obj, void*);
    static void stepBack(Fl_Widget* obj, void*);
    
    
};

#endif
