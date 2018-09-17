#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

bool myfunction (Interval i,Interval j) {
  if (i.start == j.start) return i.end < j.end;
  return i.start < j.start;
}

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.size() == 0) return result;
    sort(intervals.begin(), intervals.end(), myfunction);
    for (auto e: intervals) {
      cout << '[' << e.start << ',' << e.end << ']' << endl;
    }
    int currentCheckIndex = 0;
    while (currentCheckIndex < intervals.size()) {
      Interval current = intervals[currentCheckIndex];
      bool hasAddIndex = false;
      for (int i = currentCheckIndex + 1; i < intervals.size(); i ++) {
        auto cursorInterval = intervals[i];
        currentCheckIndex = i;
        hasAddIndex = true;
        if (cursorInterval.start <= current.end) {
          current.end = max(cursorInterval.end, current.end);
        } else {
          break;
        }
        if (i == intervals.size() - 1) currentCheckIndex = intervals.size();
      }
      result.push_back(current);
      if (!hasAddIndex) currentCheckIndex ++;
    }
    return result;
  }
};