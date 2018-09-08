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
    string transformVTS(vector<int>& nums) {
        string result;
        sort(nums.begin(), nums.end());
        for(auto e: nums) {
            result.push_back(e);
            result.push_back('-');
        }
        return result;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int start) {
        vector<vector<int>> result;
        if (start >= candidates.size()) return result;
        map<string, int> hasExist;
        for (int i = 0; i <= 1; i ++) {
            auto nextTarget = target - i * candidates[start];
            if (nextTarget < 0) break;
            if (nextTarget == 0) {
                vector<int> ns(i, candidates[start]);
                string key = transformVTS(ns);
                if (hasExist.find(key) == hasExist.end()) {
                    hasExist[key] = 1;
                    result.push_back(ns);
                }
                break;
            }
            auto smallResult = combinationSum(candidates, nextTarget, start + 1);
            if (i == 0) {
                for (auto ns: smallResult) {
                    string key = transformVTS(ns);
                    if (hasExist.find(key) == hasExist.end()) {
                        hasExist[key] = 1;
                        result.push_back(ns);
                    }
                }
            } else {
                for (auto s: smallResult) {
                    auto ns(s);
                    for (int j = 0; j < i; j ++) ns.insert(ns.begin(), candidates[start]);
                    string key = transformVTS(ns);
                    if (hasExist.find(key) == hasExist.end()) {
                        hasExist[key] = 1;
                        result.push_back(ns);
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return combinationSum(candidates, target, 0);
    }
};