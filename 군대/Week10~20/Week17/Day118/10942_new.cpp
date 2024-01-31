#include <iostream>

using namespace std;

int n;
bool palindrom[2001][2001];
int arr[2001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill_n(palindrom[0],2001*2001,false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        palindrom[i][i] = true;
    }
    for(int i = 1; i <= n-1; i++)
    {
        if(arr[i] == arr[i+1])
            palindrom[i][i+1] = true;
    }
    for (int i = n - 1; i >= 1; i--) 
    {
		for (int j = i + 2; j <= n; j++) 
        {
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true) {
				palindrom[i][j] = true;
			}
		}
    }
    int m;
    cin >> m;
    int s, e;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e;
        if(palindrom[s][e] == true)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}