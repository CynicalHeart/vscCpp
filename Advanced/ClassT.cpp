//类模板
#include<iostream>
using namespace std;

template<class NameType,class AgeType>
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
void test01(){
    Person<string, int> p1("赵蕾", 22);
    p1.shouPerson();
}

int main(){
    test01();
    system("pause");
    return 0;
}
