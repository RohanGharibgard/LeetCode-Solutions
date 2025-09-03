#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int const sizeS = s.size();
        int const sizeP = p.size();
        vector<int> startIndices;
        if (sizeS < sizeP) {
            return startIndices;
        }

        std::sort(p.begin(), p.end());
        std::multiset<char> letterFrame;
        letterFrame.insert(s.begin(), s.begin() + sizeP);

        int i = 0;
        auto const letterFrameEnd = letterFrame.end();
        auto const letterFrameBegin = letterFrame.begin();
        
        auto it = letterFrameBegin;
        while (it != letterFrameEnd) {
            if (*it != p[i])
                break;
            it++;
            i++;
        }
        if (it == letterFrameEnd) {
            startIndices.push_back(0);
        }

        int left = 0;
        for (int right = sizeP; right < sizeS; right++) {

            letterFrame.erase(letterFrame.find(s[left]));
            letterFrame.insert(s[right]);
            auto const letterFrameEnd = letterFrame.end();
            auto const letterFrameBegin = letterFrame.begin();

            int i = 0;
            auto it = letterFrameBegin;
            while (it != letterFrameEnd) {
                if (*it != p[i]) {
                    break;
                }
                    
                it++;
                i++;
            }

            if (it == letterFrameEnd) {
                startIndices.push_back(left + 1);
            }

            left++;
        }

        return startIndices;
        
    }
};

#elif SOLUTION == 2

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int const sizeS = s.size();
        int const sizeP = p.size();
        vector<int> startIndices;
        if (sizeS < sizeP) {
            return startIndices;
        }
        std::array<int, 26> pFreq{0};
        std::array<int, 26> frameFreq{0};

        std::for_each(p.begin(), p.end(), [&pFreq] (char c) {pFreq[c - 'a']++;});
    
        std::for_each(s.begin(), s.begin() + sizeP, [&frameFreq] (char c) {frameFreq[c - 'a']++;});
        if (pFreq == frameFreq) {
            startIndices.push_back(0);
        }
        int left = 0;
        for (int right = sizeP; right < sizeS; right++) {
            frameFreq[s[left] - 'a']--;
            frameFreq[s[right] - 'a']++;
            if (pFreq == frameFreq) {
                startIndices.push_back(left + 1);
            }
            left++;
        }


        return startIndices;
    }
};
#endif
