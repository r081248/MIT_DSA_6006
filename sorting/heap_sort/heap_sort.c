#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "heaps.h"

void heap_sort(int *arr, int heap_size)
{
    build_max_heap(arr, heap_size);
    while (heap_size >= 2)
    {
        swap(arr+1, arr+heap_size);
        --heap_size;
        max_heapify(arr,heap_size,1);
    }
    
}


int main()
{
	long num_cases,size,*list;
	scanf("%ld",&num_cases);
	
	for(long t=0;t<num_cases;++t)
	{
		scanf("%ld ", &size);
		list = (long *)malloc(sizeof(long)*(size+1));
		for(long v=1;v<=size;++v)
		{
			scanf("%ld ",list+v);
		}
		clock_t t = clock();
		heap_sort(list,size);
		t = clock() - t;
		double time_taken = (double)t/CLOCKS_PER_SEC;
		printf("time taken to sort the list is %lf seconds\n",time_taken);
		free(list);
	}

	return 0;
}
