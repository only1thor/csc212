// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const unsigned int sizeOfArray=5;
const unsigned int ARGMINIMUM=3;
//! find out how to pass a 2d array.
bool checkcorner(bool** theArrayOfBlobs,int y,int x, int type){
  //type is 0 to 3, for upper right, upper left, lower right, or lower left.
  if (type==0){
    //if upper right, check for blob at x-1, and y+1
    //return theArrayOfBlobs[x-1][y+1];
    return 0;
  }
  return 0;
}
int sizeOfBlob(bool** theArrayOfBlobs,int siezOfY,int sizeOfX,int y,int x,int mode){
  // mode is either 4 or 8, if you want to check diagonaly or not. (8 is diagonal checks.)
  unsigned int leftCounter=0;
  unsigned int rightCounter=0;
  unsigned int upCounter=0;
  unsigned int downCounter=0;
  int i=0;
  do{//check left
    i=x-1;
    if (i>sizeOfX || i < 0)
      break; //break if out of bounds
    if (theArrayOfBlobs[y][i])
      leftCounter++;
    else
      break;
  }while(theArrayOfBlobs[y][i]);
  return leftCounter;
}

void printer(bool **arr){
    for (int i=0; i<sizeOfArray;i++){
    //initalize array with 0.
    for (int j=0;j<sizeOfArray;j++)
      cout << arr[i][j];
    cout << endl;
  }
}


int main(int argc, char* argv[])
{ //args are: "name of file", "number of rows(sizeOfY)", "number of columns (sizeOfX)",
  //"x coordinate", "y coordinate", "type, 4 or 8."
  //! find out how to read file to array
  //bool array[sizeOfArray][sizeOfArray];
  if(argc<ARGMINIMUM+1){
    //check for enogh arguments, add one to account for the program call itself. (it's argv[0])
    cout << "error, only "<< argc -1<< " arguments given at least " << ARGMINIMUM << " needed."<< endl;
    //subtract 1 from argc to account for the program call itself.
    return 0;
  }
  int innR=atoi(argv[2]);
  int innC=atoi(argv[3]);
  cout << innR << endl << innC << endl;

  unsigned int rows=sizeOfArray;
  unsigned int columns=sizeOfArray;

  bool **array;
  array = new bool *[rows];
  for(int i = 0; i <rows; i++)
  array[i] = new bool[columns];


  for (int i=0; i<sizeOfArray;i++){
    //initalize array with 0.
    for (int j=0;j<sizeOfArray;j++)
      array[i][j]=0;
  }
  // build a couple blobs for testing.
  for(int i=2;i<5;i++)
    array[1][i]=1;
  for(int i=2;i<5;i++)
    array[2][i]=1;
  array[3][1]=1;

  printer(array);
  cout <<endl;
  int testerone = sizeOfBlob(array,sizeOfArray,sizeOfArray,innR,innC,1);
  cout << testerone << endl;
}