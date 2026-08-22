class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Her zaman kısa dizi (nums1) üzerinde arama yap
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n; // high kısa dizinin boyutu olmalı

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (n + m + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];

            // Doğru çapraz karşılaştırma
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            else {
                low = partitionX + 1;
            }
        } 
        return 0.0;
    }
};
// solved :3