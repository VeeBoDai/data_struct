#ifndef __MIN_HEAP__
#define  __MIN_HEAP__

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

template<class T>
void Swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<class T>
void Adjust(T a[], int i, int n)
{
	T min;
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

template<class T>
void Display(T a[], int n)
{
	for(int i=0; i<n; i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
	cout<<endl;
}

template<class T>
void BuildMinHeap(T a[], int n)
{
	cout<<"before build min heap"<<endl;	
    Display(a, n);

	if(n < 2){
		return;
	}
	for(int i = n/2 -1; i>=0; i--){
		Adjust(a, i, n);
	}
	cout<<"after build min heap"<<endl;
	Display(a, n);
}		

template<class T>
void SortMinHeap(T a[], int n)
{
 	cout<<"before sort:"<<endl;
	Display(a, n);

	for(int i = n-1; i>0; i--){
		Swap(a[0], a[i]);
		Adjust(a, 0, i);
	}
	cout<<"after sort:"<<endl;
	Display(a, n);
}		


#endif
