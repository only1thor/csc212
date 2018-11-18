// Thor Christian Cusick.
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "list.h"
using namespace std;
string funccc(){
    return "neh";
}

int main(int argc, char* argv[])
{
    // blahhh 
    string n;
    ostringstream neeah;
    neeah.width(7);
    neeah.precision(7);
    neeah << 36.794;
    n = " this " + to_string(5.9834) +neeah;
    n += funccc();
    cout <<n ;
}