#include "Student.h"
int main() {
	Student a[100], b, c, d;
	int n, x, y, k;
	char s[100];
	
	cout << "Please input a name: ";
	cin.getline(s,100,'\n');

	load("D:\\APCS\\CS162\\Week01\\input.txt", a, n); //Ex01

	save("D:\\APCS\\CS162\\Week01\\problem02.txt", a, n); //Ex02

	b = maxGPA(a, n);
	saveStudent("D:\\APCS\\CS162\\Week01\\problem03.txt", b); //Ex03

	belowaverage("D:\\APCS\\CS162\\Week01\\problem04.txt", a, n); //Ex04

	cout << "Please input a course: ";
	cin >> y;
	courses("D:\\APCS\\CS162\\Week01\\problem05.txt", a, n, y); //Ex05

	cout << "Please input an ID: ";
	cin >> x;
	findid("D:\\APCS\\CS162\\Week01\\problem06.txt", a, n, x); //Ex06

	findname("D:\\APCS\\CS162\\Week01\\problem07.txt", a, n, s); //Ex07

	female("D:\\APCS\\CS162\\Week01\\problem08.txt", a, n); //Ex08

	male("D:\\APCS\\CS162\\Week01\\problem09.txt", a, n); //Ex09

	sortid(a, n); //Ex10
	save("D:\\APCS\\CS162\\Week01\\problem10.txt", a, n); 

	sortname(a, n); //Ex11
	save("D:\\APCS\\CS162\\Week01\\problem11.txt", a, n);

	sortgpa(a, n); //Ex12
	save("D:\\APCS\\CS162\\Week01\\problem12.txt", a, n); 

	c = oldest(a, n); //Ex13
	saveStudent("D:\\APCS\\CS162\\Week01\\problem13.txt", c); 

	top5("D:\\APCS\\CS162\\Week01\\problem14.txt", a, n); //Ex14

	bdthismonth("D:\\APCS\\CS162\\Week01\\problem15.txt", a, n); //Ex15

	samebirthday("D:\\APCS\\CS162\\Week01\\problem16.txt", a, n); //Ex16

	d = findrandom(a, n); //Ex17
	saveStudent("D:\\APCS\\CS162\\Week01\\problem17.txt", d);

	cout << "Please input number of students in each group";
	cin >> k;
	group("D:\\APCS\\CS162\\Week01\\problem18.txt", a, n, k); //Ex18

	schoolyear("D:\\APCS\\CS162\\Week01\\problem19.txt", a, n); //Ex19

	bornmonth("D:\\APCS\\CS162\\Week01\\problem20.txt", a, n); //Ex20

	return 0;
}