class Node {
    private:
        double x;
        double y;
        double z;
        char chain;

        Node* next;
        Node* nabo; // nearest neighbor (nabo is neighbor in norwegian.)
    public:
        Node(double inx, double iny, double inz,char inchain);
        ~Node();

        friend class List;
};

class List {
    private:
    // stuff
    int nodeCount;
    Node* current;

    public:
    // more stuff 
    List();
    ~List();
    void recDel(Node* n, int c);
    void insert(double x,double y ,double z,char chain);
    void print();
    int size(void);
};