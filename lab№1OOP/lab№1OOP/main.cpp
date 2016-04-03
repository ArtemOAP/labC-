#include "string.h"
#include <iomanip>
void main()
{
	//строка для ввода и переменная для перемещения по меню
	char strInp[255],position='9'; 
	int countString=0,CountStringdefault=0, item=0; 
	int CountStringMy=0, CountStringClone=0, lenghtString=0,k,count=0,i,j;
	cout << setw(40) <<  "1-------Count all String----------" << endl;
	cin>>countString;
	if(countString>0)
	{
		String **str = new String*[countString];

		while (true)// реализация меню
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
				while (position!='0')//подменю
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
						cout << setw(40) <<  "--------- all My! ="<< String:: GetCountStringMy();
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
					cout << setw(40) <<  "press--any---key-for-next-------" << endl;
					cout << setw(40) <<  "------------(0)exit-------------" << endl;
					position=cin.get();
					if(position=='0') break;
					cin.ignore();
					cin.clear();

					while (position!='7' && (String::GetCount()>0))
					{

						cin.clear();
						cin.sync();
						cout << setw(40) <<  "1--------select String-------------"<< endl;
						cout << setw(40) <<  "2-------update String--------------"<< endl;
						cout << setw(40) <<  "3-------update lenght String-------"<< endl;
						cout << setw(40) <<  "4-------delete String--------------"<< endl;
						cout << setw(40) <<  "5------Select All String-----------"<< endl;
						cout << setw(40) <<  "6------Next operation--------------"<< endl;
						cout << setw(40) <<  "--------------(0)exit--------------" << endl;
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
							if((item>=0) && (item< (String::GetCount())))
							{
								String **temp=new String*[String::GetCount()-1];
								count=String::GetCount();
								for(int i=0; i<item;i++)
									temp[i]=str[i];
								for(int i=item; i<count-1;i++)
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
								cout << setw(40) << "-------------str["<< i<<"]"<<endl;
								str[i]->Print();
								cout << setw(40) << "-------------------------"<<endl;
							}
							break;
						case '6':
							while(position!='9' && (String::GetCount()>0))
							{
								cin.clear();
								cin.sync();
								cout << setw(40) <<"-------operations--------"<<endl;
								cout << setw(40) <<"1------ ==  >  < --------"<<endl;
								cout << setw(40) <<"2------str[i]+str[j]-----"<<endl;
								cout << setw(40) <<"3----(++/--str[i]++/--)--"<<endl;
								cout << setw(40) <<"4----|str[i]=str[j]|-----"<<endl;
								cout << setw(40) <<"5------|(int)str[j]|-----"<<endl;
								cout << setw(40) <<"6------|<<str[j]|--------"<<endl;
								cout << setw(40) <<"7------|>>str[j]|--------"<<endl;
								cout << setw(40) << "-----------(0)exit------"<< endl;
								cout << setw(40) << "<-----------9-----------"<< endl;
								position=cin.get();
								if(position=='0') break;
								cin.clear();
								switch (position)
								{
								case '1':
									while(position!='q'){
										cin.clear();
										cin.sync();
										cout << setw(40) << "-select pattern str[?] where k=";
										cin>>k;
										cout <<endl;
										k=((int)k>(String::GetCount()-1))?(String::GetCount()-1):(int)k;
										cout << setw(40) << "---- str[?] input i:=";
										cin>>i;
										cout <<endl;
										i=((int)i>(String::GetCount()-1))?(String::GetCount()-1):(int)i;
										cout << setw(40) << "---- str[?] input j:=";
										cin>>j;
										cout <<endl;
										j=((int)j>(String::GetCount()-1))?(String::GetCount()-1):(int)j;
										cin.ignore();
										for(int pos=i; pos<=j; pos++)
										{
											String::View(k,pos,(*str[k]==*str[pos]),*str[k],*str[pos]," == ");

											String::View(k,pos,(str[k]->operator>(*str[pos])),*str[k],*str[pos]," > ");

											String::View(k,pos,(*str[k]<*str[pos]),*str[k],*str[pos]," < ");

											String::View(k,pos,(*str[k]!=*str[pos]),*str[k],*str[pos]," != ");

										}
										cout << "------------------------------------------------------------------------"<<endl;
										cout << setw(40) << "---- q <-";
										position=cin.get();
									}

									break;

								case '2':
									while(position!='q'){
										cin.clear();
										cin.sync();
										cout << setw(40) << "---- str[?] input i:=";
										cin>>i;
										cout <<endl;
										i=((int)i>(String::GetCount()-1))?(String::GetCount()-1):(int)i;
										cout << setw(40) << "---- str[?] input j:=";
										cin>>j;
										cout <<endl;
										j=((int)j>(String::GetCount()-1))?(String::GetCount()-1):(int)j;
										cin.ignore();
										cout << "------------------------------------------------------------------------"<<endl;
										cout << "str[" << i << "]";
										cout << "  +  "<< "str[" << j << "] |  ";
										cout << (*str[i]+*str[j]).GetString();
										cout << "(  " << (*str[i]+*str[j]).GetLenght() << ")"<<endl;
										cout << "------------------------------------------------------------------------"<<endl;

										cout << setw(40) << "---- q <-";
										position=cin.get();
									}

									break;
								case '3': 
									while(position!='1' && (String::GetCount()>0))
								{
									cin.clear();
									cin.sync();
									cin.ignore();
									cout << setw(40) << "a--temp1=(str[i]++)-----------"<<endl;
									cout << setw(40) << "b--temp1=(str[i]--)-----------"<<endl;
									cout << setw(40) << "c--temp1=(--str[i])-----------"<<endl;
									cout << setw(40) << "d--temp1=(++str[i])-----------"<<endl;
									cout << setw(40) << "1--<<<<<<<<<<<<<<<<-----------"<<endl;
									position=cin.get();
									if(position=='a'|| position=='b'|| position=='c'|| position=='d') 
									{
									cout << setw(40) << "input i:";
									cin>>k;
									cout <<endl;
									k=((int)k>(String::GetCount()-1))?(String::GetCount()-1):(int)k;

									cout << "temp->Print()"<<endl;
									if(position=='a') {
										String temp1=(*str[k])++;
										cout << temp1.GetString()<< "(  " << temp1.GetLenght()<< ")"<<endl;
									}
									if(position=='b') {
										String temp1=(*str[k])--;
										cout << temp1.GetString()<< "(  " << temp1.GetLenght() << ")"<<endl;
									}
									if(position=='c') {
										String temp1=--(*str[k]);
										cout << temp1.GetString()<< "(  "<< temp1.GetLenght() << ")"<<endl;
									}
									if(position=='d') {
										String temp1=++(*str[k]);
										cout << temp1.GetString()<< "(  "<< temp1.GetLenght()<< ")"<<endl;
									}
									cout << "str[" << k << "]->Print()"<<endl;
									cout << (*str[k]).GetString() << "(  " << (*str[k]).GetLenght() << ")"<<endl;
									}
									}
									break;
								case '4': 
									cin.ignore();
									cout << setw(40) << "4----|str[i]=str[j]|------------"<<endl;
									cout << setw(40) << "input i:";
									cin>>i;
									cout <<endl;
									i=((int)i>(String::GetCount()-1))?(String::GetCount()-1):(int)i;
									cout << setw(40) << "input j:";
									cin>>j;
									cout <<endl;
									j=((int)j>(String::GetCount()-1))?(String::GetCount()-1):(int)j;
									*str[i]=*str[j];
									cout << "str[" << i << "] = "<< (*str[i]).GetString();
									cout << "  (  " << (*str[i]).GetLenght()<< " ) "<<endl;
									cout << "str[" << j<< "] = "<< (*str[j]).GetString();
									cout << " (  "<< (*str[j]).GetLenght()<< " ) "<<endl;
									break;
								case '5': 
									cin.ignore();
									cout << setw(40) << "5------|(int)str[j]|----"<<endl;
									cout << setw(40) << "input j:";
									cin>>j;
									cout <<endl;
									j=((int)j>(String::GetCount()-1))?(String::GetCount()-1):(int)j;

									cout << "(int) str[";cout << j; cout << "] = ";
									cout << (int)(*str[j])<<endl;
									break;
								case '6': 
									cin.ignore();
									cout << setw(40) << "6------|<<str[j]|------"<<endl;
									cout << setw(40) << "input j:";
									cin>>j;
									cout <<endl;
									j=((int)j>(String::GetCount()-1))?(String::GetCount()):(int)j;
									cout << "<< str[" << j << "] = ";
									cout <<*str[j]<<endl;
									break;
								case '7': 
									cin.ignore();
									cout << setw(40) << "7----->>str[j]|------"<<endl;
									cout << setw(40) << "input j:";
									cin>>j;
									cout <<endl;
									j=((int)j>(String::GetCount()-1))?(String::GetCount()):(int)j;
									cout << ">> str[" << j << "] = ";
									cin.ignore();
									cin>>*str[j];
									cout << ">> str[" << j << "] = ";
									cout << (*str[j]).GetString()<< "  (  "<< (*str[j]).GetLenght() << ")"<<endl;
									break;

								}

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
		cin.ignore();
		cout<<count;
		cin.ignore();

		//высвобождение занимаемой памяти
		if(count>0)
		{

			for(int i=0; i<count; i++){
				count<<i;
				delete []  str[i];
			}
			delete [] str;

		}
	}

	cin.get();

}