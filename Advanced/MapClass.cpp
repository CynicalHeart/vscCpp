//map和multimap容器(高性能),map所有的元素都是pair,第一个元素为key值(索引),第二个value值
//所有元素根据键值自动排序，本质依旧是关联式容器，底层为二叉树
//map和multimap区别：map不允许有重复key值，multimap则允许。
#include<iostream>
using namespace std;
#include<map>

//公共打印
void printMap(map<int,int>&m){
    for (map<int, int>::iterator it = m.begin(); it != m.end();it++){
        cout << "key值为" << (*it).first << " value = " << it->second << endl;
    }
    cout << endl;
}

//1.构建与赋值
void test01(){
    //创建Map容器
    map<int, int> m;
    //插入数据,插入对组
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    printMap(m);

    //拷贝构造
    map<int, int> m2(m);
    printMap(m2);

    //赋值
    map<int, int> m3;
    m3 = m2;
    printMap(m3);
}

//2.大小和交换
void test02(){
    map<int, int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    if(m.empty()){//判断空
        cout << "m为空" << endl;
    }else{
        cout << "m不为空" << endl;
        cout << "m的大小为:" << m.size() << endl;
    }
    map<int, int> m2;
    m2.insert(pair<int,int>(4,100));
    m2.insert(pair<int,int>(5,200));
    m2.insert(pair<int,int>(6,300));
    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);
    m.swap(m2);
    cout << "交换后" << endl;
    printMap(m);
    printMap(m2);
}

//3.插入与删除
void test03(){
    map<int, int> m;
    //第一种
    m.insert(pair<int,int>(1,10));
    //第二种
    m.insert(make_pair(2, 20));
    //第三种(不常用)
    m.insert(map<int, int>::value_type(3, 30));
    //第四种 简单但并不建议
    m[4] = 40;//用图 可以用key访问value,适合查看不适合插入
    printMap(m);

    //删除
    m.erase(m.begin()); // 放入迭代器
    printMap(m);

    m.erase(3);//按照key删除
    printMap(m);

    //清空
    m.clear();
    printMap(m);
}

//4.查找和统计
void test04(){
    //查找
    map<int, int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    //find返回的是一个迭代器,没找到则是end
    map<int,int>::iterator pos = m.find(3);
    if(pos!=m.end()){
        cout << "查到了元素key = " << (*pos).first << " value = " << pos->second << endl;
    }else{
        cout << "未找到" << endl;
    }

    //统计
    int num = m.count(3);//在map中不允许插入重复的key ，所以结果非0即1，multimap可能大于一
    cout << "num = "<< num << endl;
}

class myCompare{
public:
    bool operator()(int v1,int v2) const{
        //降序
        return v1 > v2 ;
    }
};
//5.排序,改变规则
void test05(){
    map<int, int,myCompare> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(5,50));
    
    for (map<int, int,myCompare>::iterator it = m.begin(); it != m.end();it++){
        cout << "key值为" << (*it).first << " value = " << it->second << endl;
    }

}

int main(){
    //1.构建与赋值
    //test01();

    //2.大小和交换
    //test02();

    //3.插入与删除
    //test03();

    //4.查找和统计
    //test04();

    //5.排序
    //test05();

    system("pause");
    return 0;
}
