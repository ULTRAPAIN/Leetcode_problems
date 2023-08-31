class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);

        int half = (n+m+1)/2;
        int left = 0;
        int right = n;

        while(left<= right){
            int mid = left + (right-left)/2;
            int lefA = mid;
            int lefB = half-mid;
            int leftA = (lefA > 0)?nums1[lefA-1]:INT_MIN;
            int leftB = (lefB > 0)?nums2[lefB-1]:INT_MIN;
            int rightA = (lefA <n)?nums1[lefA]:INT_MAX;
            int rightB = (lefB < m)?nums2[lefB]:INT_MAX;

            if(leftA <= rightB && leftB <= rightA) {
                if((n+m)%2 == 0) {
                    double ans = max(leftA,leftB)+min(rightA,rightB);
                    
                    return ans/double(2); }
                return max(leftA,leftB);
            }
            else if(leftA > rightB) right = mid-1;
            else left = mid +1;
        }
        return 0;
    }
};