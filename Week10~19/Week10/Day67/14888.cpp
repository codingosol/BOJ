#include <iostream>
#include <vector>

using namespace std;

int oper[4]; // 0은 + 1은 - 2는 * 3은 /
vector<int> v;
int max_val = -1000000000;
int min_val = 1000000000;
int num; // 수의 개수

void solve(int index, int ret)
{
    // 1. 이번 연산에 쓸 연산자를 고름
    // 2. 현재 값을 연산한 뒤 바뀐 oper과 현재값을 넘김
    // 3. 백트래킹을 통해 다른 경우의 수를 찾음
    // 4. 최대 최솟값 기록
    if(index == num - 1)
    {
        if(ret > max_val)
            max_val = ret;
        if(ret < min_val)
            min_val = ret;
    }
    for(int i = 0; i < 4; i++)
    {
        if(oper[i] > 0) // 더 고를수 없는 연산자라면 스킵함
        {
            oper[i]--;
            if(i == 0) // +
            {
                solve(index + 1, ret + v[index+1]);
            }
            else if(i == 1) // -
            {
                solve(index + 1, ret - v[index+1]);
            }
            else if(i == 2) // *
            {
                solve(index + 1, ret * v[index+1]);
            }
            else { // /
                solve(index + 1, ret / v[index+1]);

            }
            oper[i]++;
        }
        
    }
}

int main(void)
{
    cin >> num;
    int temp;
    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    } // input;
    // 이제 연산자를 어느 순서대로 끼워넣을지 생각해야 함
    solve(0,v[0]);
    cout << max_val << '\n' << min_val << '\n';
    return 0;
}