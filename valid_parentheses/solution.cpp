#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    constexpr static const std::array<std::pair<char, char>, 3> parenthesisPairs{{{'(', ')'}, {'[', ']'}, {'{', '}'}}};

public:
    /**
    * Returns a pair<bool, pair<char, char>>, where the first element of the pair is 'true' if
    * c is the opening paranthesis, and pair<char, char> is a pointer to the paranthesis pair.
    *
    */
    std::pair<bool, const std::pair<char, char>*> getPair(char c) const{
        const auto& it = std::find_if(parenthesisPairs.begin(), parenthesisPairs.end(), 
            [c](const std::pair<char, char>& pair) {
                return pair.first == c || pair.second == c;
            });
        if (it == parenthesisPairs.end()) {
            throw 1;
        }
        return {c == it->first, it};
    }

    bool isValid(string s) {
        int const size = s.size();
        vector<char> stack;

        for (int i = 0; i < size; i++) {
            char c = s[i];
            std::pair<bool, const std::pair<char, char>*> paranthesisPair = getPair(c);
            const bool& isOpening = paranthesisPair.first;
            const std::pair<char, char>* & pair = paranthesisPair.second;
            if (isOpening) {
                stack.push_back(c);
            }
            else {
                if (stack.empty())
                    return false;
                else {
                    char topChar = stack.back();
                    if (topChar == pair->first) {
                        stack.pop_back();
                    }
                    else {
                        return false;
                    }
                }
            
            }
        }

        return stack.size() == 0;
    }
};
