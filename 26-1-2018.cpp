struct Node{
	int data;
	Node* pNext;
};

void input(Node* &pHead);
void display(Node* cur);
void removeall(Node* &pHead);

void input(Node* &pHead){
cin>>t;
Node* cur=NULL; //ko set cung dc
while(t!=0){
	if(pHead==NULL){ //setting up the 1st Node
	pHead = new Node;
	pHead->pNext=NULL;
	cur=pHead; //use another pointer to set up other Nodes
	}
	else{
	cur->pNext = new Node;
	cur->data = t;
	cur->pNext=NULL;
	}
	cin>>t;
}
}

void display(Node* cur){
	while(cur!=NULL)
	cout<<cur->data;
	cur=cur->pNext; //move to the next node
}

void removeall(Node* &pHead){
	Node tmp=pHead;
	while(pHead!=NULL){
	pHead=pHead->pNext;
	cout<<tmp->data<<"is being deleted..."<<endl;
	delete tmp;
	tmp = pHead;
	}
}

//insert a node k at the beginning of the list
1->2->3->4->5....
k 1 2 3 4 5...

void insertbegin(*Node &pHead, int k){
	Node* tmp;

	//create node k
	tmp=new Node;
	tmp->data=k;

	//link node k to the 1st node
	tmp->pNext=pHead;

	//update price
	pHead=tmp;
}


void insertafter(Node* cur, int x, int k)
{
	Node *cur=pHead
	while(cur->data!=NULL){
		if(cur->data==x){
			Node *tmp;
			tmp=new Node;
			tmp->data=k;
			tmp->pNext=cur->pNext;
			cur->pNext = tmp;
			break;
		}
		cur=cur->pNext;
	}
}

void insertbefore(Node* cur, int x, int k)
{
	
}



