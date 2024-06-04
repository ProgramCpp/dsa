#include <iostream>
#include <string>
#include <algorithm>

string FractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";

    string result = "";

    if (numerator <0 && denominator < 0){
        numerator *= -1;
        denominator *= -1;
    }else if (numerator <0 ){ // can combine the below 2 conditions to one with abs()
         numerator *= -1;
         result += "-";
    }else if (denominator <0 ){
         denominator *= -1;
         result += "-";
    }

    int quotient = numerator / denominator;
    result += to_string(quotient);

    int reminder = numerator % denominator;

    if (reminder == 0)
        return result;
        
    result += ".";
    while(reminder > 0){
        // todo: handle repeating reminders to fix infinite loop
        reminder = reminder % denominator * 10 ;
        quotient = reminder / denominator;
        if (quotient)
            result += to_string(quotient);
    }  
    
    return result;
}