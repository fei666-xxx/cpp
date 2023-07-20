#include<iostream>

class CPU
{
public:
    virtual void Calculate()=0;
    ~CPU()
    {
        std::cout << "CPU开始析构" << std::endl;
    }
};

class GPU
{
public:
    virtual void Display()=0;
    ~GPU()
    {
        std::cout << "GPU开始析构" << std::endl;
    }
};

class Memory
{
public:
    virtual void Storage()=0;
    ~Memory()
    {
        std::cout << "Memory开始析构" << std::endl;
    }
};

class Computer
{
    CPU* cpu;
    GPU* gpu;
    Memory* memory;

public:
    Computer() {}
    Computer(CPU* _cpu, GPU* _gpu, Memory* _memory): cpu(_cpu),gpu(_gpu),memory(_memory) {}
    void SetCPU(CPU* cpu) {this->cpu = cpu;} 
    void SetGPU(GPU* gpu) {this->gpu = gpu;} 
    void SetMemory(Memory* memory) {this->memory = memory;} 

    void Work()
    {
        cpu->Calculate();
        gpu->Display();
        memory->Storage();
    }
    ~Computer()
    {
        std::cout << "Computer开始析构" << std::endl;
        if(cpu!=NULL) delete cpu;
        if(gpu!=NULL) delete gpu;
        if(memory!=NULL) delete memory;
    }
};


class IntelCPU: public CPU
{
    virtual void Calculate()
    {
        std::cout << "Intel CPU开始计算" << std::endl;
    }

    ~IntelCPU()
    {
        std::cout << "Intel CPU开始析构" << std::endl;
    }
};

class IntelGPU: public GPU
{
    virtual void Display()
    {
        std::cout << "Intel GPU开始显示" << std::endl;
    }

    ~IntelGPU()
    {
        std::cout << "Intel GPU开始析构" << std::endl;
    }
};

class IntelMemory: public Memory
{
    virtual void Storage()
    {
        std::cout << "Intel Memory开始存储" << std::endl;
    }

    ~IntelMemory()
    {
        std::cout << "Intel Memory开始析构" << std::endl;
    }
};

class LenovoCPU: public CPU
{
    virtual void Calculate()
    {
        std::cout << "Lenovo CPU开始计算" << std::endl;
    }

    ~LenovoCPU()
    {
        std::cout << "Lenovo CPU开始析构" << std::endl;
    }
};

class LenovoGPU: public GPU
{
    virtual void Display()
    {
        std::cout << "Lenovo GPU开始显示" << std::endl;
    }

    ~LenovoGPU()
    {
        std::cout << "Lenovo GPU开始析构" << std::endl;
    }
};

class LenovoMemory: public Memory
{
    virtual void Storage()
    {
        std::cout << "Lenovo Memory开始存储" << std::endl;
    }

    ~LenovoMemory()
    {
        std::cout << "Lenovo Memory开始析构" << std::endl;
    }
};

int main()
{
    Computer* computer1 = new Computer(new IntelCPU, new IntelGPU, new IntelMemory);
    computer1->Work();
    delete computer1;

    std::cout << "----------------------------" << std::endl;

    Computer* computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    computer2->Work();
    delete computer2;

    return 0;
}