//常用算法
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<numeric>
#include<time.h>
void print01(int val);
class print02{
public:
    void operator()(int val){
        cout << val << " ";
    }
};
class Transform{
public:
    int operator()(int v){
        return v;
    }
};
class Person{
public:
    string m_Name;
    int m_age;
    Person(string name, int age){
        this->m_Name = name;
        this->m_age = age;
    }
    bool operator==(const Person &p){
        if(this->m_Name==p.m_Name && this->m_age == p.m_age){
            return true;
        }else{
            return false;
        }
    }
};
class Greater5{
public:
    bool operator()(int val){
        return val > 5;
    }
};
class Greater25{
public:
    bool operator()(Person &p){
        return p.m_age > 25;
    }
};
class Greater30{
public:
    bool operator()(int val){
        return val >= 30;
    }
};
//常见的遍历算法 for_each
void forEach(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //放入容器的始末和处理函数
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    //仿函数
    for_each(v.begin(), v.end(), print02());//仿函数需要放入对象
    cout << endl;
}
//常见算法 transform 搬运容器到另一个容器(参数一二原容器范围,参数三目标容器首位,参数四回调函数)
void transForm(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    vector<int> vTarget;//目标容器
    vTarget.resize(v.size());//目标容器一定要提前开辟空间，否则报错

    transform(v.begin(), v.end(), vTarget.begin(), Transform());//Transform可以在做些逻辑运算
    for_each(vTarget.begin(), vTarget.end(), print02());
}
//常见算法 find(放入区间)
void find_01(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //查找元素中是否有5这个元素,无论是否成功都会返回迭代器
    vector<int>::iterator pos =  find(v.begin(), v.end(), 5);
    if(pos == v.end()){
        cout << "没有找到" << endl;
    }else{
        cout << "找到:"<<*pos<< endl;
    }

}
void find_02(){
    vector<Person> v;
    Person p1("赵蕾", 22);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("Aimi", 28);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //当使用自定义类型的时候,需要让重载==号让底层知道如何对比Person

    vector<Person>::iterator it = find(v.begin(), v.end(), p2);
    if(it == v.end()){
        cout << "没有找到" << endl;
    }else{
        cout << "找到： 姓名" << it->m_Name << " ,年龄:" << it->m_age << endl;
    }
}
//条件查找 内置数据类型
void findIf_01(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //查找大于5的数,需要放入容器范围和谓词
    vector<int>::iterator it =find_if(v.begin(), v.end(), Greater5());
    if(it==v.end()){
        cout << "没有找到" << endl;
    }else{
        cout << "找到了大于5的数字为:" << *it << endl;
    }
}
//条件查找 自定义数据类型
void findIf_02(){
    vector<Person> v;
    Person p1("赵蕾", 22);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("Aimi", 28);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //找年龄大于20的人
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater25());
    if(it == v.end()){
        cout << "没找到" << endl;
    }else{
        cout << "找到: 姓名为:" << it->m_Name << " ,年龄:" << it->m_age << endl;
    }
}
//adjacent_find 查找相邻重复元素
void adjacentFind(){
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(4);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3); //必须相邻且重复
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if(it == v.end()){
        cout << "没有找到" << endl;
    }else{
        cout << "找到了相邻的重复元素" << *it << endl;
    }
}
//binary_search 二分查找法, 条件：不能在无序的序列中使用
void binarySearch(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //查找容器中是否有9
    bool ret = binary_search(v.begin(), v.end(), 9);//序列必须有序！否则结果不准
    if(ret){
        cout << "找到了元素" << endl;
    }else{
        cout << "未找到" << endl;
    }
}
//count 统计元素个数 内置数据类型
void count_01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    //统计40个数
    int num = count(v.begin(), v.end(), 40);
    cout << "40的元素个数:" << num << endl;
}
//count 统计元素个数 自定义数据类型
void count_02(){
    vector<Person> v;
    Person p1("赵蕾", 23);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("王琦", 23);
    Person p5("Aimi", 28);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    
    Person pTarget("王琦", 23);
    //需要从在自定义数据类型的==号,告诉底层如何统计
    int num = count(v.begin(), v.end(), pTarget);
    cout << "和目标Person一样的人有:" << num << endl;
}

//count_if 条件查找 内置数据类型
void countIF_01(){
    vector<int> v;
    v.push_back(5);
    v.push_back(8);
    v.push_back(20);
    v.push_back(15);
    v.push_back(3);
    v.push_back(1);

    int num = count_if(v.begin(), v.end(), Greater5()); //范围和谓词
    cout << "大于5的元素有:" <<num << endl;
}
//count_if 条件查找 自定义数据类型
void countIF_02(){
    vector<Person> v;
    Person p1("赵蕾", 23);
    Person p2("王琦", 23);
    Person p3("萱儿", 24);
    Person p4("王琦", 23);
    Person p5("Aimi", 28);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), Greater25()); //范围和谓词
    cout << "年龄大于25的人有:" <<num << endl;
}

//常用的排序算法 sort
void sortLearn(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);

    sort(v.begin(), v.end(),greater<int>());
    for_each(v.begin(), v.end(), print01);
    cout << endl;
}
//random_shuffle
void randomShuffle(){
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //洗牌算法打乱顺序
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(), v.end(), print01);
    cout << endl;
}
//常用排序算法 Merge
void mergeLearn(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10;i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //目标容器
    vector<int> vTarget;
    vTarget.resize(v1.size()+v2.size());
    //合并
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), print01);
}
//常用的排序算法 reverse
void reverseLearn(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    cout << "反转前" << endl;
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    cout << "反转后" << endl;
    reverse(v.begin(),v.end());//放入区间 既可以反转
    for_each(v.begin(), v.end(), print01);
}
//copy 常用的拷贝算法
void copyLearn(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    vector<int> v2;
    v2.resize(v.size());//提前开辟空间
    //起始容器的范围和目标容器的起始迭代器放入函数
    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print01);
}
//replace 替换算法 
void replaceLearn(){
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);
    //把20替换为2000,放入区间，旧址和新值，替换所有值
    replace(v.begin(), v.end(), 20, 2000);
    for_each(v.begin(),v.end(), print02());
}
//replace_if 按照条件替换
void replace_ifLearn(){
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(30);

    //大于等于30的数字替换为3000,需要区间、谓词、以及替换的新值
    replace_if(v.begin(), v.end(), Greater30(),3000);
    for_each(v.begin(),v.end(), print02()); 
}
//accumulate 算数生成算法 
void accumulateLearn(){
    vector<int> v;
    for (int i = 0; i <=100;i++){
        v.push_back(i);
    }
    //累加,放入区间,初始值为0（参数三是起始累加值）
    int total = accumulate(v.begin(), v.end(),0);
    cout << "total = " << total << endl;
}
//fill 算数生成算法 填充
void fillLearn(){
    vector<int> v;
    v.resize(10);//默认填充（0）

    //可以重新的填充,主要用于后期 范围和填充值
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(),v.end(), print02());
}
//set_intersection 交集
void set_intersectionLearn(){
    vector<int> v1;
    vector<int> v2;
    
    for (int i = 0; i <10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vTarget;
    //目标容器需要提前开辟空间,按照小容器开辟
    vTarget.resize(min(v1.size(),v2.size()));

    //获取交集  两个容器的范围和目标容器的起始值。返回交集末尾的迭代器
    vector<int>::iterator itEnd = 
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    //这里使用获取的迭代器作为末尾，不使用end(),因为开辟空间可以有多余,不需要遍历所有容器内的值
    for_each(vTarget.begin(), itEnd, print02());
    cout << endl;
}
// set_union 并集算法 和二分搜索法一样一样需要,容器需要有序
void set_unionLearn(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i <10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vTarget;
    //目标容器提前开辟空间,按照没有交集的方式,相加
    vTarget.resize(v1.size() + v2.size());
    //返回并集最后的迭代器
    vector<int>::iterator itEnd =
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    //开辟的内存往往大于并集的大小，所以使用itEnd而不是end()
    for_each(vTarget.begin(), itEnd, print02());
    cout << endl;
}
// set_different 差集算法
void set_differenceLearn(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i <10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vTarget;
    //开辟容器空间，按照一点交集都没有，选择大的容器作为目标容器开辟的空间
    vTarget.resize(max(v1.size(),v2.size()));

    cout << "v1和v2的差集" << endl;
    //返回差集结束的迭代器
    vector<int>::iterator itEnd =
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    //差集小于等于vTarge的大小,所以使用ItEnd 而非end
    for_each(vTarget.begin(), itEnd,print02());

    cout << "v2和v1的差集" << endl;
    itEnd =
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd,print02());
}
int main(){
    forEach(); // for_each

    transForm(); // transform

    find_02(); // find 01内置数据类型,02自定义类型

    findIf_02(); // find_if 有条件的查找,01内置数据类型,02自定义类型

    adjacentFind(); // adjacent_find 相邻重复元素

    binarySearch(); // binary_search 查找指定元素是否存在,返回真假,不是迭代器

    count_02(); // count 统计元素的个数 01内置数据类型,02自定义类型

    countIF_02(); // count_if 按照条件统计个数 01内置数据类型,02自定义类型

    sortLearn(); // sort 排序算法

    randomShuffle(); // random_shuffle  洗牌算法随机调整顺序

    mergeLearn(); // merge 合并两个容器到一个容器中,前提两个容器都是有序的

    reverseLearn(); // reverse  反转容器中的元素

    copyLearn(); // copy 常用拷贝算法

    replaceLearn(); // raplace 指定范围内的旧址变为新值

    replace_ifLearn(); // replace_if 按照条件替换

    accumulateLearn(); // accumulate 算数生成算法,需要导入包<numeric>

    fillLearn(); // fill 填充算法

    set_intersectionLearn(); // set_intersection 交集算法

    set_unionLearn(); // set_union 并集算法(皆有序)

    set_differenceLearn(); // set_difference 差集算法(对v1来说不是v1v2交集的部分，v2和v1差集不一定相同)

    system("pause"); 
    return 0;
}


void print01(int val){
    cout << val << " ";
}

