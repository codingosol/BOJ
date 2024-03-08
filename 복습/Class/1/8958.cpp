#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        int streak = 1;
        int score = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == 'O')
            {
                score += streak;
                streak++;
            }
            else if(str[j] == 'X')
            {
                streak = 1;
            }
        }
        cout << score << '\n';
    }
    return 0;
}