//虚析构和纯虚析构
#include<iostream>
using namespace std;
class Animal{
public:
    Animal(){
        cout << "动物类的构造函数" << endl;
    }
    // //虚析构，会走子类的析构函数
    // virtual ~Animal(){
    //     cout << "动物类的虚析构函数" << endl;
    // }
    virtual ~Animal() = 0; // 纯虚析构，有了这个，类也属于抽象类，无法实例化 
    virtual void speak() = 0;//纯虚函数
};
Animal::~Animal(){
    cout << "动物类的纯虚析构函数" << endl;
}
class Cat : public Animal{
public:
    string *m_Name;
    Cat(string name){
        cout << "Cat的构造函数" << endl;
        m_Name = new string(name);
    }
    void speak(){
        cout <<*m_Name<< "小猫在说话" << endl;
    }
    ~Cat(){
        if(m_Name!=NULL){
            cout << "Cat析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
};
void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    //父类指针在析构的时候不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;
}
int main(){
    test01();
    system("pause");
    return 0;
}
