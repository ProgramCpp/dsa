int MaxProduct(std::vector<int> nums) {
    // integer can be +/- numbers or zero
    int max = 0;
    int product = 1;

    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            product = 1;
            continue;
        }
            
        product *= nums[i];
        if (product > max)
            max = product;

    }
    return max;
}