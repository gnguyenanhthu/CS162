#ifndef _STUDENT_H_
#define _STUDENT_H_
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>
#include<string.h>
#include<cstdlib>
using namespace std;

struct Birthday {
	int day, month, year;
};

enum Gender {
	MALE,
	FEMALE,
	NA
};

struct Student {
	int id, random;
	char name[31];
	char socialID[31];
	Birthday dob;
	Gender gender;
	float GPA;
};

void load(char path[], Student a[], int &n); //Ex01
void save(char path[], Student a[], int n); //Ex02
void saveStudent(char path[], Student st);
void manyStudents(char path[], Student st);
Student maxGPA(Student a[], int n); //Ex03
void belowaverage(char path[], Student a[], int n); //Ex04
void courses(char path[], Student a[], int n, int x); //Ex05
void findid(char path[], Student a[], int n, int x); //Ex06
void findname(char path[], Student a[], int n, char s[]); //Ex07
void female(char path[], Student a[], int n); //Ex08
void male(char path[], Student a[], int n); //Ex09
void sortid(Student a[], int n); //Ex10
void sortname(Student a[], int n); //Ex11
void sortgpa(Student a[], int n); //Ex12
Student oldest(Student a[], int n); //Ex13
void top5(char path[], Student a[], int n); //Ex14
void bdthismonth(char path [], Student a[], int n); //Ex15
void samebirthday(char path[], Student a[], int n); //Ex16
Student findrandom(Student a[], int n); //Ex17
void group(char path[], Student a[], int n, int k); //Ex18
void schoolyear(char path[], Student a[], int n); //Ex19
void bornmonth(char path[], Student a[], int n); //Ex20
#endif

