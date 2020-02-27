//模板使用的局限性
#include<iostream>
using namespace std;
//模板并非万能，有些特定的类型需要具体化方式做特殊实现（数组、类...）
//本例解决方案可以使用重载 == 运算符解决（麻烦） 但这里不使用
class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};

//对比两个数组是否相等
template<class T>
bool myCompare(T &a,T &b){
    if(a==b){
        return true;
    }else{
        return false;
    }
}
//利用具体化Person的版本实现，具体化优先调用   
template<> bool myCompare(Person &p1,Person &p2){
    if(p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age){
        return true;
    }else{
        return false;
    }
}
void test01(){
    int a = 10;
    int b = 20;
    bool ret = myCompare(a, b);

    if (ret){
        cout << "a = b" << endl;
    }else{
        cout << "a != b" << endl;
    }
}
 //两个自定义类进行比较
void test02(){
    Person p1("Tom", 10);
    Person p2("Tom",10);

    bool ret = myCompare(p1, p2);
    if(ret){
        cout << "p1 = p2" << endl;
    }else{
        cout << "p1 != p2" << endl;
    }
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
