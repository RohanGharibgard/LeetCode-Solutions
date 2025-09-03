#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
    
        long long totalCost = 0;

        std::multiset<int> leftSet;
        std::multiset<int> rightSet;
        int candidatesLeft = costs.size();
        int nextLeftCandidate = 0;
        int nextRightCandidate = candidatesLeft - 1;
        

        // initialize the left and right sets.
        while(nextLeftCandidate < candidates)
        {
            leftSet.insert(costs[nextLeftCandidate++]);
            rightSet.insert(costs[nextRightCandidate--]);
        }
        
        int i = k;
        while (i > 0 && candidatesLeft > candidates*2)
        {
            int leftCheapest = *leftSet.begin();
            int rightCheapest = *rightSet.begin();
            
            
            if(leftCheapest <= rightCheapest)
            {
                totalCost += leftCheapest;
                leftSet.erase(leftSet.begin());
                leftSet.insert(costs[nextLeftCandidate++]);
            }
            else
            {
                totalCost += rightCheapest;
                rightSet.erase(rightSet.begin());
                rightSet.insert(costs[nextRightCandidate--]);
            }

            i--;
            candidatesLeft--;
        }
        
        if(candidatesLeft <= candidates*2)
        {
            while(i > 0){
                int leftCheapest = *leftSet.begin();
                int rightCheapest = *rightSet.begin();
                
                if(leftCheapest <= rightCheapest)
                {
                    totalCost += leftCheapest;
                    leftSet.erase(leftSet.begin());
                }
                else
                {
                    totalCost += rightCheapest;
                    rightSet.erase(rightSet.begin());
                }
    
                i--;
            }
        }
        return totalCost;
    }
};


int main()
{
    Solution s;
    vector<int> costs = {5, 4, 3, 7, 8, 4, 10};
    std::cout << s.totalCost(costs, 3, 4);

    return 0;
}
