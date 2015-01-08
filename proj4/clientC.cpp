//
//  clientC.cpp
//  project4
//
//  Created by Raymond Borkowski on 12/8/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//

#include "clientA.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void clientC::fileRead(){
    string readLine;
    std::cin>>readLine;
    std::cin>>readLine;
    locations = stoi(readLine);
    double i = 1,o,p;
   
    
    while(i <= locations){
        std::cin>>o;
        std::cin>>p;
        store.push_back(terminalC(i-1, o, p));
        i++;
        keep.push_back(i-2);
    }
}
bool clientC::hold(int x){
    if(store[x].touched == true)
        return true;
    return false;
}
 void clientC::findPath() {
     lengths = vector<vector<double>>(locations, vector<double>(locations, 0));
     int i = 0, er = 0, eer = 0, touchDown = 1;
     while(i < locations){
         int j = i;
         while(j<locations){
             double dist = calculateDistanceC(&store[i], &store[j]).length;
             lengths[i][j]=dist;
             lengths[j][i]=dist;
             j++;
         }
         i++;
     }
     pap.push_back(0);
     store[0].touched = true;
     for(int z = touchDown; z < locations; z++){
         int p = 0;
         double bigDist = INFINITY;
         while(p<locations){
             if(p!=er){
                 if(!hold(p)){
                     if(lengths[er][p] < bigDist){
                         bigDist = lengths[er][p];
                         eer=p;
                     }
                 }
             }
             p++;
         }
         er = eer;
         
         pap.push_back(er);
         store[er].touched = true;
         xxx = xxx + bigDist;
     }
     xxx = xxx + lengths[0][er];
     keep.pop_front();
     route.push_back(0);
     change();
     ostringstream os;
     os << setprecision(2); //Always show 2 decimal places
     os << fixed; //Disable scientific notation for large numbers
     os<<xxx<<'\n';
     size_t j = pap.size();
     while (j > 0) {
         os<<pap[j]<<" ";
         j--;
     }
     cout<<os.str()<<'\n';

}

terminalB pppp(int i,int j, int k){
    return terminalB(i,j,k);
}
int clientB::gett(int i){
    return i;
}
void clientC::get(){
    clientB cb;
    size_t sip = keep.size();
    y = 0;
    double i = 0;
    if(keep.size() <= 0) {
        return;
    }
    while(i<sip){
        int p = keep[i];
        int q = store[p].x;
        int r = store[p].y;
        cb.baseB.push_back(pppp(p,q,r));
        i++;
    }
    cb.numbers = locations;
    cb.clientC();
    hol(cb.distance);

}
void clientC::hol(int x){
    y = x;
}
void clientC::zero(){
    trip = 0;
}
void clientC::locs(size_t i){
     front = lengths[route.front()][keep[i]];
     back = lengths[route.back()][keep[i]];
}
void clientC::trick(){
    size_t i = 1;
    size_t rout = route.size();
    while(i< rout){
        trip = trip + lengths[route[i-1]][route[i]];
        i++;
    }
    
}
void clientC::change() {
    bool trim = false;
    size_t rout = route.size();
    size_t i=0;
    size_t kee = keep.size();
    double gogo = 0;
    zero();
    if(rout > 1) {
        trick();
    }
    int qq = lengths[i][pap.back()];
    int pp = trip;
    gogo += trip;
    if(pp+qq < xxx)
        trim = true;
    //////////////////////////////////////////////////////////
    get();
    //////////////////////////////////////////////////////////
    z = 0;
    double from = INFINITY;
    double buck = INFINITY;
    if(rout > 0  && kee > 0) {
        while(i<kee){
            locs(i);
            if(front < from)
                from=front;
            if(back<buck)
                buck=back;
            i++;
        }
        z=buck+from;
        gogo+=z;
    }
    gogo += y;
    ///////////////////////////////////////////////////////////
    if(gogo >= xxx)
        trim = true;
    else
        trim = false;
    
    if(trim){
        return;
    }
    if(keep.empty()) {
        double x = trip;
        if(((lengths[0][route.back()]+trip)) < xxx) {
            x = lengths[0][route.back()] + x;
            trip = x;
            xxx = trip;
            pap = route;
        }
        x = lengths[0][route.back()] + x;
        trip = x;
    }
    last();
}
void clientC::last(){
    for(unsigned int i = 0; i < keep.size(); ++i) {
        addStuff();;
    }
}
void clientC::popChange(){
    route.push_back(keep[0]);
    keep.pop_front();
    change();
}
void clientC::addStuff(){
    popChange();
    keep.push_back(route[route.size()-1]);
    route.pop_back();
}