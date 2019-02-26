#include<bits/stdc++.h>

using namespace std ;

class Heap 
{
	int *harr ; // pointer to heap array
	int capacity ; //Max size of heap
	int heap_size ; // Current heap size
	public:
		Heap(int arr[] , int n) ;
		void minHeapify(int i) ;
		int left(int i) {
			return (2*i + 1) ;
		}
		int right(int i){
			return (2*i + 2) ;
		}
		int parent(int i){
			return (i - 1/2) ;
		}
		void printArray()
		{
			for(int i = 0 ; i < heap_size ; i++)
			 cout << *(harr+i) ;
		}
	
};
void swap(int *x , int *y)
{
	int temp = *x ;
	*x = *y ;
	*y = temp ;
}


Heap :: Heap(int arr[] , int size)
{
	harr = arr ;
	heap_size = size ;
	int i = heap_size - 1 / 2 ;
}

void Heap :: minHeapify(int i)
{
	int l = left(i) ;
	int r = right(i) ;
	int smallest = i ;
	if(l < heap_size && harr[l] < harr[i])
	 smallest = l ;
	if(r < heap_size && harr[r] < harr[i])
	 smallest = r ;
	 
	if(smallest != i)
	{
	 swap(&harr[i] , &harr[smallest]) ;
	 minHeapify(smallest) ;
    }
}

int main()
{
  	int arr[] = {7,1,5,2,4,3,6} ;
  	int n = sizeof(arr)/sizeof(int) ;
  	Heap h(arr,n) ;
  	h.minHeapify(0) ;
  	h.printArray() ;
}
