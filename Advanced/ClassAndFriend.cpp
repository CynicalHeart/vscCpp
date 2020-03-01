//类模板与友元
#include<iostream>
using namespace std;
template<class T1,class T2>
class Person;
//不用加作用域，但需要声明模板
template<class T1,class T2>
void printPerson2(Person<T1, T2> p){
    cout << "类外实现 -- 姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
}

template<class T1,class T2>
class Person{
    //全局函数类内实现
    friend void printPerson(Person<T1,T2> p){
        cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
    }
    //全局函数类外实现
    //加一个空模板参数列表
    //全局函数类外实现，需要让编译器提前知道这个函数存在
    friend void printPerson2<>(Person<T1, T2> p);

public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name , T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson(){
        cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << endl;
    }
};


void test01(){
    Person<string, int> p("Tom", 20);
    printPerson(p);
}
void test02(){
    Person<string, int> p("Jerry", 20);
    printPerson2(p);
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
