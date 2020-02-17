//关系运算符重载-2/17(如>,<,==,!=) 如类之间的比较设计
#include<iostream>
using namespace std;
class Person{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age){
        m_Name = name;
        m_Age = age;
    }
    //重载==号
    bool operator==(Person &p){
        if(this->m_Name==p.m_Name && this->m_Age==p.m_Age){
            return true;
        }
        return false;
    }
};
void test01(){
    Person p1("Tom", 18);
    Person p2("Jerry", 18);
    if(p1 == p2){
        cout << "p1和p2是相等的" << endl;
    }else{
        cout << "p1和p2是不相等的" << endl; 
    }
    
}
int main(){
    test01();
    system("pause");
    return 0;
}
