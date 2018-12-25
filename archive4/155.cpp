class MinStack
{
public:
  /** initialize your data structure here. */
  vector<int> datas;
  int currentMin;
  MinStack() : currentMin(0)
  {
  }

  void push(int x)
  {
    datas.push_back(x);
    currentMin = datas[0];
    for (int i = 1; i < datas.size(); i++)
    {
      currentMin = min(currentMin, datas[i]);
    }
  }

  void pop()
  {
    datas.pop_back();
    if (datas.size() > 0)
    {
      currentMin = datas.front();
      for (int i = 1; i < datas.size(); i++)
      {
        currentMin = min(currentMin, datas[i]);
      }
    }
  }

  int top()
  {
    return datas.back();
  }

  int getMin()
  {
    return currentMin;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */