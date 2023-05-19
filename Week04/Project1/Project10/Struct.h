#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;

struct Book {
	char title[200], author[40], language[30];
	int ISBN, yp, price, stlevel;
	Book *next;
};

void load(char path[], Book *&head);
void input(Book *&head);
void sellabook(int x, Book *&head);
void findbook(char s[], Book *&head);
void remove(int k, Book *&head);

#endif
