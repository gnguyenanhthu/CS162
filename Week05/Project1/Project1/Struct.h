#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include<fstream>
using namespace std;

struct Node {
	Node* next;
	Node* pre;
	int data;
};
struct DoublyList {
	Node *head;
};

void load(char path[], Node *&head);
void save(char path[], Node *&head);
void insertasc(Node *&head, int &a);

#endif
