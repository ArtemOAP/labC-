#include <iostream>
using namespace std;

template <class Type> 
class ListString
{

	class ElemString
	{
	public:
		Type (entity);
		ElemString *next;
		ElemString  *prev;
		ElemString(Type &ent);
	};

	int count;
	ElemString *first;
	ElemString *last;
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

template <class Type>
ListString<Type>::~ListString()
{
	ClearListString();
}

template <class Type>
int ListString<Type>::getCount()
{
	return count;
}

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

template <class Type>
int ListString<Type>::AddElemString(Type &ent, int n)
{
	if ((n <= 0) || (n > count))
		return -1;
	ElemString *temp = new ElemString(ent);
	ElemString *elem = first;
	for (int i = 1; i < n; i++)
		elem = elem->next;
	if (n == 1)
	{
		elem->prev = temp;
		temp->next = elem;
		first = temp;
	}
	if ((n > 1) && (n <= count))
	{
		(elem->prev)->next = temp;
		temp->prev = elem->prev;
		elem->prev = temp;
		temp->next = elem;
	}
	count++;
	return n;
}

template <class Type>
int ListString<Type>::DeleteElemString(int n)
{
	if ((n <= 0) || (n > count))
		return -1;
	ElemString *del = first;
	for (int i = 1; i < n; i++)
		del = del->next;
	if (count == 1)
		first = last = NULL;
	if ((n == 1) && (count > 1))
	{
		first = del->next;
		(del->next)->prev = NULL;
	}
	if ((n == count) && (count > 1))
	{
		last = del->prev;
		(del->prev)->next = NULL;
	}
	if ((n > 1) && (n < count))
	{
		(del->prev)->next = del->next;
		(del->next)->prev = del->prev;
	}
	delete del;
	count--;
	return n;
}

template <class Type>
void ListString<Type>::ShowListString()
{
	if (count == 0)
	{
		cout << "in List not string!" << endl;
		return;
	}
	ElemString *temp = first;
	for (int i = 1; i <= count; i++)
	{
		cout << "[" << i << "] " << temp->entity << endl;
		temp = temp->next;
	}
}

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

template <class Type>
Type * ListString<Type>::GetString(int n)
{
	if ((n <= 0) || (n > count)) return NULL;
	ElemString *temp = first;
	for (int i = 1; i < n; i++)
		temp = temp->next;
	return &(temp->entity);
}
