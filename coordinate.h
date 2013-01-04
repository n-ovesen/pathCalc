/* 
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
    
    bool init(int);
    bool init();
    void add(float, float);
    float get();
    void printVectors();
            
private:
    vector<float> lat;
    vector<float> lon;
    
    fileRead fRead;
    
    bool initialised;
};

#endif	/* COORDINATE_H */

