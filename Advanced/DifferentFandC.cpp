//类模板与函数模板的区别
#include<iostream>
using namespace std;
template<class NameType , class AgeType = int> //默认参数
class Person{
public:
    NameType m_Name;
    AgeType m_Age;
    Person(NameType name ,AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }
    void shouPerson(){
        cout << "name = " << this->m_Name << " age = " << this->m_Age << endl;
    }
};
//类模板没有自动推导使用方法
void test01(){
    //Person p1("赵蕾", 22);无法用自动类型推导
    Person<string, int> p1("赵蕾", 22);
    p1.shouPerson();
}
//类模板参数列表中可以有默认参数
void test02(){
    Person<string> p("王琦", 23);
    p.shouPerson();
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
