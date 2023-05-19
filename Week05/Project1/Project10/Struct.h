#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <fstream>
using namespace std;
struct Node {
	Node *next;
	int data;
	Node *prev;
};
struct List {
	Node *head;
};

void numbtolist(Node *&head, char s[]);
void divide(Node *&head1, Node *&head2);
bool ifbigger(Node *&head1, Node *&head2);
void insertlast(Node *&head, int t);
Node* multiplybi(Node *&head1, Node *&head2);
Node* substractbi(Node *&head1, Node *&head2);
Node* plusbi(Node *&head1, Node *&head2);
void insert(Node *&head, int t);

#endif