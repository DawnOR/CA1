#ifndef MYFUNCTIONSH
#define MYFUNCTIONSH
 #include <stdio.h>
 #include <stdio.h>
 #include <limits.h>
 #include <stdlib.h>
 #include <time.h>
 #include <stdbool.h>

 #define PHYSICAL_MEMORY "./data/physical_memory.txt"
 #define PAGE_TABLE "./data/page_table.txt"
 #define PAGE_SIZE 256
//CHAR_MAX =127
//CHAR_MIN =-128
#define MINCHAR 34
#define MIN_I 512
#define MAX_BYTES 20480
#define MIN_BYTES 2048
 char *allocate_m();
 int srand_gen(int, int);
 int srand_gen_2(int, int);
 char *process();
 void write_physical_memory(char *, FILE *);
 void write_page_table(char *, FILE *, int, int);
#endif
