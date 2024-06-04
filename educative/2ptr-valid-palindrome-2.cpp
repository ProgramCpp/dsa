bool validPalindrome(string arr)
{
    // Replace this placeholder return statement with your code
    
    bool mismatch = false;
    int i = 0, j = arr.length()-1;
    for(; i < j; i++, j--){
        if (arr[i] != arr[j] && !mismatch) {
            mismatch = true;
            i++;
        } else if (arr[i] != arr[j]) {
            break;
        }
    }  
    if (i == j -1) {
        return true;
    }

    mismatch = false;
    i = 0, j = arr.length()-1;
    for(; i < j; i++, j--){
        if (arr[i] != arr[j] && !mismatch) {
            mismatch = true;
            j--;
        } else if (arr[i] != arr[j]) {
            return false;
        }
    }  

    return true;
}