//---------------string_method.cpp-----------------
#include "string.h"
int String::CountStringDefault=0;
int String::CountStringClone=0;
int String::CountStringMy=0;

String::String()
{
	CountStringDefault++;
	//�������� ������ �� ���������
	this->lengthString = strlen("String default");
	this->strin = new char[lengthString+1];
	strcpy(strin,"String default");
	tempStr=NULL;
	construct='D';
}

String::String(const char *s)
{
	//������ ������ � �����. ��� �����.
	CountStringMy++;
	this->lengthString = strlen(s);
	this->strin = new char[lengthString+1];
	strcpy(strin,s);
	tempStr=NULL;
	construct='P';	
}

String::String(const String &t)
{
	//��������� ������
	CountStringClone++;
	lengthString=t.lengthString;
	this->strin = new char[lengthString+1];
	strcpy(strin,t.strin);
	tempStr=NULL;
	construct='C';
	
}

String::~String()
{
	
	cout<<"String delete!"<<endl;
	// �������� ����� ��������
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
	//��������� ������
	delete [] strin;
	this->lengthString = strlen(strIn);
	this->strin = new char[lengthString+1];
	strcpy(strin,strIn);
}

void String::SetlengthString(int length)
{ 
	int len=strlen(strin);
	//��������� ����� ������
	if(length>0 && length<len)
	{
		lengthString= length;
		this->tempStr = new char[lengthString+1];
		//����������� ����������� ����� ������
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

ostream & operator << (ostream &out, String &obj)
{
	out << obj.lengthString << "<->" << obj.strin << endl;
	return out;
}

istream & operator >> (istream &in, String &obj)
{
	char temp[255];
	in.getline(temp,255);
	obj.SetString(temp);
	return in;

}
String * String::Create()
{
	return new String();


}