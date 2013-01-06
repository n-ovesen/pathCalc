/**
 * @File:   fileRead.cpp
 * @Author: Nikolai
 * 
 * Created on 1. januar 2013, 19:28
 */

#include "fileRead.h"

using namespace std;

/**
 * @function: public getVector()
 * copies the lat and lon vectors within the class to temporary vectors
 * v1 and v2, clears lat and lon vectors and returns v1 and v2
 * by passing them as a reference.  
 * 
 * @param v1    -       temporary vector used for passing vectors as a reference
 * @param v2    -       temporary vector used for passing vectors as a reference
 * @return      -       returns temporary vectors v1 and v2 as references
 */

void fileRead::getVector(vector<double>& v1, vector<double>& v2) {
    
    v1 = lat;
    v2 = lon;
    
    lat.clear();
    lon.clear();
    
    //TODO: sort out full c++0x support and implement .shrink_to_fit()
    
    return;
}

/**
 * @function: public getVectLen()
 * Returns the size of the vectors lat and lon by simply calling the
 * stl vector function .size, doing a check if both vectors are the same
 * size and then returns the size of the vectors, if the vector sizes are
 * unequal the function will return 0
 * @return 
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

/**
 * @function: private parseLine()
 * receives string s from readFile function, parses it into variables
 * double lat and double lon and returns them to readFile()
 * by passing them as a reference
 * 
 * @param s     -       string to be parsed
 * @param lat   -       used to return parsed lat as a reference
 * @param lon   -       used to return parsed lon as a reference
 */

void fileRead::parseLine(string s, double& lat, double& lon){
    
    string slat, slon;
    istringstream liness( s );
    getline( liness, slat, ',' );
    getline( liness, slon,  '\n' );

    lat = strtof(slat.c_str(), 0);
    lon = strtof(slon.c_str(), 0);

    return;
}
   
/**
 * @function: public readFile()
 * opens file 'f' that is passed to function by function call
 * does some simple checking of file integrity and reads each line into
 * a temporary string variable that is passed to parseLine() and returned
 * by passing references to variables flat and flon that is pushed into
 * vectors lat and lon for temporary storage.
 * 
 * @param f     -       name of file to be opened
 */

void fileRead::readFile(string f){
    
    double flat, flon;    
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

/**
 * @function: public print()
 * testing function to print out lat and lon vectors by iteration
 * 
 * @todo: get rid of it
 */
    
void fileRead::print(){
        
    cout << "printing lat" << endl;
    cout << "buffer capacity = " << lat.size() << endl;
        
    for (unsigned int i = 0; i < lat.size(); i++){
        cout << "       buffer[" << i << "] " << lat.at(i) << endl;
    }   
    
    cout << endl;
    
}


