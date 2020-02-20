//纯虚函数和抽象类
#include<iostream>
using namespace std;
class Base{ // 有一个纯虚函数，它就是抽象类
public:
    //目的：让子类重写
    virtual void func() = 0; // 纯虚函数语法 {}代替为0
};
class Son : public Base{
public:
    void func(){
        cout << "func函数调用" << endl;
    }
};
void test01(){
    //Base b;new Base; // 抽象类不能实例化
    //抽象类的子类必须重写父类的纯虚函数
    //Son s;//必须重写，否则无法实例化
    Base *base = new Son;
    base->func();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
