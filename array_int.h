#ifndef _arrayInt
#define _arrayInt

#include<stdio.h>
#include<stdbool.h>
#include <malloc.h>
#include<string.h>


struct int_sub {
    int *tmp;
    int *arr;
    char *type;
    int maxi;
    size_t typeLeni;

    struct int_sub (*add)(struct ArrayInt *, int);
    bool (*remove)(struct ArrayInt *, int);
    int (*get)(struct ArrayInt *, int);
    void (*initi)(struct ArrayInt *);
    void (*expandi)(struct ArrayInt *, int);
    void (*print)(struct ArrayInt *);
    int (*size)(struct ArrayInt *);
    void (*freeArr)(struct ArrayInt *);
};


struct ArrayInt {
    struct int_sub _int;
    int usedBeforei;
};

void initI(struct ArrayInt *self);
void expandI(struct ArrayInt *self, int _mul);
void print_I(struct ArrayInt *self);
struct int_sub addI(struct ArrayInt *self, int var1);
bool removeI(struct ArrayInt *self, int var1);
int getI(struct ArrayInt *self, int index1);
void leftmoveI(int *arr, int start, int end, int setp);
int sizeI(struct ArrayInt *self);
void freeArrI(struct ArrayInt *self);

const struct int_sub int_set = {
        .type = "int",
        .typeLeni = sizeof(int),
        .maxi = -1,
        .add =  &addI,
        .remove = &removeI,
        .get =  &getI,
        .initi = &initI,

        .expandi =  &expandI,
        .print = &print_I,

        .size = &sizeI,
        .freeArr = &freeArrI
};


void initI(struct ArrayInt *self) {

    if (strcmp(self->_int.type, "int") == 0) {
        self->_int.arr = (int *) malloc(10 * self->_int.typeLeni);
        fputs("~~~int initi \n", stdout);

    } else {
        fputs("initi type error\n", stdout);
    }
    self->_int.maxi = 10;
    self->usedBeforei = 0;
}

void expandI(struct ArrayInt *self, int _mul) {
    // 扩容 不为NULL
    if (strcmp(self->_int.type, "int") == 0) {
        puts("expanding int array~~");
        while ((self->_int.arr = (int *) realloc(self->_int.arr, self->_int.maxi * _mul * self->_int.typeLeni)) ==
               NULL) {}
    }
    self->_int.maxi *= _mul;
    printf("~~maxi: %d\n", self->_int.maxi);
}

void print_I(struct ArrayInt *self) {
    if (strcmp(self->_int.type, "int") == 0) {
        for (int i = 0; i < self->usedBeforei; i++) {
            if (i == 0)printf("[%d, ", getI(self, i));
            else if (i == self->usedBeforei - 1)printf("%d]\n", getI(self, i));
            else printf("%d, ", getI(self, i));
        }
    }

}

struct int_sub addI(struct ArrayInt *self, int var1) {
    if (self->_int.maxi == -1) { self->_int.initi(self); } // 初始化
    if (self->usedBeforei < self->_int.maxi) {
        self->_int.arr[self->usedBeforei] = var1;
        self->usedBeforei++;
    } else {
        self->_int.expandi(self, 2);

        self->_int.arr[self->usedBeforei] = var1;
        self->usedBeforei++;
    }
    return self->_int;
}

bool removeI(struct ArrayInt *self, int var1) {
    for (int i = 0; i < self->usedBeforei; i++) {
        if (self->_int.arr[i] == var1) { // 有var1
            leftmoveI(self->_int.arr, i, self->usedBeforei, 1);
            self->usedBeforei--; // 少了一个
        }
    }
    return true;
}

void leftmoveI(int *arr, int start, int end, int step) {
    for (int i = 0; i < end - start + step; i++) {
        arr[start + i] = arr[start + i + step];
    }
}

int getI(struct ArrayInt *self, int index1) {
    return self->_int.arr[index1];
}

int sizeI(struct ArrayInt *self) {
    return self->usedBeforei;
}

void freeArrI(struct ArrayInt *self) {

    if (strcmp(self->_int.type, "int") == 0)free(self->_int.arr);

    self->_int.maxi = -1;
    self->usedBeforei = 0;
}

#endif
