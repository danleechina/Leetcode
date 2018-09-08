#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int start) {
        vector<vector<int>> result;
        if (start >= candidates.size()) return result;
        int firstMaxCount = target/candidates[start];
        for (int i = 0; i <= firstMaxCount; i ++) {
            auto nextTarget = target - i * candidates[start];
            if (nextTarget < 0) break;
            if (nextTarget == 0) {
                vector<int> ns(i, candidates[start]);
                result.push_back(ns);
                break;
            }
            auto smallResult = combinationSum(candidates, nextTarget, start + 1);
            if (i == 0) {
                result.assign(smallResult.begin(), smallResult.end());
            } else {
                for (auto s: smallResult) {
                    auto ns(s);
                    for (int j = 0; j < i; j ++) ns.insert(ns.begin(), candidates[start]);
                    result.push_back(ns);
                }
            }
        }
        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum(candidates, target, 0);
    }
};