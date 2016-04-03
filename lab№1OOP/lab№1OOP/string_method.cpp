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
	//задается строка по умолчанию
	this->lengthString = strlen("String default");
	this->strin = new char[lengthString+1];
	strcpy(strin,"String default");
	tempStr=NULL;
	construct='D';
}

String::String(const char *s)
{
	//вводим строку и перед. как парам.
	CountString++;
	CountStringMy++;
	this->lengthString = strlen(s);
	this->strin = new char[lengthString+1];
	strcpy(strin,s);
	tempStr=NULL;
	construct='P';
}

String::String(const String &t)
{
	//клонируем строку
	CountString++;
	CountStringClone++;
	lengthString=t.lengthString;
	this->strin = new char[lengthString+1];
	strcpy(strin,t.strin);
	tempStr=NULL;
	construct='C';
}

String::~String()
{
	// контрол числа объектов
	CountString--;
	if(construct=='D')
		CountStringDefault--;
	if(construct=='P')
		CountStringMy--;
	if(construct=='C')
		CountStringClone--;

	delete  [] strin;
}

void String::Print()
{
	cout << strin <<" -> ("<<lengthString <<" )"<< endl;
}

void String::SetString(const char *strIn)
{
	//обновляем строку
	delete [] strin;
	this->lengthString = strlen(strIn);
	this->strin = new char[lengthString+1];
	strcpy(strin,strIn);

}


void String::SetlengthString(int length)
{ 
	int len=strlen(strin);
	//обновляем длину строки
	if(length>0 && length<len)
	{
		lengthString= length;
		this->tempStr = new char[lengthString+1];
		//реализуется копирование части строки
		for(int i=0; i< lengthString;i++)
		{
			tempStr[i]=strin[i];
		}
		tempStr[lengthString]='\0';
		delete  [] strin;
		strin=NULL;
		strin=tempStr;
		tempStr=NULL;
	}	
	if(length==len+1)
	{
		lengthString= length;
		this->tempStr = new char[lengthString+1];
		//реализуется копирование части строки
		for(int i=0; i< len;i++)
		{
			tempStr[i]=strin[i];
		}
		tempStr[len]='*';
		tempStr[lengthString]='\0';
		delete  [] strin;
		strin=NULL;
		strin=tempStr;
		tempStr=NULL;
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

char* String:: GetString(){
	return strin;
}

int String:: GetLenght(){
	return lengthString;
}

//-строки равны если равны их длины------------------
bool String::operator == (String &strIn)
{
	if(lengthString == strIn.lengthString )
		return true;
	else
		return false;
}
//объекты являются не равными если операция == вернет false
bool String::operator != (String &strIn)
{
	return !( *this == strIn ); 
}
//реализует сравнение строк---
bool String::operator < (String &strIn)
{
	return ((lengthString < strIn.lengthString) && (strlen(strin) <strlen(strIn.strin))); 
}
//true если только операция == false < false
bool String::operator > (String &strIn)
{
	return !( (*this < strIn) || ( *this == strIn ) ); 

}
// реализуется конкатенация строк
String String ::operator + (String &strIn)
{
	String tmp;
	tmp.lengthString = lengthString + strIn.lengthString;
	tmp.strin=new char [tmp.lengthString+1];
	for(int i=0; strin[i]!='\0';i++)
		tmp.strin[i] =strin[i];
	for(int i=0; strIn.strin[i]!='\0';i++)
		tmp.strin[lengthString + i] =strIn.strin[i];
	tmp.strin[tmp.lengthString]='\0';
	return tmp;
}
// увеличение длины строки, и заполнение строку ‘*’- символом. 
//Возвращает новый статический объект!
String String :: operator ++ (int) {
	String tmp =*this;
	lengthString++;
	this->SetlengthString(lengthString);
	return tmp;
}
// уменьшает длину строки. 
//Возвращает новый статический объект!
String String :: operator -- (int) {
	String tmp= *this;
	lengthString--;
	this->SetlengthString(lengthString);
	return tmp;
}
// уменьшает длину строки. 
//Возвращает ссылку на объект!
String & String :: operator -- () {
	--lengthString;
	this->SetlengthString(lengthString);
	return *this;
}
// увеличивает длину строки. 
//Возвращает ссылку на объект!
String & String :: operator ++ () {
	++lengthString;
	this->SetlengthString(lengthString);
	return *this;
}
//реализует изменение сущ. строки
String & String::operator = (String & inStr)
{
	SetString(inStr.strin);
	return *this;   
}

//вернет длину строки
String::operator int()
{
	return lengthString;
}
//реализует вывод сущ. строки
ostream & operator << (ostream &out, String &obj)
{
	out << obj.lengthString << "<->" << obj.strin << endl;
	return out;
}
//реализует изменение сущ. строки
istream & operator >> (istream &in, String &obj)
{
	char temp[255];
	in.getline(temp,255);
	obj.SetString(temp);
	return in;

}
// шаблон
void String:: View(int k, int pos, bool res,String &str1,String &str2, char *oper ) 
{
	cout << "---------------------------------------------------------------------------"<<endl;
	cout << "str[" << k << "]" << oper<< "str[";cout << pos; cout << "] | ";
	cout << (res? "true  ": "false  ");
	cout << (str1.GetString()) << "  (" << str1.GetLenght();cout << ")" << oper;
	cout << str2.GetString() << "  (" << str2.GetLenght()<< ")"<<endl;

}