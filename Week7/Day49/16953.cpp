#include <iostream>
#include <queue>

using namespace std;

typedef long long int_64;

int_64 solve(int_64 start, int_64 target, int_64 cnt)
{
    // start에서 시작해서 target을 찾는 함수임
    // 한 단계씩 거칠수록 2 ^ n개의 수를 탐색할 수 있으며 
    // 수가 작아지는 법은 없으므로 초과될 경우 -1을 출력하면 됨
    // dfs로 푸니까 오류가 생김.... -> bfs로 전환
    queue<pair<int_64,int_64>> q; // first는 cur값을, second는 cnt값을 저장함
    q.push({start,cnt});
    while(!q.empty())
    {
        pair<int_64,int_64> cur = q.front();
        q.pop();
        if(cur.first == target)
        {
            return cur.second;
        }
        else {
            int_64 twice = cur.first * 2;
            if(twice <= target)
                q.push({twice,cur.second + 1});
            int_64 plus_one = cur.first * 10 + 1;
            if(plus_one <= target)
                q.push({plus_one,cur.second + 1});
        }
    }
    return -1;
}


int main(void)
{
    int_64 n;
    cin >> n;
    int_64 target;
    cin >> target;
    // 최대 수는 10^9 배열로 메모리 선언시 무조건 메모리 초과임
    cout << solve(n,target,1) << '\n';
    return 0;
}