#include <iostream> 
using namespace std;

class Stack
{
    static const int SIZE = 10; // количество элементов в стеке (при желании можно поменять) 

    int ar[SIZE]; // обычно реализуется как статический массив 
    int index = 0; // индекс, по которому будет добавляться очередной новый элемент 
    // также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент 

public:
    void Clear()
    {
        index = 0;
    }

    bool IsEmpty() const
    {
        return index == 0;
    }

    bool IsFull() const
    {
        return index == SIZE;
    }

    int GetCount() const
    {
        return index;
    }

    void Push(int value)
    {
        if (!IsFull())
        {
            ar[index++] = value;
        }
        else
        {
            throw "Stack overflow!";
        }
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            return ar[--index];
        }
        else
        {
            throw "Stack is empty!";
        }
    }

    int Peek() const
    {
        if (!IsEmpty())
        {
            return ar[index - 1];
        }
        else
        {
            throw "Stack is empty!";
        }
    }

    bool Contains(int value) const
    {
        for (int i = 0; i < index; i++)
        {
            if (ar[i] == value)
            {
                return true;
            }
        }
        return false;
    }

};

int main()
{
    Stack st; // создаём "пустой" стек 

    // до тех пор, пока стек не заполнился 
    while (!st.IsFull())
        st.Push(rand() % 90 + 10); // добавляем элемент на вершину стека 

    // до тех пор, пока в стеке есть какие-либо значения 
    while (!st.IsEmpty())
        cout << st.Pop() << " " << st.Peek() << "\n"; // извлечь значение и показать на экране 

    if (st.Contains(5))
    {
        cout << "True - the stack contains the value 5 :)" << endl;
    }
    else
    {
        cout << "False - the stack doesn't contain the value 5 ;(" << endl;
    }

}