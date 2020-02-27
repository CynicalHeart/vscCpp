//普通函数和模板函数的区别
#include<iostream>
using namespace std;
/*  1、普通函数调用可以发生隐式类型转换
    2、函数模板用自动类型推导，不可以发生隐式类型转换
    3、函数模板用显示指定类型，可以发生隐式类型转换
*/
int myAdd01(int a , int b){
    return a + b;
}
//函数模板
template<class T>
T myAdd02(T a,T b){
    return a + b;
}
//普通函数
void test01(){
    int a = 10;
    int b = 20;
    char c = 'c'; // a - 97 , c - 99 字符型隐式转成asc 
    cout << myAdd01(a, c) << endl;
    //自动类型推导，不能隐式转换
    //cout << myAdd02(a, c) << endl; 
    //显示指定类型 不是int类型都转成int,能隐式转换。
    cout << myAdd02<int>(a, c) << endl;
}

int main(){
    test01();
    system("pause");
    return 0;
}
