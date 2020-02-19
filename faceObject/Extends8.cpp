//菱形继承-2/19（不使用多继承避免菱形继承）
#include<iostream>
using namespace std;
class Animal{
public:
    int m_Age;
};
//需要使用虚继承解决菱形继承的问题,使数据唯一
//Animal变为虚基类
class Sheep : virtual public Animal{

};
class Camel :virtual public Animal{
    
};
class SheepTuo : public Sheep,public Camel{
};
void test01(){
    SheepTuo st;
    st.Sheep::m_Age=18;
    st.Camel::m_Age=28;
    //当出现菱形继承，出现两个想用数据，需要加作用域区分
    cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
    cout << "st.Camel::m_Age=" << st.Camel::m_Age << endl;
    //但这个数据只需要一份，菱形继承导致了数据具有两份，资源浪费了
    cout <<"st.m_Age:"<<st.m_Age << endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}
