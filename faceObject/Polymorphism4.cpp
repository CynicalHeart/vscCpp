//多态案例 饮品 -2/20
#include<iostream>
using namespace std;
class AbstractDrinking{
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅助作料
    virtual void PutSomething() = 0;
    //制作饮品
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};
//咖啡
class Coffee:public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout << "开始煮水" << endl;
    }
    //冲泡
    virtual void Brew(){
        cout << "冲泡咖啡" << endl;
    };
    //倒入杯中
    virtual void PourInCup(){
        cout << "导入杯中" << endl;
    };
    //加入辅助作料
    virtual void PutSomething(){
        cout << "导入糖和牛奶" << endl;
    };
};
//茶叶
class Tea : public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout << "开始煮水" << endl;
    }
    //冲泡
    virtual void Brew(){
        cout << "冲泡茶叶" << endl;
    };
    //倒入杯中
    virtual void PourInCup(){
        cout << "导入杯中" << endl;
    };
    //加入辅助作料
    virtual void PutSomething(){
        cout << "导入柠檬、枸杞" << endl;
    };
};
void doWork(AbstractDrinking *abs){
    abs->makeDrink();
    delete abs;
}
void test01(){
    //制作咖啡
    doWork(new Coffee);
}
int main(){
    test01();
    system("pause");
    return 0;
}
