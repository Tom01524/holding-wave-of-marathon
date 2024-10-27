#ifndef _arrayFloat
#define _arrayFloat

#include<stdio.h>
#include <malloc.h>
#include<string.h>


struct float_sub {
    float *tmp;
    float *arr;
    char *type;
    int maxf;
    size_t typeLenf;

    struct float_sub (*add)(struct ArrayFloat *, float);
    bool (*remove)(struct ArrayFloat *, float);
    float (*get)(struct ArrayFloat *, int);
    void (*initf)(struct ArrayFloat *);
    void (*expandf)(struct ArrayFloat *, int);
    void (*print)(struct ArrayFloat *);
    size_t (*size)(struct ArrayFloat *);
    void (*freeArr)(struct ArrayFloat *);
};


struct ArrayFloat {
    struct float_sub _float;
    int usedBeforef;

};

void initF(struct ArrayFloat *self);
void expandF(struct ArrayFloat *self, int _mul);
void print_F(struct ArrayFloat *self);
struct float_sub addF(struct ArrayFloat *self, float var1);
bool removeF(struct ArrayFloat *self, float var1);
void leftmoveF(float *arr, int start, int end, int step);
float getF(struct ArrayFloat *self, int index1);
size_t sizeF(struct ArrayFloat *self);
void freeArrF(struct ArrayFloat *self);


const struct float_sub float_set = {
        .type = "float",
        .typeLenf = sizeof(float),
        .maxf = -1,
        .add =  &addF,
        .remove = &removeF,
        .get =  &getF,
        .initf = &initF,

        .expandf =  &expandF,
        .print = &print_F,

        .size = &sizeF,
        .freeArr = &freeArrF
};

void initF(struct ArrayFloat *self) {
    if (strcmp(self->_float.type, "float") == 0) {
        //puts("~~~");
        self->_float.arr = (float *) malloc(10 * self->_float.typeLenf);
        fputs("~~~float initi\n", stdout);
    } else {
        fputs("initi type error\n", stdout);
    }
    self->_float.maxf = 10;
    self->usedBeforef = 0;
}

void expandF(struct ArrayFloat *self, int _mul) {
    // 扩容 不为NULL
    if (strcmp(self->_float.type, "float") == 0) {
        puts("expanding float array~~");
        while ((self->_float.arr = (float *) realloc(self->_float.arr,
                                                     self->_float.maxf * _mul * self->_float.typeLenf)) == NULL) {}
    }

    self->_float.maxf *= _mul;
    printf("~~maxi: %d\n", self->_float.maxf);
}

void print_F(struct ArrayFloat *self) {

    if (strcmp(self->_float.type, "float") == 0) {
        //puts("printw~~~");
        for (int i = 0; i < self->usedBeforef; i++) {
            if (i == 0)printf("[%f, ", getF(self, i));
            else if (i == self->usedBeforef - 1)printf("%f]\n", getF(self, i));
            else printf("%f, ", getF(self, i));
        }
    }
}


struct float_sub addF(struct ArrayFloat *self, float var1) {
    if (self->_float.maxf == -1) { self->_float.initf(self); } // 初始化
    //puts("add~~");
    if (self->usedBeforef < self->_float.maxf) {
        self->_float.arr[self->usedBeforef] = var1;
        self->usedBeforef++;
    } else {
        self->_float.expandf(self, 2);

        self->_float.arr[self->usedBeforef] = var1;
        self->usedBeforef++;
    }
    return self->_float;
}

bool removeF(struct ArrayFloat *self, float var1) {
    for (int i = 0; i < self->usedBeforef; i++) {
        if (self->_float.arr[i] == var1) { // 有var1
            leftmoveF(self->_float.arr, i, self->usedBeforef, 1);
            self->usedBeforef--; // 少了一个
        }
    }
    return true;
}

void leftmoveF(float *arr, int start, int end, int step) {
    for (int i = 0; i < end - start + step; i++) {
        arr[start + i] = arr[start + i + step];
    }
}

float getF(struct ArrayFloat *self, int index1) {
    return self->_float.arr[index1];
}

size_t sizeF(struct ArrayFloat *self) {
    return self->usedBeforef;
}

void freeArrF(struct ArrayFloat *self) {
    //if(strcmp(self->_wchar.type, "wchar_t") == 0)free(self->_wchar.arr);

    if (strcmp(self->_float.type, "float") == 0)free(self->_float.arr);
    self->_float.maxf = -1;
    self->usedBeforef = 0;

}

#endif
