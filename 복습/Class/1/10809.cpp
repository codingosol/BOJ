#include <iostream>

using namespace std;

int main(void)
{
    int alphabet[26];
    fill_n(alphabet,26,-1);
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(alphabet[str[i] - 97] == -1)
        {
            alphabet[str[i] - 97] = i;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << ' ';
    }
    cout << '\n';
    return 0;
}