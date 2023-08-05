#include <iostream>

using namespace std;

int parent[100001];

int find_parent(int n) // 부모를 찾음
{
    if(parent[n] == n)
    {
        return n;
    }
    else {
        return parent[n] = find_parent(parent[n]);
    }
}

void union_parent(int a, int b) // a와 b의 부모를 하나로 묶
{
    int pa = find_parent(a); // a의 부모
    int pb = find_parent(b); // b의 부모
    // 두 부모 중 더 앞에 있는 수로 묶으면 됨
    if(pa > pb)
    {   
        parent[pa] = pb;
    }
    else {
        parent[pb] = pa;
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int gate, plane;
    cin >> gate >> plane;
    int temp;
    int ans = 0;
    // 시간복잡도가 O(n^2)이므로 크기인 10^5 최대 10^10가 됨 따라서 불가능
    for(int i = 1; i <= 100000; i++)
    {
        parent[i] = i; // 자기 자신의 부모 설정
    }
    // 시간복잡도를 줄이는 법을 찾아야 함
    // 부모가 자기 자신이라면 비어있는 항 그렇지 않다면 비어있는 게이트를 왼쪽으로 탐색
    for(int i = 0; i < plane; i++)
    {
        cin >> temp;
        // 기항할 수 있는 게이트 입력받음
        // 일단 최선으로 채워야 하므로 댈 수 있는 최대에 댐
        int target = find_parent(temp); // target은 비어있는 게이트의 번호를 리턴함
        if(target == 0) // 빈 게이트가 없다면
        {
            break;
        } 
        // union_parent(target - 1, target); // 이 게이트에 댔으므로 최소의 부분 재탐색
        parent[target] = find_parent(target-1);
        //union_parent(target, temp);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}