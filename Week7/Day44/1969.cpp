#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m; // n은 케이스 수 m은 길이
    string temp;
    vector<string> v;
    for(int i = 0; i < n; i++) // v에 string push
    {
        cin >> temp;
        v.push_back(temp);
    }
    // 브루트포스로 풀면 최대 4 ^ 50이므로 불가능 - > 가장 많이 겹치는 자릿수로 하는게 나음
    int arr[50][4]; // 1,2,3,4는 각각 A,C,G,T임
    memset(arr,0,sizeof(arr));
    for(int i = 0; i < n; i++) // 케이스 수만큼 반복
    {
        for(int j = 0; j < m; j++) // 길이만큼 반복
        {
            // j는 몇 번째 자리인지를 나타냄
            if(v[i][j] == 'A')
                arr[j][0]++; 
            if(v[i][j] == 'C')
                arr[j][1]++;
            if(v[i][j] == 'G')
                arr[j][2]++;
            if(v[i][j] == 'T')
                arr[j][3]++;
        }
    }
    string ans;
    int dist = 0;
    for(int i = 0; i < m; i++)
    {
        int max = 0;
        int index;
        for(int j = 0; j < 4; j++)
        {
            if(max < arr[i][j])
            {
                max = arr[i][j];
                index = j; // 가장 많은 글자의 인덱스 수
            }
        } // 가장 많이 나오는 글자 찾기 -> arr[i][j] 돌면서 arr[i][index]가 아닌(j != index)의 수 더해주면 됨
        for(int j = 0; j < 4; j++)
        {
            if(j != index)
            {
                dist += arr[i][j];
            }
        }
        // hamming distance 측정
        if(index == 0)
            ans += 'A';
        if(index == 1)
            ans += 'C';
        if(index == 2)
            ans += 'G';
        if(index == 3)
            ans += 'T';
    }
    cout << ans << '\n' << dist << '\n';
    return 0;
}