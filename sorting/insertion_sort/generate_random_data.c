#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen("test_data","w");

	if(fp==NULL)
	{
		printf("unable to generate random data... File Error\n");
		return 1;
	}

	long int num_case = atol(argv[1]);

	fprintf(fp,"%ld\n",num_case);

	for(long int i=0; i<num_case; ++i)
	{
		long int num_values = atol(argv[2+i]);
		fprintf(fp,"%ld\n",num_values);
		srand(time(NULL));
		for(long int j=0;j<num_values;++j)
		{
			fprintf(fp,"%ld ", rand()%num_values);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
	return 0;
}
