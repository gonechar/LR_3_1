#include <iostream>
#include <fstream>
#include "io.h"
#include "windows.h"
#include <list>
#include <iterator> 
#include <string>
using namespace std;
class filew
{
private:
	char *fname1, *fname2;
protected:
	void fcreate();
	void fdelete();
	void fcopy();
	void frename();
	void dcreate();
	void ddelete();
	void dcopy();
	void getfilelist();
	bool fsearch(std::string);
public:
	filew(){}
	~filew(){}
	void funcswitch(char *,char *,char*,filew *,int);
};
