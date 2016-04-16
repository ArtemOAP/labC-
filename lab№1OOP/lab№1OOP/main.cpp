#include "string.h"
#include <iomanip>
void main()
{
	char c = 0;
	AbstractString* temp;
	char strInp[255],position='9'; 
	int i;
	int countString=0,CountStringdefault=0,count=0,k;

	while (c != '0')
	{
		cin.clear();
		cin.sync();
		cout<<endl;
		cout << "-------------menu--------------:" << endl;
		cout << "1---add String default----------" << endl;
		cout << "2---add New String--------------" << endl;
		cout << "3---update String---------------" << endl;
		cout << "4---update lenght String--------" << endl;
		cout << "5---Delete----------------------" << endl;
		cout << "6---Show All String-------------" << endl;
		cout << "7---Delete All------------------" << endl;
		cout << "0---exit------------------------" << endl;
		cin >> c;
		switch (c)
		{
		case '1':
			String::AddStringDefault();

			break;
		case '2':
			cin.ignore();
			cout <<"Input String:"<<endl;
			cin.getline(strInp,255);
			String::AddMyString(strInp);
			break;
		case '3':
			if(String::GetSize()==0)
				break;
			cout <<"Input nuber String=";
			cin>>i;
			i=(int)i;
			if(i<1 || i>String::GetSize())
				break;
			temp=String::GetStringAbstr(i-1);
			cin.ignore();
			cout <<"Input String:"<<endl;
			cin.getline(strInp,255);
			temp->SetString(strInp);
			temp->Print();

			break;
		case '4':
			if(String::GetSize()==0)
				break;
			cout <<"Input nuber String=";
			cin>>i;
			i=(int)i;
			if(i<1 || i>String::GetSize())
				break;
			temp=String::GetStringAbstr(i-1);
			cout <<"Input lenght=";
			cin>>i;
			i=(int)i;
			if(i==0)
				break;
			temp->SetlengthString(i);
			temp->Print();
			break;

		case '5':
			if(String::GetSize()==0)
				break;
			cout << "Number delete string= ";
			cin >> i;
			i=(int)i;
			if(i>0 && i<=String::GetSize())
				String::del(i-1);
			break;
		case '6':
			if(String::GetSize()==0)
				break;
			String::show();
			break;
		case '7':
			String::delAll();
			break;
		}
	}
	String::delAll();
}