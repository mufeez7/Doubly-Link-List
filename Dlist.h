#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	T data;
	Node *next;
	Node *prev;
public:
	Node (T elem)
	{
		data = elem;
		next = NULL;
		prev = NULL;
	}
	void setnext (Node *x)
	{
		next = x;
	}
	Node<T> *getnext ()
	{
		return next;
	}
	Node<T> *getprev ()
	{
		return prev;
	}
	void setprev(Node *y)
	{
		prev = y;
	}
	void setdata (T pval)
	{
		data = pval;
	}
	T getdata ()
	{
		return data;
	}
};

template <class T>
class Dlist 
{
private:
	Node<T> *head;
public:
	Dlist ()
	{
		head = NULL;
	}
	void Insert (Node<T> *pbefore , Node<T> *pnew)
	{
		if (head == NULL)
		{
			head = pnew;
		}
		else
		{
			if (pbefore == 0 && head != NULL)
			{
				pnew->setnext(pbefore);
				pbefore->setprev(pnew);
				head = pnew;
			}
			else if (pbefore->getnext() == NULL)
			{
				pbefore->setnext(pnew);
				pnew->setprev(pbefore);
			}
			else
			{
				pnew->setnext(pbefore->getnext());
				pbefore->getnext()->setprev(pnew);
				pnew->setprev(pbefore);
				pbefore->setnext(pnew);
			}
		}
	}
	void Delete (Node<T> *ptodel)
	{
		if (ptodel == head)
		{
			head = ptodel->getnext();
			delete ptodel;
		}
		else
		{
			if (ptodel->getnext() == NULL)
			{
				ptodel->getprev()->setnext(NULL);
				delete ptodel;
			}
			else 
			{
				ptodel->getprev()->setnext(ptodel->getnext());
				ptodel->getnext()->setprev(ptodel->getprev());
				delete ptodel;
			}
		}
	}
	void printlist ()
	{
		Node<T> *temp;
		temp = head;

		while (temp != NULL)
		{
			cout<<temp->getdata()<<" ";
			temp = temp->getnext();
		}

	}
};