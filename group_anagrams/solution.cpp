#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // idea: anagrams are words that have the exact same letters.
        // Sort all strings s, and insert them into a map[sort(s), list]. 
        //Then iterate over all keys in the map and group  anagrams.
        std::vector<std::vector<std::string>> anagrams;
        std::unordered_map<string, int> anagramMap;

        int vectorIndex = 0;
        for(string& str : strs) {
            string strCopy = str;
            std::sort(strCopy.begin(),strCopy.end());
            if (anagramMap.contains(strCopy)) {
                int index = anagramMap[strCopy];
                anagrams[index].push_back(str);
            }
            else {
                anagramMap.emplace(strCopy, vectorIndex);
                anagrams.emplace_back();
                anagrams[vectorIndex].push_back(str);
                vectorIndex++;
            }
        }

        return anagrams;

    }
};
