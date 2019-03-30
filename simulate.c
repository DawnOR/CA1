#include "dist/my-functions.h"

int main(){
	
	//PART 1 
	char *m = allocate_m();

	//PART 2 & 3
	int byte_count = srand_gen(MIN_BYTES,MAX_BYTES);
	int i;
	i = srand_gen_2(MIN_I,USHRT_MAX);
	printf("Randomly generated index \n");
	printf("%d", i / 256);
	printf("\n");

	//PART 4 & 5
	m = process(m, byte_count, i);
	FILE *physical_memory = fopen(PHYSICAL_MEMORY, "w");

	FILE *page_table = fopen(PAGE_TABLE, "w");

	write_physical_memory(m,physical_memory);
	fclose(physical_memory);
	write_page_table(m,page_table, byte_count,i); 
	fclose(page_table);
	free(m);
	return 0;

}
