/*
Algorithm idea:

iterate from right to left

if 'price' is strictly less than prev price ,  
    dont buy at the prev price, instead consider buying at 'price'
else if ('price' - fee) is greater than prev price,
    buy at prev price


*/

#include <vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int profit = 0;
        int numDays = prices.size();
        int priceToSell = prices[numDays - 1];
        int priceToPurchase = prices[numDays - 1];


        for(int i = numDays - 2; i >= 0; i--)
        {
            int priceToday = prices[i];
            if(priceToday < priceToPurchase)
            {
                // if there is a cheaper purchase price, buy at that price instead.
                priceToPurchase = priceToday;
            }
            else if(priceToday > priceToPurchase + fee && priceToPurchase + fee < priceToSell)
            {
                // take profit
                profit += priceToSell - priceToPurchase - fee;
                
                priceToSell = priceToday;
                priceToPurchase = priceToday;
            }
            else if(priceToday > priceToSell)
            {
                priceToPurchase = priceToSell = priceToday;
            }
        }

        if(priceToPurchase + fee < priceToSell)
        {
            profit += priceToSell - priceToPurchase - fee;
        }

        return profit;
    }
};
