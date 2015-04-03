#define _CRT_SECURE_NO_WARNINGS 1
#include "argsParse.h"
#include "filew.h"

#include <Windows.h>
#include <iostream>
#include <string>



using namespace std;


void filew::fcreate()
{
		char *temp = new char[strlen(fname1)+1];
		strcpy(temp, fname1);
		int i = strlen(temp) - 1;
		while (temp[i] != '\\')
		{
			i--;
		}
		i++;
		temp[i] = '\0';
		if (_access(fname1, 0)&&!_access(temp,0))
		{
			ofstream desc(fname1);
		}
		else
			cout << "Cant create file" << endl;
		delete temp;
}
void filew::fdelete()
{
		char *temp = new char[strlen(fname1) + 10];
		strcpy(temp,"DEL \"");
		strcat(temp, fname1);
		strcat(temp,"\" /q");
		if (!_access(fname1, 0))
		{
			if (system(temp)!=0)	
			cout << "unsuccessful system calling" << endl;
		}
		else
			cout << "file not found" << endl;
		delete temp;
}
void filew::fcopy()
{
		char *temp = new char[strlen(fname1) + strlen(fname2) + 19];
		strcpy(temp,"COPY \"");
		strcat(temp, fname1);
		strcat(temp, "\" \"");
		strcat(temp,fname2);
		strcat(temp, "\"");
		char *temp2 = new char[strlen(fname1)];
		strcpy(temp2, fname1);
		int i = strlen(temp2) - 1;
		while (temp2[i] != '\\')
		{
			i--;
		}
		i++;
		temp2[i] = '\0';
		if (_access(fname2, 0) && !_access(fname1, 0) && !_access(temp2, 0))
		{
			if (system(temp) != 0)
				cout << "unsuccessful system calling" << endl;
		}
		else
			cout << "cant copy file or first file not found" << endl; 
		delete temp, temp2;
}
void filew::frename()
{
		if (rename(fname1, fname2) != 0)
			cout << "rename error" << endl; return;
}

bool filew::fsearch(string filePath){
		bool isExist = false;
		char *repMes;
		ifstream fin(filePath.c_str());
		if (fin.is_open())isExist = true;
		if (isExist == true) repMes=" YES_FILE_EXISTS";
		else repMes = " FILE_NOT_FOUND";
		cout << "\n WAY TO SEARCH " << filePath.c_str() << "\t";
		cout << "\n IS FILE EXIST? => " << repMes << "\n";
		fin.close();
		return isExist;
}


void filew::funcswitch(char *fproc, char *str1, char *str2, filew *file, int argentum)
{
	fname1 = str1;
	fname2 = str2;
	char proc[6]; proc[0] = 'e';
	*proc = *fproc;
	argsParsing *argsMASS = new argsParsing;

	
	
	switch (argsMASS->getCMNDArg(fproc))
	{
	case 1:{if (argentum < 3){ cout << "second argument error" << endl; break; } file->fcreate(); break; }
	case 2:{if (argentum < 3){ cout << "second argument error" << endl; break; }file->fdelete(); break; }
	case 3:{if (argentum < 4){ cout << "second argument error" << endl; break; }file->frename(); break; }
	case 4:{if (argentum < 4){ cout << "second argument error" << endl; break; }file->fcopy(); break; }
	case 5:{if (argentum < 3){ cout << "second argument error" << endl; break; }file->dcreate(); break; }
	case 6:{if (argentum < 3){ cout << "second argument error" << endl; break; }file->ddelete(); break; }
	case 7:{if (argentum < 4){ cout << "second argument error" << endl; break; }file->dcopy(); break; }
	case 8: {cout << "command was not given" << endl; break; }
	case 9:{if (argentum < 3){ cout << "second argument error" << endl; break; }file->fsearch(str1); break; }
	case 10: {cout << "______________________________________________________\n\n"; break; }
	case 404:{if (argentum < 3){ cout << "second argument error" << endl; break; }file->getfilelist(); break; }
	case 0: {cout << "wrong command was given" << endl; break; }

	default: {cout << "illegal command not found" << endl; break; }
	}
	delete argsMASS;
}

void filew::dcreate()
{
	char *temp = new char[strlen(fname1) + 10];
	strcpy(temp, "MKDIR \"");
	strcat(temp, fname1);
	strcat(temp, "\"");
	if (_access(fname1, 0))
	{
		if (system(temp) != 0)
			cout << "unsuccessful system calling" << endl;
	}
	else
		cout << "directory already exists" << endl;
	delete temp;
}
void filew::ddelete()
{
	fdelete();
	char *temp = new char[strlen(fname1) + 10];
	strcpy(temp, "RMDIR \"");
	strcat(temp, fname1);
	strcat(temp, "\"");
	if (!_access(fname1, 0))
	{
		if (system(temp) != 0)
			cout << "unsuccessful system calling" << endl;
	}
	else
		cout << "directory not found" << endl;
	delete temp;
}
void filew::dcopy()
{

	char *temp = new char[strlen(fname1) + strlen(fname2) + 19];
	strcpy(temp, "MKDIR \"");
	strcat(temp, fname2);
	strcat(temp, "\"");
	if (system(temp) != 0)
		cout << "unsuccessful system calling" << endl;
	strcpy(temp, "COPY \"");
	strcat(temp, fname1);
	strcat(temp, "\" \"");
	strcat(temp, fname2);
	strcat(temp, "\"");
	if (system(temp) != 0)
		cout << "unsuccessful system calling" << endl;
	delete temp;
}

void filew::getfilelist()
{
	
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	list<string> uselesslist;
	char *temp = new char[strlen(fname1) + 3];
	strcpy(temp, fname1);
	strcat(temp, "\\*");
	hf = FindFirstFile(temp, &FindFileData);
	delete temp;
	
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			
			
			if (FindFileData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY){
				cout << "DIRECTORY " << FindFileData.cFileName << " " << endl;
			}
			else{
				cout << "NON_DIRECTORY " << FindFileData.cFileName << " " << endl;
				uselesslist.push_back(FindFileData.cFileName);
			}


		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	
	
	uselesslist.sort();

	cout << endl;
	copy(uselesslist.begin(), uselesslist.end(), ostream_iterator<string>(cout, "\n"));
	cout << endl;
	uselesslist.reverse();
	copy(uselesslist.begin(), uselesslist.end(), ostream_iterator<string>(cout, "\n"));
}