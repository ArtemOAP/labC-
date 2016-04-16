//------------------------string.h-----
#include <iostream>
using namespace std;

class AbstractString
{	 
public:
	virtual void Print()=0;
	virtual  void SetlengthString(int)=0;
	virtual  void SetString(const char *strIn)=0;
	virtual ~AbstractString(){
	cout<<"memory clear"<<endl;
	};
};

class String : public AbstractString
{
	int lengthString;
	char *strin;
	char *tempStr;
	char construct;
	static int CountStringMy;
	static int CountStringDefault;
	static int CountStringClone;
	static AbstractString** AbString;
	void static  Add(AbstractString*);
	 static int size;
public:
	String();
	String(const char *str);
	String(const String &t);
	virtual ~String();
	virtual void Print();
	virtual void SetlengthString(int);
	virtual void SetString(const char *strIn);
	static AbstractString* GetStringAbstr(int i);
	static void AddStringDefault();
	static void AddMyString(const char *str);
	static void AddClone(const String &t);
	static void delAll();

	static void show();
	static void del(int n);
	int static GetCountStringMy();
	int static GetCountStringDefault();
	int static GetCountStringClone();
	int static GetSize();
	char* GetString();
	int GetLenght();
	void static View(int k, int pos, bool res,String &str1,String &str2, char *oper);
	//-------------------------------//
};
//---------------------------------------------//





