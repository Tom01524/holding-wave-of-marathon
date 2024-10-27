#ifndef _arrayWchar
#define _arrayWchar

#include<stdio.h>
#include<wchar.h>
#include <malloc.h>
#include<string.h>
#include<stdbool.h>

struct wchar_sub {
    wchar_t *tmp;
    wchar_t *arr;
    char *type;
    int maxw;
    size_t typeLenw;

    struct wchar_sub (*add)(struct ArrayWchar *, wchar_t);
    void (*add_str)(struct ArrayWchar *, wchar_t*);
    bool (*remove)(struct ArrayWchar *, wchar_t);
    wchar_t (*get)(struct ArrayWchar *, int);
    void (*initw)(struct ArrayWchar *);
    void (*expandw)(struct ArrayWchar *, int);
    void (*print)(struct ArrayWchar *);
    void (*print_str)(struct ArrayWchar *);
    size_t (*size)(struct ArrayWchar *);
    void (*freeArr)(struct ArrayWchar *);
};


struct ArrayWchar {
    struct wchar_sub _wchar;
    int usedBeforew;

};

void initw(struct ArrayWchar *self);
void expandw(struct ArrayWchar *self, int _mul);
void print_W(struct ArrayWchar *self);
void print_WSTR(struct ArrayWchar *self);
struct wchar_sub addW(struct ArrayWchar *self, wchar_t var1);
void add_strW(struct ArrayWchar *self, wchar_t* src_ptr);
bool removeW(struct ArrayWchar *self, wchar_t var1);
void leftmoveW(wchar_t *arr, int start, int end, int step);
wchar_t getW(struct ArrayWchar *self, int index1);
size_t sizeW(struct ArrayWchar *self);
void freeArrW(struct ArrayWchar *self);


const struct wchar_sub wchar_set = {
        .type = "wchar_t",
        .typeLenw = sizeof(wchar_t),
        .maxw = -1,
        .add =  &addW,
        .add_str = &add_strW,
        .remove = &removeW,
        .get =  &getW,
        .initw = &initw,

        .expandw =  &expandw,
        .print = &print_W,
        .print_str = &print_WSTR,

        .size = &sizeW,
        .freeArr = &freeArrW
};


void initw(struct ArrayWchar *self) {

    if (strcmp(self->_wchar.type, "wchar_t") == 0) {

        self->_wchar.arr = (wchar_t *) malloc(10 * self->_wchar.typeLenw);
        fputs("~~~wchar_t initi\n", stdout);
    } else {
        fputs("initi type error\n", stdout);
    }
    self->_wchar.maxw = 10;
    self->usedBeforew = 0;
}

void expandw(struct ArrayWchar *self, int _mul) {
    // 扩容 不为NULL

    if (strcmp(self->_wchar.type, "wchar_t") == 0) {
        puts("expanding wchar_t array~~");
        while ((self->_wchar.arr = (wchar_t *) realloc(self->_wchar.arr,
                                                       self->_wchar.maxw * _mul * self->_wchar.typeLenw)) == NULL) {}
    }

    self->_wchar.maxw *= _mul;
    printf("~~maxi: %d\n", self->_wchar.maxw);
}

void print_W(struct ArrayWchar *self) {

    if (strcmp(self->_wchar.type, "wchar_t") == 0) {
        //puts("printw~~~");
        for (int i = 0; i < self->usedBeforew; i++) {
            if (i == 0)wprintf(L"[%lc, ", getW(self, i));
            else if (i == self->usedBeforew - 1)wprintf(L"%lc]\n", getW(self, i));
            else wprintf(L"%lc, ", getW(self, i));
        }
    }
}
void print_WSTR(struct ArrayWchar *self){
    for (int i = 0; i < self->usedBeforew; i++) {
        wprintf(L"%lc", getW(self, i));
    }puts("");
}

struct wchar_sub addW(struct ArrayWchar *self, wchar_t var1) {
    if (self->_wchar.maxw == -1) { self->_wchar.initw(self); } // 初始化

    if (self->usedBeforew < self->_wchar.maxw) {
        self->_wchar.arr[self->usedBeforew] = var1;
        self->usedBeforew++;
    } else {
        self->_wchar.expandw(self, 2);

        self->_wchar.arr[self->usedBeforew] = var1;
        self->usedBeforew++;
    }
    return self->_wchar;
}

void add_strW(struct ArrayWchar *self, wchar_t* src_ptr){
    int len = wcslen(src_ptr);
    for(int i=0;i<len;i++){
        addW(self,src_ptr[i]);
    }
}

bool removeW(struct ArrayWchar *self, wchar_t var1) {
    for (int i = 0; i < self->usedBeforew; i++) {
        if (self->_wchar.arr[i] == var1) { // 有var1
            leftmoveW(self->_wchar.arr, i, self->usedBeforew, 1);
            self->usedBeforew--; // 少了一个
        }
    }
    return true;
}

void leftmoveW(wchar_t *arr, int start, int end, int step) {
    for (int i = 0; i < end - start + step; i++) {
        arr[start + i] = arr[start + i + step];
    }
}


wchar_t getW(struct ArrayWchar *self, int index1) {
    return self->_wchar.arr[index1];
}

size_t sizeW(struct ArrayWchar *self) {
    return self->usedBeforew;
}

void freeArrW(struct ArrayWchar *self) {

    if (strcmp(self->_wchar.type, "wchar_t") == 0)free(self->_wchar.arr);
    self->_wchar.maxw = -1;
    self->usedBeforew = 0;

}

#endif
