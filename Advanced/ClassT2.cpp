//类模板中成员函数的创建时机
#include<iostream>
using namespace std;
//类模板中成员函数在调用时才去创建
class Person1{
public:
    void showPerson1(){
        cout << "Person 1 show" << endl;
    }
};
class Person2{
public:
    void showPerson2(){
        cout << "Person 2 show" << endl;
    }
};
template<class T>
class Myclass{//没调用该模板成员函数是不会创建的，编译不出错
public:
    T obj;
    //类模板成员函数
    void func1(){
        obj.showPerson1();
    }
    void func2(){
        obj.showPerson2();
    }
};
void test01(){
    Myclass<Person1> m; //调用后才创建
    m.func1();
    //m.func2(); m 没有showPerson2，反之T=person2，不能调用func1
}
int main(){
    test01();
    system("pause");
    return 0;
}
