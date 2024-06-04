bool IsPalindrome(string inputString)
{
    // Replace this placeholder return statement with your code
    for (int i = 0, j = inputString.length()-1; i <= j; i++, j--) {
        if (inputString[i] != inputString[j])
            return false;
    }
    return true;
}