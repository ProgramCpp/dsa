// 11. Container With Most Water

/*
start with left and right most lines.
keep track of max of volumes between the two lines
move left line if its smaller than the right line. vice versa

what if the second line is bigger than the first one?

ex: 4 10 2 3
the smaller right line index keep moving left. finally, the max volume = 10 * 4 = 40
say, there is some tall line is in the middle. the tall middle line, when multipled by the bigger number gives the maximum volume.
=> move the smaller line

even if the second line is bigger, the smaller line will make the volume smaller, so no point holding onto the smaller line
remember, you are taking the product at every step. 
*/

int min(int a, int b){
    return a < b? a : b;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        for(int i = 0, j = height.size() -1; i < j; ){
            int water = (j-i) * min(height[i], height[j]);
            //cout << i << " " << j << ":" << height[i] << " " << height[j] << ":" << water << endl;
            if(maxWater < water)
                maxWater = water;
            if(height[i] < height[j])
                i++;
            else 
                j--; 
        }

        return maxWater;
    }
};