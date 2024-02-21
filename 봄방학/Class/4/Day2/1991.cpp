#include <iostream>

using namespace std;

int tree[26][2]; // 0이 왼쪽 노드 1이 오른쪽 노드

void preorder(int node) // 중 왼 오
{
    cout << char(node + 'A');
    if(tree[node][0] != -1){
        preorder(tree[node][0]);
    }
    if(tree[node][1] != -1){
        preorder(tree[node][1]);
    }
}

void inorder(int node) // 왼 중 오
{
    if(tree[node][0] != -1){
        inorder(tree[node][0]);
    }
    cout << char(node + 'A');
    if(tree[node][1] != -1){
        inorder(tree[node][1]);
    }
}

void postorder(int node) // 왼 오 중
{
    if(tree[node][0] != -1){
        postorder(tree[node][0]);
    }
    if(tree[node][1] != -1){
        postorder(tree[node][1]);
    }
    cout << char(node + 'A');
}

int main(void)
{
    int n;
    cin >> n;
    char root, r, l;
    for(int i = 0; i < n; i++)
    {
        cin >> root >> l >> r;
        if(l != '.') // 왼쪽 입력
            tree[root - 'A'][0] = l - 'A';
        else
            tree[root - 'A'][0] = -1;
        if(r != '.') // 오른쪽 입력
            tree[root - 'A'][1] = r - 'A';
        else
            tree[root - 'A'][1] = -1;
    } // input
    preorder(0); // 전위 순회
    cout << '\n';
    inorder(0); // 중위 순회
    cout << '\n';
    postorder(0); // 후위 순회
    cout << '\n';
    return 0;
}