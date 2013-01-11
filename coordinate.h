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
#include <math.h>

#include "fileRead.h"

using namespace std;

class coordinate {
    
public:
    
    bool init();
    void add(double, double);
    void getPos(int, double&, double&);
    void printVectors();
    double distanceInMeters(double, double, double, double);
    int nearestWaypt(int current);
            
private:
    
    //used for great circle calculations, do not change!
    static constexpr double DEG_TO_RAD = 0.017453292519943295769236907684886;
    static constexpr double EARTH_RADIUS_IN_METERS = 6372797.560856;
    
    struct waypoint{
        double lat, lon;
        int next, prev;
        bool visited;
        string name;
    };
    
    vector<waypoint> wpt;    
    vector<double> tempLat;
    vector<double> tempLon;    
    fileRead fRead;    
    bool initialised;
    
    double arcInRadians(double, double, double, double);
    
    

};

#endif	/* COORDINATE_H */

