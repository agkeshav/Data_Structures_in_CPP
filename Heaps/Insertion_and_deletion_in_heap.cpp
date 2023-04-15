#include <bits/stdc++.h>
using namespace std;
class heap
{
    int arr[100];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

public:
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        int i = 1;
        swap(arr[i], arr[size]);
        size--;

        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && rightIndex < size && arr[leftIndex] > arr[i] && arr[leftIndex] > arr[rightIndex])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (leftIndex < size && rightIndex < size && arr[rightIndex] > arr[i] && arr[rightIndex] > arr[leftIndex])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;
}