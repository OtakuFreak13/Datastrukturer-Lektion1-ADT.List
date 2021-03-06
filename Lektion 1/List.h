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
public://TODO adda fler funktioner
	List();
	~List();
	void insertAt(const T& data, int pos)throw(...);
	void printAll()const;//Tillf�llig ska tas bort. Finns bara f�r debug
	void remove(int pos);

};

template <typename T>
List<T>::List()
{
	this->nrOfElements = 0;
	this->first = nullptr;
}
template<typename T>
inline List<T>::~List()
{
	
	do
	{
		Node* walker = this->first;

		Node *next = walker->next;

		this->first = next;
		delete walker;
	} while(this->first!=nullptr);
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

template<typename T>
void List<T>::remove(int pos)
{
	Node* walker=this->first;
	Node* prev;
	for (int i = 0; i < pos + 1; i++)
	{
		if (i == pos - 1)
		{
			prev = walker;
		}
		if (i == pos)
		{
			if (pos == 0)
			{
				Node *next = walker->next;

				this->first = next;
				delete walker;
				this->nrOfElements--;
			}
			else if (pos == this->nrOfElements - 1)
			{
				prev->next = nullptr;
				delete walker;
				this->nrOfElements--;
			}
			else
			{
				prev->next = walker->next;
				delete walker;
				this->nrOfElements--;
			}

		}
		walker = walker->next;

	}
}



#endif // !LIST_H
