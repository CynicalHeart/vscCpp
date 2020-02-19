//继承中同名成员的处理
#include<iostream>
using namespace std;
class Base{
public:
    int m_A;
    Base(){
        m_A = 100;
    }
    void func(){
        cout << "Base - func()函数调用" << endl;
    }
    void func(int){
        cout << "Base - func(int)函数调用" << endl;
    }
};
class Son : public Base{
public:
    int m_A;
    Son(){
        m_A = 200;
    }
    void func(){
        cout << "Son - func()函数调用" << endl;
    }
};
//同名成员属性
void test01(){
    Son s;
    cout << "Son m_A = " << s.m_A << endl; 
    cout << "Base m_A = " << s.Base::m_A << endl; //s.后加上父类的作用域就能拿到父类同名属性
}
//同名成员函数处理
void test02(){
    Son s;
    s.func();//直接调用调用的子类
    
    s.Base::func();//调用父类同名函数
    //如果子类中出现和父类同名的成员函数，子类的同名成员函数会隐藏掉父类所有的同名成员函数
    //想访问父类隐藏的同名成员函数需要加作用域
    s.Base::func(100);
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
