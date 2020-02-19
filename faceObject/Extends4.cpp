//继承中的析构和构造顺序-2/18
#include<iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base的构造函数" << endl;
    }
    ~Base(){
        cout << "Base的析构函数" << endl;
    }
};
class Son : public Base{
public:
    Son(){
        cout << "Son的构造函数" << endl;
    }
    ~Son(){
        cout << "Son的析构函数" << endl;
    }
};
void test01(){
    //Base base;
    Son son;//先构造父类再构造子类，析构顺序与析构造顺序相反。
}
int main(){
    test01();
    system("pause");
    return 0;
}
