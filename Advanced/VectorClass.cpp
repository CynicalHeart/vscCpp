//Vector学习 
//数组为静态空间不可扩展，vector为动态空间（即找更大的空间复制数据后释放原空间）
//vector的迭代器支持随机访问
#include<iostream>
using namespace std;
#include<vector>

//int 公共打印接口
void printVectorInt(vector<int> &v){
    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
//vector的构造
void test01(){
    vector<int> v1; //默认构造，无参构造
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
    }
    printVectorInt(v1);   

     //利用区间的方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVectorInt(v2);  

    //n个elem的方式构造
    vector<int> v3(10, 100);//第一个是个数，第二个是值
    printVectorInt(v3); 

    //拷贝构造
    vector<int> v4(v3);
    printVectorInt(v4); 
}

//赋值操作，和构造能够对应
void test02(){
    vector<int> v1;
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
    }
    //=号赋值
    vector<int> v2 = v1;
    printVectorInt(v2);

    //assign赋值法
    vector<int> v3;
    v3.assign(v1.begin(), v1.end()); //左闭右开获取v1所有数据
    printVectorInt(v3);

    //n个elem赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVectorInt(v4);
}

//容量与大小
void test03(){
    vector<int> v1;
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
    }
    //判断是否为空
    if(v1.empty()){ // 为真就是空
        cout << "v1为空" << endl;
    }else{
        cout << "v1不为空" << endl;
        cout << "v1的容量为:" << v1.capacity() << endl;
        cout << "v1的大小是" << v1.size() << endl;
    }

    //重新制定大小
    v1.resize(15);//如果重新制定比原来长，默认用0区填充新的位置，也可以在第二个参数制定填充值（重载）
    printVectorInt(v1);

    v1.resize(5);
    printVectorInt(v1);//如果重新指定的比原来短了，就会删除超出的部分
}

//插入和删除
void test04(){
    vector<int> v1;
    //尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVectorInt(v1);

    //尾删法
    v1.pop_back();
    printVectorInt(v1);

    //插入
    v1.insert(v1.begin(), 100);//头部插入100，第一个参数是迭代器
    printVectorInt(v1);

    v1.insert(v1.begin(), 2, 1000);//第二个参数是插几个
    printVectorInt(v1);

    //删除
    v1.erase(v1.begin());//删除参数也是迭代器
    printVectorInt(v1);

    v1.erase(v1.begin(), v1.end());//全部删除，两个参数是区间
    printVectorInt(v1);
    //v1.clear();//效果同上 清空
}

//数据存取
void test05(){
    vector<int> v1;
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
    }
    
    //利用[]访问元素
    for (int i = 0; i < v1.size();i++){
        cout << v1[i] << " ";
    }
    cout << endl;

    //利用at访问
    for (int i = 0; i < v1.size();i++){
        cout << v1.at(i) << " ";
    }
    cout << endl;

    //获取第一个元素
    cout << "第一个元素是" << v1.front() << endl;

    //获取最后一个元素
    cout << "最后一个元素是" << v1.back() << endl;
}

//互换容器
void test06(){
    vector<int> v1;
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
    }
    cout << "交换前：" << endl;
    printVectorInt(v1);
    vector<int> v2;
    for (int i = 10; i >0 ;i--){
        v2.push_back(i);
    }
    printVectorInt(v2);
    cout << "交换后:" << endl;
    v1.swap(v2);//互换v1和v2
    printVectorInt(v1);
    printVectorInt(v2);
}
//容器交换的实际用途
void test6Pro(){
    vector<int> v;
    for (int i = 0; i < 100000; i++){
        v.push_back(i);
    }
    cout << "V的容量:" << v.capacity()<<endl;//容量已经多扩展了3000多了
    cout << "V的大小:" << v.size() << endl;//100000

    //当使用resize(3)是大小变小后容量依旧是13000+，浪费容量
    v.resize(3);
    cout << "V的容量:" << v.capacity()<<endl;

    //巧用swap 收缩容量
    vector<int> (v).swap(v);//vector<int>(v)新建匿名对象并用v初始化，后进行交换操作，容边变为3了。匿名对象会被回收。

    cout << "V的容量:" << v.capacity()<<endl;//容量已经多扩展了3000多了
    cout << "V的大小:" << v.size() << endl;//100000
}

//预留空间，减少动态容量扩展次数
void test07(){
    vector<int> v;

    //利用预留空间减少开辟次数
    v.reserve(100000);

    int num = 0;//统计动态扩展开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++){
        v.push_back(i);
        if(p!=&v[0]){
            p = &v[0];//因为动态扩展每次扩展都会换一个更大的空间拷贝，记录指针就知道扩展次数了
            num++;
        }
    }
    cout << "num=" << num << endl;
}

int main(){
    //1.构造
    //test01();

    //2.赋值
    //test02();

    //3.容量与大小
    //test03();

    //4.插入与删除
    //test04();

    //5.数据存取
    //test05();

    //6.互换容器
    //test06();
    //test6Pro();//实际用图 ，缩内存。

    //7.预留空间
    //test07();

    system("pause");
    return 0;
}
