#include <iostream>
#include "doubly_order_list.h"

using namespace std;
bool DoublyOrderList::Insert(int k)
{
	if(NULL == _head){
		pnode temp = new node_t(k);
		_head = _end  = temp;
		return true;
	}

	pnode pos = _head;	
	pnode temp = new node_t(k);
	while(k > pos->data){
		if(NULL == pos->next){
			pos->next = temp;
			temp->pre = pos;
			_end = temp;
			return true;
		}else{	
			pos = pos->next;
		}
	}

	pnode pre = pos->pre;
	if(NULL == pre){
		temp->next = pos;
		pos->pre = temp;
		_head = temp;
	}else{
		pre->next = temp;
		temp->pre = pre;
		temp->next = pos;
		pos->pre = temp;
	}
	return true;
}

bool DoublyOrderList::Delete(int k)
{
	if(NULL == _head){
		return false;
	}

	pnode temp = _head;
	while(NULL != temp && k > temp->data){
		temp = temp->next;
	}

	if(NULL == temp || k != temp->data){
		return false;
	}

	while(NULL != temp && k == temp->data){
		pnode pre = temp->pre;
		pnode next = temp->next;
		if(NULL == pre && NULL == next){
			_head = _end = NULL;
		}else if(NULL == pre){
			_head = next;
			next->pre = NULL;
		}else if(NULL == next){
			_end = pre;
			pre->next = NULL;
		}else{
			pre->next = next;
			next->pre = pre;
		}
		temp->pre = temp->next=NULL;
		delete temp;
		temp = next;
	}
	temp = NULL;
	return true;
}

void DoublyOrderList::DisplayList()
{
	int i = 0;	
	pnode temp = _head;
	while(NULL != temp){
		cout<<"id:"<<i++<<"--d:"<<temp->data<<", ";
		temp = temp->next;
	}
	cout<<endl;
}



