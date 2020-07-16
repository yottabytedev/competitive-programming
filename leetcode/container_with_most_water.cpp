class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        
        int area = 0;
        
        while (i<j) {
            area = max(area, min(height[i],height[j])*(j-i));
            if (height[i]<height[j])
                i++;
            else
                j--;
            
        }
        
        return area;
    }
};

//	O(n)
//	Runtime: 36 ms, faster than 44.28% of C++ online submissions for Container With Most Water.
//	Memory Usage: 14.3 MB, less than 58.46% of C++ online submissions for Container With Most Water.