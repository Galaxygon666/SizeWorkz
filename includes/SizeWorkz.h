#ifndef SizeWorkzHeader
#define SizeWorkzHeader

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Files {
   char     name[50];
   int      size;
   char     location[1000];
   char     isFolder[6];
};

long int get_size(char file_name[]);
void handle_files(char folder[]);
void size_sorter(char files[1024][100]);
void printFile(struct Files files_array[], int array_size);

#endif