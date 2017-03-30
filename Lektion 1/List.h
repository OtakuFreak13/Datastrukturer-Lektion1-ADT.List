#ifndef LIST_H
#define LIST_H

#include<iostream>

using namespace std;

template <typename T>
class List
{
private:
	class Node 
	{
	public:
		Node* next;
		T element;
		Node(Node* next, T element)
		{
			this->next = next;
			this->element = element;
		}
	};
	Node* first;
	int nrOfElements;
public:
	List();
	//~List();//Tror inte  denna ska vara med
	void insertAt(const T& data, int pos)throw(...);
	void printAll()const;//Tillfällig ska tas bort. Finns bara för debug
};

template <typename T>
List<T>::List()
{
	this->nrOfElements = 0;
	this->first = nullptr;
}
template <typename T>
void List<T>::insertAt(const T& element, int pos) throw(...)
{
	Node * walker = this->first;
	if (this->nrOfElements == 0)
	{
		this->first = new Node(nullptr, element);
	}
	else
	{
		Node* prev;
		for (int i = 0; i < pos+1; i++)
		{
			
			Node* old = walker;
			if (i == pos - 1)
			{
				prev = walker;
			}
			if (i == pos)
			{
				if (pos == 0)
				{
					Node* ptr = new Node(old, element);
					this->first = ptr;
				}
				else if (pos == this->nrOfElements)
				{
					Node* ptr = new Node(nullptr, element);
					prev->next = ptr;
				}
				else if(pos == this->nrOfElements-1)
				{
					Node *ptr = new Node(old, element);
					prev->next = ptr;
				}
				else
				{
					Node *ptr = new Node(walker->next, element);
					prev->next = ptr;
				}
			}
			if (i != this->nrOfElements)
			{
				walker = walker->next;
			}
		}
	}
	this->nrOfElements++;
}

template<typename T>
void List<T>::printAll()const
{
	Node* walker = this->first;
	for (int i = 0; i < this->nrOfElements; i++)
	{
		cout << walker->element << endl;
		walker = walker->next;
	}
}




#endif // !LIST_H
