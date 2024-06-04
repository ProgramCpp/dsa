std::vector<int> SortColors(std::vector<int> colors) {
    int len = colors.size();
    int r =0, w = 1, b = len - 1;

    while (w <= b) {
        if (colors[w] == 0) {
            colors[w] = colors[r];
            colors[r] = 0;
            r++;
        }
        else if (colors[w] == 2) {
            colors[w] = colors[b];
            colors[b] = 2;
            b--;
        } else {
             w++;
        }
        if (r == w)
            w++;

    }
    
    return colors;
}