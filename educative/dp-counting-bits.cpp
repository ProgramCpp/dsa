// this isnt dp!
std::vector<int> CountingBits(int n) {
    vector<int> bits(n + 1, 0);
    bits[0]=0;
    bits[1]=1;
    for(int i = 2; i <= n; i ++){
        int c = 0;
        int k = i;
        for(int j = 0; j <64; j++){
            if(k & 1)
                c++;
            k = k >> 1;
        }
        bits[i]=c;
    }
    return bits;
}