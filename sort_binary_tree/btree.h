#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdlib.h>
typedef struct node_t
{
	int data;
	node_t *left;
	node_t *right;
	node_t(int k):data(k),left(NULL),right(NULL){}
}*pnode;

class Btree
{
public:
	Btree():_pr(NULL){}	
	bool Insert(int k);
	bool Delete(int k);
	void Display();
private:
	bool Insert(pnode &r, int k);
	void Display(pnode p);
	bool Delete(pnode &pos, int k);
	bool Delete2(pnode &p);
private:
	pnode _pr;	
};

#endif

