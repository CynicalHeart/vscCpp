//继承方式-2/18
#include<iostream>
using namespace std;
//父类
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son1 : public Base1{
public:
    void func(){
        m_A = 10;//父类中的公共权限到子类依旧公共
        m_B = 10;//父类保护成员到子类依旧保护权限
        //m_C = 10;//父类私有成员无法访问
    }    
};
class Son2 : protected Base1{
public: 
    void func(){
        m_A = 100;//父类公共成员变为保护权限
        m_B = 100;//父类中保护成员到子类成员依旧保护权限
        //m_C = 10;//父类私有成员无法访问
    }
};
class Son3 : private Base1{
public:
    void func(){
        m_A = 100;//父类公共成员变为私有权限
        m_B = 100;//父类中保护成员到子类成私有权限
        //m_C = 10;//父类私有成员无法访问
    }
};
//验证Son3的属性书否都变为私有
class GrandSon3 : public Son3{
public:
    void func(){
        //m_A = 1000;//Son3中该属性已经变为私有，无论何种继承方式都无法访问
    }
};
void test(){
    Son2 s2;
    Son3 s3;
    //s2.m_A=100;//已经变更为保护权限，类外不可以访问
    //s3.m_A=1000;//已经变更为私有权限，类外不可以访问
}
int main(){
    
    system("pause");
    return 0;
}
