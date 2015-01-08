//
//  main.cpp
//  proj4
//
//  Created by Raymond Borkowski on 12/4/14.
//  Copyright (c) 2014 Raymond Borkowski. All rights reserved.
//
#include <iostream>
#include "getopt.h"
#include <string>
#include "clientA.h"
#include "temp.h"
#include <fstream>
#include <cstring>
#include "main.h"
#include <iomanip>

using namespace std;

char getopt(int argc, char ** argv){
    char returnVal = '\0';
    
    struct option longOpts[] = {{
        "clientType", required_argument, NULL, 'c'
    },{
        "help", no_argument, NULL, 'h'
    }};
    int opt = 0, index = 0;
    while((opt = getopt_long (argc, argv, "hc:", longOpts, &index)) != -1){
        switch(opt) {
            case 'c':{
                if(!strcmp("C", optarg))
                    returnVal = 'c';
                else if(!strcmp("B", optarg))
                    returnVal = 'b';
                else if(!strcmp("A", optarg))
                    returnVal = 'a';
                else{
                    cerr<<"NOT A CLIENT!!!\n"; 
                    exit(1);
                }
            }
                break;
            case 'h':
                cout << "This is drone Routing Stuff\n"
                <<"--clientType or -c with A|B|C\n";
                exit(0);
            default:
                cerr<<"INVALID INPUT\n";
                exit(1);
        }
    }
    return returnVal;
}




int main(int argc, char ** argv) {
    ios_base::sync_with_stdio(false);
    ifstream in("test-2-C.txt");
    cin.rdbuf(in.rdbuf());
    
    char clientLeter = getopt(argc, argv);
    if(clientLeter == 'a'){
        clientA client1;
        client1.fileRead();
        client1.fileRead2();
        client1.search();
    }
    else if (clientLeter == 'b'){
        clientB client2;
        client2.fileRead();
        client2.search();
    }
    else{
        clientC client3;
        client3.fileRead();
        client3.findPath();
    }
    
}
