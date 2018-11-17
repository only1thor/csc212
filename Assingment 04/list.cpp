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
    ++nodeCount;
}

void List::print(){
        cout<<current->x << "," << current->y << ","; 
        cout << current->z << "," << current->chain;
}

void List::printL(){
    cout << "---"<<endl;
    for(int i=0;i<nodeCount;i++){
        cout<<current->x << "," << current->y << ","; 
        cout << current->z << "," << current->chain<< endl;
        cout << "---" << endl;
        current=current->next;
    }
}

void List::printN(){
        cout << "---" << endl;
        print();
        cout << " -> ";
        cout<<current->nabo->x << "," << current->nabo->y << ","; 
        cout << current->nabo->z << "," << current->nabo->chain;
        cout << endl;
        cout << "---" << endl;
}

void List::printLN(){
    cout << "---"<<endl;
    for(int i=0;i<nodeCount;i++){
        printN();
        current=current->next;
    }
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