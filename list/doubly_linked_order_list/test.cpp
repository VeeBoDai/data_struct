#include <assert.h>
#include "doubly_order_list.h"

int main()
{
	int ar[] = {5,6,2,4,7,9,5,0};
	DoublyOrderList dlist;
	for(int i = 0; i< sizeof(ar)/sizeof(int); i++){
		dlist.Insert(ar[i]);
		//dlist.DisplayList();
	}
	dlist.DisplayList();
	assert(dlist.Delete(2));
	dlist.DisplayList();
	assert(dlist.Delete(0));
	dlist.DisplayList();
	assert(dlist.Delete(9));
	dlist.DisplayList();
	assert(dlist.Delete(5));
	dlist.DisplayList();
	assert(!dlist.Delete(3));
	dlist.DisplayList();
	return 0;
}		
