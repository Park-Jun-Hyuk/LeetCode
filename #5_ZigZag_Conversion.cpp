#include <iostream>
#include <string>
using namespace std;


string convert(string s, int numRows) {

    if(numRows == 1)
        return s;
    
    string rst = "";
    for(int row = 0; row < numRows; row++)
    {
        int idx  = row;
        bool toggle = true;
        if(row == numRows-1)
            toggle = !toggle;

        while(idx < s.length())
        {
            rst += s[idx];
            if(toggle){
                idx += 2 * (numRows - row - 1);
            }
            else{
                idx += 2 * row;
            }

            if(row > 0 && row < numRows-1)
                toggle = !toggle;
        }
    }
    return rst;
}



int main(void)
{

    string s = "A";

    //cin >> s;
    cout << convert(s , 1) << endl;

    //cin >> s;
    cout << convert(s , 4) << endl;

    return 0;
}