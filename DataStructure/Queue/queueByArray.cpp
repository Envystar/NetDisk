#include <iostream>

template<class T>
class Queue
{
public:
    Queue(): m_Array(new T[10]), m_Front(0), m_Back(-1), m_Size(0), m_Capcity(10){};//默认构造函数
    
    //访问第一个元素
    T front()
    {
        return this->m_Array[this->m_Front];
    }

    //访问最后一个元素
    T back()
    {
        return this->m_Array[this->m_Back];
    }

    //返回容纳的元素数
    int size()
    {
        return this->m_Size;
    }

    //删除首个元素
    void pop()
    {
        if(this->m_Size == 0) return;
        this->m_Front = (this->m_Front + 1) % this->m_Capcity;
        --this->m_Size;
    }

    //判断队列是否为空
    bool empty()
    {
        return this->m_Size == 0;
    }

    //向队列尾部插入元素
    void push(const T val)
    {
        if(this->m_Size != this->m_Capcity)//数组没满时
        {

            this->m_Back = (this->m_Back + 1) % this->m_Capcity;
            this->m_Array[this->m_Back] = val;
            
        }
        else if(this->m_Size == this->m_Capcity)//数组满时
        {   
            this->m_Capcity *= 2;//新容量为原来的二倍
            T* newArray = new T[this->m_Capcity];//开辟新空间
            for(int i = this->m_Front, j = 0; j < m_Size; j++)//将原有数据拷贝进新空间
            {
                newArray[j] = this->m_Array[(i + j) % this->m_Size];
            }
            delete[] this->m_Array;//删除原有数据
            this->m_Array = newArray;//指针指向新空间
            this->m_Array[this->m_Size] = val;//添加新值
            this->m_Front = 0;//改变队头索引
            this->m_Back = this->m_Size;//改变队尾索引
        }
        ++this->m_Size;
    }
private:
    T* m_Array;//数组
    int m_Front;//队头索引
    int m_Back;//队尾索引
    int m_Size;//队列长度
    int m_Capcity;//数组容量
};

int main()
{
    Queue<int> q;
    std::cout << q.size() << "\n";
    system("pause");
    return 0;
}
