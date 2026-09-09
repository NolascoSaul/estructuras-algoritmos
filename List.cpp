#include <iostream>
using namespace std;

static const int MAX = 100;

template <class T>
class List
{
private:
    T data[MAX];
    int size = 0;

public:
    bool insert(int val)
    {
        if (size >= MAX)
            return false;

        data[size] = val;
        size++;
        return true;
    }

    void erase()
    {
        if (size == 0)
            cout << "NO HAY ELEMENTOS\n";
        else
        {
            cout << data[size - 1] << endl;
            size--;
        }
    }

    T getData(int pos) const
    {
        if (pos < 0 || pos >= size)
            return -1;

        return data[pos];
    }

    int getSize() const
    {
        return size;
    }
^
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "[" << i << "] " << data[i] << endl;
        }
    }
};

int main()
{
    List<int> l;
    cout << "Valor inicial: " << l.getSize() << endl;
    l.erase();
    l.insert(100);
    cout << "Despues de 1: " << l.getSize() << endl;
    l.insert(5);
    cout << "Despues de 2: " << l.getSize() << endl;
    l.erase();
    cout << "Despues de borrar: " << l.getSize() << endl;
    l.print();
    return 0;
}