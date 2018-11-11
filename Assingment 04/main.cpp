// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const unsigned int sizeOfArray=5;
//! find out how to pass a 2d array.


int main(int argc, char* argv[])
{
    // Step 1. Get the filename from the command line
    // extracts the filename from the command line and saves it to a string
    string fname = argv[1];

    // Step 2. Create an ifstream to read from the file
    // infile is an input stream which can operate on files
    ifstream infile;

    // Step 3. Open the file for reading
    infile.open(fname);

    // creates a string str to hold the file lines
    string str;
      // each time the below function runs, the entire line from the text file is stored in string str
    int z=0;
    while(!infile.eof()){
        getline(infile,str);
        if(str.substr(0,4).compare("ATOM") ==0){
            if(str.substr(13,2).compare("CA") ==0){
                cout << str << endl;
                cout << " x: "<<stod(str.substr(31,7)) <<" y: "<<stod(str.substr(39,7)) <<" z: "<<stod(str.substr(47,7)) <<endl;
            }
        }
        //for(int i=0;i<innC;i++){}
    }
    // Step 4. Remember to close your file reader once you are done with it
    infile.close();

    
}
