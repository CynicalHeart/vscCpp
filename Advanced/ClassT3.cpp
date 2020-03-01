//类模板实例化出的对象，向函数传参的方式
#include<iostream>
using namespace std;
//类模板对象函数做参数 
template<class T1,class T2>
class Person{
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
//1.指定传入的类型
void printPerson1(Person<string,int>&p){
    p.showPerson();
}
void test01(){
    Person<string, int> p("赵蕾", 22);
    printPerson1(p);
}
//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
    //显示 T1，T2的数据类型,使用 typeid().name
    cout << "T1的类型为： " << typeid(T1).name()<< endl;
    cout << "T2的类型为： " << typeid(T2).name()<< endl;
}
void test02(){
    Person<string, int> p("王琦", 23);
    printPerson2(p);
}
//3.整个类模板化，T识别一个类Person
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout << "T的类型为： " << typeid(T).name()<< endl;
}
void test03(){
    Person<string, int> p("萱儿", 23);
    printPerson3(p);
}
int main(){
    test01();
    test02();
    test03();   
    system("pause");
    return 0;
}
