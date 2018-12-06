// Thor Christian Cusick.
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>



void to_hostname(char *address) {
    unsigned int endOfHostName=0;
    unsigned int startOfHostName=0;
    unsigned int counterOfSlashes=0;
    do{
        if(address[startOfHostName]=='/')
            counterOfSlashes++;
        startOfHostName++;
    }while(counterOfSlashes<2);
    endOfHostName=startOfHostName;
    do{
        if(address[endOfHostName]=='/'||address[endOfHostName]==':'){
            counterOfSlashes++;
            endOfHostName--;
        }
        endOfHostName++;
    }while(counterOfSlashes<3&&endOfHostName<strlen(address));
    for(int i=startOfHostName;i<endOfHostName;i++){
        address[i-startOfHostName]=tolower(address[i]);
    }
    address[endOfHostName-startOfHostName]='\0';
    return;
}

int main(){
    char pat[]=" sl";
    char txt[]="https://WWW.cs.uri.edu:80/aoeu";
    to_hostname(txt);
    std::cout << txt;
}
