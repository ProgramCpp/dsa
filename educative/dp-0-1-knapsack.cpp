int FindMaxKnapsackProfit(int capacity, vector<int> weights, vector<int> values)
{
    vector<vector<int>> maxProfits(weights.size() + 1, vector<int>(capacity + 1,0));

    for(int i = 1; i <= weights.size(); i++){
        for(int j = 1; j <= capacity; j++){
            if(weights[i - 1] > j){
                maxProfits[i][j] = maxProfits[i-1][j];
            }else{
                maxProfits[i][j] = max(values[i-1]+maxProfits[i-1][j-weights[i-1]], maxProfits[i-1][j]);
            }
        }
    }

    return maxProfits[weights.size()][capacity];
}