//---------------string_method.cpp-----------------
#include "string.h"
int String::CountString=0;
int String::CountStringDefault=0;
int String::CountStringClone=0;
int String::CountStringMy=0;

String::String()
{
	CountString++;
	CountStringDefault++;
	this->lengthString = strlen("String default");
	this->str = new char[lengthString+1];
	strcpy(str,"String default");
}

String::String(const char *s)
{
	CountString++;
	CountStringMy++;
	this->lengthString = strlen(s);
	this->str = new char[lengthString+1];
	strcpy(str,s);
}

String::String(const String &t)
{
	CountString++;
	CountStringClone++;
	lengthString=t.lengthString;
	this->str = new char[lengthString];
	strcpy(str,t.str);

}

String::~String()
{
	CountString--;
	//delete  [] str;
	//delete [] temp;

}

void String::Print()
{
	cout << str << endl;
	cout << lengthString << endl;

}

void String::SetString(const char *strIn)
{
	delete [] str;
	str=NULL;
	this->lengthString = strlen(strIn);
	this->str = new char[lengthString+1];
	strcpy(str,strIn);
}


void String::SetlengthString(int length)
{

	if(length>0 && length<lengthString)
	{
		lengthString= length;
		this->temp = new char[lengthString];
		for(int i=0; i< lengthString;i++)//реализуется копирование части строки
		{
			temp[i]=str[i];
		}
		temp[lengthString]='\0';
		this->str = new char[lengthString];
		strcpy(str,temp);

	}	
}

int  String::GetCount()
{
	return CountString;
}
int String:: GetCountStringMy()
{
	return CountStringMy;
}

int String:: GetCountStringDefault()
{
	return CountStringDefault;
}

int String:: GetCountStringClone()
{
	return CountStringClone;
}
//-------------------------------------------------------