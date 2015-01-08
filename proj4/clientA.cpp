//
//  clientA.cpp
//  project4
//
//  Created by Raymond Borkowski on 12/4/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "clientA.h"
#include "main.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;
void clientA::fileRead() {
    string readLine;
    cin>>readLine;
    cin>>readLine;
    double locationNumbers = stoi(readLine);
    double i = 1, x , y;
    
    while(i <= locationNumbers){
        cin>>x;
        cin>>y;
        base.push_back(terminal(i-1, x, y));
        i++;
    }
}
void clientA::fileRead2(){
    string readLine;
    cin>>readLine;
    cin>>readLine;
    int whatPat = stoi(readLine);
    int i = 1, x, y;
    while(i <= whatPat){
        cin>>x;
        cin>>y;
        terminal *xx = &base[x];
        terminal *yy = &base[y];
        calculateDistance *p = new calculateDistance(xx, yy);
        facilities.roads.push(p);
        i++;
    }
}
bool compare::operator()(calculateDistance* i, calculateDistance* j) const {
    double x = i->length;
    double y = j->length;
    return x > y;
}

void clientA::search(){
here:
    calculateDistance *path = nullptr;
    if(facilities.roads.size() != 0){
        
        path = facilities.roads.top();
        terminal *f1 = path->loc1;
        terminal *f2 = path->loc2;
    temp:
        if(f1->location != f1->tec){
            f1 = &base[f1->tec];
            goto temp;
        }
    temp1:
        if(f2->location != f2->tec){
            f2 = &base[f2->tec];
            goto temp1;
        }
        if(f1->location != f2->location){
            int temp;
            terminal *alpha;
            
            if(f1->location < f2->location){
                alpha = path->loc2;
                while(alpha->tec != f1->location) {
                    temp = alpha->tec;
                    alpha->tec = f1->location;
                    alpha = &base[temp];
                }
            }
            else {
                alpha = f1;
                while(alpha->tec != f2->location) {
                    temp = alpha->tec;
                    alpha->tec = f2->location;
                    alpha = &base[temp];
                }
            }
            distance += path->length;
            facilities.printRoads.push(path);
        }
        
        facilities.roads.pop();
        
        goto here;
    }
    ostringstream os;
    cout << setprecision(2); //Always show 2 decimal places
    cout << fixed; //Disable scientific notation for large numbers
    
    cout<<distance<<'\n';
print:
    if( facilities.printRoads.size() != 0){
        path = facilities.printRoads.front();
        os<<path->loc1->location<<" ";
        os<<path->loc2->location<<'\n';
        facilities.printRoads.pop();
        goto print;
    }
    delete path;
    cout<<os.str();
}
