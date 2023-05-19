//1
void load(  List &l)
{
	Node* p, *cur=l.head;
	ifstream fin;
	fin.open("problem(load).txt");
	if (!fin.is_open()) {
	
	return;
	}
	
	int n;
	fin >> n;//n=6
	for(int i=0;i<n;++i)
	{
		int x;
		fin >> x;
		////create node x
		p = new Node;
		p->data = x;
		p->next = NULL;


		if (l.head == NULL)//Neu mang ko co so nao
		{
			l.head = p;
			cur = l.head;
		}
		else
		{
			cur->next = p;//p nối với Node cuối
			cur = p;//p chính thức bằng node cuối
		}
	}
	fin.close();

}

void save( List& l)
{
	Node* cur = l.head;
	ofstream fout;
	fout.open("problem(save).txt");
	if (!fout.is_open()) {
		return;
	}
	while (cur != NULL) {
		fout << cur->data << " ";
		cur = cur->next; //move to the next node
	}
    fout.close();
}