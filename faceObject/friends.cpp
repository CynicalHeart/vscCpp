//友元：全局函数做友元-2/15
#include<iostream>
using namespace std;
class Building{ //建筑物类
    //意义：goodGay全局函数作为Building类的好朋友可以访问我的私有成员
    friend void goodGay(Building *building);//用friend关键字声明
public:
    string m_SittingRoom;//客厅
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
private:
    string m_BedRoom;//卧室
};
//全局函数（核心）
void goodGay(Building *building){
    cout<< "基友的全局函数 正在访问:" <<building->m_SittingRoom<< endl;
    cout<< "基友的全局函数 正在访问:" <<building->m_BedRoom<< endl;
}
//测试案例01
void test01(){
    Building building;
    goodGay(&building);
}
int main(){
    test01();
    system("pause");
    return 0;
}
