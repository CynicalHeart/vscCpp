//queue队列学习-先进先出(FIFO)双出口,队头出数据，队尾进数据
//第一个元素是队头，最后一个事队尾，例：打饭
//只有队头和队尾能被看到，不能遍历
#include<iostream>
using namespace std;
#include<queue>
//数据类
class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};
//6个常用接口 -push -pop -front -back -empty -size
void test(){
    //创建队列
    queue<Person> q;
    //准备数据
    Person p1("赵蕾",22);
    Person p2("王琦",23);
    Person p3("萱儿",24);
    Person p4("阿狸",28);

    //入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    
    cout << "队列的大小" << q.size() << endl;

    //判断队列是否为空 查看队头队尾
    while(!q.empty()){
        //队头
        cout << "队头元素--姓名:" << q.front().m_Name << "，年龄:" << q.front().m_Age << endl;
        //队尾
        cout << "队尾元素--姓名:" << q.back().m_Name << "，年龄:" << q.back().m_Age << endl;
        //出队
        q.pop();
    }
    cout << "队列的大小" << q.size() << endl;
}
int main(){
    test();
    system("pause");
    return 0;
}
