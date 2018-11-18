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
    blah.insert(1.234,23,4,'b');
    blah.insert(1,3,9,'b');
    blah.insert(1,2,2,'y');
    blah.insert(7,0,4,'y');
    
    string n;
    for(int i=blah.size();i>0;--i){
        n=blah.print();
        cout <<n.substr(0,29)<<endl;
        blah.move(1);
    }
    
    blah.findNN();
    for(int i=blah.size();i>0;--i){
        n=blah.print().substr(0,29) + " -> " +blah.printN().substr(0,29);
        cout <<n<<endl;
        blah.move(1);
    }
    
}
