void List::~List(){
	Node* p=head;
	while(){
		p=p->next;
		delete head;
		head=p;
	}
	// this is only used if the destructor is needed for clearing the list.
	tail=head; // or tail=NULL;

	// Alternative method for destructor:
	//deleter(head);
}

//recursive destructor.
void List::deleter(Node* p){
	if(p==NULL){
		return;
	}
	deleter(p->next);
	delete p;
}

void List::clearFirst(){
	Node* p=head;
	head=head->next;
	delete p;
	if(head==NULL){ // this is needed for removing the last element.
		tail=head;
	}
}


void List::append(int a){
	// Make a node for a (allocate space for a.)
	Node *p = new Node(a);
	if(head==NULL){
		head=tail=p;
	}
	else{
		// find tail (use tail pointer)
		// make tail's next_item pointer point to address of a.
		tail->next = p;
		// make the tail pointer point to the new node.
		tail=p;
		// make a's next_item pointer point to NULL.
	}
}

void List::print(){
	Node* p=head;
	while(p!=NULL){
		// do stuff
		std::cout << p->data << " -> ";
		p=p->next;
	}
}

