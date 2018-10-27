// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printer(bool **arr){
    for (int i=0; i<sizeOfArray;i++){
    //initalize array with 0.
    for (int j=0;j<sizeOfArray;j++)
      cout << arr[i][j];
    cout << endl;
  }
}


int main(int argc, char* argv[])
{ 
  return 0;
}