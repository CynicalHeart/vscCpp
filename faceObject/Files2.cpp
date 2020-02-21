//文件操作之二进制文件
#include<iostream>
#include<fstream>
using namespace std;
class Person{
public:
    char m_Name[64];
    int m_Age;
};
//写
void test01(){
    //2.创建流对象
    ofstream ofs;
    //3.打来文件
    ofs.open("person.txt", ios::out | ios::binary);//二进制写
    //4.写文件
    Person p = {"张三",18};
    ofs.write((const char *)&p,sizeof(Person));//地址转为const char * ， 并计入长度
    //5.关闭
    ofs.close();
}
//读
void test02(){
    //创建流对象
    ifstream ifs;
    //打开文件并判断
    ifs.open("person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout << "打开文件失败" << endl;
        return;
    }
    //读
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名:" << p.m_Name << "，年龄：" << p.m_Age << endl;
    //关闭
    ifs.close();
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}

