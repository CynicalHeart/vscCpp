//list链表-非连续存储结构,是一个双向循环链表,由一系列结点构成（结点包括数据域和指针域）
//优点:链表对于任意位置进行快速插入、删除元素;动态分配;
//缺点:遍历速度没有数组快;占用的空间也比数组大(多了指针域)
//与vector不同，插入删除操作不会造成原有的迭代器失效。list和vector是最常用的的两个容器。
#include<iostream>
using namespace std;
#include<list>
#include<algorithm>
//遍历容器
void printList(const list<int> &L){
    for (list<int>::const_iterator it = L.begin(); it != L.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
//1.构造方式 同其他的容器相同
void test01(){
    list<int> L1;//默认构造
    //添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    //区间方式构造
    list<int> L2(L1.begin(), L1.end());
    printList(L2);

    //拷贝构造
    list<int> L3(L2);
    printList(L3);

    //n个elem
    list<int> L4(10, 100);
    printList(L4);
}

//2.赋值和交换
void test02(){
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //operator= 的方式赋值
    list<int> L2 = L1;
    printList(L2);

    //assign方法赋值 区间
    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);

    //n个elem
    list<int> L4;
    L4.assign(10, 100);
    printList(L4);

    //交换 swap函数
    L2.swap(L4);
    cout << "交换后的L2和L4:" << endl;
    printList(L2);
    printList(L4);
}

//3.大小操作
void test03(){
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //判断是否为空
    if(L1.empty()){
        cout << "L1为空" << endl;
    }else{
        cout << "L1不为空" << endl;
        cout << "L1的元素个数"<<L1.size()<< endl;
    }
    //重新制定大小
    L1.resize(10,1);//多出的默认为0，第二个参数为制定参数值
    printList(L1);
    L1.resize(2);//多余的被删除
    printList(L1);
}

//4.插入和删除
void test04(){
    list<int> L1;
    //尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    //头插
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    printList(L1);

    //尾删
    L1.pop_back();
    printList(L1);
    //头删
    L1.pop_front();
    printList(L1);

    //insert插入
    L1.insert(L1.begin(), 1000);//可以用迭代器It来移动插入位置
    printList(L1);
    //删除
    L1.erase(L1.begin());
    printList(L1);

    //移除remove
    L1.push_back(10000);
    printList(L1);
    L1.remove(10000);//直接制定删除值,将list的所有10000匹配的元素。
    printList(L1);
    //清空
    L1.clear();
    printList(L1);
}

//5.数据存取,与vector\deque等迭代器不同，不能用[]、at的方法，因为它不连续，用的指针遍历，且不支持跳跃访问，只能前后移
void test05(){ 
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //list本质是链表，不是用连续线性空间存储，迭代器不支持随机访问(只能要for和迭代器遍历)
    cout << "第一个元素是:" << L1.front() << endl;
    cout << "最后一个元素是:" << L1.back() << endl;
}

//回调函数
bool myCompare(int v1,int v2){
    //降序就让第一个数>第二个数
    return v1 > v2;
}
//6.反转与排序
void test06(){
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(40);
    L1.push_back(30);
    printList(L1);//默认无序列表

    //反转
    cout << "反转后" << endl;
    L1.reverse();
    printList(L1);

    //排序,所有不支持随机访问迭代器的容器，不可以用标准的算法
    //不支持随机访问迭代器的容器，内部会提供对应的成员函数算法
    cout << "排序后:" << endl;
    L1.sort();//默认排序规则-升序
    printList(L1);

    //降序
    L1.sort(myCompare);
    printList(L1);
}

//自定义数据类型
class Person{
public:
    string m_Name;
    int m_Age;
    int m_Height;
    Person(string name,int age,int height){
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
};
//制定自定义数据类型排序规则
bool personCompare(Person &p1,Person &p2){
    //同年龄按照身高降序
    if(p1.m_Age == p2.m_Age){
        return p1.m_Height > p2.m_Height;
    }
    //按照年龄升序
    return p1.m_Age < p2.m_Age;
}
//7.排序Demo
void test07(){
    list<Person> L;
    Person p1("赵蕾",22,172);
    Person p2("王琦",23,168);
    Person p3("阿狸",28,176);
    Person p4("萱儿",24,160);
    Person p5("爱美",22,170);
    Person p6("aiai",22,175);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end();it++){
        cout << "姓名:" << (*it).m_Name << ",年龄:" << it->m_Age << ",身高:" << it->m_Height << endl;
    }

    //排序
    cout << "-------------------------------" << endl;
    cout << "排序后:" << endl;
    //自定义数据类型 排序需要制定排序规则
    L.sort(personCompare);

    for (list<Person>::iterator it = L.begin(); it != L.end();it++){
        cout << "姓名:" << (*it).m_Name << ",年龄:" << it->m_Age << ",身高:" << it->m_Height << endl;
    }
}

int main(){
    //1.构造
    //test01();

    //2.赋值和交换
    //test02();

    //3.大小操作
    //test03();

    //4.插入与删除
    //test04();

    //5.数据存取
    //test05();

    //6.反转和排序
    //test06();

    //7.排序Demo
    //test07();

    system("pause");
    return 0;
}

