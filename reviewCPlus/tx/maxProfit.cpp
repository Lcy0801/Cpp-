#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        bool hold = false;
        for (int i = 0; i < prices.size(); i++)
        {
            int price = prices[i];
            if (i == prices.size() - 1 && hold)
            {
                profit += price;
            }
            else
            {
                int priceNext = prices[i + 1];
                if (!hold && price < priceNext)
                {
                    hold = true;
                    profit -= price;
                }
                else if (hold && price > priceNext)
                {
                    profit += price;
                    hold = false;
                }
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    int res = Solution().maxProfit(prices);
    cout << res << endl;
    system("pause");
    return 0;
}