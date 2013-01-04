/*** 
 * File:   coordinate.cpp
 * Author: Nikolai
 * 
 * Created on 1. januar 2013, 17:07
 */

#include "coordinate.h"

using namespace std;

/**
 *      @Function: init(int)
 *      calls functions to read csvFile,
 *      parse it and return the vectors to
 *      this class
 */

bool coordinate::init(int m){
    
    lat.reserve(m);
    lon.reserve(m);
    
    fRead.print();
    
    initialised = true;
    return initialised;
}

bool coordinate::init(){
    
    coordinate::init(0);
}

void coordinate::add(float flat, float flon){
    if (initialised != true) {
        cout << "initializing with standard value of '10'" << endl;
        coordinate::init(10);
    }

    lat.push_back(flat);
    lon.push_back(flon);
}

float coordinate::get(/*int i*/) {
        
    return 1;
}

void coordinate::printVectors() {
    
    cout << "printing vector::lon()" << endl;    
    for (unsigned int i = 0; i < lon.capacity(); i++ ){
        cout << "       lon[" << i << "] " << lon[i] << endl;
    }
    cout << endl;
    
    cout << "printing vector::lat()" << endl;
    
    for (unsigned int i = 0; i < lat.capacity(); i++ ){
        cout << "       lat[" << i << "] " << lat[i] << endl;
    }
    cout << endl;
}
