//多态案例 电脑组装-2/20
#include<iostream>
using namespace std;
//CPU
class CPU{
public:
    //抽象机选函数
    virtual void calculate() = 0;
    virtual ~CPU() = 0;
};

//显卡
class VideoCard{
public:
    //显示函数
    virtual void diaplay() = 0;
    virtual ~VideoCard() = 0;
};

//内存条
class Memory{
public:
    //抽象存储函数
    virtual void storage() = 0;
    virtual ~Memory() = 0;
};

CPU::~CPU(){}
VideoCard::~VideoCard(){}
Memory::~Memory(){}

class Computer{
private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
public:
    Computer(CPU *cpu,VideoCard *vc,Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    void work(){ // 工作，调用接口
        m_cpu->calculate();
        m_vc->diaplay();
        m_mem->storage();
    }
    //提供一个析构函数来释放三个零件
    ~Computer(){
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_vc!=NULL){
            delete m_vc;
            m_vc = NULL;
        }
        if(m_mem!=NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }
};

//厂商
//Intel厂商
class IntelCPU : public CPU{
public:
     void calculate(){
         cout << "Intel的CPU开始计算了" << endl;
     };
};
class IntelViedoCard : public VideoCard{
    public:
     void diaplay(){
         cout << "Intel的显卡开始显示处理了" << endl;
     };
};
class IntelMemory : public Memory{
    public:
     void storage(){
         cout << "Intel的内存条开始存储了" << endl;
     };
};
//Lenovo厂商
class LenovoCPU : public CPU{
public:
     void calculate(){
         cout << "Lenovo的CPU开始计算了" << endl;
     };
};
class LenovoViedoCard : public VideoCard{
    public:
     void diaplay(){
         cout << "Lenovo的显卡开始显示处理了" << endl;
     };
};
class LenovoMemory : public Memory{
    public:
     void storage(){
         cout << "Lenovo的内存条开始存储了" << endl;
     };
};
void test01(){
    cout << "第一台电脑" << endl;
    //第一台零件
    CPU *intelCPU = new IntelCPU;
    VideoCard *intelVc = new IntelViedoCard;
    Memory *intelMem = new IntelMemory;
    //第一台电脑组装
    Computer *computer1 = new Computer(intelCPU,intelVc,intelMem);
    computer1->work();
    delete computer1;
    //第二台
    cout << "---第二台电脑---" << endl;
    Computer *computer2 = new Computer(new LenovoCPU,new LenovoViedoCard, new LenovoMemory);
    computer2->work();
    delete computer2;
}
int main(){
    test01();
    system("pause");
    return 0;
}
