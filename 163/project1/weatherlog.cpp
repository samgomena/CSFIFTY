#include <iostream>
#include <fstream>
#include "datalogger.h"

using namespace std;

int main(int argc, char** argv) {

    datalogger dl;
    LinkedList ll;

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <datafile>" << endl;
        exit(0);
    }
    const char* fileName = "/Users/sgomena/Documents/repos/Classwork/163/project1/climatedata.txt";

    // Read the data

    char* datafile = argv[1];
    ifstream infile(fileName);
    int timestamp;
    double temperature;
    double windspeed;

    while (!infile.eof()) {
        infile >> timestamp;
        infile >> temperature;
        infile >> windspeed;

        if (!infile.eof()) {
            dl.addData(timestamp, temperature, windspeed);
        }
    }

    // Output the report
    dl.printReport();
    
    return(0);
}
