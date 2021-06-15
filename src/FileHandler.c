#include "includes/Biggest.h"

long int get_size(char file_name[])
{
    FILE* fp = fopen(file_name, "r");

    if(fp == NULL)
    {
        printf("File not found...\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);

    long int res = ftell(fp);
    fclose(fp);

    return res;
}


void handle_files(char folder[])
{
    int count = 0;
    char file_name[50];
    char dir_name[100];
    struct Files files_array[25];

    DIR *d;
    struct dirent *dir;
    d = opendir(folder);

    if (d) {
      while ((dir = readdir(d)) != NULL) {
            if (*dir->d_name != '.')
            {
                strcpy(dir_name, folder);
                strcpy(file_name, dir->d_name);
                strncat(dir_name, dir->d_name, strlen(dir->d_name));

                DIR *d;
                d = opendir(dir_name);
                if(d)
                {
                    strcpy(files_array[count].name, dir_name);
                    files_array[count].size = 0;
                    strcpy(files_array[count].location, dir_name);
                    strcpy(files_array[count].isFolder, "True");

                    closedir(d);
                    count++;
                }
                else
                {
                    strcpy(files_array[count].name, file_name);
                    files_array[count].size = get_size(dir_name);
                    strcpy(files_array[count].location, dir_name);
                    strcpy(files_array[count].isFolder, "False");

                    count++;
                }
            }
      }
      printFile(files_array, count);
      closedir(d);
    }
}


void printFile(struct Files files_array[], int array_size) 
{
    for(int i = 0; i < array_size - 1; i++)
    {
         printf("Name : %s\n",  files_array[i].name);
         printf("Size : %d\n",  files_array[i].size);
         printf("Location : %s\n", files_array[i].location);
         printf("isFolder : %s\n\n", files_array[i].isFolder);
         printf("--------------------------------------\n");
    }

}


void size_sorter(char files[1024][100])
{

}