//---------------string_method.cpp-----------------
#include "string.h"
int String::size=0;
AbstractString** String::AbString=0;
int String::CountStringDefault=0;
int String::CountStringClone=0;
int String::CountStringMy=0;

String::String()
{
	CountStringDefault++;
	//задается строка по умолчанию
	this->lengthString = strlen("String default");
	this->strin = new char[lengthString+1];
	strcpy(strin,"String default");
	tempStr=NULL;
	construct='D';
	String::Add(this);
}

String::String(const char *s)
{
	//вводим строку и перед. как парам.
	CountStringMy++;
	this->lengthString = strlen(s);
	this->strin = new char[lengthString+1];
	strcpy(strin,s);
	tempStr=NULL;
	construct='P';
	String::Add(this);

}

String::String(const String &t)
{
	//клонируем строку
	CountStringClone++;
	lengthString=t.lengthString;
	this->strin = new char[lengthString+1];
	strcpy(strin,t.strin);
	tempStr=NULL;
	construct='C';
	String::Add(this);
}

String::~String()
{
	if (size == 1)
	{
		//	delete this;
		if (AbString != NULL)
			delete AbString;
		AbString = NULL;
		size--;
	}
	if (size - 1 > 0)
	{
		AbstractString** NewsAbString=new AbstractString* [size-1];
		for (int i = 0, j = 0; i < size; i++)
			if (AbString[i] != this)
				NewsAbString[j++] = AbString[i];
		delete[] AbString;
		AbString = NewsAbString;
		size--;
	}

	// контрол числа объектов
	if(construct=='D')
		CountStringDefault--;
	if(construct=='P')
		CountStringMy--;
	if(construct=='C')
		CountStringClone--;

	delete  [] strin;
}

void String::show()
{
	cout << "size=" << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout <<"№"<< i << "->";
		AbString[i]->Print();
	}
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


void String::del(int n)
{
	if(n>=0 && n<size)
		delete AbString[n];
}

void String::Add(AbstractString* AbStr)
{
	//реализуем создание (добавление) указателей на объект базового класса
	AbstractString** NewsAbString=new AbstractString* [size+1];
	for (int i = 0; i < size; i++)
		NewsAbString[i] = AbString[i];
	NewsAbString[size++] = AbStr;
	if (AbString != NULL)
		delete[] AbString;
	AbString = NewsAbString;

}