class Solution {
public:
    double median2(int a, int b)
    {
        return ( a + b) / 2.0;
    }
    double median3(int a, int b, int c)
    {
        return a + b + c - max(a, max(b,c)) - min(a, min(b,c));
    }
    double median4(int a, int b ,int c, int d)
    {
        return (a + b + c + d - max(max(a,b),max(c,d)) - min(min(a,b),min(c,d))) / 2;
    }
    double mediansingle(vector<int> a)
    {
        int n = a.size();
        if (n==0)
            return -1;
        if (n%2 == 0)
            return (double)(a[n/2] + a[n/2-1])/2;
        return a[n/2];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l2<l1)
            return findMedianSortedArrays(nums2,nums1);
        
        if (l1 == 0)
            return mediansingle(nums2);
        
        if (l1 == 1)
        {
            if (l2 == 1)
                return median2(nums1[0],nums2[0]);
            
            if (l2 & 1)
                return median2(nums2[l2/2],median3(nums1[0],nums2[l2/2-1],nums2[l2/2+1]));
            
            return median3(nums1[0],nums2[l2/2],nums2[l2/2-1]);
        }

        if (l1 == 2)
        {
            if (l2 == 2)
                return median4(nums1[0],nums1[1],nums2[0],nums2[1]);
            
            if (l2 & 1 )
                return median3(nums2[l2/2], max(nums1[0],nums2[l2/2-1]), min(nums1[1],nums2[l2/2+1]));
            
            return median4(nums2[l2/2],nums2[l2/2 - 1], max(nums1[0],nums2[l2/2 -2]), min(nums1[1],nums2[l2/2 + 1]));
        }

        int idxA = ( l1 - 1 ) / 2;
        int idxB = ( l2 - 1 ) / 2;

        if (nums1[idxA] <= nums2[idxB])
            return findMedianSortedArrays( nums1 + idxA, nums2);
        return findMedianSortedArrays( nums1, nums2 + idxA);
    }
};