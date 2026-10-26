#include <iostream>
using namespace std;

template <typename T>
struct Element
{
    T data;
    Element* Next;
};

template <typename T>
class Stack
{
private:
    Element<T>* Top;
    int Count;

public:
    Stack()
    {
        Top = nullptr;
        Count = 0;
    }
    ~Stack()
    {
        DelAll();
    }
    
    void Add(T data)
    {
        Element<T>* temp = new Element<T>;

        temp->data = data;
        temp->Next = Top;

        Top = temp;
        Count++;
    }

    void Del()
    {
        Element<T>* temp = Top;

        Top = Top->Next;

        delete temp;
        Count--;
    }

    void DelAll()
    {
        while (Top != nullptr)
        {
            Del();
        }
    }

    void Print()
    {
        Element<T>* temp = Top;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->Next;
        }

        cout << endl;
    }
};

int main()
{
    Stack<int> st;

    st.Add(10);
    st.Add(20);
    st.Add(30);
    st.Add(40);

    cout << "Stack: ";
    st.Print();

    st.Del();

    cout << "After deleting: ";
    st.Print();

    return 0;
}
