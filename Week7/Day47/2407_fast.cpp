#include <iostream>
#include <cstring>

using namespace std;

string str[105][105];

string add(string a, string b)
{
    string num = "";
    int sum = 0;
    int size = max(a.size(),b.size());
    for(int i = 0; i < size || sum; i++){
        if(a.size() > i) 
            sum += a[i]-'0';
        if(b.size() > i) 
            sum += b[i]-'0';
        num += sum % 10 + '0';
        sum /= 10;
    }
    return num;
}

string solve(int n, int m)
{
    if(n == m || m == 0)
    {
        return "1";
    }
    else {
        if(str[n][m] == "") // 방문한 적 없을 때
        {
            str[n][m] = add(solve(n-1, m-1), solve(n-1,m));
            return str[n][m];
        }
        else {
            return str[n][m];
        }
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    string ans;
    ans = solve(n,m);
    for(int i = str[n][m].size() - 1; i >= 0; i--)
    {
        cout << str[n][m][i];
    }
    return 0;
}