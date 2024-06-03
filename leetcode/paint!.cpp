
// 256. Paint House

/*
dynamic programming: for each house, track minimum cost so far for each color
            color 0                 color 1              color 2
house 0     cost if colored 0   cost if colored 1   cost if colored 2

return minimum(last row)
*/


// 276. Paint Fence

/*
dynamic programming: recurrence relation
totalWays(i) = (k - 1) * (totalWays(i - 1) + totalWays(i - 2))
*/