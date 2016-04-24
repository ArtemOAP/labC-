#include "string.h"
#include "template.h"
#include <iomanip>
void main()
{
	
	String *p;
	ListString<String> list;	
	int number, count;
	char c = 0;
	while (c != '0')
	{
		cin.clear();
		cin.sync();
		cout<<endl;
		cout << "1. add new string in end list---------------" << endl;
		cout << "2. add new string in position---------------" << endl;
		cout << "3. del string-------------------------------" << endl;
		cout << "4. show string------------------------------" << endl;
		cout << "5. Clear  list------------------------------" << endl;
		cout << "6. Show All String--------------------------" << endl;
		cout << "0. exit-------------------------------------" << endl;
		cin >> c;
		switch (c)
		{
		case '0':NULL;
			break;

		case '1':
			cout << "add new string in end list" << endl;
			cin.ignore();
			p=String::Create();
			cin >> *p;
			count = list.AddElemString(*p);
			cout << "Create [" << count << "] string " << *p << endl;
			break;

		case '2':
			cout << "add new string in position" << endl;
			cout << "input position: ";
			cin >> number;
			p=String::Create();
			cin.ignore();
			cin >> *p;			
			number = list.AddElemString(*p,number);
			if (number == -1)
				cout << "Error number undefined--------" << endl;
			else
				cout << "Create [" << count << "] string " << *p << endl;
			break;

		case '3':
			cout << "3. del string-------------------------------" << endl;
			cout << "input position: ";
			cin >> number;
			number = list.DeleteElemString(number);
			if (number == -1)
				cout << "Error number undefined--------" << endl;
			else
				cout << "del " << number << "string!" << endl;
			break;

		case '4':
			cout << "4. show string------------------------------" << endl;
			cout << "input position: ";
			cin >> number;
			p = list.GetString(number);
			if (p == NULL)
				cout << "Error number undefined--------" << endl;
			else
				cout << "[" << number << "] " << *p << endl;
			break;

		case '5':
			cout << "5. Clear  list------------------------------" << endl;
			list.ClearListString();
			cout << "list clear!-----------------" << endl;
			break;
		
		case '6':
			cout << "6. Show All String--------------------------" << endl;
			list.ShowListString();
			break;
		}
	}

}