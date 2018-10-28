// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
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


int main(int argc, char* argv[])
{ //args are: "name of file", "number of rows(sizeOfY)", "number of columns (sizeOfX)",
  //"x coordinate", "y coordinate", "type, 4 or 8."
  //! find out how to read file to array
  const unsigned int ARGMINIMUM=3; //! change to a larger check structure to test for different programs. 
  if(argc<ARGMINIMUM+1){
    //check for enogh arguments, add one to account for the program call itself. (it's argv[0])
    cout << "error, only "<< argc -1<< " arguments given at least " << ARGMINIMUM << " needed."<< endl;
    //subtract 1 from argc to account for the program call itself.
    return 0;
  }
  //! Add if statement to check what program to run. 
  //! programs are called by first argument. 
  //! "./cells","./blobs","./path","./sudoku"

  int innR=atoi(argv[1]);
  int innC=atoi(argv[2]);
  int type=atoi(argv[3]);
  cout << innR << endl << innC << endl<< endl;

  unsigned int rows=sizeOfArray;
  unsigned int columns=sizeOfArray;

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



  int **suArr;
  suArr = new int *[9];
  for(int i = 0; i <9; i++){
    suArr[i] = new int[9];
  }  
  for (int i=0;i<3;i++){
    //initalize array with 0.
    for (int j=0;j<3;j++){
      array[i][j]=0;
    }
  }





  /* old test code 
  //build a 1-9 array to test some sudoku stuff
  for(int c=0,i=0;i<3;i++){
    for(int j=0;j<3;j++){
      suArr[j][i]=1+c++;
    }
  }
  suArr[1][1]=0;


  intPrinter(suArr,9,9);
  bool result = sudokuSolve(suArr,0,0);
  if(result){
    cout << endl << "yep!" << endl;
  }
  else{
    cout << endl << "nope.." << endl;
  }
  intPrinter(suArr,9,9);

  cout << endl << sudokuCheck(suArr,1,1,1) <<endl;
  cout << argv[0] << endl << endl;

  // build a couple blobs for testing.
  for(int i=2;i<5;i++)
    array[i][0]=1;
  for(int i=2;i<5;i++)
    array[i][1]=1;
  array[1][3]=1;
  array[0][4]=1;

  cout << "vale at point x:" << innC << " y:" << innR << endl;
  cout <<endl;
  int testerone = countBlob(array,columns,rows,type);// sizeOfBlob(array,columns,rows,innR,innC,type);
  cout <<"Number of blobs: " << testerone << endl;
  */
}