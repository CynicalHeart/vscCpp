//类模板与继承
#include<iostream>
using namespace std;
template<class T>
class Base{
    T m;
};
//指定出来父类的T是什么类型，否则子类无法继承,但父类只能是固定类型（int）
class Son : public Base<int>{
    
};
void test01(){
    //Son s1;
}
//想灵活指定父类T的类型，那么子类也要是模板
template<class T1 ,class T2>
class Son2 : public Base<T2>{//T2是集成父类
public:
    T1 obj;
    Son2(){
        cout<<"T1的类型为: "<< typeid(T1).name()<<endl;
        cout<<"T2的类型为: "<< typeid(T2).name()<<endl;
    }
};
void test02(){
    Son2<int, char> S2;
}
int main(){
    test02();
    system("pause");
    return 0;
}
