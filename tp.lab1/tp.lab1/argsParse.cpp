#define _CRT_SECURE_NO_WARNINGS 1
#include "argsParse.h"
using namespace std;
unsigned short argsParsing::getCMNDArg(char *procA)
{
	for (int i = 0; i < strlen(procA); i++){
		procA[i] = tolower(procA[i]);
	}
	if (strcmp(procA, "generate") == 0 || strcmp(procA, "create") == 0){
		return 1;
	}
	if (strcmp(procA, "del") == 0 || strcmp(procA, "delete") == 0){
		return 2;
	}
	if (strcmp(procA, "rename") == 0){
		return 3;
	}
	if (strcmp(procA, "copy") == 0){
		return 4;
	}
	if (strcmp(procA, "dirgen") == 0){
		return 5;
	}
	if (strcmp(procA, "rd") == 0){
		return 6;
	}
	if (strcmp(procA, "dircopy") == 0){
		return 7;
	}
	if (strcmp(procA, " ") == 0 || strcmp(procA, "") == 0){
		cout << "EMPTY_ARGS \t First argument [" << procA << "]\t First letter is " << *procA << "\n";
		return 8;
	}
	if (strcmp(procA, "isexist") == 0) {
		return 9;
	}
	if (strcmp(procA, "abz") == 0) {
		return 10;
	}
	if (strcmp(procA, "list") == 0) {
		return 404;
	}
	return 0;
}