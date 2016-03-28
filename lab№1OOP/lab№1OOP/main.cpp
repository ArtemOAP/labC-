#include "string.h"
#include <iomanip>
void main()
{
	char strInp[255],position='9'; //строка дл€ ввода и переменна€ дл€ перемещени€ по меню
	int countString=0,CountStringdefault=0, item=0; 
	int CountStringMy=0, CountStringClone=0, lenghtString=0,k,count=0;
	cout << setw(40) <<  "1-------Count all String----------" << endl;
	cin>>countString;
	if(countString>0)
	{
		String **str = new String*[countString];

		while (true)
		{
			cin.clear();
			cin.sync();
			cout << setw(40) <<  "1-------Create String----------" << endl;
			cout << setw(40) <<  "q-------------(0)exit------------" << endl;
			position=cin.get();
			cin.clear();
			if(position=='0') break;
			if(position=='1') 
			{
				while (position!='0')
				{	
					cout << setw(40) <<  "--Count string default-------=";
					cin>>CountStringdefault;
					cout << endl;
					if(CountStringdefault>0 && countString-CountStringdefault>=0 )
					{
						countString-=CountStringdefault;
						count=String::GetCount()+CountStringdefault;
						if(String::GetCount()>0)
						{
							k=String::GetCount();
						}
						else
						{
							k=0;
						}

						for(int i=k;i<count;i++)
						{
							cout <<"String ["<<i<<"]"<<endl;
							str[i] = new String();
						}
						count=0;
						CountStringdefault=0;
						cout << setw(40) <<  "--------------all String Default! =";
						cout << String:: GetCountStringDefault();
						cout<<endl;
					}
					else
					{
						CountStringdefault=0;
						cout << setw(40) <<  "------------OK! all String Default! =";
						cout << String:: GetCountStringDefault();
						cout<<endl;
					}
					cin.clear();
					cin.get();
					cout << setw(40) <<  "- Count My string------------=" ;
					cin>>CountStringMy;
					cout<<endl;

					if(CountStringMy>0 && countString-CountStringMy>=0)
					{
						countString-=CountStringMy;
						count=String::GetCount()+CountStringMy;
						cin.ignore();
						if(String::GetCount()>0)
						{
							k=String::GetCount();
						}

						else
						{
							k=0;
						} 

						for(int i=k;i<count;i++)
						{

							cout <<"Input String ["<<i<<"]"<<endl;
							cin.getline(strInp,255);
							str[i] = new String(strInp); 

						}
						count=0;
						CountStringMy=0;
						cout << setw(40) <<  "--------- all My! ="; 
						cout << String:: GetCountStringMy();
						cout<<endl;
					}
					cin.clear();
					cin.get();
					cout << setw(40) <<  "-----count clone-------------->";
					cin>>CountStringClone;
					cout<<endl;
					if(String::GetCount()>0 && CountStringClone>0 && countString-CountStringClone>=0)
					{
						countString-=CountStringClone;
						count=String::GetCount()+CountStringClone-1;
						cin.clear();
						if(String::GetCount()>0)
						{
							k=String::GetCount();
						}
						else
						{
							k=0;
							count-=1;
						}

						for(int i=k;i<=count;i++)
						{
							cout << setw(45) <<"String clone ["<<i<<"]-->";
							cin>>k;
							if(k<0 || k>String::GetCount())
								break;
							str[i] = new String( * str[k]);
						}
						count=0;
						CountStringClone=0;
						cout << setw(40) <<  "-OK! all clone! ="; 
						cout << String:: GetCountStringClone();
						cout<<endl;
					}
					else
					{
						CountStringClone=0;
						cout << setw(40) <<  "--------------OK! clone! ="; 
						cout << (String:: GetCountStringClone());
						cout<<endl;
					}
					cin.clear();
					cin.get();
					cout << setw(40) <<  "--------Create My String------->"; 
					cout <<String:: GetCountStringMy()<< endl;
					cout << setw(40) <<  "---------- string default------>";
					cout <<String:: GetCountStringDefault()<< endl;
					cout << setw(40) <<  "---------- string clone-------->" ;
					cout <<String:: GetCountStringClone()<< endl;
					cout << setw(40) <<  "----------All create string---->" ;
					cout << String:: GetCount()<<endl;
					cout << setw(40) <<  "any key--------next-------------" << endl;
					cout << setw(40) <<  "------------(0)exit-------------" << endl;
					position=cin.get();
					if(position=='0') break;
					cin.ignore();
					cin.clear();

					while (position!='6' && (String::GetCount()>0))
					{

						cin.clear();
						cin.sync();
						cout << setw(40) <<  "1--------select String-------------"<< endl;
						cout << setw(40) <<  "2-------updata String--------------"<< endl;
						cout << setw(40) <<  "3-------updata lenght String-------"<< endl;
						cout << setw(40) <<  "4-------delete String--------------"<< endl;
						cout << setw(40) <<  "5------Select All String-----------"<< endl;
						cout << setw(40) <<  "6-------------(0)exit--------------" << endl;
						position=cin.get();

						switch (position)
						{
						case '1':

							cout << setw(40) <<  "---select String item=" << endl;
							cin>>item;
							item=(int)item;
							cout<<endl;
							if((item>=0) && (item<=(String::GetCount())))
							{
								str[item]->Print();
								cin.clear();
								cin.sync();
								cin.get();
							}
							break;
						case '2':
							cout << setw(40) <<  "--------updata String item=";
							cin>>item;
							item=(int)item;
							cout<<endl;
							if((item>=0) && (item<=(String::GetCount())))
							{
								cin.ignore();
								cout << setw(40) <<  "--------input String-------"<< endl;
								cin.getline(strInp,255);
								str[item]->SetString(strInp);
							}
							break;
						case '3':
							cout << setw(40) <<  "--------updata lenght String item=";
							cin>>item;
							cout<<endl;
							item=(int)item;
							if((item>=0) && (item<=(String::GetCount())))
							{
								cin.clear();
								cin.sync();
								cout<<endl;
								cin>>lenghtString;
								str[item]->SetlengthString(lenghtString);
								lenghtString=0;
							}
							break;
						case '4':
							cout << setw(40) <<  "4-------delete String-item=";
							cin>>item;
							cout<<endl;
							item=(int)item;
							if((item>=0) && (item<=(String::GetCount())))
							{
								String **temp=new String*[String::GetCount()-1];
								count=String::GetCount();
								for(int i=0; i<item;i++)
									temp[i]=str[i];
								for(int i=item; i<count;i++)
									temp[i]=str[i+1];
								delete  str[item];
								delete [] str;
								str=NULL;
								str=temp;

							}
							break;
						case '5':
							cout << setw(40) << "-------------------------"<<endl;
							k=String::GetCount();
							for(int i=0; i<k; i++)
							{
								cout << setw(40) << "-------------str[";
								cout << i ;
								cout <<"]"<<endl;
								str[i]->Print();
								cout << setw(40) << "-------------------------"<<endl;
							}
							break;


							if(position=='0') break;
						}
						if(position=='0') break;
					} 
					if(position=='0') break;
				}
				if(position=='0') break;	
			}

		}

		count=String::GetCount();

		if(count>0)
		{
			for(int i=0; i<count; i++)
				delete  str[i];

			delete [] str;
		}
	}
	cin.get();

}