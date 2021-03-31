#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s) {
        
    unordered_map<char, int> ch;
    // key: each char
    // value: the position of key char

    int start = 0;
    int maxS = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(ch.find(s[i]) != ch.end())
        {
            int tempS = i - start;

            if(maxS < tempS) 
                maxS = tempS;

            
            if(ch[s[i]] + 1 > start)
                start = ch[s[i]] + 1;
            
            ch[s[i]] = i;
        }
        else
        {
            ch.emplace(s[i], i);
        }
    }

    int tempS = s.length() - start;

    if(maxS < tempS) 
        maxS = tempS;
    
    return maxS;
}

int main(void)
{

    string s;

    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}