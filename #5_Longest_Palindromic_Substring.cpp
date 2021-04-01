#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string longestPalindrome(string s) {
    int start=0; int end=0;
    if(s.size()==0)
        return "";
    else
    {
        // Center를 기준으로 좌우로 퍼트려가면서 확인
        // Center, Center +1의 경우는 Center가 1개 문자가 아니라 2개 문자일 경우를 대비해서 추가됨 
        for (int center=0;center<s.size();center++)
        {
            int len1=PaliLength(center, center, s);
            int len2=PaliLength(center, center+1, s);
            if(len1>end-start)
            {
                start=center-len1/2;
                end=center+len1/2;
            }
            if(len2>end-start)
            {
                start=center+1-len2/2;
                end=center+len2/2;
            }
        }
    }
    return s.substr(start, end-start+1);
}

int PaliLength(int L, int R, string s)
{
    int len=0;
    while (L>=0&&R<s.size())
    {
        if(s[L]==s[R])
        {
            len=R-L+1;
            L--;
            R++;
        }
        else
            break;
    }
    return len;
}

int main(void)
{

    string s;

    cin >> s;
    cout << longestPalindrome(s) << endl;

    return 0;
}