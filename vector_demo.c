#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdbool.h>
#include <malloc.h>
#include"IntVector.h"


extern struct _IntVec VectorInt; // 88 bytes
#define primex VectorInt



int startx = 2;
const int endx = 50000;
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
    for (int k = 0; k < primex.size(); k++) {
        printf("%d  ", primex.get(k));
    }


    printf("\nlength=%d\n", primex.size());
}
int main(){
    //std::ios_base::sync_with_stdio(false);

    for(int j=startx;j<endx;j++){
        if(j==2){
            primex.add(2); //第一个2
            //puts("add:2");
        }
        else{
            if(is_prime(j)){
                primex.add(j);
                //printf("add: %d\n", j);

            }
        }
    }
    back1:
    int count;
    fputs("input 1 to continue\n",stdout);
    scanf("%d",&count);

    if(count == 1)primex.print();//list_show();
    else goto back1;
    primex.freeArr(); // reset for new start


    return 0;
}
