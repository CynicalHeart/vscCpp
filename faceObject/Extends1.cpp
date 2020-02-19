//继承 页面实现-2/18
#include<iostream>
using namespace std;
//公共页面类(父类)
class BasePage{
public:
    void header(){
        cout << "首页，公开课，登录，注册...（公共头部）" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图...公共底部"<< endl;
    }
    void left(){
        cout << "Java、Python、C++...（公共分类列表）" << endl;
    }
};
//Java页面
class Java : public BasePage{//继承
public:
    void content(){
        cout << "Java学科视频" << endl;
    }
};
//Python页面
class Python : public BasePage{
public:
    void content(){
        cout << "Python学科视频" << endl;
    }
};
//C++页面
class CPP : public BasePage{
public:
    void content(){
        cout << "C++学科视频" << endl;
    }
};
//测试类
void test01(){
    cout << "Java下载视频页面如下:" << endl;
    Java java;
    java.header();
    java.footer();
    java.left();
    java.content();
    cout << "------------------------------" << endl;
    cout << "Python下载视频页面如下:" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "------------------------------" << endl;
    cout << "C++下载视频页面如下:" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}
int main(){
    test01();
    system("pause");
    return 0;
}
