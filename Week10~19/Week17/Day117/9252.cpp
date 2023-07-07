#include <iostream>
#include <vector>

using namespace std;

int lcs[1001][1001];
int n, m; // n은 a의 길이, m은 b의 길이

int main(void)
{
    string a, b; // a가 세로에 올 문자열이며 b가 가로에 올 문자열임
    cin >> a >> b;
    n = a.length();
    m = b.length();
    fill_n(lcs[0],1001*1001,0); // 0으로 초기화
    int maxval = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i-1] != b[j-1])
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
            else if(a[i-1] == b[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            if(lcs[i][j] > maxval)
                    maxval = lcs[i][j];
        }
    } // 최대 길이를 얻는 건 했는데 이제 그 문자열은 어떻게 출력하지?
    cout << maxval << '\n';
    // lcs 배열의 최댓값에서 시작
    vector<char> ans;
    while(lcs[n][m] != 0)
    {
        // 주변에 같은 값이 있는지 탐색
        if(lcs[n-1][m] == lcs[n][m])
        {
            n--;
        }
        else if(lcs[n][m-1] == lcs[n][m])
        {
            m--;
        }
        // 같은값이 있다면 그리로 이동
        else
        {
            // 같은값이 없다면 ans에 추가
            ans.push_back(a[n-1]);
            // 후 lcs[n-1][m-1]로 이동
            n--;
            m--;
        }
    }
    for(int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}