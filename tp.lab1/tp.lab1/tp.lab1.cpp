#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include "io.h"
#include "filew.h"
using namespace std;
int main(int argc,char *argv[])
{
	filew *file=new filew;
	if (argc < 2) { 
		cout << "not enough arguments" << endl; 
		return -1; 
	}
	if (argc > 4) {
		cout << "too much arguments" << endl;
		return -1;
	}
	file->funcswitch(argv[1], argv[2], argv[3], file, argc);
	delete file;
	return 0;
}
