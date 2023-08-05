#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n; // 문자열의 길이 저장
char arr[21];
vector<int> v; // 고추창을 만났을 때 그 인덱스를 저장할 벡터
bool flag = false;

void print()
{
    for(int i = 0 ; i < n; i++)
    {
        cout << arr[i];
    }
    cout << '\n';
    return;
}

bool isright() // 올바른 괄호 문자열인지 판단
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == '(') // 좌괄호일 경우 cnt 증가
            cnt++;
        else if(arr[i] == ')')
        {
            cnt--;
            if(cnt < 0) // 우괄호가 좌괄호의 개수를 넘은 경우
            {
                return false;
            }
        }
    }
    if(cnt > 0) // 좌괄호가 남아있을 경우
    {
        return false;
    }
    return true;
}

void solve(int pos) // pos는 현재 v의 인덱스
{
    if(flag)
        return;
    // 1. v에서 맨 앞의 원소를 받고 그 위치의 G를 ( 혹은 )로 바꿈
    // 2. 다음 위치로 옮겨가서 v가 빌때까지 반복...
    // 3. v의 끝에 다다랐다면 이제 그 문자열이 괄호 문자열인지 판단.
    if(pos == v.size()) // 끝이라면
    {
        if(isright()) // 괄호 문자열이라면 출력 -> 하나만 출력해야 하는데 전부 출력해버림
        {
            print();
            flag = true;
            return;
        }
    }
    else {
        int cur = v[pos];
        arr[cur] = '('; // 우괄호인 경우
        solve(pos+1); // 더 깊게 들어감
        arr[cur] = ')'; // 좌괄호인 경우
        solve(pos+1);
    }
}

int main(void)
{
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++)
    {
        arr[i] = cin.get();
        if(arr[i] == 'G')
            v.push_back(i);
    }
    // G가 묻으면 고추장임
    if(v.empty()) // 고추장이 안묻었다면
    {
        print();
        return 0;
    }
    // 백트래킹을 이용하여 G를 모든 경우의 수에서 ( 또는 )로 바꾼 후 괄호 문자열이 된다면 출력하기로 하자
    else
        solve(0);
    return 0;
}