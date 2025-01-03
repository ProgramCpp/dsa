// 88. Merge Sorted Array//https://leetcode.com/problems/merge-sorted-array/description/// in place merge. start merging from back where there is empty space

/*
1. copy nums2 into nums1 and then sort
2. copy nums1 out and the merge them into one nums1 array3. 
in-place: move from the right. HINT: the right of nums1 is unused. start filling the empty space from right.
in-place: point to both arrays. swap the indices if moving element from the second- doesnt work
ex:
1 5 4
2 3

*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {   // already sorted!
        // sort(num1.begin(), nums1.end());
        // sort(num2.begin(), nums2.end());
        for (int i = m - 1, j = n - 1, k = m + n - 1; i >= 0 || j >= 0; k--)
        {
            if (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[k] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    j--;
                }
            }
            else if (i >= 0)
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            { // n >= 0
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};