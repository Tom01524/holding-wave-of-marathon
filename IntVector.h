
void init();
void arrMove();
void expand(int _mul) ;
void print();
void add(int var1);
int get(int index1);
int size();
void freeArr();

struct _IntVec{
    int* arr;
    int* nextArr;
    int max;
    int usedBefore;

    void (*init)();
    void (*arrMove)();
    void (*expand)(int _mul) ;
    void (*print)();
    void (*add)(int var1);
    int (*get)(int index1);
    int (*size)();
    void (*freeArr)();


};

struct _IntVec VectorInt = {
        .max = -1,
        .init = &init,
        .arrMove = &arrMove,
        .expand = &expand,
        .print = &print,
        .add = &add,
        .get = &get,
        .size = &size,
        .freeArr = &freeArr
};

void init(){
    fputs("~~first init\n",stdout);
    VectorInt.arr = (int*)malloc(10*sizeof(int));
    VectorInt.max = 10;
    VectorInt.usedBefore = 0;
}
void arrMove(){
    for(int i=0;i<VectorInt.usedBefore;i++){
        VectorInt.nextArr[i] = VectorInt.arr[i];
        //printf("moving: %d\n", arr[i]);
    }
}
void expand(int _mul) {

    while((VectorInt.nextArr = (int*)malloc(VectorInt.max * _mul * sizeof(int))) == NULL); // 扩容

    fputs("~~realloc\n",stdout);
    arrMove(); // 扩容
    fputs("~~arr move\n",stdout);
    free(VectorInt.arr);

    VectorInt.arr = VectorInt.nextArr; // 扩容
    VectorInt.max *= _mul;
    printf("~~max: %d\n",VectorInt.max);
}
void print() {
    for (int i = 0; i < VectorInt.usedBefore; i++) {
        if (i == 0)printf("[%d, ", VectorInt.arr[i]);
        else if (i == VectorInt.usedBefore - 1)printf("%d]\n", VectorInt.arr[i]);
        else printf("%d, ", VectorInt.arr[i]);
    }
}
void add(int var1){
    if(VectorInt.max == -1){VectorInt.init();} // 初始化
    if(VectorInt.usedBefore<VectorInt.max){
        VectorInt.arr[VectorInt.usedBefore] = var1;
        VectorInt.usedBefore++;
    }else{
        VectorInt.expand(2);

        VectorInt.arr[VectorInt.usedBefore] = var1;
        VectorInt.usedBefore++;
    }
}
int get(int index1){
    return VectorInt.arr[index1];
}
int size(){
    return VectorInt.usedBefore;
}
void freeArr(){
    free(VectorInt.arr);
    VectorInt.max = -1;
    VectorInt.usedBefore = 0;
    VectorInt.arr = NULL;
    VectorInt.nextArr = NULL;
}
