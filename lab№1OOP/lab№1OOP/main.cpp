#include "string.h"
#include "template.h"
#include <iomanip>
void main()
{

	String p;
	//int p=5;
	//ListString<int> list;	
	ListString<String> list;
	int number, count;
	char c = 9;
	while (c != '0')
	{
		cin.clear();
		cin.sync();
		cout<<endl;
		cout << "1. add new string in end list---------------" << endl;
		cout << "2. add new string in position---------------" << endl;
		cout << "3. show string------------------------------" << endl;
		cout << "4. Show All String--------------------------" << endl;
		cout << "5. del string-------------------------------" << endl;
		cout << "6. Clear  list------------------------------" << endl;
		cout << "0. exit-------------------------------------" << endl;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "input string:" << endl;
			cin.ignore();
			cin >> p;
			count = list.AddElemString(p);
			cout << "Create [" << count << "] string " << p << endl;
			break;
		case '2':
			cout << "input position: ";
			cin >> number;
			number = list.AddElemString(p,number);
			if (number == NULL)
			{
				cout << "Error number undefined--------" << endl;
				break;
			}
			cout << "input string: ";
			cin.ignore();
			cin >> p;			
			cout << "Create [" << count << "] string " << p << endl;
			break;
		case '3':
			cout << "input position: ";
			cin >> number;
			if (list.GetString(number) == NULL)
				cout << "Error number undefined--------" << endl;
			else
				cout << "[" << number << "] " << *(list.GetString(number)) << endl;
			break;
		case '4':
			cout << "All String:{" << endl;
			list.ShowListString();
			cout << "}---------------------" << endl;
			break;
		case '5':
			cout << "input position for delete: ";
			cin >> number;
			number = list.DeleteElemString(number);
			if (number == NULL)
				cout << "Error number undefined!" << endl;
			else
				cout << "del {" << number << "} string!" << endl;
			break;
		case '6':
			cout << "\n Clear  list!" << endl;
			list.ClearListString();
			cout << "\nlist clear!------" << endl;
			break;
		case '0':list.ClearListString();
			break;
		}

	}

}