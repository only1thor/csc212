// Thor Christian Cusick.
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>



//swaps 2 items in a list, given indexes, and pointer to the list. 
void swp(int a, int b, int *ptr){//a small funciton to swap 2 items in the list. 
    int tmp=ptr[a];
    ptr[a]=ptr[b];
    ptr[b]=tmp;
}

void sort_three(int a, int b, int c, int *list){


    list[0]=a;//load all numbers into the list.
    list[1]=b;
    list[2]=c;
    if(list[0]<list[1]) //make sure the largest value is in the lowest index.
        swp(0,1,list);
    if(list[0]<list[2])
        swp(0,2,list);
    if(list[1]<list[2])
        swp(1,2,list);

}

unsigned int str_search(const char *pattern, const char *text) {
    int count=0;
    int test=0;
    int lengPat= strlen(pattern);
    int lengTxt= strlen(text);
//just a quick test to see if the patter is longer than the text. 
//if it is then the pattern will never be valid.
    if(lengPat<=lengTxt){
        for(int i=0; i <= (lengTxt-lengPat); i++){ //step through the text
            if(pattern[0]==text[i]){ //look for the first letter, if a hit
                                     //is found, check the rest of the pattern
                for(int j=0;j<lengPat;j++){ 
                    if(pattern[j]==text[i+j]){
                        test=1;
                    }
                    else{ //if any part of the patter does not mach, 
                          //reset test, and exit
                        test=0;
                        break;
                    }
                }
                count+=test;
                test=0;
            }
        }
    }
 return count;
}

unsigned long int any2dec(const char *num, unsigned int b) {
    int lengNum = strlen(num);
    int sum=0;
    char dex[]= "0123456789ABCDEF"; //make an index to compare with.
    char convertedArray[lengNum]={0};
    for(int i=0; i<lengNum;i++){ // search the entire string.
        for(int j=0;j<b;j++){ //compare only to the valid chars for this base
            if(dex[j]==num[i]){
                convertedArray[i]=j;
                sum+=j*pow(b,(lengNum-1-i)); //use the index of the number 
                                             //to do the convertion. 
            }
        }
    }
 return sum;
}

void hex2rgb(const char *hex, char *rgb) {
    char array[3]={'\0'};
    unsigned long int decArray[3];
    for(int i=0;i<3;i++){ //load 2 and 2 hex values into the array and convert
        array[0]=hex[2*i+1]; // them to decimal, then save them for the string
        array[1]=hex[2*i+2]; // later. 
        decArray[i]=any2dec(array,16);
    }
    // put all the converted numbers into the string. 
    sprintf(rgb,"rgb(%d,%d,%d)",decArray[0],decArray[1],decArray[2]); 
 return;
}

int gStrLen(const char *array){ // this function was going to read the length
    int lenArray=strlen(array); // of the "base" Gmail address for a quick
    int i=0;                    // check to see if they are possible maches.
    int counter=0;
    char test='0';
    do{
        if(array[i]!='.'&&array[i]!='+') //an atemt at trying to only count 
            counter++;                   //vaild chars
        else
            test=array[i];
    }while(test!='+' && test!='@');//and try to exit when the valid addess ends
}


bool same_gmail(const char *g1, const char *g2) {
    int lenG1=strlen(g1);   //gave up due to bad time managment on my part.
    int lenG2=strlen(g2);

    
 return 0;
}

unsigned int unique_letters(const char *S) {
    bool foundOne=false;
    unsigned int lenStr=strlen(S);
    unsigned int countOfLetters=0;
    char listOfFoundLetters[30]={'\0'};
    //defining the characters that are considered letters, 
    //to be able to exclude non letters. 
    char listOfLetters[] ="abcdefghijklmnopqrstuvwxyz";
                          
    for(int i=0;i<lenStr;i++){ //look through the entire string.

        //check for letters, if no letters, skip to next itteration. 
        for(int j=0;j<26;j++){
            if(tolower(S[i])==listOfLetters[j]){
                foundOne=true;
            }
        }
        //if a letter is found, reset so this var can be used later
        if(foundOne){
            foundOne=false; 
        }
        else{
            continue; 
        }
        
        //find unique letters.
        for(int j=0;j<30;j++){
            if(tolower(S[i])==listOfFoundLetters[j]){
                foundOne=true;
            }
        }
        if(!foundOne){
            listOfFoundLetters[countOfLetters]=tolower(S[i]);
            countOfLetters++;
        }
        else {
            foundOne=false;
        }
    }
    return countOfLetters;
}

unsigned int n_inversions(const int *A, unsigned int n) {
 return 0;
}

unsigned int l_mode(const int *A, unsigned int n) {
 return 0;
}


void to_hostname(char *address) {
    unsigned int endOfHostName=0;
    unsigned int startOfHostName=0;
    unsigned int counterOfSlashes=0;
    do{ // find the start of the domain regardless of protocol (http/https). 
        if(address[startOfHostName]=='/')
            counterOfSlashes++;
        startOfHostName++;
    }while(counterOfSlashes<2);
    endOfHostName=startOfHostName; // get ready to look for the end

    // look for the end, either, a "/", a ":", or just end when the string ends
    do{ 
        if(address[endOfHostName]=='/'||address[endOfHostName]==':'){
            counterOfSlashes++;
            endOfHostName--; //if an end char is found, subtract one so the null
        }                    //gets placed at the right spot.
        endOfHostName++;
    }while(counterOfSlashes<3&&endOfHostName<strlen(address));

    // now move all the importat parts forward. 
    for(int i=startOfHostName;i<endOfHostName;i++){
        address[i-startOfHostName]=tolower(address[i]);
    }
    // and add a null to end the string. 
    address[endOfHostName-startOfHostName]='\0';
    return;
}

bool circular_prime(unsigned int n) {
 return 0;
}

long int unique_sums(const int *A, unsigned int n, unsigned int k) {
 return 0;
}
