#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CR_SECURE_NO_WARNINGS

char partitionName[20];
unsigned int partSize;


void setDefaultValues(){
    strcpy(partitionName, "myPart.bin");
    partSize = 2000000;
}

int main(int argc, char** argv){

    printf("%d", argc);
    setDefaultValues();

    int i;
    if(strcmp(argv[0], "./operating_sys") != 0)
    {
        printf("\ndas geht aber nicht");
        return -1;
    }

    for (i = 0; i < argc; i++)
    {
        printf("\n[%d] ==> %s", i, argv[i]);
    }
    

    for (i = 0; i < argc; i++)
    {
        if(strcmp(argv[i],"-create") == 0){
            if(i < (argc - 1))
            strcpy(partitionName, argv[i+1]);
        }

        if(strcmp(argv[i],"-size") == 0){
            if(i < (argc - 1))
                partSize =  atoi(argv[i + 1]);
        }
    }

    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-create") ==  0)
        {
            if (i < argc)
            {
                printf("\ncreating partition [%s], size=%d", partitionName, partSize);
            }
            
        }
    }


    return 0;
}