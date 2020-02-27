//函数模板案例-通用数组选择排序(大到小)
#include<iostream>
using namespace std;
template<class T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}
//交换排序模板
template<class T>
void mySort(T arr[],int len){
    for (int i = 0; i < len; i++){
        int max = i; //最大值下标
        for (int j = i+1 ; j<len; j++){
            if(arr[max]<arr[j]){
                max = j;//更新最大值下标
            }
        }
        if (max != i){
            //交换max和i下标元素
            mySwap(arr[max], arr[i]);
        }
    }
}
template<class T>
void printArray(T arr[], int len){
    for (int  i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
//测试char
void test01(){
    char charArr[] = "badcfe";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}
//测试int
void test02(){
    int intArr[] = {5,6,1,3,7,9,8,3,4};
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}
