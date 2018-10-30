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

int countBlob(bool** theArrayOfBlobs,int sizeOfX,int sizeOfY,int mode){
  int blobCount=0;
  for(int i=0;i<sizeOfY;i++){
    for(int j=0;j<sizeOfX;j++){
      if(sizeOfBlob(theArrayOfBlobs,sizeOfX,sizeOfY,j,i,mode)>0){
        blobCount++;
      }
    }
  }
  return blobCount;
}

bool sudokuCheck(int **arr,int x,int y,int number){
  int cornerX=(x/3)*3;
  int cornerY=(y/3)*3;
  for(int i=0;i<8;i++){
    if(arr[i][y]==number){
      return false;
    }
  }
  for(int i=0;i<8;i++){
    if(arr[x][i]==number){
      return false;
    }
  }
  for(int i=cornerY;i<(cornerY+3);i++){
    for(int j=cornerX;j<(cornerX+3);j++){
      if(arr[j][i]==number){
        return false;
      }
    }
  }
  return true;
}



//! do nr4.
bool sudokuSolve(int **arr,int x,int y){
  if(y>8){
    return 1;
  }
  if(x>8){
    return sudokuSolve(arr,0,y+1);  //! this might have to change. 
  }
  if(arr[x][y]>0){
    sudokuSolve(arr,x+1,y);
  }
  bool check=0;
  for(int i=1;i<10;i++){
    if(sudokuCheck(arr,x,y,i)){
      arr[x][y]=i;
      if(sudokuSolve(arr,x+1,y)){
        return 1;
      }
    }
    arr[x][y]=0;
  }
  return check;
};




void boolPrinter(bool **arr,int sizeOfX,int sizeOfY){
    for (int i=0; i<sizeOfY;i++){
      for (int j=0;j<sizeOfX;j++){
        cout << arr[j][i];
      }
    cout << endl;
  }
}
void intPrinter(int **arr,int sizeOfX,int sizeOfY){
    for (int i=0; i<sizeOfY;i++){
      for (int j=0;j<sizeOfX;j++){
        cout << arr[j][i];
        if(j<(sizeOfX-1)){
          cout<<',';
        }
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


  /*
  int j=0;
  while(getline(infile,str)) {
    int xCord=0;
    // you could do this to access each element in each line 
      for(int i = 0; i < str.length(); i++) {
        if(str[i]!=' ')
        array[xCord][j]=atoi(&str[i]);
        xCord++;
      }
    j++;
  }
  */
  cout << sizeOfBlob(array,innR,innC,innY,innX,type) << endl;
  array[innX][innY]=true;
  //boolPrinter(array,innR,innC);
  boolDeleteArray(array,innR);

/*

  bool **array;
  array = new bool *[columns];
  for(int i = 0; i <columns; i++){
    array[i] = new bool[rows];
  }
  for (int i=0; i<rows;i++){
    //initalize array with 0.
    for (int j=0;j<columns;j++){
      array[i][j]=0;
    }
  }
*/


}