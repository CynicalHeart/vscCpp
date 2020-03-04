//初识stl - vector存放内置数据类型
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm> //标准算法头文件

void myPrint(int val){
    cout << val << endl;
}

void test(){
    vector<int> v;

    //想容器中插入数据,尾插数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    
   /*  //通过迭代器访问
    vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个
    //第一种循环方式
    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    } */
    
  /*   //第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout << *it << endl;
    } */

    //利用stl提供的算法 foreach
    for_each(v.begin(), v.end(), myPrint);
}   
int main(){
    test();
    system("pause");
    return 0;
}
