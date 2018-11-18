// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "list.h"
using namespace std;

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

    List atoms;
    for(;!infile.eof();){
        // each time the below function runs, the entire line from the text file is stored in string str
        getline(infile,str);
        if(str.substr(0,4).compare("ATOM") ==0){
            if(str.substr(13,2).compare("CA") ==0){
                // add to datastrcture. 
                double x = stod(str.substr(31,7));
                double y = stod(str.substr(39,7));
                double z = stod(str.substr(47,7));
                char Cid = str[21];
                atoms.insert(x,y,z,Cid);
                //cout << " x: "<<stod(str.substr(31,7)) <<" y: "<<stod(str.substr(39,7)) <<" z: "<<stod(str.substr(47,7)) << " Cid: " << str.substr(21,1)<<endl;
            }
        }
    }
    // Step 4. Remember to close your file reader once you are done with it
    infile.close();

    ofstream outfile;
    //outfile.open("coords.js");
    outfile.open("test.csv");

    atoms.findNN();

    outfile << "var colors = ["<<endl;
    string n;
    for(int i=atoms.size();i>0;--i){
        n= "    " + atoms.print()+ ", " + atoms.printN() + ",";
        outfile <<n<<endl;
        atoms.move(1);
    }
    outfile << "];" << endl;
    //atoms.printLN();
    
}
