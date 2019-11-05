#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(long *list1, long *list2, long left_size, long right_size)
{
	long size = left_size + right_size;
	long *auxilary_mem = (long *)malloc(sizeof(long)*(size));
	long left_index,right_index,aux_index=0;
	for(left_index=0,right_index=0;left_index<left_size && right_index<right_size;++aux_index)
	{
		if(list1[left_index]>=list2[right_index])
		{
			auxilary_mem[aux_index] = list2[right_index];
			++right_index;
		}
		else
		{
			auxilary_mem[aux_index] = list1[left_index];
			++left_index;
		}
	}
	if(left_index==left_size)
	{
		for(;aux_index!=size;++aux_index,++right_index)
		{
			auxilary_mem[aux_index] = list2[right_index];
		}

	}
	else
	{
		for(;aux_index!=size;++aux_index,++left_index)
		{
			auxilary_mem[aux_index] = list1[left_index];
		}
	}

	for(long aux_index=0;aux_index!=size;++aux_index)
	{
		list1[aux_index] = auxilary_mem[aux_index];
	}

	free(auxilary_mem);
	return;
}

void merge_sort(long *list, long size)
{
	if(size>1)
	{
		long left_size = size/2;
		long right_size = size - left_size;
		merge_sort(list,left_size);
		merge_sort(list+left_size, right_size);
		merge(list, list+left_size, left_size, right_size);
	}
}

void print_list(long *lst, long size)
{
	for(long i=0;i!=size;++i)
	{
		printf("%ld ",lst[i]);
	}
	printf("\n");
	return;
}


int main()
{
	long num_cases,size,*list;
	scanf("%ld",&num_cases);
	
	for(long t=0;t<num_cases;++t)
	{
		scanf("%ld ", &size);
		list = (long *)malloc(sizeof(long)*size);
		for(long v=0;v<size;++v)
		{
			scanf("%ld ",list+v);
		}
		clock_t t = clock();
		merge_sort(list,size);
		t = clock() - t;
		double time_taken = (double)t/CLOCKS_PER_SEC;
		printf("time taken to sort the list is %lf seconds\n",time_taken);
		print_list(list,size);
		free(list);
	}

	return 0;
}
