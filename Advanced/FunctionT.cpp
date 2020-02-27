//函数模板案例 
#include<iostream>
using namespace std;
template<typename T> //声明一个模板，告诉编译器后面紧跟的T不要报错，T是一个通用的数据类型
//typename可以替换成class（效果一样）
void  mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
//使用注意事项
    /* 
        1.自动类型推导必须导出一致的数据类型T才可以使用，也就是第一种使用方法
        比如整型和字符型交换 char c = 'c';mySwap(a,c);就会出问题，推导不出一致的T
    */
   /*
        2.模板必须要确定出T的数据类型，才可以使用，即你必须用上T；（第一种方法出错）
        如果想正常运行，只能使用第二种方法显示指定类型，代替自动推导
   */
void test(){
    int a = 10;
    int b = 20;
    //两种方式使用模板
    //1.自动类型推导
    //mySwap(a, b);
    //2.显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main(){
    test();
    system("pause");
    return 0;
}
