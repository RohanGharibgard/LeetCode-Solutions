#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int numDays = temperatures.size();

        stack<pair<int, int>> tempStack = stack<pair<int, int>>();
        vector<int> answer(numDays);

        for(int i = numDays - 1; i >= 0; i--)
        {
            int tempToday = temperatures[i];
            if(tempStack.empty())
            {
                answer[i] = 0;
            }
            else 
            {
                pair<int, int> top = tempStack.top();

                if(tempToday >= top.first)
                {
                    do
                    {
                        tempStack.pop();
                    }
                    while(!tempStack.empty() && tempToday >= tempStack.top().first);

                    answer[i] = tempStack.empty() ? 0 : tempStack.top().second - i;
                }
                else
                {
                    answer[i] = top.second - i;
                }
            }
            tempStack.emplace(tempToday, i);

            
        }

        return answer;
    }
};
