#include <iostream>

using namespace std;

int n; // 수의 개수
int inorder[100001];
int postorder[100001];
int map[100001]; 

void preorder(int instart, int inend, int poststart, int postend) // 인오더의 시작점, 끝점, 포스트오더의 시작, 끝점을 받음
{
    if(instart > inend || poststart > postend) // 더이상 재귀할 수 없을 때
    {
        return;
    }
    // 이제 포스트오더의 끝점에 있는 노드를 인오더에서 찾고 나서 재귀해야 함
    int pivot = map[postorder[postend]];
    // map에 인덱스를 기록해놓았으므로 찾을 수 있음
    int rootnode = inorder[pivot];
    // 루트노드를 찾았으므로 M->L->R 규칙에 따라 루트 출력
    cout << rootnode << ' ';
    // 그 이후 왼쪽, 오른쪽 노드 재귀
    // 인오더의 경우 왼쪽은 instart부터 시작해서 pivot-1까지이고 오른쪽 탐색은 pivot+1로 시작하여 inend까지임
    // 포스트오더의 경우 루트 노드가 끝에 있었으므로 반으로 나눠야 하는데 나누기가 힘듬
    // 이때, 앞에서 인오더와 포스트오더가 처음으로 달라지는 순간이 각각 루트노드, R노드임을 이용함
    int left_size = pivot - instart; // 달라지는 순간까지의 크기
    preorder(instart, pivot-1, poststart, poststart + left_size - 1);
    preorder(pivot+1, inend, poststart + left_size, postend - 1);

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    // 이후 2개의 줄에 인오더, 포스트오더를 받으면 프리오더를 내뱉어야 함
    // 인오더는 L->M->R 이며 포스트오더는 L->R->M 프리오더는 M->L->R이다
    for(int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        map[inorder[i]] = i; // 입력받은 노드가 몇 번 인덱스에 있는지 여부를 기록함
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }
    // 인오더와 포스트오더로 어떻게 트리를 구성할 수 있을까
    // 인오더와 포스트오더가 처음으로 달라지는 순간이 인오더는 루트노드이며 포스트오더는 R노드임
    // 포스트오더의 맨 마지막에는 무조건 루트 노드가 옴
    // 포스트오더의 맨 마지막 루트 노드를 인오더에서 찾고 양쪽으로 분할해서 반복할 수 있음
    preorder(1, n, 1, n);
    cout << '\n';
    return 0;
}