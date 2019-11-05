#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main(int argc,char **argv)
{
	long num_sequences,size;
	FILE *test_data = fopen("test_data", "w");
	
	if(test_data == NULL)
	{
		printf("FILE ERROR....\n");
		return 1;
	}

	num_sequences = atol(argv[1]);
	fprintf(test_data,"%ld\n",num_sequences);
	for(long i=0;i<num_sequences;++i)
	{
		srand(time(NULL));
		size = atol(argv[2+i]);
		fprintf(test_data, "%ld\n", size);
		for(long j=0;j<size;++j)
		{
			fprintf(test_data,"%ld ",rand());
		}

		fprintf(test_data,"\n");
	}
	fclose(test_data);
	return 0;
}
