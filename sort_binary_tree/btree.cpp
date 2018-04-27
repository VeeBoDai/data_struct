#include <stdlib.h>
#include <iostream>
#include "btree.h"

using namespace std;

void Btree::Display()
{
	Display(_pr);
	cout<<endl;
}

void Btree::Display(pnode p)
{
	if(NULL == p){
		return;
	}

	Display(p->left);
	cout<<p->data<<", ";
	Display(p->right);
}		

bool Btree::Insert(int k)
{
	return Insert(_pr, k);
}

bool Btree::Insert(pnode &pos, int k)
{
	if( NULL == pos){
		pnode temp = new node_t(k);
		pos = temp;
		return true;
	}

	if(k < pos->data){
		return Insert(pos->left, k);
	}else if(k > pos->data){
		return Insert(pos->right,k);
	}else{
		cout<<"key:"<<k<<", already exist!"<<endl;	
		return false;
	}
}

bool Btree::Delete2(pnode &pos){
	pnode pare = pos;
	pnode right = pos->left;
	while(NULL != right->right){
		pare = right;
		right = right->right;
	}
	pos->data = right->data;
	if(pare == pos){
		pos->left = right->left;
	}else{
		pare->right = right->left;
	}
	delete right;
	right = NULL;

}

bool Btree::Delete(pnode &pos, int k){
	if(NULL == pos){
		cout<<"key:"<<k<<", not exist!"<<endl;
		return false;
	}

	if(k < pos->data){
		return Delete(pos->left, k);
	}else if(k > pos->data){
		return Delete(pos->right, k);
	}else{
		if(NULL != pos->left && NULL != pos->right){
			return Delete2(pos);
		}else if(NULL == pos->left){
			pnode temp = pos->right;
			pos->data = temp->data;
			pos->left = temp->left;
			pos->right = temp->right;
			delete temp;
			temp = NULL;
		}else if(NULL == pos->right){
			pnode temp = pos->left;
			pos->data = temp->data;
			pos->left = temp->left;
			pos->right = temp->right;
			delete temp;
			temp = NULL;
		}else{
			delete pos;
			pos = NULL;
		}
		return true;
	}

}


bool Btree::Delete(int k)
{
	return Delete(_pr, k); 
}
