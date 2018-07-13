#include<stdlib.h>
#include "min_heap.h"

int main()
{
	int a[] = {9, 8, 7, 2, 4, 5, 3};
	int n = sizeof(a)/sizeof(int);
    BuildMinHeap(a, n);
	SortMinHeap(a, n);
	return 0;
}

