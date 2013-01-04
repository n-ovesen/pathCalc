/* 
 * File:   fileRead.cpp
 * Author: Nikolai
 * 
 * Created on 1. januar 2013, 19:28
 */

#include "fileRead.h"

using namespace std;

/*
 *      Function: getVector(vector<float>& v1, vector<float>& v2)
 *      copies the lat and lon vectors within the class to temporary vectors
 *      v1 and v2 and returns these by passing them as a reference
 * 
 *      TODO: delete lat & lon to save memory usage   
 */

void fileRead::getVector(vector<float>& v1, vector<float>& v2) {
    v1 = lat;
    v2 = lon;
    return;
}

/*
 *      Function: parseLine(string s, float& lat, float& lon)
 *      receives string s from readFile function, parses it into variables
 *      float lat and float lon and returns them to readFile()
 *      by passing them as a reference
 * 
 *      TODO: nothing afaik 
 */

void fileRead::parseLine(string s, float& lat, float& lon){
    string slat, slon;
    istringstream liness( s );
    getline( liness, slat, ',' );
    getline( liness, slon,  '\n' );

    lat = strtof(slat.c_str(), 0);
    lon = strtof(slon.c_str(), 0);

    return;
}

/*
 *      Function: readFile(string f)
 *      opens file 'f' that is passed to function by function call
 *      does some simple checking of file integrity and reads each line into
 *      a temporary string variable that is passed to parseLine() and returned
 *      by passing references to variables flat and flon that is pushed into
 *      vectors lat and lon for temporary storage.
 * 
 *      TODO: consider if it is worth it to store varables in vector of struct
 *      containing float lat, lon.
 */    
    
void fileRead::readFile(string f){
    
    float flat, flon;    
    csvFile.open(f);
    
    if(!csvFile) {
        cout << "file does not exist" << endl;
        exit (EXIT_FAILURE);
    }
    
    while(!csvFile.eof()){
        getline(csvFile,buf);
        fileRead::parseLine(buf,flat, flon);
        lat.push_back(flat);
        lon.push_back(flon);
        
    }    
    csvFile.close();
}

/*
 *      Function: print()
 *      testing function to print out lat and lon vectors by iteration
 * 
 *      TODO: get rid of this
 */
    
void fileRead::print(){
        
    cout << "printing lat" << endl;
    cout << "buffer capacity = " << lat.size() << endl;
        
    for (unsigned int i = 0; i < lat.size(); i++){
        cout << "       buffer[" << i << "] " << lat.at(i) << endl;
    }   
    
    cout << endl;
    
    /*cout << "printing lon" << endl;
    cout << "buffer capacity = " << lon.size() << endl;
        
    for (unsigned int i = 0; i < lon.size(); i++){
        cout << "       buffer[" << i << "] " << lon.at(i) << endl;
    }      
    
    cout << endl;*/
}

/*
 *      Function: getVectLen()
 *      Returns the size of the vectors lat and lon by simply calling the
 *      stl vector function .size, doing a check if both vectors are the same
 *      size and then returns the size of the vectors, if the vector sizes are
 *      unequal the function will return 0
 */

int fileRead::getVectLen(){
    
    int s1 = lat.size();
    int s2 = lon.size();
    
    if (s1 != s2){
        return 0;
    }
    
    else {
        return (s1 + s2) / 2;
    }
}
