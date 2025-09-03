#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    static bool firstElemLess(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), firstElemLess);
        vector<vector<int>> mergedIntervals;
        const int size = intervals.size();
        vector<int> mergedInterval(2);
        for(int i = 0; i < size; i++) {            
            mergedInterval[0] = intervals[i][0];
            mergedInterval[1] = intervals[i][1];

            while ( i < size - 1 && mergedInterval[1] >= intervals[i + 1][0]) {
                if (mergedInterval[1] < intervals[i + 1][1]) {
                    mergedInterval[1] = intervals[i + 1][1];
                }
                i++; 
            }
            mergedIntervals.push_back(mergedInterval);
        }

        return mergedIntervals;
    }
};
