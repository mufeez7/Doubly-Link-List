#include <iostream>
#include "Dlist.h"
using namespace std;

int main ()
{
	Node<int> *a, *b, *c, *d;
	a = new Node<int> (1);
	b = new Node<int> (2);
	c = new Node<int> (3);
	d = new Node<int> (4);

	Dlist<int> *list = new Dlist<int> ();
	list->Insert(0,a);
	list->Insert(a,b);
	list->Insert(a,d);
	list->Insert(b,c);

	list->printlist();
	cout<<"After deleting the node"<<endl;
	list->Delete(d);
	list->printlist();
	
	Node<string> *f = new Node<string> ("mustaeenisdobu");
	Dlist<string> *temp = new Dlist<string> ();
	temp->Insert(0,f);
	temp->printlist();

	return 0;
}