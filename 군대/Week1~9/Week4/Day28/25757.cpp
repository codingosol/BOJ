#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    map<string,int> m;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        m[str] = 1;
    }
    int num_p = 0;
    for(auto i : m)
    {
        if(i.second == 1) // 사람이 있을 경우
        {
            num_p++;
        }
    }
    if(c == 'Y') // 윷놀이(2인큐)
    {
        cout << num_p << "\n"; // 그냥 사람수 출력
    }
    else if(c == 'F') // 같은그림찾기(3인큐)
    {
        cout << num_p / 2 << "\n";
    }
    else if(c == 'O') // 원카드(4인큐)
    {
        cout << num_p / 3 << "\n";
    }
    return 0;
}