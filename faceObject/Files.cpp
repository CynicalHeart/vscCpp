//文件操作之文本文件 -2/21
#include<iostream>
#include<fstream>
using namespace std;
//写
void test01(){
    //1.包含头文件 <fstream>
    //2.穿件流对象
    ofstream ofs;
    //3.指定打开方式
    ofs.open("test.txt", ios::out);//路径，方式
    //4.写内容
    ofs << "姓名:吴天宇" << endl;
    ofs << "姓别:男" << endl;
    ofs << "年龄:18" << endl;
    //关闭
    ofs.close();
}
//读
void test02(){
    //2.创建流对象
    ifstream ifs;
    //3.打开文件并判断是否成功
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open()){ //判断打开是否成功
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读(4种)
    //第一种
    /* char buf[1024] = {0};
    while(ifs>>buf){
        cout << buf << endl;
    } */

    //第二种
    /* char buf[1024] = {0};
    while(ifs.getline(buf,sizeof(buf))){
        cout << buf << endl;
    } */

    //第三种
    string buf;
    while(getline(ifs,buf)){
        cout << buf << endl; 
    } 
    
    //第四种(不推荐)
    /*char c;
    while((c=ifs.get())!=EOF){ //EOF  = end of file
        cout << c;
    } */

    //5.关闭
    ifs.close();
}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}

