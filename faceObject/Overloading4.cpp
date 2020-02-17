//赋值运算符的重载
#include<iostream>
using namespace std;
class Person{
public:
    int *m_Age;
    Person(int age){
        m_Age = new int(age);
    }
    ~Person(){//析构释放堆区内存
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
    Person& operator=(Person &p){
        //由编译器提供的潜拷贝
        //m_Age = p.m_Age;
        //先判断是否有属性在堆区，若果有则需要释放干净，再进行深拷贝
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);//深拷贝
        return *this;
    }
};
void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;//连等操作
    cout << "p1的年龄为:" <<*p1.m_Age<< endl;
    cout << "p2的年龄为:" <<*p2.m_Age<< endl;
    cout << "p3的年龄为:" <<*p3.m_Age<< endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
