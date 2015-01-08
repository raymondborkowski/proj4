//
//  clientB.cpp
//  project4
//
//  Created by Raymond Borkowski on 12/6/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "clientA.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

bool compareB::operator() (terminalB *i, terminalB *j) const {
    double xx = i->location, yy = j->location;
    if(xx == j->small){
        if(i->location > yy)
            return true;
        return false;
    }
    else if(xx != yy){
        if(i->small > j->small){
            return true;
        }
        return false;
    }
    return false;
}

void clientB::fileRead(){
    string readLine;
    std::cin>>readLine;
    std::cin>>readLine;
    numbers = stoi(readLine);
    double i = 1,o,p;
    
    while(i <= numbers){
        std::cin>>o;
        std::cin>>p;
        baseB.push_back(terminalB(i-1, o, p));
        
        i++;
        
    }
    copy();
}

void terminalB::create(int x, int y, int z){
    location = x;
    x = y;
    y = z;
}

void clientB::copy(){
    for(int i = 0; i < numbers; i++){
        baseBTouched.push_back(&baseB[i]);
    }
}
void clientB::copyC(int i){
    baseBTouched.push_back(&baseB[i]);
}
void clientB::clientC(){
    for(unsigned int i = 0; i < baseB.size(); i++){
        baseBTouched.push_back(&baseB[i]);
    }
    baseB[0].small = 0;
    size_t opp= baseBTouched.size();
    for(unsigned int i = 0; i < opp; i++){
        unsigned int second = 0, third = 0;
        for(unsigned int j = 0; j < baseBTouched.size(); j++) {
        temp1:
            if(third < baseBTouched.size()){
                if(baseBTouched[third]->small < baseBTouched[second]->small){
                    second = third;
                }
                third++;
                goto temp1;
            }
            if(j!=second){
                if(calculateDistanceB(baseBTouched[second],baseBTouched[j]).length
                                                            < baseBTouched[j]->small){
                    baseBTouched[j]->small=calculateDistanceB(baseBTouched[second],
                                                              baseBTouched[j]).length;
                    baseBTouched[j]->hold=baseBTouched[second];
                }
            }
            
        }
        distance += baseBTouched[second]->small;
        baseBTouched.erase(baseBTouched.begin()+second);
    }
}


void clientB::search(){
    for(int i = 0; i < numbers; i++){
        unsigned int second = 0, third = 0;
        for(unsigned int j = 0; j < baseBTouched.size(); j++) {
        temp1:
            if(third < baseBTouched.size()){
                if(baseBTouched[third]->small < baseBTouched[second]->small){
                    second = third;
                }
                third++;
                goto temp1;
            }
            if(j!=second){
                if(calculateDistanceB(baseBTouched[second],baseBTouched[j]).length
                                                            < baseBTouched[j]->small){
                    baseBTouched[j]->small=calculateDistanceB(baseBTouched[second],
                                                              baseBTouched[j]).length;
                    baseBTouched[j]->hold=baseBTouched[second];
                }
            }

        }
        baseBTouched.erase(baseBTouched.begin()+second);
    }
    ostringstream os;
    cout << setprecision(2); //Always show 2 decimal places
    cout << fixed; //Disable scientific notation for large numbers
    int i = numbers-1;
print:
    
    if(i > 0){
        terminalB *jp = &baseB[i];
        if(jp->hold != nullptr){
            distance += jp->small;
            if(jp->location < jp->hold->location){
                os<<jp->location;
                os<<" "<<jp->hold->location<<'\n';
            }
            else{
                os<<jp->hold->location;
                os<<" "<<jp->location<<'\n';
            }
        }
        i--;
        goto print;
    }
    cout<<distance<<'\n';
    cout<<os.str();
}
