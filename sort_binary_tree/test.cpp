#include <stdlib.h>
#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	Btree bt;
	int ar[] = {4,5,3,2,7,5};
	for(int i=0; i<sizeof(ar)/sizeof(int); i++){
		bt.Insert(ar[i]);
	}
	bt.Display();
	bt.Delete(5);
	bt.Display();
	bt.Delete(4);
	bt.Display();
	bt.Delete(1);
	bt.Display();



	return 0;
}

