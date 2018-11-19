#include "list.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
using namespace std;

Node::Node(double inx ,double iny ,double inz ,char inchain){
    x=inx;
    y=iny;
    z=inz;
    chain=inchain;
}
Node::~Node(){
    // TODO make a working destructor. 
    //if(next!=0)
    //delete next;
    //delete nabo;
}

double Node::distance(Node* p){
    // distance is taken between the "current" node to node p. 
    // p is a pointer to the node you want to check the distance to.
    return sqrt(pow(p->x-x,2)+pow(p->y-y,2)+pow(p->z-z,2));
}

List::List(){
    nodeCount=0;
    current=0;
}
List::~List(){
    recDel(current,nodeCount);
}
void List::recDel(Node* n,int c){
    // recursively delete each node. 
    if(!c){
    // when the counter is 0, all nodes are deleted. 
        delete n;
    }
    else{// recurse to the next node, and decrement counter
    recDel(n->next,c-1);
    delete n;// after recursion delete the node. 
    }
}


void List::insert(double x, double y, double z, char chain){
    // make a new node with all the data. 
    Node* n=new Node(x,y,z,chain);
    if(current==0){ // if the list is empty, make an inital node. 
        current=n;// move from NULL to the first node
        n->next=n;// point first node to it self. 
    }
    else{ // plopp the new node in after the current node. 
        n->next=current->next; 
        current->next=n;
        current=n;
    }
    ++nodeCount;
}

string List::print(){ 
    // print the current node's x,y, and z value, in csv format.
    string n;
    stringstream stream;
    stream << fixed << setprecision(3) << current->x;
    n = stream.str() + ", "; 
    stream.str("");
    stream << fixed << setprecision(3) << current->y;
    n += stream.str() + ", "; 
    stream.str("");
    stream << fixed << setprecision(3) << current->z;
    n += stream.str() + ", ";
    return n;
}
string List::printN(){
    // print the current node's nearest neighbor's x,y, and z value, in csv format.
    string n;
    stringstream stream;
    stream << fixed << setprecision(3) << current->nabo->x;
    n = stream.str() + ", "; 
    stream.str("");
    stream << fixed << setprecision(3) << current->nabo->y;
    n += stream.str() + ", "; 
    stream.str("");
    stream << fixed << setprecision(3) << current->nabo->z;
    n += stream.str() + ", ";
    return n;
}


string List::printC(){
    // print the current node, and it's nearest neighbor's color value, 
    // based on the chain. 
    string n;
    // getting the colors for the current node
    if('A'==current->chain)
        n="0, 0, 1,";
    else if('B'==current->chain)
        n="0, 1, 0,";
    else if('C'==current->chain)
        n="1, 0, 0,";
    else if('D'==current->chain)
        n="1, 1, 0,";
    else if('E'==current->chain)
        n="1, 1, 1,";
    else
        n="1, 0.5, 0,";

    // getting the colors for the nearest neighbor
    if('A'==current->nabo->chain)
        n+=" 0, 0, 1,";
    else if('B'==current->nabo->chain)
        n+=" 0, 1, 0,";
    else if('C'==current->nabo->chain)
        n+=" 1, 0, 0,";
    else if('D'==current->nabo->chain)
        n+=" 1, 1, 0,";
    else if('E'==current->nabo->chain)
        n+=" 1, 1, 1,";
    else
        n+=" 1, 0, 1,";
    return n;
}

int List::size(){
    return nodeCount;
}

void List::findNN(){
    Node* n;
    for(int i=0;i<nodeCount;++i){
        n=current->next;
        double dist = current->distance(n);
        current->nabo=n;
        for(int j=0;j<(nodeCount-1);++j){ 
            // (nodeCount-1) to avoid finding the current node. 
            // find distance:
            double chDist=current->distance(n);
            // cout << endl << "curdist: " << chDist << endl;
            // compare 
            if(dist>chDist){
                dist=chDist;
                // store nearest neighbor:
                current->nabo=n;
            }
            n=n->next;
        }
        // move current
        current=current->next;
    }
}

void List::move(int a){
    // move current pointer "a" nodes along the list.
    for(int i=0;i<a;++i){
        current=current->next;
    }
}