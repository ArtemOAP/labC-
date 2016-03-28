//------------------------string.h-----
#include <iostream>
using namespace std;

class String
{
	int lengthString;
	char *str;
	char *temp;
	static int CountString;
	static int CountStringMy;
	static int CountStringDefault;
	static int CountStringClone;

public:
	String();
	String(const char *str);
	String(const String &t);
	~String();
	void Print();
	void SetlengthString(int);
	void SetString(const char *strIn);
	int static GetCount();
	int static GetCountStringMy();
	int static GetCountStringDefault();
	int static GetCountStringClone();
};
//---------------------------------------------





