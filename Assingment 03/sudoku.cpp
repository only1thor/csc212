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

bool sudokuCheck(int **arr,int x,int y,int number){
  int cornerX=(x/3)*3;
  int cornerY=(y/3)*3;
  for(int i=0;i<9;i++){
    if(arr[i][y]==number){
      return false;
    }
  }
  for(int i=0;i<9;i++){
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
bool sudokuSolve(int **arr,int x ,int y){
  if(y>8){
    return 1;
  }
  if(x>8){
    return sudokuSolve(arr,0,y+1);  //! this might have to change. 
  }
  if(arr[x][y]>0){
    return sudokuSolve(arr,x+1,y);
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

int **intArray(int row,int col) {
    int **grid = new int*[row];
    for (int i = 0 ; i < row ; i ++) {
        grid[i] = new int[col];
    }
    return grid;
}

// Deallocates a 2D array created by empty_solutions_grid()
void intDeleteArray(int **grid, int row) {
    for (int i = 0 ; i < row ; i ++) {
        delete [] grid[i];
    }
    delete [] grid;
}


int main(int argc, char* argv[])
{ //args are: "name of file", "number of rows(sizeOfY)", "number of columns (sizeOfX)",
  //"x coordinate", "y coordinate", "type, 4 or 8."

  // maybe make a struct instead? havent used one of those in forever.. 




  int **array=intArray(9,9);

  // Step 1. Get the filename from the command line
  // extracts the filename from the command line and saves it to a string
  string fname = argv[1];

  // Step 2. Create an ifstream to read from the file
  // infile is an input stream which can operate on files
  ifstream infile;

  // Step 3. Open the file for reading
  /* make sure the right file is read. 
  infile.open(fname);
  cout<< infile.rdbuf() << endl;
  infile.close();
  */
  infile.open(fname);
  // creates a string str to hold the file lines
  string str;
  // each time the below function runs, the entire line from the text file is stored in string str
int z=0;
for(int j=0;j<9;j++){
  getline(infile,str);
  for(int i=0;i<9;i++){
    array[i][j]=(str[z]-'0');
    z+=2;
  }
  z=0;
}
  // Step 4. Remember to close your file reader once you are done with it
  infile.close();


  //intPrinter(array,9,9);
  //cout << endl;
  sudokuSolve(array,0,0);
  intPrinter(array,9,9);
  intDeleteArray(array,9);


}