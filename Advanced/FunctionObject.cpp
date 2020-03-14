//函数对象(重载函数调用操作符),当重载的是()时,行为类似函数调用，也叫仿函数
//本质：函数对象(仿函数)是一个类，不是一个函数
/** 特点：
 *      函数对象可以像普通函数那样调用，可以有参数，可以有返回值
 *      超出普通函数的概念，函数对象可以有自己的状态
 *      函数对象可以作为参数传递
 */
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional> //内建仿函数,自带的仿函数需要引用此类
//仿函数案例1
class Myadd{
public:
    int operator()(int v1,int v2){
        return v1 + v2;
    }
};
class MyPrint{
public:
    MyPrint(){
        this->count = 0;
    }
    void operator()(string text){
        cout << text << endl;
        this->count++;
    }
    int count; // 记录被调用给的次数
};
void doPrint(MyPrint &mp,string text){
    mp(text);
}

//函数对象在使用的时候可以像普通函数那样调用，可以有参数、返回值
void test01(){
    Myadd myAdd;
    MyPrint myPrint;

    cout << myAdd(10, 10) << endl;
    
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");
    cout << "MyPrint调用的次数:" << myPrint.count << endl;

    doPrint(myPrint, "Hello c++");
}

//仿函数案例2
class Greater5{
public:
    bool operator()(int val){//一元谓词
        return val > 5;
    }
};
class MyCompare{
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};
//谓词(返回为bool类型的仿函数),有一个参数叫一元谓词,两个参数的叫二元谓词
void test02(){
    vector<int> v;
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    //查找容器中有没有大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), Greater5());//首位迭代器，和自定义查找规则,谓词,并使用匿名对象
    if(it == v.end()){
        cout << "未找到" << endl;
    }else{
        cout << "找到了大于5的数字为:"<< *it << endl;
    }
}
//二元谓词
void test02Pro(){
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    //使用二元谓词改变排序规则 变降序
    sort(v.begin(),v.end(),MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
//算数仿函数
void test03(){
    //一元仿函数 取反
    negate<int> n; 
    cout<<n(50)<<endl;//即对50进行取反

    //二元仿函数-加法
    plus<int> p; //默认同种类型相加
    cout << p(10, 20) << endl;

    //减法类型名称-minus
    //乘法类型名称-multiplies
    //除法类型名称-divides
    //取模仿函数名称-modulus
}

//关系仿函数
void test04(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    //降序排序
    //sort(v.begin(), v.end(), MyCompare());

    //使用编译器提供的greater(大于),等同于自定义的排序
    sort(v.begin(), v.end(), greater<int>()); 

    /*
    *   其他的关系仿函数
    *   等于 - equal_to
    *   不等于 - not_equal_to
    *   小于 - less
    *   大于等于 - greater_equal
    *   小于等于 - less_equal
    */

    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

//逻辑仿函数 与或非
void test05(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    
    for (vector<bool>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    //利用取反操作搬到另外一个容器中
    vector<bool> v2;

    //transform前 必须对目标容器开辟空间，否则不能搬运
    v2.resize(v.size());

    //表示搬运转移容器数据,第一二个参数表示原容器的范围,第三个参数表示填充目标容器，最后是需要进行的操作
    //logical_not 逻辑非，全部取反
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end();it++){
        cout << *it << " ";
    }
    cout << endl;

    //逻辑与 - logical_and
    //逻辑或 - logical_or
}

int main(){
    //仿函数使用
    //test01();

    //谓词
    //test02();
    //test02Pro();

    //算数仿函数
    //test03();

    //关系仿函数
    //test04();

    //逻辑仿函数
    //test05();

    system("pause");
    return 0;
}
 