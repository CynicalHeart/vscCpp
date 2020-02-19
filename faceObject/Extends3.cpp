//继承中的对象模型
#include<iostream>
using namespace std;
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son : public Base1{
public:
    int m_D;
};
void test(){
    //父类中所有非静态成员属性都会被子类继承
    //父类的私有成员被编译器隐藏了，访问不到，但确实被继承了
    cout << "size of Son = " <<sizeof(Son)<< endl;//16
}
int main(){
    test();
    system("pause");
    return 0;
}
