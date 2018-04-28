#include <stdlib.h>
#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	Btree bt;
	int ar[] = {8,10,6,7,5,3,15,9,12};
//	int ar[] = {8,10,6};
	for(int i=0; i<sizeof(ar)/sizeof(int); i++){
		bt.Insert(ar[i]);
	}
	bt.Display();
	bt.Delete(6);
	bt.Display();
	bt.Delete(5);
	bt.Display();
	bt.Delete(3);
	bt.Display();

	bt.Delete(9);
	bt.Display();
	bt.Delete(15);
	bt.Display();

	bt.Delete(8);
	bt.Display();
	bt.Delete(18);
	bt.Display();

	return 0;
}

