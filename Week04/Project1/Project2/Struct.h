#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	Node *next;
	int data;
};

struct List {
	Node *head;
};

void listsum(Node *&head);
void load(char path[], Node *&head);
void save(char path[], Node *&head);

#endif
