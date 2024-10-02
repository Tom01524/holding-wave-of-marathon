#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdbool.h>

#include"IntVector.h"


struct _IntVec primex = {
        .max = -1,
        .init = &init,
        //.arrMove = &arrMove,
        .expand = &expand,
        .print = &print,
        .add = &add,
        .get = &get,
        .size = &size,
        .freeArr = &freeArr
};
struct _IntVec* primePtr = &primex;

//#define primePtr VecIntPtr



int startx = 2;
const int endx = 20000;
//IntVec primex = (new IntVec())[0];


bool is_prime(int num){
    for(int i=2;i*i<num+1;i++){
        //if(num % i == 0)return false;
        switch(num % i){
            case 0:
                return false;
        }
    }
    return true;
}
void list_show() {
    for (int k = 0; k < primePtr->size(); k++) {
        printf("%d  ", primePtr->get(k));
    }


    printf("\nlength=%d\n", primePtr->size());
}
int main(){

    for(int j=startx;j<endx;j++){
        if(j==2){
            primePtr->add(2); //第一个2
            //puts("add:2");
        }
        else{
            if(is_prime(j)){
                primePtr->add(j);
                //printf("add: %d\n", j);

            }
        }
    }
    back1:
    int count;
    fputs("input 1 to continue\n",stdout);
    scanf("%d",&count);

    if(count == 1)primePtr->print();//list_show();
    else goto back1;
    primePtr->freeArr(); // reset for new start


    return 0;
}
