#include "list.h"
#include <iostream>
#include <math.h>
using namespace std;

Node::Node(double inx ,double iny ,double inz ,char inchain){
    x=inx;
    y=iny;
    z=inz;
    chain=inchain;
}
Node::~Node(){
    
}

double Node::distance(Node* p){
    return sqrt((x*p->x)+(y*p->y)+(z*p->z));
}

List::List(){
    nodeCount=0;
    current=0;
}
List::~List(){
    recDel(current,nodeCount);
}
void List::recDel(Node* n,int c){
    if(!c){
        delete n;
    }
    else{
    recDel(n->next,c-1);
    delete n;
    }
}


void List::insert(double x, double y, double z, char chain){
    // make a new node with all the data. 
    Node* n=new Node(x,y,z,chain);
    if(current==0){
        current=n;// move from NULL to the first node
        n->next=n;// point first node to it self. 
    }
    else{ // plopp the new node in after the current node. 
        n->next=current->next; 
        current->next=n;
        current=n;
    }
    nodeCount++;
}

void List::print(){
    cout << "---"<<endl;
    for(int i=0;i<nodeCount+1;i++){
        cout<<current->x << "," << current->y << ","; 
        cout << current->z << "," << current->chain<< endl;
        cout << "---" << endl;
        current=current->next;
    }
}

int List::size(){
    return nodeCount;
}


void List::findNN(){
    for(int i=0;i<nodeCount;++i){
        Node* n=current->next;
        double dist = current->distance(n);
        for(int j=0;j<(nodeCount-1);++j){
            // compare 
            
        }
        // move current
        current=current->next;
    }
}