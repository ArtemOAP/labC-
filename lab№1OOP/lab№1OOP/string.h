//------------------------string.h-----
#include <iostream>
using namespace std;


class String 
{
	int lengthString;
	char *strin;
	char *tempStr;
	char construct;
	static int CountStringMy;
	static int CountStringDefault;
	static int CountStringClone;

public:
	String();
	String(const char *str);
	String(const String &t);
	virtual ~String();
	void Print();
	void SetlengthString(int);
	void SetString(const char *strIn);
	int static GetCountStringMy();
	int static GetCountStringDefault();
	int static GetCountStringClone();
	int static GetSize();
	char* GetString();
	int GetLenght();
	friend ostream & operator << (ostream &out, String &obj);
	friend istream & operator >> (istream &in, String &obj);
	String & operator = (const String & inStr);
	static String *  Create();
};
//---------------------------------------------//





