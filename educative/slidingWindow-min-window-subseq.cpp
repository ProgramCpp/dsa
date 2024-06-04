#include <climits>

string MinWindow(string str1, string str2){
    int len = str2.length();

    int s2 = len - 1;
    int end = 0;
    int minSubSeq = INT_MAX;
    int startIndex = 0;
    for (int s1 = str1.length() - 1; s1 >=0; s1--){
        if (str1[s1] == str2[s2]){
            if (s2 == len -1)
                end = s1;
            s2--;
            if (s2 < 0){
                int l = end - s1 + 1;
                if (l <= minSubSeq){
                    minSubSeq = l;
                    startIndex = s1;
                }
                s2 = len -1;
            }
        }
    }

    if (minSubSeq == INT_MAX)
        return "";
    
    return str1.substr(startIndex, minSubSeq);
}