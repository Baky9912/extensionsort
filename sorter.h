#ifndef SORTER_H
#define SORTER_H

#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>


int is_directory(const char *path);
char* get_extension(const char *path);
int sorter(const char *path);
int delete_empty(const char *path);

#ifdef __cplusplus
}
#endif
#endif // SOTER_H
