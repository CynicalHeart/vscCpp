//普通函数与函数模板调用规则
#include<iostream>
using namespace std;
//1.如果函数模板和普通函数都可以调用，则优先调用普通函数
//2.通过空模板参数列表，强制调用模板函数
//3.模板也可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板
void myPrint(int a , int b){
    cout << "调用的是普通函数" << endl;
}
template<class T>
void myPrint(T a,T b){
    cout << "调用的是函数模板" << endl;
}
template<class T>
void myPrint(T a,T b,T c){//模板函数发生重载
    cout << "调用的是重载的函数模板" << endl;
}
void test01(){
    int a = 10;
    int b = 20;

    //优先调用普通函数,即使普通函数没有实现。
    myPrint(a,b); 
    
    //通过空模板参数列表强制使用模板函数
    myPrint<>(a, b);

    myPrint(a, b, 100);//重载

    //函数模板产生更好的匹配，优先使用模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2); //调用普通函数会进行隐式转换，所以优先调用函数模板，匹配更好
}
int main(){
    test01();
    system("pause");
    return 0;
}
