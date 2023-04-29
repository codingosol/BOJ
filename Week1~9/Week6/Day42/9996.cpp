#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    string pat;
    cin >> pat;
    string start, end;
    int mid;
    for(int i = 0; i < pat.length(); i++)
    {
        if(pat[i] == '*')
        {
            mid = i;
        }
    }
    start = pat.substr(0,mid);
    end = pat.substr(mid + 1, pat.length());
    string str;
    for(int i = 0; i < testcase; i++)
    {
        cin >> str;
        if(str.length() < start.length() + end.length())
        {
            cout << "NE\n";
            continue;
        }
        string cmp1, cmp2;
        cmp1 = str.substr(0,start.length());
        cmp2 = str.substr(str.length() - end.length(), str.length());
        if(cmp1 == start && cmp2 == end)
        {
            cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }
    return 0;
}
