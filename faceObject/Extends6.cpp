//继承同名静态成员处理-2/19
#include<iostream>
using namespace std;
class Base{
public:
    static int m_A;
    static void func(){
        cout << "Base - static void func" << endl;
    }
};
int Base::m_A = 100;//类内声明，类外初始化。
class Son : public Base{
public:
    static int m_A;
    static void func(){
        cout << "Son - static void func" << endl;
    }
};
int Son::m_A = 200;

void test01(){
    //1.通过对象访问
    Son s;
    cout << "Son m_A = " << s.m_A << endl;
    cout << "Base m_A = " << s.Base::m_A << endl;
    //2.通过类名访问静态成员
    cout << "Son m_A ="<< Son::m_A << endl;
    cout << "Base m_A ="<< Son::Base::m_A << endl;//Son类访问父类作用域下属性
}
void test02(){
    //通过对象访问静态方法
    Son s;
    s.func();
    s.Base::func();
    //通过类名访问静态方法
    Son::func();
    Son::Base::func();
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
