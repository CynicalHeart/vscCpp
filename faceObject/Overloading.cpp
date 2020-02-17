//加号运算符重载-2/16 
#include<iostream>
using namespace std;
class Person{
public:
    //1.成员函数重载加号,本质Person p3 = p1.operator+(p2);
    /*  Person operator+(Person &p) {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    } */
    int m_A;
    int m_B;
};
//2.全局函数重载加号,本质Person p3 = operator+(p1,p2)
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
void test01(){
    //设计两个用例， 让他们相加，设计加号重载
    Person p1; 
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;
    Person p3 = p1 + p2;
    cout << "p3.m_A=" <<p3.m_A<<endl;
    cout << "p3.m_B=" <<p3.m_B<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
