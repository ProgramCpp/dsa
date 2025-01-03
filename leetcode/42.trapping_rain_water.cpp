/*
42. trapping rain water
a higher elevation splits water traps
a segment of water trapped = width of area between lowest and highest elevations * lowest of them - (sum of elevations between lowest and highest elevations)
segment water trapped = mark left and keep adding elevations, find right >= left. when right found, reset left and elevation sum and repeat
NOTE: only the lower height matters (the smaller of the heights defines the water trapped)
it is essential to reset when a higher right is found, since it could trap more water on the other end
time: O(n)
space: O(1)
how do you handle the last part of water trapped, when the left is higher than the right? 
reset when the left is lower? wont work. calculate from the right again?
track the point until which the water segment is calculated, lastWaterTrapped
when reaching lastWaterTrapped, how do you handle the running `elevations`?
you dont have to. there are only 3 cases when traversing backwards.
- right is higher than i : would be already calcuted on the left to right traversal
- right is at same level as i : would be already calcuted on the left to right traversal
- right is lower than i : this is exactly the one last segment of trapped water calculated in the right to left traversal
hopefully this works! really scared to run this code :fingers_crossed:
woah!!! you wont believe what just happened! with a couple of compiler errors, solution got accepted that beats 100%


HINTS: 
- total water trapped = sum of water trapped at each elevation, wi
- wi = water capacity at i, wci - elevation at i
- wci = min(maxLeft, maxRight) - min of max elevation on its left and max elevation on its right
- maxLeft: track from left, the max elevation so far, store the left for each i. similarly, track maxRight for all i, by traversing from right
const mem with 2 ptr: neetcode: https://www.youtube.com/watch?v=ZI2z5pq0TqA
takeaways: 
look at the problem at one position at a time
when you need both left and right bounds to calculate a value, try traversing from either sides, at once or separately in 2 iterations
when the far right edge case isnt taken care, it is usually covered in backward traversal
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0; // index
        int leftHeight = height[left];
        int elevations = height[left];
        int waterTrapped = 0;
        int lastWaterTrapped = left;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] >= leftHeight) {
                lastWaterTrapped = i - 1; // next segment starts from i
                waterTrapped += (i - left ) * leftHeight - elevations;
                left = i;
                leftHeight = height[left];
                elevations = height[left];
            } else {
                elevations += height[i];
            }
        }

        int right = height.size()-1;
        int rightHeight = height[right];
        elevations = height[right];
        // only the last segment of water trapped to be calculated
        // iterate because the last water trapped id due to right higher than last elevation but lower than lastWaterTrapped
        for (int i = right - 1; i >= lastWaterTrapped; i--) {
            if (height[i] >= rightHeight) {
                waterTrapped += (right - i ) * rightHeight - elevations;
                right = i;
                rightHeight = height[right];
                elevations = height[right];
            } else {
                elevations += height[i];
            }
        }

        return waterTrapped;
    }
};