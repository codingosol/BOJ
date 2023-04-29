#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int day;
    cin >> n >> day;
    int num;
    int arr[101][51]; // 사람이 외우고 있는 노래 수
    memset(arr,0,sizeof(arr));
    int temp;
    for(int i = 1; i <= day; i++)
    {
        cin >> num;
        vector<int> v;
        bool flag = false;
        for(int j = 0; j < num; j++)
        {
            cin >> temp;
            v.push_back(temp); // 그날의 참가자 명단
            if(temp == 1) // 선영이가 껴있다면
            {
                flag = true; // 그 날은 모두 그 노래만 부름
            }
        }
        if(flag) // 모두 그 노래만 부르는 날
        {
            for(int j = 0; j < v.size(); j++)
            {
                arr[v[j]][i]++; // 그 날의 노래를 안다고 표기
            }
        }
        else { // 아는 노래를 공유
            for(int j = 0; j < v.size(); j++) // 그 날 참석한 사람들에게
            {
                for(int k = 1; k <= day; k++) // 그 날 까지의 노래를
                {
                    if(arr[v[j]][k] == 1) // 알고 있는 노래라면
                    {
                        for(int l = 0; l < v.size(); l++) // 모든 사람에게
                        {
                            arr[v[l]][k] = 1; // 공유해
                        }
                    }
                }
            }
        }
    }
    // 노래를 최대로 알고 있는 사람 수를 전부 출력
    // 선영이는 항상 최대로 알고 있으므로 arr[1]를 순환해서 최댓값을 구함
    int max = 0;
    for(int i = 1; i <= day; i++)
    {
        if(arr[1][i] == 1)
            max++;
    }
    for(int i = 1; i <= n; i++) // n명의 사람을 돌면서 최대값과 같을 때 출력
    {
        int cnt = 0;
        for(int j = 1; j <= day; j++)
        {
            if(arr[i][j] == 1)
                cnt++;
        }
        if(cnt == max)
        {   
            cout << i << "\n";
        }
    }
    return 0;
}