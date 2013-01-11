/**
 * @File:   main.cpp
 * @Author: Nikolai
 *
 * Created on 4. januar 2013, 02:57
 */

#include <cstdlib>
#include "coordinate.h"

using namespace std;

coordinate coord;


/**
 * 
 */
int main(int argc, char** argv) {
    
    cout.setf(ios::fixed, ios::floatfield);

    cout << "HAI" << endl;
    
    coord.init();
    /*coord.printVectors();*/
    
    int nearest = coord.nearestWaypt(0);
    
    cout << "nearest coordinate is: [" << nearest << "]" << endl;
    
    return 0;
}

