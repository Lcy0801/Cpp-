#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    int n = heights.size();
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        if (heights[i] <= heights[st.top()])
        {
            do
            {
                int j = st.top();
                st.pop();
                int k;
                if (st.size())
                {
                    k = st.top();
                }
                else
                {
                    k = -1;
                }
                res = max((i - k - 1) * heights[j], res);
            } while (st.size() && heights[i] <= heights[st.top()]);
        }
        st.push(i);
    }
    while (st.size())
    {
        int i = n;
        int j =st.top();
        st.pop();
        int k;
        if (st.size())
        {
            k = st.top();
        }
        else
        {
            k = -1;
        }
        res = max(res, (i - k - 1) * heights[j]);
    }
    return res;
}

int main()
{
    vector<int> heights;
    heights.reserve(10);
    heights.push_back(1);
    cout << heights.size() << endl;
    system("pause");
    return 0;
}