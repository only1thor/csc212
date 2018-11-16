// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
using namespace std;

void prettyPrint(double x[],double y[],double z[],char Cid[],int lines){
    for(int i=0;i<lines;i++){
        cout << "x: " << x[i];
        cout << "   y:  " << y[i];
        cout << "   z:  " << z[i];
        cout << "   Cid:" << Cid[i] << endl;
    }
}


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

    // create some arrays to hold the info:
    double x[310]={0};
    double y[310]={0};
    double z[310]={0};
    char Cid[310]={'0'};
    
    for(int i=0;!infile.eof();){
        // each time the below function runs, the entire line from the text file is stored in string str
        getline(infile,str);
        if(str.substr(0,4).compare("ATOM") ==0){
            if(str.substr(13,2).compare("CA") ==0){
                //cout << str << endl;
                x[i]=stod(str.substr(31,7));
                y[i]=stod(str.substr(39,7));
                z[i]=stod(str.substr(47,7));
                Cid[i]=str[21];
                i++;
                //cout << " x: "<<stod(str.substr(31,7)) <<" y: "<<stod(str.substr(39,7)) <<" z: "<<stod(str.substr(47,7)) << " Cid: " << str.substr(21,1)<<endl;
            }
        }
    }
    // Step 4. Remember to close your file reader once you are done with it
    infile.close();

    prettyPrint(x,y,z,Cid, 310);
    
}
