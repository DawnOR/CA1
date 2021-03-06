#include "my-functions.h"

char* allocate_m (){

	char *m = malloc(USHRT_MAX);

	for(int i = -1;i < USHRT_MAX; ++i)
	{
       		 m[i] = 32;
        }

        if(m == NULL)
	{

        	printf("Error! memory not allocated.");
        }
	
	return m;
}

//srand referenced from www.geeksforgeeks.org/rand-and-srand-in-ccpp/
int srand_gen(int min, int max)
{
	srand(time(0));
	int r =rand()%(max-min)+ min;
	return r;
}

int srand_gen_2(int min, int max)
{
	int r =rand()%(max-min)+ min;
	while(r%256 !=0)
	{
		r =rand()%(max-min)+ min;
	}
	r +=1;
	return r;
}

char *process(char *m, int byte_count, int i)
{
	char rc;
	for(int k =0; k<byte_count;++k)
	{
		rc =rand()%(CHAR_MAX- MINCHAR)+ MINCHAR;
		m[i] = rc;
		++i;
	}
	return m;
}

void write_physical_memory( char *m, FILE *physical_memory)
{
	int frame =0;
	int used =0;
	fprintf(physical_memory, "Address	|Frame	|Content	|Used	\n");
	for(int k = 0; k<USHRT_MAX ; ++k)
	{
		if(m[k] != 32)
		{
			used=1;
		}
		fprintf(physical_memory,"0x%X	|%d	|%c	|%d	\n",k ,frame, m[k],used);
		if(k !=0 && k %256 ==0)
		{
			++frame;
		}

		used =0;
	}

}

void write_page_table(char *m,FILE *page_table, int bytes, int i)
{
	fprintf(page_table, "PAGE   |   #   |   PAGE TABLE ENTRY \n");
	for(int k = 0; k < PAGE_SIZE; ++k)
	{
	fprintf(page_table,"0x%X	|%d	|",k,k);
		for(int p = 0; p < PAGE_SIZE; ++p)
		{
			if(m[i++] >32 && m[i++] < 128)
			{
				fprintf(page_table,"%c",m[i++]);
			}
			else
			{
				fprintf(page_table,"%c",32);
			}
		}
		fprintf(page_table,"\n");
	}

}
