#include "my-functions.h"

int main(){

//allocate memory
	char *m = allocate_m();

	int get_number_of_bytes = srand_gen(MIN_BYTES,MAX_BYTES);
	int i;
//starting index location
	i = srand_gen_2(MIN_I,USHRT_MAX);
	printf("%d\n", i / 256);
//set our random characters up starting at random index
	m = process_bytes(m, get_number_of_bytes, i);

//open files and check if they are available
	FILE *physical_memory = fopen(PHYSICAL_MEMORY, "w");
	if(physical_memory == NULL)
	{
	printf("File NAME: %s could not be opened...\n", PHYSICAL_MEMORY);
	}

	FILE *page_table = fopen(PAGE_TABLE, "w");
	if(page_table == NULL)
	{
	printf("File NAME: %s could not be opened...\n",PAGE_TABLE);
	}
	write_physical_memory(m,physical_memory);
	fclose(physical_memory);
	write_page_table(m,page_table,get_number_of_bytes,i); 
	fclose(page_table);

	char search_memory_input[5];
	int done_search = 0;
	printf("Please enter a Memory address (ie 0F32),enter STOP to stop searching..\n 0x");
	while(done_search !=1)
	{
		scanf("%4s", search_memory_input);
		if(compare_input(search_memory_input) == 1)
		{
			printf("OK BYE!");
			done_search = 1;
		}
		else
		{
			printf("Enter another Address.\n 0x");
		}
	}
	free(m);
	return 0;

}
