//多态实现计算器 - 2/19
#include<iostream>
using namespace std;
//普通写法
class Calculator{
public:
    int m_Num1;
    int m_Num2;
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1 + m_Num2;
        }else if (oper == "-"){
            return m_Num1 - m_Num2;
        }else if (oper == "*"){
            return m_Num2 * m_Num2;
        }
        //如果加功能，需要修改源码，在真正开发过程中提倡开闭原则，对扩展开发，对修改关闭
    }
};
void test01(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << "Num1 + Num2 = " << c.getResult("+") << endl;
    cout << "Num1 - Num2 = " << c.getResult("-") << endl;
    cout << "Num1 * Num2 = " << c.getResult("*") << endl;
}
//设计计算机的基类（抽象类）
class AbstractCalculator{
public:
    int m_Num1;
    int m_Num2;
    virtual int getResult(){//设计接口，不写实现
        return 0;
    }
};
class AddCalculator:public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 + m_Num2;
    }
};
class SubCalculator:public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};
class MulCalculator:public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 * m_Num2;
    }
};
void test02(){
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
    //销毁
    delete abc;
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}
