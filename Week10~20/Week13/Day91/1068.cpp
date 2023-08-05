#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51];
int n;
int cnt = 0;
int root, delnode;

int dfs(int node)
{
    // 끝에 도달하면 cnt + 1;
    if (node == delnode) 
        return -1;
	if (!tree[node].size()) {
		cnt++;
		return 0;
	}
	for (int i = 0; i < tree[node].size(); i++) {
		int tmp = dfs(tree[node][i]);
		if (tmp == -1 && tree[node].size() == 1)
			cnt++;
	}
	return 0;
}

void solve()
{
    dfs(root);
    cout << cnt << '\n';
}

int main(void)
{
    cin >> n;
    // 0번 노드부터 n-1번 노드까지
    int p;
    for(int i = 0; i < n; i++)
    {
        cin >> p;
        if(p == -1)
        {
            root = i;
        }
        else {
            tree[p].push_back(i);
        }
    } // input;
    cin >> delnode;
    solve();
    return 0;
}
