#ifndef NULL
#define NULL 0x00
#endif

class Node {
    private:
        int data;
        Node *left;
        Node *right;

    public:
        Node(int d) {
            data = d;
            left = right = NULL;
        }

        ~Node() {
        }

        friend class BSTree;
};

class BSTree {
    private:
        Node *root;

    public:
        BSTree() {
            root = NULL;
        }
        ~BSTree();
        bool search(int k);
        void insert(int k);
  			bool rec_insert(Node *p, int k);
  			bool BSTree::alt_insert;
};

BSTree::~BSTree() {
}

bool BSTree::search(int k) {
    Node *p = root;
    while (p) {
        if (k == p->data) return true;
        if (k < p->data) p = p->left;
        else p = p->right;
    }
    return false;
}

void BSTree::insert(int k) {
  //go through tree comparing data value in new node to current node (greater or less than)
  Node *p = root;
  if (!root) {
    //create node, place here
    root = new Node(k);
  }
  else {
  	// if the pointer points to null, insert.
  	rec_insert(p, k);
  	//keep going; when your comparison points to null, make it point to the new node instead
  }
}

bool BSTree::rec_insert(Node *p, int k) {
  	//when we hit the null
	  if (p == NULL) {
      //let the previous frame know that we need to place the node here
      return true;
    } 
  	else {
      //lets us know whether we need to make the new node and place it
      bool place;
      //dir = 0 -> go left, dir = 1 -> go right
      bool dir;
      /*
      conditionals to check whether to go left or right
      */
      //goes to the left
      if (p->data > k) {
        place = rec_insert(p->left, k);
        dir = 0;
      }
      //goes to the right
      else {
        place = rec_insert(p->right, k);
        dir = 1;
      }
      
      //occurs when we returned from the place we need to put the new node
      if (place) {
      	//create node with k as data
 	 			Node *faen = new Node(k);
        
        //if we need to set the new node to the right
        if (dir) {
          p->right = faen;
        }
        //else set to the left
        else {
          p->left = faen;
        }
      }
      
      //to let other frames know that the node is placed
      return false;
    } 
}


bool BSTree::alt_insert(Node* p, int k){
	if(p->data>k){
    // if there is no node to the left of the current node..
    if(!p->left){
      Node* faen= new Node(k); // ..make a new node with the value..  
      p->left=faen;// point the left pointer to the new node. 
      return true; // tell the program all is well 
    }
    alt_insert(p->left,k);
  }  
  
  //if k is less then the current node:
  else{
    if(!p->right){
      Node* faen= new Node(k);
      p->right=faen;
      return true;
    }
    alt_insert(p->right,k);
  }  
  return false;
}


int main() {
    BSTree a;
  	
}

