#ifndef _arrayInt
#define _arrayInt

#include<stdio.h>

#include <malloc.h>
#include<string.h>


struct int_sub{
    int *tmp;
   int *arrI;
    char* typei;
    size_t typeLeni;
    struct int_sub (*addi)(struct _ArrayInt*, int );
    int (*geti)(struct _ArrayInt*, int );
    void (*initi)(struct _ArrayInt* );

    void (*expandi)(struct _ArrayInt* , int) ;
    void (*print_i)(struct _ArrayInt* );

    int (*sizei)(struct _ArrayInt* );
    void (*freeArri)(struct _ArrayInt* );
};


struct _ArrayInt{
    struct int_sub typeI;
    //struct float_sub typeF;


    int maxi;
    int usedBeforei;

};

void initI(struct _ArrayInt* self);
//void arrMove();
void expandI(struct _ArrayInt* self, int _mul) ;
void print_I(struct _ArrayInt* self);

struct int_sub addI(struct _ArrayInt* self, int var1);

wchar_t getW(struct _ArrayInt* self, int index1);
int getI(struct _ArrayInt* self, int index1);
float getF(struct _ArrayInt* self, int index1);
int sizeI(struct _ArrayInt* self);
void freeArrI(struct _ArrayInt* self);

const struct int_sub int_set = {
        .typei = "int",
        .typeLeni = sizeof(int),
        .addi =  &addI,
        .geti =  &getI,
        .initi = &initI,

        .expandi =  &expandI,
        .print_i = &print_I,

        .sizei = &sizeI,
        .freeArri = &freeArrI
};


void initI(struct _ArrayInt* self){
    fputs("~~~first initi\n",stdout);

    if(strcmp(self->typeI.typei, "int") == 0)
    {
        self->typeI.arrI = (int*)malloc(10 * self->typeI.typeLeni);
        printf("~~~int initi %zd\n",self->typeI.typeLeni);

    }
    else{
        fputs("initi typei error\n",stdout);
    }
    self->maxi = 10;
    self->usedBeforei = 0;
}

void expandI(struct _ArrayInt* self, int _mul) {
    // 扩容 不为NULL
    if(strcmp(self->typeI.typei, "int") == 0)
    {
        puts("expanding int array~~");
        while((self->typeI.arrI = (int*)realloc(self->typeI.arrI, self->maxi * _mul * self->typeI.typeLeni)) == NULL){}

    }



    self->maxi *= _mul;
    printf("~~maxi: %d\n",self->maxi);
}
void print_I(struct _ArrayInt* self) {
    if(strcmp(self->typeI.typei, "int") == 0){
        for (int i = 0; i < self->usedBeforei; i++) {
            if (i == 0)printf("[%d, ", getI(self,i));
            else if (i == self->usedBeforei - 1)printf("%d]\n", getI(self, i));
            else printf("%d, ", getI(self,i));
        }
    }

}

struct int_sub addI(struct _ArrayInt* self, int var1){
    if(self->maxi == -1){self->typeI.initi(self);} // 初始化
    if(self->usedBeforei < self->maxi){
        self->typeI.arrI[self->usedBeforei] = var1;
        self->usedBeforei++;
    }else{
        self->typeI.expandi(self, 2);

        self->typeI.arrI[self->usedBeforei] = var1;
        self->usedBeforei++;
    }return self->typeI;
}



int getI(struct _ArrayInt* self, int index1){
    return self->typeI.arrI[index1];
}

int sizeI(struct _ArrayInt* self){
    return self->usedBeforei;
}
void freeArrI(struct _ArrayInt* self){
 
    if(strcmp(self->typeI.typei, "int") == 0)free(self->typeI.arrI);
 
    self->maxi = -1;
    self->usedBeforei = 0;

}
#endif
