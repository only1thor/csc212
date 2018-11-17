// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
using namespace std;


int main(int argc, char* argv[])
{
    List blah;
    blah.insert(1,23,4,'b');
    blah.insert(1,3,9,'b');
    blah.insert(1,2,2,'y');
    blah.insert(7,0,4,'y');
    blah.print();
    blah.findNN();
    cout<< endl << "nn:" << endl;
    blah.printN();
    blah.printLN();
}
