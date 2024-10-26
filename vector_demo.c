
/*
 * compiler msvc
 */
#include "array_int.h"
#include "array_float.h"
#include "array_wchar.h"
#include<locale.h>
//#include<windows.h>


int main(){

    //SetConsoleOutputCP(65001);
    struct _ArrayInt arrInt = {
           .typeI = int_set,
           .maxi = -1          // 函数指针 对应函数首地址
    };
    struct _ArrayInt* arrIntPtr = &arrInt;
    arrInt.typeI.addi(arrIntPtr, 1).addi(arrIntPtr, 2).addi(arrIntPtr, 3).addi(arrIntPtr, 4);
    printf("geti int value: %d\n",arrInt.typeI.geti(arrIntPtr, 0));

    arrInt.typeI.print_i(arrIntPtr);
    arrInt.typeI.freeArri(arrIntPtr);


    for(int i=0;i<64;i++){
        arrInt.typeI.addi(arrIntPtr,i);
    }

    //arrInt.typeI.addi(arrIntPtr, 4).addi(arrIntPtr, 3).addi(arrIntPtr, 1).addi(arrIntPtr, 2);
    printf("int array sizei: %d\n",arrInt.typeI.sizei(arrIntPtr));

    arrInt.typeI.print_i(arrIntPtr);
    arrInt.typeI.freeArri(arrIntPtr);puts("");


    struct _ArrayFloat arrFloat = {
            .typeF = float_set,
            .maxf = -1          // 函数指针 对应函数首地址
    };
    struct _ArrayFloat* arrFloatPtr = &arrFloat;
    arrFloat.typeF.addf(arrFloatPtr, 1.1F).addf(arrFloatPtr, 2.2F)
    .addf(arrFloatPtr, 3.3F).addf(arrFloatPtr, 4.4F);
    printf("geti float value: %f\n",arrFloat.typeF.getf(arrFloatPtr, 0));

    arrFloat.typeF.print_f(arrFloatPtr);
    arrFloat.typeF.freeArrf(arrFloatPtr);

    for(float i=0.0;i<47.8;i+=0.1){
        arrFloatPtr->typeF.addf(arrFloatPtr,i);
    }

    //arrFloat.typeF.addf(arrFloatPtr, 4.4).addf(arrFloatPtr, 2.2)
    //.addf(arrFloatPtr, 3.3).addf(arrFloatPtr, 1.1);
    printf("float array sizei: %zd\n",arrFloat.typeF.sizef(arrFloatPtr));

    arrFloat.typeF.print_f(arrFloatPtr);
    arrFloat.typeF.freeArrf(arrFloatPtr);puts("");

    setlocale(LC_ALL,"");
    struct _ArrayWchar arrWchar = {
            .typeW = wchar_set,
            .maxw = -1          // 函数指针 对应函数首地址
    };

    struct _ArrayWchar* arrWcharPtr = &arrWchar;
    for(int i=16384;i<32768;i++){
        arrWchar.typeW.addw(arrWcharPtr,(wchar_t)i);
    }
    //arrWchar.typeW.addw(arrWcharPtr, L'一').addw(arrWcharPtr, L'二')
    //.addw(arrWcharPtr, L'三').addw(arrWcharPtr, L'十');
    wprintf(L"geti wchar value: %lc\n",arrWchar.typeW.getw(arrWcharPtr, 0));
    printf("wchar array sizei: %zd\n",arrWchar.typeW.sizew(arrWcharPtr));

    arrWchar.typeW.print_w(arrWcharPtr);
    arrWchar.typeW.freeArrw(arrWcharPtr);puts("");

    return 0;
}
