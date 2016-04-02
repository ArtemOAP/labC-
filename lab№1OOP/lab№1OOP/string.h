//------------------------string.h-----
#include <iostream>
using namespace std;

class String
{
	int lengthString;
	char *strin;
	char *tempStr;
	static int CountString;
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
	int static GetCount();
	int static GetCountStringMy();
	int static GetCountStringDefault();
	int static GetCountStringClone();
	char* GetString();
	int GetLenght();
	//-------------------------------//
	bool operator == (String &strIn);
	bool operator != (String &strIn);
	bool operator < (String &strIn);
	bool operator > (String &strIn);
	String operator + (String &strIn);
	String operator ++ (int);
	String & operator ++ ();
	String & operator -- ();
	String  operator -- (int);
	String & operator = (String & inStr);
	operator int();
	friend ostream& operator << (ostream &out, String &obj);
	friend istream& operator >> (istream &in, String &obj);
};
//---------------------------------------------//





