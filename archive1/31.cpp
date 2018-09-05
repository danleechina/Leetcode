#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    for(int i = nums.size() - 1; i >= 0; i --) {
      bool isOk = false;
      int j = i - 1;
      if (j < 0) break;
      if (nums[i] > nums[j]) {
        sort(nums.begin() + i, nums.end(), myfunction);
        for(int k = i;k < nums.size(); k ++) {
          if (nums[k] > nums[j]) {
            int tmp = nums[k];
            nums[k] = nums[j];
            nums[j] = tmp;
            isOk = true;
            sort(nums.begin() + i, nums.end(), myfunction);
            break;
          }
        }
      }
      if (isOk) {
        return;
      }
    }
    for (int i = 0; i < nums.size()/2; i ++) {
      int j = nums.size() - 1 - i;
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
  }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  
  vector<int> p1;
  p1.push_back(1);
  p1.push_back(2);
  p1.push_back(3);
  sln.nextPermutation(p1);
  for (auto p: p1) cout << p << " ";
  cout << endl;


  vector<int> p2;
  p2.push_back(3);
  p2.push_back(2);
  p2.push_back(1);
  sln.nextPermutation(p2);
  for (auto p: p2) cout << p << " ";
  cout << endl;


  vector<int> p3;
  p3.push_back(1);
  p3.push_back(1);
  p3.push_back(5);
  sln.nextPermutation(p3);
  for (auto p: p3) cout << p << " ";
  cout << endl;


// 2,1 3
  vector<int> p4;
  p4.push_back(1);
  p4.push_back(3);
  p4.push_back(2);
  sln.nextPermutation(p4);
  for (auto p: p4) cout << p << " ";
  cout << endl;

  vector<int> p5;
  p5.push_back(4);
  p5.push_back(2);
  p5.push_back(0);
  p5.push_back(2);
  p5.push_back(3);
  p5.push_back(2);
  p5.push_back(0);
  sln.nextPermutation(p5);
  for (auto p: p5) cout << p << " ";
  cout << endl;
  return 0;
}
