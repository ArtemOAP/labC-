#include <iostream>
using namespace std;

template <class Type> 
class ListString
{

	class ElemString
	{
	public:
		Type (entity);
		ElemString *next;//на следующий
		ElemString  *prev;//на предыдущий
		ElemString(Type &ent);
	};

	int count;
	ElemString *first;//указатель на начало списка
	ElemString *last;// указатель на конец списка
	//метод класса для получения указателя на элемент в заданной позиции
	ElemString* getElementInPosition(int posit)
	{
	ElemString *elem;
	if(posit <= count/2)
	{
		elem = first;
		
		for (int i = 1; i < posit; i++)
			elem = elem->next;
	}
	if(posit>count/2)
	{
		elem = last;
	for (int i = count; i > posit; i--)
			elem = elem->prev;

	} 
	return elem;
	}
public:
	ListString();
	~ListString();
	int getCount();
	int AddElemString(Type &ent);
	int AddElemString(Type &ent, int n);
	int DeleteElemString(int n);
	void ShowListString();
	void ClearListString();
	Type * GetString(int n);
};

template <class Type>
ListString<Type>::ElemString::ElemString(Type &ent)
{
	next = prev = NULL;
	entity = ent;
}

template <class Type>
ListString<Type>::ListString()
{
	count = 0;
	first = last = NULL;
}
//деструктор класса список
template <class Type>
ListString<Type>::~ListString()
{
	ClearListString();
}
//количество элементов списка
template <class Type>
int ListString<Type>::getCount()
{
	return count;
}
// добавление  элемента списка в конец списка
template <class Type>
int ListString<Type>::AddElemString(Type &ent)
{
	ElemString *temp = new ElemString(ent);
	if (count == 0) 
		first = last = temp;
	if (count > 0)
	{
		last->next = temp;
		temp->prev = last;
		last = temp;
	}
	count++;
	return count;
}
// добавление  элемента списка на заданную позицию
template <class Type>
int ListString<Type>::AddElemString(Type &ent, int posit)
{
	if ((posit <= 0) || (posit > count)) {return NULL;}
	ElemString *temp = new ElemString(ent);
	ElemString *elem=getElementInPosition(posit);
	

	if (posit == 1)
	{
		elem->prev = temp;
		temp->next = elem;
		first = temp;
	}
	if ((posit > 1) && (posit <= count))
	{
		(elem->prev)->next = temp;
		temp->prev = elem->prev;
		elem->prev = temp;
		temp->next = elem;
	}
	count++;
	return posit;
}
// удаление заданого элемента списка 
template <class Type>
int ListString<Type>::DeleteElemString(int posit)
{
	if ((posit <= 0) || (posit > count)) return NULL;
	ElemString *del=getElementInPosition(posit);

	if (count == 1)
		first = last = NULL;
	if ((posit == 1) && (count > 1))
	{
		first = del->next;
		(del->next)->prev = NULL;
	}
	if ((posit == count) && (count > 1))
	{
		last = del->prev;
		(del->prev)->next = NULL;
	}
	if ((posit > 1) && (posit < count))
	{
		(del->prev)->next = del->next;
		(del->next)->prev = del->prev;
	}
	delete del;
	count--;
	return posit;
}
// последовательный вывод элементов списка
template <class Type>
void ListString<Type>::ShowListString()
{
	if (count == 0)
	{
		return;
	}
	ElemString *elem  = first;

	for (int i = 1; i <= count; i++)
	{
		cout << "[" << i << "] " << elem->entity << endl;
		elem = elem->next;
	}
}
// очищает список элементов (у объектов вызывает деструктор)
template <class Type>
void ListString<Type>::ClearListString()
{
	if (count > 0)
	{
		ElemString *temp = first->next;
		while (temp != NULL)
		{
			delete (temp->prev);
			temp = temp->next;			
		}
		delete (last);
		count = 0;
	}	
}
// метод для получения указателя на объект(или другово типа)
//в заданной позиции хранимого в классе элемент
template <class Type> 
Type *  ListString<Type>::GetString(int posit)
{
	if ((posit <= 0) || (posit > count)) return NULL;
	ElemString *elem=getElementInPosition(posit);
	return &(elem->entity);
}

