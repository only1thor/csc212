// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
const unsigned int sizeOfArray=5;
//! find out how to pass a 2d array.

int sizeOfBlob(bool** theArrayOfBlobs,int sizeOfX,int sizeOfY,int x,int y,int mode){
  if(x<0 || y<0 ||x>=sizeOfX || y>=sizeOfY){
    return 0;
  }
  if(!theArrayOfBlobs[x][y]){
    return 0;
  }

  int counter = 0;

  if(theArrayOfBlobs[x][y]){
    theArrayOfBlobs[x][y]=0;
    counter+=1;
    counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x-1,y,mode);
    counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x+1,y,mode);
    counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x,y+1,mode);
    counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x,y-1,mode);
    if(mode>7){
      counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x-1,y+1,mode);
      counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x+1,y-1,mode);
      counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x-1,y+1,mode);
      counter+=sizeOfBlob(theArrayOfBlobs,sizeOfY,sizeOfX,x+1,y-1,mode);
    }
  }
  return counter;
}


void boolPrinter(bool **arr,int sizeOfX,int sizeOfY){
    for (int i=0; i<sizeOfY;i++){
      for (int j=0;j<sizeOfX;j++){
        cout << arr[j][i];
      }
    cout << endl;
  }
}

// Creates a length by length 2D array of bools with all values initialized to 0
bool **boolArray(int row,int col) {
    bool **grid = new bool*[row];
    for (int i = 0 ; i < row ; i ++) {
        grid[i] = new bool[col];
    }
    return grid;
}

// Deallocates a 2D array created by empty_solutions_grid()
void boolDeleteArray(bool **grid, int row) {
    for (int i = 0 ; i < row ; i ++) {
        delete [] grid[i];
    }
    delete [] grid;
}



int main(int argc, char* argv[])
{ //args are: "name of file", "number of rows(sizeOfY)", "number of columns (sizeOfX)",
  //"x coordinate", "y coordinate", "type, 4 or 8."

  // maybe make a struct instead? havent used one of those in forever.. 
  unsigned int innR=atoi(argv[2]);
  unsigned int innC=atoi(argv[3]);
  unsigned int innX=atoi(argv[4])-1;
  unsigned int innY=atoi(argv[5])-1;
  unsigned int type=atoi(argv[6]);
  //unsigned int rows=innR;
  //unsigned int columns=innC;




  bool **array=boolArray(innR,innC);

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
for(int j=0;j<innR;j++){
  getline(infile,str);
  for(int i=0;i<innC;i++){
    array[i][j]=(str[z]-'0');
    z+=2;
  }
  z=0;
}
  // Step 4. Remember to close your file reader once you are done with it
  infile.close();


  cout << sizeOfBlob(array,innR,innC,innY,innX,type) << endl;
  array[innX][innY]=true;
  //boolPrinter(array,innR,innC);
  boolDeleteArray(array,innR);

}