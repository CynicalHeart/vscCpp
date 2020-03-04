//string 基础学习,快速学习string类基础功能
//包括定义、构造、拼接、查找替换等....
#include<iostream>
using namespace std;

//string 本质是类，如下四个为它的构造方法
void test01(){
    //默认构造
    string s1;
    //有参构造
    const char *str = "Hello world";
    string s2(str);
    cout << "S2 = " << s2 << endl;
    //拷贝构造
    string s3(s2);
    cout << "S3 = " << s3 << endl;
    //字符初始化
    string s4(10, 'a');
    cout << "S4 = " << s4 << endl;
}

//string赋值操作
void test02(){
    //1.char*类型
    string str1;
    str1 = "Hello World";
    cout << "str1 = " << str1 << endl;
    //2.string赋值
    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;
    //3.单字符赋值
    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;
    //4.字符串赋给当前字符串(成员函数)
    string str4;
    str4.assign("Hello C++");
    cout << "str4 = " << str4 << endl;
    //5.子串（前n个）
    string str5;
    str5.assign("Hello C++", 5);
    cout << "str5 = " << str5 << endl;
    //6.用另一个字符串赋值，类似2
    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;
    //7.n个字符赋值给当前字符串
    string str7;
    str7.assign(10, 'w');
    cout << "str7 = " << str7 << endl;
}

//字符串拼接，两种 += 和 append
void test03(){
    string str1 = "我";
    //1.+=号拼接
    str1 += "爱玩游戏";
    cout << "str1 = " << str1 << endl;
    //2.+=号追加字符
    str1 += ":";
    cout << "str1 = " << str1 << endl;
    //3.追加其他字符串
    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;
    //4.append方式
    string str3 = "I";
    str3.append(" love ");
    cout << "str3 = " << str3 << endl;
    //5.append前n个字符
    str3.append("game abcde", 4);
    cout << "str3 = " << str3 << endl;
    //6.追加字符串
    str3.append(str2);
    cout << "str3 = " << str3 << endl;
    //7.有限追加，自定义长度
    str3.append(str2, 4, 3); //第二个参数为起始参数，第三个参数为截取个数
    cout << "str3 = " << str3 << endl;
}
//字符串的查找与替换
void test04(){
    //查找
    string str1 = "abcdefg";
    int pos = str1.find("de");//不写第二个参数，默认起始为零，返回int
    cout << "pos = " << pos << endl;//返回第一个字符的下标（0开始），没有返回-1

    //rfind
    pos = str1.rfind("de");//rfind是从右边往左查找，下标依旧是从左排列
    cout << "pos = " << pos << endl;

    //替换
    str1.replace(1,3,"1111");//三个参数为起始、多少个、字符串
    cout << "str1 = " << str1 << endl;//从1号字符其，三个字符替换为str1
}

//字符串比较
void test05(){
    string str1 = "hello";
    string str2 = "hello";
    if(str1.compare(str2)==0){
        cout << "str1等于str2" << endl;
    }
    if(str1.compare(str2)>0){ // 大于返回1
        cout << "str1大于str2" << endl;
    }
    if(str1.compare(str2)<0){ // 销毁返回-1
        cout << "str1小于str2" << endl;
    }
}
//字符串获取
void test06(){
    string str = "hello";
    cout <<"str = "<<str<< endl;
    //1.通过[]访问单个字符
    for (int i = 0; i < str.size();i++){
        cout << str[i] << " ";
    }
    cout << endl;
    //2.通过at的方式访问
    for (int i = 0; i < str.size();i++){
        cout << str.at(i) << " ";
    }
    cout << endl;

    //修改单个字符
    str[0] = 'x';
    cout <<"str = "<<str<< endl;

    str.at(1) = 'x';
    cout <<"str = "<<str<< endl;
}

//字符串的插入与删除
void test07(){
    string str = "hello";
    //插入
    str.insert(1, "111");//下标，插入str
    cout <<"str = "<<str<< endl;//h111ello

    //删除
    str.erase(1, 3);//从哪个位置删除几个字符
    cout <<"str = "<<str<< endl;
}

//子串获取
void test08(){
    string str = "abcdef";
    string subStr = str.substr(1,3);//哪个位置截取多少个
    cout << "subStr = " << subStr << endl;//bcd

    string email = "zhangsan@sina.com";
    int pos =email.find("@");
    string userName = email.substr(0, pos);
    cout << "userNmae="<<userName << endl;
}

int main(){
    /*string 学习章节目录 api展示*/

    //构造方法学习
    //test01();

    //赋值操作
    //test02();

    //字符串拼接
    //test03();

    //查找替换
    //test04();

    //字符串比较
    //test05();

    //字符串存储取
    //test06();

    //字符串的插入与删除
    //test07();

    //子串获取
    //test08();

    system("pause");
    return 0;
}

