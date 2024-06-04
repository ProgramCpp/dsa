void FloodFillWithColor(std::vector<std::vector<int>>& grid, int sr, int sc, int target, int src){
    
    
    if (sr < 0 || sc < 0 || sr == grid.size() || sc ==grid[0].size())
        return;

    if (grid[sr][sc] != src)
        return;

    grid[sr][sc] = target;

    FloodFillWithColor(grid, sr +1, sc, target, src);
    FloodFillWithColor(grid, sr -1, sc, target, src);
    FloodFillWithColor(grid, sr, sc + 1, target, src);
    FloodFillWithColor(grid, sr, sc - 1, target, src);
}

std::vector<std::vector<int>> FloodFill(std::vector<std::vector<int>>& grid, int sr, int sc, int target) {
    if(grid.size() == 0)
        return grid;

    if (grid[sr][sc] == target)
        return grid;
    FloodFillWithColor(grid, sr, sc, target, grid[sr][sc]);

    return grid;
}
