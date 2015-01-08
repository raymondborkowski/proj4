//
//  clientA.h
//  project4
//
//  Created by Raymond Borkowski on 12/4/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#ifndef __project4__clientA__
#define __project4__clientA__

#include "temp.h"
#include <stdio.h>
#include "main.h"
#include <deque>
#include <cmath>
#include <iostream>
#include <limits>
#include <cfloat>

struct terminal {
    double x = 0, y = 0, tec = 0, location = 0;
    terminal(int term, int i, int j){
        location = term;
        x = i;
        y = j;
        tec = term;
    }
};
struct calculateDistance{
    terminal *loc1 = nullptr, *loc2 = nullptr;
    double length = 0.0;
    calculateDistance(terminal *i, terminal *j){
        loc1 = i;
        loc2 = j;
        length = 0;
        double x = ((loc1->x - loc2->x));
        double y = ((loc1->y - loc2->y));
        length = pow((x*x)+(y*y), .5);
    }
    calculateDistance() { }
};
struct compare{
    bool operator()(calculateDistance*, calculateDistance*) const;
};
struct facilitiess{
    priority_queue<calculateDistance*,
    vector<calculateDistance*>, compare> roads;
    queue<calculateDistance*> printRoads;
};

struct clientA{
    facilitiess facilities;
    deque<terminal> base;
    double distance = 0;
    void fileRead();
    void fileRead2();
    void search();
};

struct terminalB {
    double max = INFINITY;
    double x = 0, y = 0, small = max, location = 0;
    bool touched = false;
    terminalB(int termB, int i, int j){
        location = termB;
        x = i;
        y = j;
    }
    terminalB *hold = nullptr;
    void create(int,int,int);
    
};

struct compareB{
    terminalB * one = nullptr;
    terminalB * two = nullptr;
    bool operator()(terminalB*, terminalB*) const;
};

struct calculateDistanceB {
    terminalB *loc1 = nullptr, *loc2 = nullptr;
    double length = 0.0;
    calculateDistanceB(terminalB *i, terminalB *j){
        loc1 = i;
        loc2 = j;
        length = 0;
        double x = ((loc1->x - loc2->x));
        double y = ((loc1->y - loc2->y));
        length = pow((x*x)+(y*y), .5);
    }
};

struct clientB{
    deque<terminalB> baseB;
    priority_queue<terminalB*,
        vector<terminalB*>, compareB> paths;
    double distance = 0, numbers = 0;
    void fileRead();
    void search();
    bool trueOrFalse(terminalB&);
    bool trueOrFalse1(terminalB&);
    void copy();
    priority_queue<terminalB*,
    deque<terminalB*>, compareB> pathsB;
    deque<terminalB*> baseBTouched;
    void clientC();
    void copyC(int);
    int gett(int);
};



struct terminalC{
    double x = 0, y = 0, location = 0;
    bool touched = false;
    terminalC(double termC, double i, double j){
        location = termC;
        x = i;
        y = j;
    }
};

struct calculateDistanceC {
    terminalC *loc1 = nullptr, *loc2 = nullptr;
    double length = 0.0;
    calculateDistanceC(terminalC *i, terminalC *j){
        loc1 = i;
        loc2 = j;
        length = 0;
        double x = ((loc1->x - loc2->x));
        double y = ((loc1->y - loc2->y));
        length = pow((x*x)+(y*y), .5);
    }
};
struct clientC{
    deque<int> route;
    deque<int> pap;
    double length = 0, locations = 0, trip=0, y=0, z=0;
    void fileRead();
    void change();
    deque<int> keep;
    void findPath();
    double xxx = 0;
    deque<terminalC> store;
    bool hold(int);
    vector<vector<double>> lengths;
    void get();
    void hol(int);
    void zero();
    void popChange();
    void last();
    void addStuff();
    double front;
    double back;
    void locs(size_t);
    void trick();
    
};






#endif /* defined(__project4__clientA__) */
