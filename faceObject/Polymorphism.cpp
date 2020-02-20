//多态 - 2/20
#include<iostream>
using namespace std;
class Animal{
public:
    //虚函数,用于动态多态
    virtual void speak(){
        cout << "动物在说话" << endl;
    }
};
//猫
class Cat : public Animal{
public:
    void speak(){//重写虚函数
        cout << "小猫在说话" << endl;
    }
};
//狗
class Dog : public Animal{
public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
};
//地址早绑定，编译阶段确定了函数地址
//如果想执行让猫执行说话，这个函数地址需要晚绑定，即运行时候绑定
void doSpeak(Animal &animal){//Animal &animal = cat,父类的指针或者引用指向子类对象
    animal.speak();
}
void test01(){
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
void test02(){
    cout << "sizeof(Animal)=" << sizeof(Dog) << endl;
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
