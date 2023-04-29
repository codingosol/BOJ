#include <iostream>
// #include <map> // map쓰면 시간초과
#include <set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    set<string> s;
    string tmp;
    for(int i = 1; i <= str.length(); i++) // 시간복잡도 n
    {
        tmp = "";
        int len = i; // 문자열 길이
        for(int j = 0; j < str.length() - i + 1; j++) // 시간복잡도 n(n-1)/ 2 * 1000
        {
            tmp = str.substr(j,len);
            s.insert(tmp);
        }
    }
    // O(n) = n^3 ->> 10^9이므로 1초내 불가능..
    cout << s.size() << '\n';
    return 0;
}