#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calc(const string &str)
{
    vector<int> nums;
    vector<char> operators;
    string s;
    int index = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            int num = atoi(str.substr(index, i - index).c_str());
            nums.push_back(num);
            operators.push_back(str[i]);
            index = i + 1;
        }
        nums.push_back(atoi(str.substr(index).c_str()));
    }
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (operators[i - 1] == '+')
        {
            res += nums[i];
        }
        else
        {
            res -= nums[i];
        }
    }
    return res;
}

int main()
{

}