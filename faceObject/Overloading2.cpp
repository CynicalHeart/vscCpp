//左移运算符的重载-2/16
#include<iostream>
using namespace std;
class Person{
public:
    int m_A;
    int m_B;
};
//只能用全局函数重载左移
ostream & operator<<(ostream &cout,Person &p){
    cout << "p.m_A = " << p.m_A << ",p.m_B = " << p.m_B ;
    return cout;
}

void test(){
    Person p;
    p.m_A = 10;
    p.m_B = 10;
    cout << p <<endl;//直接输出对象
}
int main(){
    test();
    system("pause");
    return 0;
}
