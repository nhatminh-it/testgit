/*****Version 1.1***********/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1, int& baseHP2, int& wp1, int& wp2, int& ground)
{
	const char* file_name = "C:/Users/ACER/Downloads/input.txt";
	ifstream in;
	in.open(file_name);
	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;
	in.close();
	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;
	in.close();
	return 1;
}
void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1) {
		cout << fOut;
	}
	else {
		char s[10];
		//sprintf(s, "%.2f", fOut);
		cout << s;
	}
}
//todo
int snt(int n)
{
	int count = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count++;
		}
	}
	if (count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main(void)
{
	int baseHP1, baseHP2, wp1, wp2, ground;
	float fOut = 0.00;
	readFile(baseHP1, baseHP2, wp1, wp2, ground);
	//write your code here
	int realHP1, realHP2;
	if (wp1 == 1) realHP1 = baseHP1;
	if ((wp2 == 1) || (wp2 == 3)) 
		realHP2 = baseHP2;
	if (wp1 == 0) 
		realHP2 = baseHP1 / 10;
	if (wp2 == 0) 
		realHP2 = baseHP2 / 10;
	if ((ground == baseHP1) && (realHP1 * (1.1) <= 999)) {
		realHP1 = realHP1 * 110 / 100;
	}
	else {
		if (ground == baseHP1) realHP1 = 999;
	}
	if ((ground == baseHP2) && (realHP2 * (1.1) <= 999)) {
		realHP2 = realHP2 * 110 / 100;
	}
	else {
		if (ground == baseHP2) realHP2 = 999;
	}
	fOut = float((realHP1 - realHP2 + 999) / 2000);
	if (wp1 == 2 && wp2 == 2) fOut = 0.5;
	else {
		if ((wp1 == 2) && (fOut < 0.5))  fOut = 0.5;
		if ((wp2 == 2) && (fOut > 0.5))  fOut = 0.5;
	}
	if ((wp1 == 3) && (realHP1 * 2 <= 999)) {
		realHP1 = realHP1 * 2;
		fOut = float((realHP1 - realHP2 + 999) / 2000);
	}
	else {
		if (wp1 == 3) realHP1 = 999;
		fOut = float((realHP1 - realHP2 + 999) / 2000);
	}
	if (baseHP2 == 999) fOut = 1;
	if (baseHP1 == 888) fOut = 0.00;
	if ((snt(baseHP1) == 1) && (snt(baseHP2) == 1)) {
		if (baseHP1 == baseHP2) fOut = 0.50;
	}
	else {
		if (snt(baseHP1) == 1) fOut = float(99)/float(100);
		if (snt(baseHP2) == 1) fOut = float(1)/float(100);
	}
	display(fOut);
	system("pause");
	return 0;
}	