#include <stdlib.h>
#include <iostream>

typedef struct node_t
{
	int data;
	node_t* pre;	
	node_t* next;
	node_t(int k):data(k),pre(NULL),next(NULL){}
}*pnode;

class DoublyOrderList
{
public:
	DoublyOrderList():_head(NULL), _end(NULL){}	

	bool Insert(int k);
	bool Delete(int k);
	void DisplayList();

private:
	pnode _head;
	pnode _end;
};

