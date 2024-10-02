
void init();
//void arrMove();
void expand(int _mul) ;
void print();
void add(int var1);
int get(int index1);
int size();
void freeArr();

struct _IntVec{
    int* arr;
    //int* nextArr;
    int max;
    int usedBefore;

    void (*init)();
    //void (*arrMove)();
    void (*expand)(int _mul) ;
    void (*print)();
    void (*add)(int var1);
    int (*get)(int index1);
    int (*size)();
    void (*freeArr)();


};

struct _IntVec VectorInt= { // 初始化结构体 max = -1
        .max = -1,          // 函数指针 对应函数首地址
        .init = &init,
        //.arrMove = &arrMove,
        .expand = &expand,
        .print = &print,
        .add = &add,
        .get = &get,
        .size = &size,
        .freeArr = &freeArr
};
struct _IntVec* VecIntPtr = &VectorInt;

void init(){
    fputs("~~first init\n",stdout);
    VecIntPtr->arr = (int*)malloc(10*sizeof(int));
    VecIntPtr->max = 10;
    VecIntPtr->usedBefore = 0;
}
//void arrMove(){
//    for(int i=0;i<VecIntPtr->usedBefore;i++){
//        VecIntPtr->nextArr[i] = VecIntPtr->arr[i];
//        //printf("moving: %d\n", arr[i]);
//    }
//}
void expand(int _mul) {
    // 扩容 不为NULL
    while((VecIntPtr->arr = (int*)realloc(VecIntPtr->arr,VecIntPtr->max * _mul * sizeof(int))) == NULL){}

    fputs("~~realloc\n",stdout);
    //arrMove(); // 扩容

    //free(VecIntPtr->arr);

    //VecIntPtr->arr = VecIntPtr->nextArr; // 扩容
    VecIntPtr->max *= _mul;
    printf("~~max: %d\n",VecIntPtr->max);
}
void print() {
    for (int i = 0; i < VecIntPtr->usedBefore; i++) {
        if (i == 0)printf("[%d, ", VecIntPtr->arr[i]);
        else if (i == VecIntPtr->usedBefore - 1)printf("%d]\n", VecIntPtr->arr[i]);
        else printf("%d, ", VecIntPtr->arr[i]);
    }
}
void add(int var1){
    if(VecIntPtr->max == -1){VecIntPtr->init();} // 初始化
    if(VecIntPtr->usedBefore<VecIntPtr->max){
        VecIntPtr->arr[VecIntPtr->usedBefore] = var1;
        VecIntPtr->usedBefore++;
    }else{
        VecIntPtr->expand(2);

        VecIntPtr->arr[VecIntPtr->usedBefore] = var1;
        VecIntPtr->usedBefore++;
    }
}
int get(int index1){
    return VecIntPtr->arr[index1];
}
int size(){
    return VecIntPtr->usedBefore;
}
void freeArr(){
    free(VecIntPtr->arr);
    VecIntPtr->max = -1;
    VecIntPtr->usedBefore = 0;
    VecIntPtr->arr = NULL;
    //VecIntPtr->nextArr = NULL;
}
