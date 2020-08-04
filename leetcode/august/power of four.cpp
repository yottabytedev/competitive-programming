bool is_integer(float k)
{
  return std::floor(k) == k;
}
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<1) return false;
        float n = log(num)/log(4);
        return is_integer(n);
    }
};