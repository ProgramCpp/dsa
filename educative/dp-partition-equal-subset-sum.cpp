bool CanPartitionArray(vector<int> arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    // only if total equally dividable
    if (sum % 2 != 0)
        return false;
    sum = sum/2;
    vector<vector<bool>> sums(sum + 1, vector<bool>(arr.size()+1, false));
    for (int i = 0; i <= arr.size(); i++){
        sums[0][i] = true;
    }

    // check for elements only for half of the total. the rest will form the other half
    for(int i =1; i <= sum ; i++){
        for(int j = 1; j <= arr.size(); j++ ){
            if (i - arr[j-1] >= 0)
                sums[i][j] = sums[i-arr[j-1]][j-1];
            else
                sums[i][j] = sums[i][j-1];
        }
    }
    
    return sums[sum][arr.size()];
}