#include <stdio.h>
#include <iostream>

/*
index begin 0,1,2,....,n-1

*/

using namespace std;

int Pare(int i)
{
	return (i-1)/2;
}

int Left(int i)
{
	return 2*i+1;
}		

int Right(int i)
{
	return 2*i+2;
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Adjust(int a[], int i, int n)
{
	int min;
	int left = Left(i);
	int right = Right(i);
	int min_id;
	if(left < n){
		min = a[left];
		min_id = left;
		if(right < n && min > a[right]){
			min = a[right];
			min_id = right;
		}

		if(min < a[i]){
			Swap(a[i],a[min_id]);	
			Adjust(a, min_id, n);
		}
	}
}

void Display(int a[], int n)
{
	cout<<endl;	
	for(int i=0; i<n; i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
}

void BuildMinHeap()
{
	int a[] = {9,8,7,2,4,5,3};
	int n = sizeof(a)/sizeof(int);
    Display(a, n);


	if(n < 2){
		return;
	}
	for(int i = n/2 -1; i>=0; i--){
		Adjust(a, i, n);
	}

	Display(a, n);

	for(int i = n-1; i>0; i--){
		Swap(a[0], a[i]);
		Adjust(a, 0, i);
	}
	Display(a, n);

}		

int main()
{
	BuildMinHeap();
	return 0;
}		

