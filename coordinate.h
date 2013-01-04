/**
 * File:   coordinate.h
 * Author: Nikolai
 *
 * Created on 4. januar 2013, 02:52
 */

#ifndef COORDINATE_H
#define	COORDINATE_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fileRead.h"

using namespace std;

class coordinate {
    
public:
    
    bool init();
    void add(float, float);
    float get();
    void printVectors();
            
private:
    
    struct waypoint{
        float lat, lon;
        int next, prev;
        bool visited;
    };
    
    vector<waypoint> wpt;
    
    vector<float> tempLat;
    vector<float> tempLon;    
    fileRead fRead;    
    bool initialised;
    

};

#endif	/* COORDINATE_H */

