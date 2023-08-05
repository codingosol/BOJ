#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int_64;

int main(void)
{
    int n;
    cin >> n;
    vector<int_64> v;
    int_64 temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    /*for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';*/
    int_64 min_abs = 10987654321;
    bool flag = false;
    int left;
    int right;
    int mid;
    int ans_l, ans_r, ans_b; // 각각 왼쪽, 오른쪽, 고정 좌표 저장
    for(int i = 0; i < n-1; i++)
    {
        if(flag)
            break;
        left = i+1;
        right = n-1;
        int_64 base = v[i];
        //cout << "current base is " << i << '\n';
        while(left < right && left > 0 && right < n && left < n-1 && right > 0)
        {
            //cout << "left : " << left << ' ' << "right : " << right << '\n';
            // mid = (left + right) / 2;
            int_64 curval = base + v[left] + v[right];
            if(curval < 0) // 현재 값이 0보다 작다면
            {
                if(abs(curval) < abs(min_abs)) // 최소 절대값이 갱신되었다면
                {
                    //cout << "checked " << curval << '\n';
                    min_abs = curval;
                    ans_l = left;
                    ans_r = right;
                    ans_b = i;
                    //cout << "fixed l r b : " << ans_l << ' ' << ans_r << ' ' << ans_b << '\n';
                }
                left++;
            }
            else if(curval > 0)
            {
                if(abs(curval) < abs(min_abs)) // 최소 절대값 갱신되었다면
                {
                    //cout << "checked " << curval << '\n';
                    min_abs = curval;
                    ans_l = left;
                    ans_r = right;
                    ans_b = i;
                    //cout << "fixed l r b : " << ans_l << ' ' << ans_r << ' ' << ans_b << '\n';
                }
                right--;
            }
            else { // 0과 일치한다면 출력하고 종료
                flag = true;
                min_abs = curval;
                ans_l = left;
                ans_r = right;
                ans_b = i;
                break;
            }
        }
    }
    vector<int_64> ans;
    ans.push_back(v[ans_l]), ans.push_back(v[ans_r]), ans.push_back(v[ans_b]);
    sort(ans.begin(),ans.end());
    for(int i = 0; i < 3; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}