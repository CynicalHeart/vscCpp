//Set/multiset容器学习-所有元素在插入时自动排序，属于关联式容器，底层由二叉树实现 
//set 不允许重复数据插入,multiset可以。
#include<iostream>
using namespace std;
#include<set>

//公共打印
void printSet(set<int> &s){
    for (set<int>::iterator it = s.begin(); it != s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
//仿函数定制类
class Mycompare{
public:
    bool operator()(int v1,int v2) const{
        return v1 > v2;
    }
};
//自定义数据类
class Person{
public:
    string m_Name;
    int m_Age;
    Person(string name , int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};
class ComParePerson{
public:
    bool operator()(const Person &p1,const Person &p2) const{
        //按照年龄降序
        return p1.m_Age > p2.m_Age;
    }
};

//1.容器构造和赋值
void test01(){
    set<int> s1;
    //插入数据只有Insert的方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    //set插入数据两个特点:插入时自动排序;不能插入重复数据
    printSet(s1);

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);
    
    //赋值操作
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

//2.大小和交换  set不支持resize 重新制定大小
void test02(){
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    //判断是否为空 empty()
    if(s1.empty()){
        cout << "s1为空" << endl;
    }else{
        cout << "s1不为空" << endl;
        cout << "s1的大小" <<s1.size()<< endl;
    }
    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    cout << "交换前:" << endl;
    printSet(s1);
    printSet(s2);
    cout << "----------------------------" << endl;
    cout << "交换后:" << endl;
    s1.swap(s2);//交换容器数据
    printSet(s1);
    printSet(s2);
}

//3.插入与删除
void test03(){
    set<int> s1;
    //插入数据，只能用insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //删除
    s1.erase(s1.begin()); //放入迭代器，此例删除的是容器首部
    printSet(s1);

    s1.erase(30);//类似list中的remove ，直接删除容器中数据为30的数据。
    printSet(s1);

    //清空
    s1.clear();
    printSet(s1);
}

//4.查找与统计
void test04(){
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //查找
    set<int>::iterator pos = s1.find(30);//查找数据，并返回迭代器，无论找没找到，没找到返回s.end()
    //判断是否找到
    if(pos!=s1.end()){
        cout << "找到元素:" << *pos << endl;
    }else{
        cout << "未找到元素" << endl;
    }

    //统计30的个数
    int num = s1.count(30); // 对于set来说，结果只有0或1,因为set不能插入重复的数据
    cout << "mum = " << num << endl; 
}

//5.set与muliset的区别
void test05(){
    set<int> s;
    s.insert(10);
    pair<set<int>::iterator,bool> ret = s.insert(10);//插入两次不会成功
    //查看是否插入成功
    if(ret.second){
        cout << "插入成功了" << endl;
    }else{
        cout << "插入失败了" << endl;
    }
    //multiset插入不会返回是否插入成功的Bool
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it = ms.begin(); it != ms.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

//6.pair对组创建，利用对组可以返回两个数据
void test06(){
    //第一种方式创建对组
    pair<string, int> p("赵蕾",22);
    cout << "姓名:" << p.first << ", 年龄:" << p.second << endl;//first 和 second代表着两个参数

    //第二种方式创建对组 (make_pair) 
    pair<string, int> p2 = make_pair("王琦", 24);
    cout << "姓名:" << p2.first << ", 年龄:" << p2.second << endl;

}


//7.排序,默认是升序 存放内置类型修改排序规则
void test07(){
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    printSet(s1);

    //指定排序规则为从大到小,在插入数据之前就需要告诉容器规则
    set<int,Mycompare> s2; //第二个参数指定仿函数,自定义功能。因为是数据类型，则需要建立类
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);
    for (set<int,Mycompare>::iterator it = s2.begin(); it != s2.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

//自定义数据类型排序,都会制定排序规则
void test07Pro(){
    set<Person,ComParePerson> s;
    Person p1("赵蕾", 22);
    Person p2("王琦", 24);
    Person p3("萱儿", 23);
    Person p4("爱美", 28);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person,ComParePerson>::iterator it = s.begin(); it != s.end();it++){
        cout << "姓名:" << it->m_Name << ", 年龄:" << it->m_Age << endl;
    }
}


int main(){
    //1.容器构造和赋值
    //test01();

    //2.大小和交换
    //test02();

    //3.插入与删除
    //test03();

    //4.查找与统计
    //test04();

    //5.set与muliset的区别
    //test05();

    //6.pair对组
    //test06();

    //7.排序
    //test07();
    //test07Pro();

    system("pause");
    return 0;
}
