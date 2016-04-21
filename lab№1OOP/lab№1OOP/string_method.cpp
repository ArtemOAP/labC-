//---------------string_method.cpp-----------------
#include "string.h"
int String::size=0;
AbstractString** String::AbString=NULL;
int String::CountStringDefault=0;
int String::CountStringClone=0;
int String::CountStringMy=0;
int String::CountString=0;
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
	String::Add(*this);
}

String::String(const char *s)
{
	//вводим строку и перед. как парам.
	CountStringMy++;
	CountString++;
	this->lengthString = strlen(s);
	this->strin = new char[lengthString+1];
	strcpy(strin,s);
	tempStr=NULL;
	construct='P';
	String::Add(*this);

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
	String::Add(*this);
}

String::~String()
{
	//size--;
	CountString--;
	cout<<"String delete!"<<endl;
	// контроль числа объектов
	if(construct=='D')
		CountStringDefault--;
	if(construct=='P')
		CountStringMy--;
	if(construct=='C')
		CountStringClone--;
	Remove(*this);
	delete  [] strin;
	strin=NULL;

}

void String::show()
{    if(CountString>0)
{
	cout << "size=" << size << endl;
	cout << "count string=" << CountString << endl;
	for (int i = 0; i < size; i++)
	{
		if(AbString[i]!=NULL)
		{
			cout <<"["<< i+1 <<"] "<<"->";
			AbString[i]->Print();
		}

	}
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

//реализует перераспределение памяти
void String::del(int n)
{
	if((n>=0) && (n< GetSize()))
	{
		if(AbString[n]!=NULL)
			delete  AbString[n];
	}
}

void String::Add(String &Str)
{
	if(AbString==NULL)
	{
		size=5;
		AbString=new AbstractString* [size];
		for(int i=0;i<size;i++)
			AbString[i]=NULL;
	}

	for(int i=0;i<size;i++)
		if(AbString[i]==NULL)
		{
			AbString[i]=&Str;
			return;
		}
		int newsSize=size*2;
		AbstractString** NewsAbString=new AbstractString* [ newsSize];

		for (int i = 0; i < newsSize; i++)
			if(i<size)
				NewsAbString[i] = AbString[i];
			else
				NewsAbString[i] =NULL;
		NewsAbString[size]=&Str;
		delete [] AbString;
		AbString=NewsAbString;
		size=newsSize;
}

int String:: GetSize()
{
	return size;
}

int String:: GetCountString()
{
	return CountString;
}


AbstractString* String::GetStringAbstr(int i)
{
	return AbString[i];
}


void String::AddStringDefault()
{
	AbstractString* temp= new String();
	temp->Print();
	cout<< "create string Default number=";
	cout<< CountString<<endl;

}

void String::AddMyString(const char *str)
{
	AbstractString* temp=new String(str);
	temp->Print();
	cout<< "create string  number= ";
	cout<< CountString<<endl;
}

void String::delAll()
{
	if(size>0)
	{
		for(int i=0; i<size;i++)
			if(AbString[i]!=NULL)
				delete AbString[i];
		//очистка массива указателей
		delete [] AbString;
		AbString=NULL;
		size=0;
	}
}

void  String::Remove(String &Str)
{
	int i,tempSize=size/2+1,a;
	int newsSize=size/2;
	for( i=0;i<size;i++)
	{
		if(AbString[i]==&Str)
		{
			AbString[i]=NULL;
		}
	}

	if(AbString[size/2 -1]==NULL && AbString[size -1]==NULL)
	{
		for (i=size/2 -1; i<size ; i++)
		{
			if(AbString[i]==NULL)
			{
				--tempSize;
			}
		}
				
		if(!tempSize)
		{
			AbstractString** NewsAbString=new AbstractString* [ newsSize];
			for ( i = 0; i < newsSize; i++)
				NewsAbString[i] = AbString[i];
			delete [] AbString;
			AbString=NewsAbString;
			size=newsSize;
		}
	}

}