#include <string>
using namespace std;

class Node {
    private:
        double x;
        double y;
        double z;
        char chain;

        Node* next; // next node in the circular list.
        Node* nabo; // nearest neighbor (nabo is neighbor in norwegian.)
        
    public:
        Node(double inx, double iny, double inz,char inchain);
        ~Node();
        double distance(Node* p);
        friend class List;
};

class List {
    /*
    the list is circular, and there is only one pointer: "current".
    This class stores data in nodes, that are inserted in the list 
    after what ever node the current pointer is pointing at. 

    The idea is somewhat like the tip of a recordpayer, except that 
    at the end, it continues from the beginning. 

    The move function moves the "current"-pointer along the list, 
    so any node can be accessed.

    This class has no concept of head, or tail. Althogh if data is 
    inserted without using any other methods that move the 
    "current" pointer (like: findNN) then the current will point at the 
    last inserted item, and the next node will be the first item inserted.  
    */
    private:
    int nodeCount;
    Node* current;

    public:
    List();
    ~List();
    void recDel(Node* n, int c);
    void insert(double x,double y ,double z,char chain);
    string print();
    string printN();
    string printC();
    int size();
    void findNN();
    void move(int a);
};