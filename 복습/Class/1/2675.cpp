#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; 
        string str;
        cin >> n >> str;
        for(int j = 0; j <= str.length()-1; j++)
        {
            for(int k = 0; k < n; k++)
            {
                cout << str[j];
            }
        }
        cout << '\n';
    }
}