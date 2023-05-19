void insertbefore (Node *&head, int x, int y)
if(head==NULL)
	return; //empty list
if(head->data==x)
{
	insertbegin(head,y);
	return;
}
Node *cur=head;
while (cur->next!=NULL && cur->next->data!=x)
	cur=cur->next;
if(cur->next!=NULL) //found x in the list
{
	
}