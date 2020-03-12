//deque容器学习(双端数组：对头端删除或者插入)
/**与vector的区别：
 * 1.vector对于头部插入删除的代价大(移动，数据量越大大家越大)
 * 2.deque可以快速插入删除
 * 3.vector访问元素比deque快
 */
#include<iostream>
using namespace std;
#include<deque>
#include<algorithm> // 标准算法头文件

//公共打印接口
void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end();it++){//只读迭代器
        cout << *it << " ";
    }
    cout << endl;
}

//1.构造函数
void test01(){
    deque<int> d1;
    for (int i = 0; i < 10;i++){
        d1.push_back(i);
    }
    printDeque(d1);

    //区间方式复制
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);
    //n个几方式复制
    deque<int> d3(10, 100);
    printDeque(d3);
    //拷贝构造方式
    deque<int> d4(d3);
    printDeque(d4);
}

//2.赋值操作
void test02(){
    deque<int> d1;
    for (int i = 0; i < 10;i++){
        d1.push_back(i);
    }

    // =号赋值(重载了operator=)
    deque<int> d2 = d1;
    printDeque(d2);
    //assign方式赋值
    deque<int> d3(d1.begin(), d1.end());
    printDeque(d3);
    //n个数值
    deque<int> d4(10, 100);
    printDeque(d4);
}

//3.大小操作,deque是没有容量的，无限扩展，它用中控器就能管理
void test03(){
    deque<int> d1;
    for (int i = 0; i < 10;i++){
        d1.push_back(i);
    }

    if(d1.empty()){//判断是否为空
        cout << "d1为空" << endl;
    }else{
        cout << "d1不为空" << endl;
        cout << "d1的大小:" <<d1.size()<< endl;//deque没有容量
    }
    //重新制定大小
    d1.resize(15,1);//用1填充多出的部分
    printDeque(d1);
    d1.resize(5);//多余的全删除掉
    printDeque(d1);
}

//4.插入和删除(两端)
void test04(){
    deque<int> d1;
    //尾插法
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    //尾删除
    d1.pop_back();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);
}
//插入删除（内部）
void test04Pro(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    //insert方式插入
    d1.insert(d1.begin(), 1000);//头部插入1000
    printDeque(d1);
    d1.insert(d1.begin(),2, 10000);//第二个参数是插入几个
    printDeque(d1);

    //按照区间方式插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());//在d1的头部插入d2的全部内容
    printDeque(d1);

    //删除
    deque<int>::iterator it = d1.begin();
    it++;//即d1的第二个元素
    d1.erase(it);
    printDeque(d1);

    //按照区间删除
    d1.erase(d1.begin(), d2.end());//全删
    //d1.clear();效果等同
    printDeque(d1);
}

//5.数据存取
void test05(){
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //通过[]方式访问
    for (int i = 0; i < d.size();i++){
        cout << d[i] << " ";
    }
    cout << endl;

    //通过at的方式访问
    for (int i = 0; i < d.size();i++){
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "访问头元素:" << d.front() << endl;//头元素
    cout << "访问最后一个元素:" << d.back() << endl;//尾元素
}

//6.排序
void test06(){
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);

    //sort排序方法 注意引用头文件 (vector也支持sort算法)
    sort(d.begin(), d.end());//放入区间
    printDeque(d); // 默认从小到大的排序
}

int main(){
    //1.构造函数
    //test01();

    //2.赋值操作
    //test02();

    //3.大小操纵
    //test03();
    
    //4.插入和删除
    //test04();
    //test04Pro();

    //5.数据存取
    //test05();

    //6.排序
    //test06();

    system("pause");
    return 0;
}

