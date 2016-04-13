//------------------------string.h-----
#include <iostream>
using namespace std;

class AbstractString
{
public:
	virtual void Print()=0;
	virtual  void SetlengthString(int)=0;
	virtual  void SetString(const char)=0;
	virtual ~AbstractString(){};
};




class String : public AbstractString
{
	int lengthString;
	char *strin;
	char *tempStr;
	char construct;
	static int CountString;
	static int CountStringMy;
	static int CountStringDefault;
	static int CountStringClone;

public:
	String();
	String(const char *str);
	String(const String &t);
	virtual ~String();
	virtual void Print();
	virtual void SetlengthString(int);
	virtual void SetString(const char *strIn);
	int static GetCount();
	int static GetCountStringMy();
	int static GetCountStringDefault();
	int static GetCountStringClone();
	char* GetString();
	int GetLenght();
	void static View(int k, int pos, bool res,String &str1,String &str2, char *oper);
	//-------------------------------//
	
};
//---------------------------------------------//





