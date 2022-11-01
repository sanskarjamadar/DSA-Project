#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "common.h"

int checkFile(char* filepath)
{
    if (access(filepath, 0) != -1){
        
        return 0;
    }
    else{
        
        return 1;
    }
}

int main(int argc, char * argv[])
{
    errorcode ret = SUCCESS;

    if (argc != 4)
        return onError(INPUTERROR, argv[0]);

    if ((strcmp(argv[1], "-c") != 0))
        return onError(INPUTERROR, argv[2]);

    if (checkFile(argv[2]) != 0)
        return onError(FILENOTFOUNDERROR, argv[2]);

    if (strcmp(argv[1], "-c") == 0){
        ret = HuffmanC(argv[2], argv[3]);
    }
    if (!ret)
        return onError(ret, argv[2]);

    return ret;
}
