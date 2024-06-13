#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;

class BitMap
{
private:
    int maxValue;
    int size = 32;
    int capacity;
    int *byteBits = nullptr;

public:
    BitMap(int maxValue_)
    {
        maxValue = maxValue_;
        capacity = (maxValue + 1) / size + 1;
        byteBits = new int[capacity];
    }
    ~BitMap()
    {
        delete[] byteBits;
    }
    void addValue(int value)
    {
        int index = value / size;
        int position = value % size;
        byteBits[index] = byteBits[index] | 1 << position;
        return;
    }
    void deleteValue(int value)
    {
        if (hasValue(value))
        {
            int index = value / size;
            int position = value % size;
            byteBits[index] = byteBits[index] ^ 1 << position;
        }
        return;
    }
    bool hasValue(int value)
    {
        int index = value / size;
        int position = value % size;
        int flag = byteBits[index] & 1 << position;
        return flag;
    }
    vector<int> getAllValues()
    {
        vector<int> res;
        for (int i = 0; i <= maxValue; i++)
        {
            if (hasValue(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    BitMap bitmap(9);
    vector<int> values;
    srand((unsigned int)time(nullptr));
    cout << "去重前：" << endl;
    for (int i = 0; i < 100; i++)
    {
        int value = rand() % 10;
        // cout << value << endl;
        bitmap.addValue(value);
    }
    cout << "去重后:" << endl;
    values = bitmap.getAllValues();
    for (auto v : values)
    {
        cout << v << endl;
    }
    system("pause");
    return 0;
}