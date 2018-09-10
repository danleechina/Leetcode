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
  int trap(vector<int>& height, int start, int end, bool isReverse) {
    if (start >= end) return 0;
    int current = start + 1;
    int blockSize = 0;
    if (!isReverse) {
      while (current <= end) {
        blockSize += height[current - 1];
        if (height[current] >= height[start]) {
          break;
        } else {
          current ++;
        }
      }
    } else {
      current = end - 1;
      while (current >= start) {
        blockSize += height[current + 1];
        if (height[current] >= height[end]) {
          break;
        } else {
          current --;
        }
      }
    }
    if (current > end && !isReverse) {
      return trap(height, start, end, true);
    } else {
      if (!isReverse) {
        cout << height[start] * (current - start) - blockSize << endl;
        return height[start] * (current - start) - blockSize + trap(height, current, end, false);
      } else {
        cout << height[end] * (end - current) - blockSize << endl;
        return height[end] * (end - current) - blockSize + trap(height, start, current, true);
      }
    }
  }

  int trap(vector<int>& height) {
    return trap(height, 0, height.size() - 1, false);
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  vector<int> heights;
  // heights.push_back(0);
  // heights.push_back(1);
  // heights.push_back(0);
  // heights.push_back(2);
  // heights.push_back(1);
  // heights.push_back(0);
  // heights.push_back(1);
  // heights.push_back(3);
  // heights.push_back(2);
  // heights.push_back(1);
  // heights.push_back(2);
  // heights.push_back(1);

  heights.push_back(4);
  heights.push_back(2);
  heights.push_back(3);

  // heights.push_back(4);
  // heights.push_back(4);
  // heights.push_back(4);

  heights.clear();
  auto result = sln.trap(heights);
  cout << result << endl;
  return 0;
}
