#include <iostream>
#include <vector>
/*
from each position, track maximum reachable position from that point.
in the end, if the tracked reachable position is >= nums    size, return true
*/

bool JumpGame(vector<int> nums)
{
    int reachable = 0;
    for(int i = 0; i < nums.size() && reachable < nums.size() - 1; i++){
        if(i + nums[i] > reachable){
            reachable = i+ nums[i];
        }
    }
    if (reachable == nums.size() - 1) 
        return true;
    return false;
}