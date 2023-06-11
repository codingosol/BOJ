#include <iostream>

using namespace std;

int cnt = 0;

bool recursion(string &str, int s, int e)
{
    cnt++;
    if(s >= e)
    {
        return true;
    }
    else if(str[s] != str[e])
    {
        return false;
    }
    else {
        return recursion(str, s+1, e-1);
    }
}


bool ispalindrom(string &str)
{
    return recursion(str,0,str.length()-1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    string str;
    while(testcase--)
    {
        cin >> str;
        if(ispalindrom(str))
        {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
        cout << cnt << '\n';
        cnt = 0;
    }
}