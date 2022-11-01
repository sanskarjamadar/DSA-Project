#pragma once
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#define MAX 256
#define MAXLZW 4096

//Error code definitions
typedef enum errorcode{
    SUCCESS = 0,
    INPUTERROR,  //error while taking input.
    FILENOTFOUNDERROR,  //if file pointer is null.
    FILEWRITEFAILED,  //not able to write in file.
    FILECORRUPTED,  //if file is corrupted.
    DISKFULLERROR,
}errorcode;


void printUsage();
int onError(errorcode error, char* filename);
errorcode  HuffmanC(char* infile, char* outfile);
float getratio(char* infile, char* outfile);
void printsize(char* file);
