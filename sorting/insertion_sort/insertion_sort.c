#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertion_sort(long *list, long size)
{
	for(long i=1; i<size; ++i)
	{
		long key = list[i];
		long j = i-1;
		while(j>=0 && key < list[j])
		{
			list[j+1] = list[j];
			--j;
		}
		list[j+1] = key;
	}
}

void print_list(long *list, long size, FILE *fp)
{
	for(long i=0; i<size; ++i)
	{
		fprintf(fp,"%ld ",list[i]);
	}
	fprintf(fp,"\n");	
}

int main()
{
	FILE *sorted_data = fopen("sorted_data","w");
	long num_cases,*list;
	scanf("%ld",&num_cases);
	for(long i=0;i<num_cases;++i)
	{
		long num_values;
		scanf("%ld ",&num_values);
		list = (long *)malloc(sizeof(long)*num_values);
		for(int j=0;j<num_values;++j)
		{
			scanf("%ld ", list+j);
		}
		clock_t t = clock();
		insertion_sort(list, num_values);
		t = clock() - t;
		double time_taken = (double)t/CLOCKS_PER_SEC;
		printf("time_taken to sort %ld elements is %lf\n",num_values,time_taken);
		print_list(list,num_values,sorted_data);
		free(list);
	}
	fclose(sorted_data);
	return 0;
}
