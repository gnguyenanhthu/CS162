#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<ctime>
using namespace std;

struct Node {
	Node *next;
	int id;
	char name[50];
};


void date(char path1[], char path2[], Node *&head);
void load(char path[], Node *&head);


#endif
