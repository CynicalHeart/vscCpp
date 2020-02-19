//多继承（不建议使用）-2/19
#include<iostream>
using namespace std;
class Base1{
public:
    int m_A;
    Base1(){
        m_A = 100;
    }
};
class Base2{
public:
    int m_A;
    Base2(){
        m_A = 200;
    }
};
//继承Base1和Base2
class Son : public Base1,public Base2{
public: 
    int m_C;
    int m_D;
    Son(){
        m_C = 300;
        m_D = 400;
    }
};
void test01(){
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;//查看Son的自己，自己的两个属性加两个父类的属性
    //当父类出现同名成员需要加作用域
    cout << "m_A = " << s.Base1::m_A << endl;
    cout << "m_A = " << s.Base2::m_A << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
