#ifndef _arrayFloat
#define _arrayFloat

#include<stdio.h>

#include <malloc.h>
#include<string.h>


struct float_sub{
    float *tmp;
    float *arr;
    char* typef;
    size_t typeLenf;
    struct float_sub (*addf)(struct _ArrayFloat*, float );
    float (*getf)(struct _ArrayFloat*, int );
    void (*initf)(struct _ArrayFloat* );

    void (*expandf)(struct _ArrayFloat* , int) ;
    void (*print_f)(struct _ArrayFloat* );

    size_t (*sizef)(struct _ArrayFloat* );
    void (*freeArrf)(struct _ArrayFloat* );
};




struct _ArrayFloat{

    struct float_sub typeF;

    int maxf;
    int usedBeforef;

};

void initF(struct _ArrayFloat* self);
//void arrMove();
void expandF(struct _ArrayFloat* self, int _mul) ;
void print_F(struct _ArrayFloat* self);


struct float_sub addF(struct _ArrayFloat* self, float var1);


float getF(struct _ArrayFloat* self, int index1);
size_t sizeF(struct _ArrayFloat* self);
void freeArrF(struct _ArrayFloat* self);


const struct float_sub float_set = {
        .typef = "float",
        .typeLenf = sizeof(float),
        .addf =  &addF,
        .getf =  &getF,
        .initf = &initF,

        .expandf =  &expandF,
        .print_f = &print_F,

        //.typeI.addi = &addI,
        //.typeI.geti =  &getI,

        .sizef = &sizeF,
        .freeArrf = &freeArrF
};

void initF(struct _ArrayFloat* self){
    fputs("~~~first initi\n",stdout);

        if(strcmp(self->typeF.typef, "float") == 0)
        {
            //puts("~~~");
            self->typeF.arr = (float*)malloc(10 * self->typeF.typeLenf);
            printf("~~~float initi\n",self->typeF.typeLenf);
        }else{
        fputs("initi typei error\n",stdout);
    }
    self->maxf = 10;
    self->usedBeforef = 0;
}

void expandF(struct _ArrayFloat* self, int _mul) {
    // 扩容 不为NULL


    if(strcmp(self->typeF.typef, "float") == 0)
    {
        puts("expanding float array~~");
        while((self->typeF.arr = (float*)realloc(self->typeF.arr, self->maxf * _mul * self->typeF.typeLenf)) == NULL){}
    }

    self->maxf *= _mul;
    printf("~~maxi: %d\n",self->maxf);
}
void print_F(struct _ArrayFloat* self) {

    if(strcmp(self->typeF.typef, "float") == 0){
        //puts("printw~~~");
        for (int i = 0; i < self->usedBeforef; i++) {
            if (i == 0)printf("[%f, ", getF(self,i));
            else if (i == self->usedBeforef - 1)printf("%f]\n", getF(self, i));
            else printf("%f, ", getF(self,i));
        }
    }
}


struct float_sub addF(struct _ArrayFloat* self, float var1){
    if(self->maxf == -1){self->typeF.initf(self);} // 初始化
    //puts("addf~~");
    if(self->usedBeforef < self->maxf){
        self->typeF.arr[self->usedBeforef] = var1;
        self->usedBeforef++;
    }else{
        self->typeF.expandf(self, 2);

        self->typeF.arr[self->usedBeforef] = var1;
        self->usedBeforef++;
    }return self->typeF;
}


float getF(struct _ArrayFloat* self, int index1){
    return self->typeF.arr[index1];
}
size_t sizeF(struct _ArrayFloat* self){
    return self->usedBeforef;
}
void freeArrF(struct _ArrayFloat* self){
    //if(strcmp(self->_wchar.typei, "wchar_t") == 0)free(self->_wchar.arrI);

    if(strcmp(self->typeF.typef, "float") == 0)free(self->typeF.arr);
    self->maxf = -1;
    self->usedBeforef = 0;

}
#endif
