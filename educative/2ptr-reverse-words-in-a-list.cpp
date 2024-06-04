string ReverseWords(string sentence)
{
    // Replace this placeholder return statement with your code
    int len = sentence.length();

    for (int i = 0; i < len ; ){
        if (sentence[i] == ' '){
            i++;
            continue;
        }
        int j = i;
        while(j < len && sentence[j] != ' ')
            j++;
        for(int k =j-1; i < k; i++, k--){
            char c = sentence[i];
            sentence[i] = sentence[k];
            sentence[k] = c;
        }
        i = j + 1;
    }

    for (int i = 0, j = len -1; i < j; i++, j--) {
        char c = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = c;
    }

    int index = 1;
    for (int i = 1; i < len; i++){
        if (!(sentence[i] == ' ' && sentence[i - 1] == ' ')){
            sentence[index] = sentence[i];
            index++;
        }
    }
    // sentence[index] = 0;
    sentence.erase(index, len-index);




    // for (int i = 1; i < len; i++){
    //     if (sentence[i] == ' ' && sentence[i - 1] == ' '){
    //         sentence.erase(i, 1);
    //     }
    // }

    return sentence;
}