// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts(greedy)

/*
for every combination of cuts, track the max area of the piece between them.
O(n^2)

> Therefore, we know the largest piece of cake must have a height equal to the tallest height after applying only the horizontal cuts, and it will have a width equal to the widest width after applying only the vertical cuts.
O(2n)

Q: are cuts ordered from left to right and top to bottom?

*/

const int MOD = pow(10, 9) + 7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxHeight = 0;

        // order cuts
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        for(int i = 1; i < horizontalCuts.size(); i++){
            int h = horizontalCuts[i] - horizontalCuts[i-1];
            if(h > maxHeight)
                maxHeight= h;
        }

        // handle corner pieces
        if(maxHeight < h - *(horizontalCuts.end()-1))
            maxHeight = h - *(horizontalCuts.end()-1);

        if(maxHeight < horizontalCuts[0])
            maxHeight = horizontalCuts[0];

        int maxWidth = 0;
        for(int i = 1; i < verticalCuts.size(); i++){
            int w = verticalCuts[i] - verticalCuts[i-1];
            if(w > maxWidth)
                maxWidth= w;
        }

        // handle corner pieces
        if(maxWidth < w - *(verticalCuts.end()-1))
            maxWidth = w - *(verticalCuts.end()-1);

        if(maxWidth < verticalCuts[0])
            maxWidth = verticalCuts[0];

        // use appropriate data type for overflows
        return (((long)maxHeight % MOD) * ((long)maxWidth % MOD)% MOD);
    }
};