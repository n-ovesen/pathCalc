/*** 
 * File:   coordinate.cpp
 * Author: Nikolai
 * 
 * Created on 1. januar 2013, 17:07
 */

#include "coordinate.h"

using namespace std;

/**
 * @function init()
 * 
 * initializes various required functionality for the class and also calls
 * read file function within fileRead class and returns the vectors containing
 * the data from the csv file.
 * 
 * then it places the data from the csv file into a vector of waypoint structs
 * accordingly
 * 
 * @return      -       returns true to allow checking that the initialization
 *                      was successful.
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

/**
 * @function: private arcInRadians()
 * 
 * Uses the law of haversine to calculate the great circle distance between
 * coordinates
 * 
 * @param latFrom       -       latitude of coordinate from
 * @param lonFrom       -       longitude of coordinate from
 * @param latTo         -       latitude of coordinate to
 * @param lonTo         -       longitude of coordinate to
 * @return              -       the arc in radians
 */

double coordinate::arcInRadians(double latFrom, double lonFrom, double latTo, double lonTo) {
    double latitudeArc  = (latFrom - latTo) * DEG_TO_RAD;
    double longitudeArc = (lonFrom - lonTo) * DEG_TO_RAD;
    double latitudeH = sin(latitudeArc * 0.5);
    latitudeH *= latitudeH;
    double lontitudeH = sin(longitudeArc * 0.5);
    lontitudeH *= lontitudeH;
    double tmp = cos(latFrom*DEG_TO_RAD) * cos(latTo*DEG_TO_RAD);
    return 2.0 * asin(sqrt(latitudeH + tmp*lontitudeH));
}

/**
 * @function: public distanceInMeters()
 * 
 * takes in parameters mentioned below, multiplies the earth radius in meters
 * with the returned value from @function arcInRadians() and returns it as a
 * distance in meters
 * 
 * @param latFrom       -       latitude of coordinate from
 * @param lonFrom       -       longitude of coordinate from
 * @param latTo         -       latitude of coordinate to
 * @param lonTo         -       longitude of coordinate to
 * @return              -       returns the distance between the coordiantes in meters
 */

double coordinate::distanceInMeters(double latFrom, double lonFrom, double latTo, double lonTo) {
    return EARTH_RADIUS_IN_METERS*arcInRadians(latFrom, lonFrom, latTo, lonTo);
}

/**
 * @function: public nearestWaypt()
 * 
 * takes in current waypoint, calculates distance to all other waypoints in 
 * vector of waypoints and returns the id of the nearest waypoint
 *  
 * @param wptCur        -       current waypoint
 * @return              -       returns the ID of the nearest waypoint
 * 
 * @todo:       figure out if it is needed to store the distance to nearest waypoint.
 */

int coordinate::nearestWaypt(int wptCur) {

    double latCur, lonCur, curShortest, d;
    curShortest = 40000000; //40000000 is roughly the circumference of the earth
    int id = 0;
    coordinate::getPos(wptCur, latCur, lonCur);
    
    for(int i = 0; i < wpt.size(); i++) {
        d = coordinate::distanceInMeters(latCur, lonCur, wpt.at(i).lat, wpt.at(i).lon);
        
        cout << "dist to: [" << i << "] is: " << d << endl;
        
        if (i != wptCur) {            
            if (d < curShortest) {
                curShortest = d;
                id = i;
            }
        } 
    }
    
    return id;
}

void coordinate::add(double flat, double flon){    

    tempLat.push_back(flat);
    tempLon.push_back(flon);
}

void coordinate::getPos(int i, double& lat, double& lon) {
    lat = wpt.at(i).lat;
    lon = wpt.at(i).lon;
    return;
}

void coordinate::printVectors() {
    
    for(unsigned int i = 0; i < wpt.size(); i++){
        cout << "lat: " << wpt.at(i).lat << " lon: " << wpt.at(i).lon << endl;            
    }
}
