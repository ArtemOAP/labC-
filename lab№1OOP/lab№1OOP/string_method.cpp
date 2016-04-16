//---------------string_method.cpp-----------------
#include "string.h"
int String::size=0;
AbstractString** String::AbString=NULL;
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
	size--;
	cout<<"String delete!"<<endl;
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
{    if(size>0)
{
	cout << "size=" << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout <<"№"<< i+1 << "->";
		AbString[i]->Print();
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
		AbstractString** NewsAbString=new AbstractString* [size-1];
		int count=size;
		for(int i=0; i<n;i++)
			NewsAbString[i] = AbString[i];
		for(int i=n; i<count-1;i++)
			NewsAbString[i] = AbString[i+1];
		//вызов деструктора
		delete AbString[n];
		delete [] AbString;
		AbString=NULL;
		AbString=NewsAbString;
		NewsAbString=NULL;
		
	}


}

void String::Add(AbstractString* AbStr)
{
	//реализуем создание (добавление) указателей на объект базового класса
	AbstractString** NewsAbString=new AbstractString* [size+1];
	for (int i = 0; i < size; i++)
		NewsAbString[i] = AbString[i];
	NewsAbString[size] = AbStr;
	if (AbString != NULL)
		delete[] AbString;
	AbString = NewsAbString;
	size++;

}

int String:: GetSize()
{
	return size;
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
	cout<< GetSize()<<endl;

}

void String::AddMyString(const char *str)
{
	AbstractString* temp=new String(str);
	temp->Print();
	cout<< "create string  number= ";
	cout<< GetSize()<<endl;
}

void String::delAll()
{
	if(size>0)
	{
		int count=size;
		for(int i=0; i<count;i++)
			//вызов деструктора для каждого
			delete AbString[i];
		//очистка массива указателей
		delete [] AbString;
		AbString=NULL;
	}
}