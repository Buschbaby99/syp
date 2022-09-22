#include <stdio.h>
#include <string.h>

#define BLOCKSIZE 8

 struct person{
        char firstname[16];
        char surname[16];
        int year_of_birth;
    };


struct person AKIFT3[] = {
    {"mihael", "subasic", 1991},
    {"lukas", "zorn", 1990},
    {"neil", "agy", 1998},
};

void printPers(struct person p);
void printPersZ(struct person *p);

void printList(struct person *l, int size);

void sortYear(struct person *p, int size);


void hexdumb(void* pt, int size){

    int rows = size / BLOCKSIZE;
    if(size % BLOCKSIZE != 0){
        rows++;
    }

    printf("==================\n");

    for (int j = 0; j < rows; j++)
    {
        printf("\n0x%8.8x: ", (unsigned long long)pt+(j*BLOCKSIZE));

        for (int i = 0; i < BLOCKSIZE; i++)
        {
            printf("%2.2x ", *((unsigned char*)pt + i + j * BLOCKSIZE));
        }
        
    }
    
    
    printf("\n==================\n");

}


int main(int argc, char** argv){

    float f1 = 0.5;

    double dArray[] = {1.0, 2.0, 4.0, 8.0};


    for (int i = 0; i < sizeof(dArray)/sizeof(double); i++)
    {
        printf("\n [%d] ==> [%.2f]", i, dArray[i]);
    }
    
    printf("\n");

    double *dpt2 = &dArray[1];
    printf("\n%f %f %f", dArray[2] , dpt2[1], *(dpt2+1));
    char* s = "BULME";
    printf("\nstring=%s %s %s", s, &s[0], &s[2]);

    printf("\n");
    hexdumb(&f1, sizeof(f1));
    hexdumb(dArray, sizeof(dArray));


   

    struct person mihael = {"mihael", "subasic", 1998};

    printPers(mihael);
    printPers(mihael);
    printPersZ(&mihael);
    printPersZ(&mihael);

    printf("\n");

    printList(AKIFT3, sizeof(AKIFT3)/sizeof(struct person));

    printf("\n");

    sortYear(AKIFT3, sizeof(AKIFT3)/sizeof(struct person));

    printf("\n");

    printList(AKIFT3, sizeof(AKIFT3)/sizeof(struct person));


    return 0;
}


void printPers(struct person p){
    printf("%s %s is born %d \n", p.firstname, p.surname, p.year_of_birth);
    strcpy(p.firstname, "Mario");
}


void printPersZ(struct person *p){

    printf("%s %s is born %d \n", p->firstname, p->surname, p->year_of_birth);
    strcpy(p->firstname, "Mario");


}

void printList(struct person *l, int size){

    for (int i = 0; i < size; i++)
    {
        printPers(l[i]);
    }
    
}


void sortYear(struct person *p, int size){

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            struct person help;
            if ((p+i)->year_of_birth > (p+j)->year_of_birth)
            {
                help = *(p + i);
                *(p+i) = *(p+j);
                *(p + j) = help;
            }
        }
    }
}