#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>


using namespace std;

// User function template for C++
class Solution {
  public:
  
    template <class T>
    void displayList(const T& list) {
        // cout << "[";
        
        // for (int i = 0; i < list.size(); i++) {
        //     std::cout << list[i] << ", ";
        // }
        // cout << "]" << endl;
        
    }
    int minValue(string S, int K) {
        // Your code goes here
        if (K > S.length()) {
            return 0;
        }
        
        std::array<int, 26> charCounts{0};
        
        for (char c : S) {
            charCounts[c - 'a']++;
        }
        
        std::sort(charCounts.begin(), charCounts.end(), std::less<int>{});
        std::array<int, 26> sumsToEnd {0};
        sumsToEnd[25] = charCounts[25];
        for(int i = 24; i >= 0; i--) {
            sumsToEnd[i] = sumsToEnd[i + 1] + charCounts[i];
        }
        
                displayList(charCounts);
        displayList(sumsToEnd);

        int i;
        for(i = 0; i < 25; i++) {
            int costToFlatten = sumsToEnd[i] - charCounts[i] * (26 - i);
            if (costToFlatten <= K) {
                K -= costToFlatten;
                for (int j = i + 1; j < 26; j++) {
                    charCounts[j] = charCounts[i];
                }
                break;
            }
        }
        

        int reductionPerGroup = K / (26 - i);
        if (i < 25 && reductionPerGroup > 0) {
            K = K % (26 - i);

            for(; i < 26; i++) {
                charCounts[i] -= reductionPerGroup;
            }
        }
        int j = 25;
        while(K > 0) {
            charCounts[j]--;
            j--;
            K--;
        }
        displayList(charCounts);

        return std::accumulate(charCounts.begin(), charCounts.end(), 0, [](int sum, int count){
           return sum + count * count; 
        });
        
        
        
        
    }
};


int main() {

    Solution s;
    ifstream f("input.txt");
    int num;
    string text;
    f >> text;

    f >> num;
    cout << s.minValue("caacedccbe", 2);
    cout << s.minValue(text, num);
}
