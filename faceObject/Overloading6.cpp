//函数调用运算符重载,函数的小括号发生重载-称其为仿函数，没有固定写法非常零落
#include<iostream>
using namespace std;
//打印输出类
class Myprint{
public:
    //重载函数调用运算符
    void operator()(string test){
        cout << test << endl;
    }
};
//加法类
class MyAdd{
public:
    int operator()(int num1,int num2){
        return num1 + num2;
    }
};
void test01(){
    Myprint myPrint;
    myPrint("Hello World!");//仿函数指的是在用的时候像函数
}
void test02(){
    MyAdd myAdd;
    int res = myAdd(100, 100);
    cout <<"res = "<< res << endl;
    //匿名函数对象
    cout << "MyAdd()(100,100)匿名函数对象使用"<<MyAdd()(100, 100) << endl;
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
