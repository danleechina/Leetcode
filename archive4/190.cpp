class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            int t = n & 1;
            if (t)
            {
                res |= 1;
            }
            n >>= 1;
        }
        return res;
    }
};
