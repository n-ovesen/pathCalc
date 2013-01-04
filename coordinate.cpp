/*** 
 * File:   coordinate.cpp
 * Author: Nikolai
 * 
 * Created on 1. januar 2013, 17:07
 */

#include "coordinate.h"

using namespace std;

/**
 *      @Function: init()
 *      calls function within fileRead class to read and parse the csv file
 *      containing coordinates, allocates space of size s to the vectors tempLat
 *      and tempLon that temporarily store the data returned from the getVector
 *      function within the fileRead class and then copies the data to the vectors
 *      lat and lon within the vector wpt containing the struct waypoint,
 *      then it returns 'true' so that one can later check that init has been called
 *      as nothing will work properly unless it has been called.
 */

bool coordinate::init(){
    
    fRead.readFile("data.csv");
    
    int s = fRead.getVectLen();
    
    tempLat.reserve(s);
    tempLon.reserve(s);

    fRead.getVector(tempLat, tempLon);
    
    for (unsigned int i = 0; i < s; i++){
        wpt.push_back({tempLat.at(i), tempLon.at(i)});
    }
    
    tempLat.clear();
    tempLon.clear();
    
    //TODO: sort out full c++0x support and implement .shrink_to_fit()
        
    initialised = true;
    return initialised;
}

void coordinate::add(float flat, float flon){    

    tempLat.push_back(flat);
    tempLon.push_back(flon);
}

float coordinate::get(/*int i*/) {
        
    return 1;
}

void coordinate::printVectors() {
    
    for(unsigned int i = 0; i < wpt.size(); i++){
        cout << "lat: " << wpt.at(i).lat << " lon: " << wpt.at(i).lon << endl;            
    }
}
