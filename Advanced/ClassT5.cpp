//类模板成员函数类外实现
#include<iostream>
using namespace std;

template<class T1,class T2>
class Person{
public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name, T2 age);
    // {
    //     this->m_Name = name;
    //     this->m_Age = age;
    // }
    void showPerson();
    // {
    //     cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << endl;
    // }
};
//类外实现构造函数
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age){//类记得加尖括号说明它是类模板而不是普通的模板函数 
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson(){//即使没用T1，T2也得声明模板并加上参数列表
    cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << endl;
}
void test(){
    Person<string, int> p("刘静萱", 24);
    p.showPerson();
}
int main(){
    test();
    system("pause");
    return 0;
}
