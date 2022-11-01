//error handling file

#include "common.h"

//This function prints usage of the 'program'.
void printUsage()
{
    printf("Usage : \nprogram -c <file> <compressed-file-name>\n");
    printf("program -uc <compressed-file-name> <uncompressed-file-name>\n");
    printf("Where :\n-c and -uc options are for Huffman compression technique\n");
}

//This function prints error message for different error codes
int onError(errorcode error, char* filename)
{
    switch (error)
    {
    case INPUTERROR:
        printf("Error : Invalid input parameters.\n");
        printUsage();
        break;
    case FILENOTFOUNDERROR:
        printf("Error : %s - No such file found.\n", filename);
        printUsage();
        break;
    case DISKFULLERROR:
        printf("Error : No space left on device. Free up space by deleting some files and then retry.\n");
        break;
    case FILECORRUPTED:
        printf("Error : Input file is corrupted.\n");
        break;
    case SUCCESS:
        break;
    default:
        printf("Error : Error occured.\n");
        break;
    }

    return 1;
}
