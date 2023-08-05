#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int need[10];
    fill_n(need,10,0);
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        need[str[i] - '0']++;
        // cout << need[str[i] - '0'] << '\n';
    }
    // 6과 9는 뒤집어서 쓸 수 있으므로 하나로 합쳐줌
    need[6] += need[9];
    int max_val = 0;
    int temp;
    for(int i = 0; i <= 8; i++)
    {
        if(i == 6)
        {
            temp = ceil(float(need[6]) / 2);
        }
        else {
            temp = need[i];
        }
        if(temp > max_val)
            max_val = temp;
    }
    cout << max_val << '\n';
    return 0;
}