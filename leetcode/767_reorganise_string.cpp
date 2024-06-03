// 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/

/*
If there is some character c with freq(c)>(n+1)/2 then it is impossible
build frequency hash map
put into max heap
keep building the output string until heap is empty. check if its not possible to create this string
priority_queue: https://workat.tech/problem-solving/tutorial/cpp-stl-priority-queue-complete-guide-bnwvwagtxrws
iterating map: https://stackoverflow.com/a/6963910/2508038
*/

#include "algorithm"

struct character
{
    int frequency;
    char c;
    character(int f, char c) : frequency(f), c(c) {}
    bool operator<(const character &other) const
    {
        return frequency < other.frequency;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        map<int, int> frequency;

        for (int i = 0; i < s.length(); i++)
        {
            if (frequency.find(s[i]) != frequency.end())
            {
                frequency[s[i]]++;
            }
            else
            {
                frequency[s[i]] = 1;
            }
        }

        priority_queue<character> priorityCharacter;

        for (auto i : frequency)
        {
            priorityCharacter.push(character(i.second, i.first));
        }

        string output = "";

        character c = priorityCharacter.top();
        priorityCharacter.pop();
        while (!priorityCharacter.empty())
        {
            output += c.c;
            c.frequency--;
            character t = priorityCharacter.top();
            priorityCharacter.pop();
            if (c.frequency > 0)
            {
                priorityCharacter.push(c);
            }
            c = t;
        }

        if (c.frequency == 1)
            output += c.c;
        else
            output = "";

        return output;
    }
};