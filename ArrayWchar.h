#ifndef _arrayWchar
#define _arrayWchar

#include<stdio.h>
#include<wchar.h>
#include <malloc.h>
#include<string.h>


struct wchar_sub{
    wchar_t *tmp;
    wchar_t *arrW;
    char* typew;
    size_t typeLenw;
    struct wchar_sub (*addw)(struct _ArrayWchar*, wchar_t );
    int (*getw)(struct _ArrayWchar*, int );
    void (*initw)(struct _ArrayWchar* );

    void (*expandw)(struct _ArrayWchar* , int) ;
    void (*print_w)(struct _ArrayWchar* );

    size_t (*sizew)(struct _ArrayWchar* );
    void (*freeArrw)(struct _ArrayWchar* );
};



struct _ArrayWchar{

    struct wchar_sub typeW;

    int maxw;
    int usedBeforew;

};

void initw(struct _ArrayWchar* self);
//void arrMove();
void expandw(struct _ArrayWchar* self, int _mul) ;
void print_W(struct _ArrayWchar* self);
struct wchar_sub addW(struct _ArrayWchar* self, wchar_t var1);

wchar_t getW(struct _ArrayWchar* self, int index1);

size_t sizeW(struct _ArrayWchar* self);
void freeArrW(struct _ArrayWchar* self);


const struct wchar_sub wchar_set = {
        .typew = "wchar_t",
        .typeLenw = sizeof(wchar_t),
        .addw =  &addW,
        .getw =  &getW,
        .initw = &initw,

        .expandw =  &expandw,
        .print_w = &print_W,

        //.typeI.addi = &addI,
        //.typeI.geti =  &getI,

        .sizew = &sizeW,
        .freeArrw = &freeArrW
};


void initw(struct _ArrayWchar* self){
    fputs("~~~first initi\n",stdout);

    if(strcmp(self->typeW.typew, "wchar_t") == 0)
    {
        //puts("~~~");
        self->typeW.arrW = (wchar_t*)malloc(10 * self->typeW.typeLenw);
        printf("~~~wchar_t initi\n",self->typeW.typeLenw);
    }else{
        fputs("initi typei error\n",stdout);
    }
    self->maxw = 10;
    self->usedBeforew = 0;
}

void expandw(struct _ArrayWchar* self, int _mul) {
    // 扩容 不为NULL

    if(strcmp(self->typeW.typew, "wchar_t") == 0)
    {
        puts("expanding wchar_t array~~");
        while((self->typeW.arrW = (wchar_t*)realloc(self->typeW.arrW, self->maxw * _mul * self->typeW.typeLenw)) == NULL){}
    }

    self->maxw *= _mul;
    printf("~~maxi: %d\n",self->maxw);
}
void print_W(struct _ArrayWchar* self) {

    if(strcmp(self->typeW.typew, "wchar_t") == 0){
        //puts("printw~~~");
        for (int i = 0; i < self->usedBeforew; i++) {
            if (i == 0)wprintf(L"[%lc, ", getW(self,i));
            else if (i == self->usedBeforew - 1)wprintf(L"%lc]\n", getW(self, i));
            else wprintf(L"%lc, ", getW(self,i));
        }
    }
}


struct wchar_sub addW(struct _ArrayWchar* self, wchar_t var1){
    if(self->maxw == -1){self->typeW.initw(self);} // 初始化

    if(self->usedBeforew < self->maxw){
        self->typeW.arrW[self->usedBeforew] = var1;
        self->usedBeforew++;
    }else{
        self->typeW.expandw(self, 2);

        self->typeW.arrW[self->usedBeforew] = var1;
        self->usedBeforew++;
    }return self->typeW;
}



wchar_t getW(struct _ArrayWchar* self, int index1){
    return self->typeW.arrW[index1];
}
size_t sizeW(struct _ArrayWchar* self){
    return self->usedBeforew;
}
void freeArrW(struct _ArrayWchar* self){
    //if(strcmp(self->_wchar.typei, "wchar_t") == 0)free(self->_wchar.arrI);

    if(strcmp(self->typeW.typew, "wchar_t") == 0)free(self->typeW.arrW);
    self->maxw = -1;
    self->usedBeforew = 0;

}
#endif
