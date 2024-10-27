
/*
 * compiler msvc
 */
#include "array_int.h"
#include "array_float.h"
#include "array_wchar.h"
#include "array_wstr.h"
#include<locale.h>

//#include<windows.h>


int main(){

    //SetConsoleOutputCP(65001);
    struct ArrayInt demo1 = {._int = int_set};
    /*for(int i=0;i<64;i++){
        demo1._int.add(listIntPtr, i);
    }*/
    demo1._int.add(&demo1, 4).add(&demo1, 3).add(&demo1, 1).add(&demo1, 2)
    .add(&demo1, 5).add(&demo1, 8).add(&demo1, 6);
    printf("int array size: %d\n", demo1._int.size(&demo1));

    demo1._int.print(&demo1);
    printf("remove:%d\n",1);
    demo1._int.remove(&demo1, 1);
    demo1._int.print(&demo1);
    printf("remove:%d\n",3);
    demo1._int.remove(&demo1, 3);
    demo1._int.print(&demo1);
    demo1._int.freeArr(&demo1);puts("");


    struct ArrayFloat demo2 = {._float = float_set};
    //for(float i=0.0;i<47.8;i+=0.1){
        //listFloatPtr->_float.add(listFloatPtr, i);
    //}
    demo2._float.add(&demo2, 4.4).add(&demo2, 2.2)
    .add(&demo2, 3.3).add(&demo2, 1.1)
    .add(&demo2, 3.1415926).add(&demo2, 123.456)
    .add(&demo2, 765.432).add(&demo2, 22.3344);
    printf("float array size: %zd\n", demo2._float.size(&demo2));

    demo2._float.print(&demo2);
    printf("remove:%f\n",2.2);
    demo2._float.remove(&demo2, 2.2);
    demo2._float.print(&demo2);
    printf("remove:%f\n",3.3);
    demo2._float.remove(&demo2, 3.3);
    demo2._float.print(&demo2);

    demo2._float.freeArr(&demo2);puts("");


    setlocale(LC_ALL,"");
    struct ArrayWchar demo3 = {._wchar = wchar_set};

    //for(int i=16384;i<32768;i++){
        //demo3._wchar.add(listWcharPtr, (wchar_t)i);
    //}
    demo3._wchar.add(&demo3, L'一').add(&demo3, L'二')
    .add(&demo3, L'三').add(&demo3, L'十').add(&demo3, L'人')
    .add(&demo3, L'个').add(&demo3, L'大');
    wprintf(L"get wchar value: %lc\n", demo3._wchar.get(&demo3, 0));
    printf("wchar array size: %zd\n", demo3._wchar.size(&demo3));
    demo3._wchar.print(&demo3);
    wprintf(L"remove %lc\n",L'十');demo3._wchar.remove(&demo3, L'十');
    demo3._wchar.print(&demo3);
    wprintf(L"remove %lc\n",L'大');demo3._wchar.remove(&demo3, L'大');
    demo3._wchar.print(&demo3);

    demo3._wchar.freeArr(&demo3);puts("");


    struct ArrayWchar demo4 = {._wchar = wchar_set};
    wprintf(L"use vector<char> as string...\n");

    demo4._wchar.add_str(&demo4, L"今天天气不错");
    printf("wchar array size: %zd\n", demo4._wchar.size(&demo4));
    demo4._wchar.print_str(&demo4);
    demo4._wchar.freeArr(&demo4);puts("");


    struct ArrayWstr demo5 = {._wstr = wstr_set};
    //for(int i=0;i<300;i++){
        //demo5._wstr.add( &demo5, L"你好");
    //}
    demo5._wstr.add(&demo5, L"你好").add(&demo5, L"谢谢")
            .add(&demo5, L"再见").add(&demo5, L"世界").add(&demo5, L"Hello")
            .add(&demo5, L"Thank you!").add(&demo5, L"Bye bye~");
    wprintf(L"get wchar value: %ls\n", demo5._wstr.get(&demo5, 0));

    printf("wchar array size: %zd\n", demo5._wstr.size(&demo5));

    demo5._wstr.print(&demo5);

    demo5._wstr.remove(&demo5, L"再见");
    wprintf(L"remove %ls\n",L"再见");
    demo5._wstr.print(&demo5);

    demo5._wstr.remove(&demo5, L"谢谢");
    wprintf(L"remove %ls\n",L"谢谢");
    demo5._wstr.print(&demo5);

    demo5._wstr.freeArr(&demo5);puts("");


    return 0;

}
