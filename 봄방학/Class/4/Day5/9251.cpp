#include <iostream>

using namespace std;

int main(void)
{
    int lcs[1001][1001];
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++)
    {
        for(int j = 0; j < b.length(); j++)
        {
            if(a[i] == b[j]){
                lcs[i+1][j+1] = lcs[i][j] + 1;
            }
            else{
                lcs[i+1][j+1] = max(lcs[i+1][j],lcs[i][j+1]);
            }
        }
    }
    cout << lcs[a.length()][b.length()] << '\n';
    return 0;
}