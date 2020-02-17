//递增运算符重载-2/17
#include<iostream>
using namespace std;
//自定义整型
class MyInteger{
    friend ostream &operator<<(ostream &cout, MyInteger myInt);//全局函数友元访问私有属性
public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符;返回引用是为了对同一个数据进行++操作，如果返回对象，则会新创建一个对象，加加操作不在原数上。
    MyInteger& operator++(){
        m_Num++;
        return *this;
    }
    //重载后置++运算符,int 用于占位，负责区分前置后置
    //后置版本的重载++不能返回引用，函数返回一个临时变量违规
    MyInteger operator++(int){
        MyInteger temp = *this;//临时变量存储原对象值
        m_Num++;
        return temp;
    }
private:
    int m_Num;
};
//重載左移运算符
ostream& operator<<(ostream& cout,MyInteger myInt){
    cout << myInt.m_Num;
    return cout;
}
void test01(){
    MyInteger myInt;
    cout << ++myInt << endl;
}
void test02(){
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
