#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<fstream>
using namespace std;


void load(char path[], int*&p, int& n); //1
bool checkprime(int n);
int largestprime(int *p, int n); //2
void sortoddeven(int *p, int n); //3
void insert(int *&p, int &n, int k); //4
void removeone(int *s, int &n, int a);
void removesame(int *p, int &n); //5
int gcdtwo(int a, int b);
int gcdarray(int *p, int n); //6
void display(int *p, int n); //7
void save(char path[], int *p, int n); //8

#endif