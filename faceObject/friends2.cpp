//类作友元-2/15
#include<iostream>
using namespace std;

class Building{
    //GoodGay类是本类的好朋友，可以访问私有权限
    friend class GoodGay;
public:
    string m_SittingRoom;//客厅
    Building();
private:
    string m_BedRoom;//卧室
};

class GoodGay{
public:
    Building *building;
    GoodGay();
    void visit();//参观函数，访问Building中属性
};

//类外写成员函数 双冒号提示函数域
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodGay::GoodGay(){
    building = new Building;
}
void GoodGay::visit(){
    cout << "好基友正在访问:" <<building->m_SittingRoom<< endl;
    cout << "好基友正在访问:" <<building->m_BedRoom<< endl;
    delete building;
}
//测试案例01
void test01(){
    GoodGay goodGay;
    goodGay.visit();
}
int main(){
    test01();
    system("pause");
    return 0;
}
