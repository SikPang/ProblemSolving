class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>* temp;

      if (nums1.size() > nums2.size()){
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        temp = &nums1;
      }
      else{
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        temp = &nums2;
      }

      sort(temp->begin(), temp->end());
      if (temp->size() % 2 == 0)
        return ((*temp)[temp->size() / 2] + (*temp)[temp->size() / 2 - 1]) / 2.0;
      else
        return (double)(*temp)[temp->size() / 2];
    }
};