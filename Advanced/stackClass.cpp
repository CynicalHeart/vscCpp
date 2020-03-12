//stack容器学习-先进后出(单出口FILO)  例 ：弹匣
//栈不允许遍历，只能访问栈顶，它可以判断为空，也能查询栈内元素个数
#include<iostream>
using namespace std;
#include<stack>
//5个常用的接口 -push -pop -empty -top -size
void test(){
    //先进后出的数据结构
    stack<int> s;
    
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "栈的大小" <<s.size() << endl;

    //无法遍历，只能单个浏览，即查看栈顶后出栈该元素（只要栈不为空循环）
    while(!s.empty()){
        //查看栈顶元素 top()
        cout << "栈顶元素是:" << s.top() << endl;

        //出栈栈顶元素
        s.pop();

    }

    cout << "栈的大小" <<s.size() << endl;
}

int main(){
    test();
    system("pause");
    return 0;
}
