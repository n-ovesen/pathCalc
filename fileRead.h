/**
 * File:   fileRead.h
 * Author: Nikolai
 *
 * Created on 1. januar 2013, 19:28
 */

#ifndef FILEREAD_H
#define	FILEREAD_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class fileRead {
public:
    
    void getVector(vector<double>& v1, vector<double>& v2);
    int getVectLen();
    void readFile(string f);
    void print();
    
private:

    vector<double> lat;
    vector<double> lon;
        
    ifstream csvFile;
    string buf;
        
    void parseLine(string s, double& lat, double& lon);
    
};

#endif	/* FILEREAD_H */

