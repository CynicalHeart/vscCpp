//vector容器存放自定义数据类型
#include <iostream>
using namespace std;
#include <vector>
class Person{
public:
    string m_Name;
    int m_age;
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_age = age;
    }
};
void test(){
    vector<Person> v;

    Person p1("赵蕾", 22);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("阿狸", 30);
    Person p5("Loli", 16);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++){
        cout << "姓名：" << (*it).m_Name << ",年龄：" << (*it).m_age << endl;
    }
}
//存放自定义类数据类型 指针
void test02(){
    vector<Person*> v;

    Person p1("赵蕾", 22);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("阿狸", 30);
    Person p5("Loli", 16);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //遍历容器中的数据
    for (vector<Person*>::iterator it = v.begin(); it != v.end();it++){
        cout << "姓名：" << (*it)->m_Name << ",年龄：" << (*it)->m_age << endl;
    }
}
int main(){
    //test();
    test02();
    system("pause");
    return 0;
}
