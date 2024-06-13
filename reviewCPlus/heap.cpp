// 参见教程：https://www.bilibili.com/video/BV1Eb41147dK
// 堆一种数据结构
/**
 * 1：是完全二叉树，生成顺序满足从上到下，从左到右
 * 2：父节点的值大于子节点
 */

#include <iostream>
#include <ctime>
using namespace std;

// 对某一个节点进行heapify，使其满足父节点的值大于子节点
void heapify(int tree[], int N, int no)
{
    while (no >= 0 && no < N)
    {
        int max = no;
        if (2 * no + 1 < N && tree[2 * no + 1] > tree[max])
            max = 2 * no + 1;
        if (2 * no + 2 < N && tree[2 * no + 2] > tree[max])
            max = 2 * no + 2;
        if (max == no)
        {
            return;
        }
        else
        {
            int temp = tree[max];
            tree[max] = tree[no];
            tree[no] = temp;
            no = max;
        }
    }
}

// 从最后一个父节点开始向上遍历每一个节点，最终生成堆
void buildHeap(int tree[], int N)
{
    if (N <= 1)
        return;
    for (int i = (N - 2) / 2; i >= 0; i--)
    {
        heapify(tree, N, i);
    }
}

// 堆排序
void heapSort(int tree[], int N)
{
    for (int i = N - 1; i >= 0; i--)
    {
        int temp = tree[0];
        tree[0] = tree[i];
        tree[i] = temp;
        heapify(tree, i, 0);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int s[10];
    cout << "随机数生成" << endl;
    for (int i = 0; i < 10; i++)
    {
        s[i] = rand() % 10;
        cout << s[i] << "\t";
    }
    cout << endl;
    cout << "堆化" << endl;
    buildHeap(s, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << "\t";
    }
    cout << endl;
    cout << "堆排序" << endl;
    heapSort(s, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << "\t";
    }
    cout << endl;
    system("pause");
    return 0;
}