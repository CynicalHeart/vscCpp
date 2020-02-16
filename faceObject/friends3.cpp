//成员函数做友元-2/16
#include<iostream>
using namespace std;
//交叉使用对方类时，一定会产生定义错误，应该把类的方法实现写在类外
class Building;
class GoodGay{
public:
    Building *building;
    GoodGay();
    void visit(); //让visit能够访问Building类中的私有成员
    void visit2(); //让visit2不能访问Building类中的私有成员
};
class Building{
    //GoodGay类下的visit作为本类的好朋友，可以访问私有内容
    friend void GoodGay::visit();
public:
    string m_SittingRoom;
    Building();
private:
    string m_BedRoom;
};
GoodGay::GoodGay(){
    building = new Building;
}
void GoodGay::visit(){
    cout << "visit 正在访问："<<building->m_SittingRoom<<endl;
    cout << "visit 正在访问："<<building->m_BedRoom<<endl;
}
void GoodGay::visit2(){
     cout << "visit2 正在访问："<<building->m_SittingRoom<<endl;
    //cout << "visit 正在访问："<<building->m_BedRoom<<endl;
}
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
    delete gg.building;
}
int main(){
    test01();
    system("pause");
    return 0;
}
