#include <iostream>

using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node* make_subtree(int num);
    node* init_node(int num);
};

node* init_node(int num)
{
    node* nodeptr = (node*)malloc(sizeof(node));
    nodeptr->val = num;
    nodeptr->right = nullptr;
    nodeptr->left = nullptr;
    return nodeptr;
}

void make_subtree(node* curnode, int num)
{
    if(curnode->val > num) // 작다면 왼쪽
    {
        if(curnode->left != nullptr)
        {
            make_subtree(curnode->left, num);
        }
        else {
            curnode->left = init_node(num);
        }
    }
    else { // 크다면 오른쪽
        if(curnode->right != nullptr)
        {
            make_subtree(curnode->right, num);
        }
        else {
            curnode->right = init_node(num);
        }
    }
}

void postorder(node* rootnode) // 트리를 순회하며 후위 출력함
{
    // 왼쪽 -> 오른쪽 -> 루트
    if(rootnode->left != nullptr)
    {
        postorder(rootnode->left);
    }
    if(rootnode->right != nullptr)
    {
        postorder(rootnode->right);
    }
    cout << rootnode->val << '\n';
}

int main(void)
{
    // 입력은 계속 주어짐
    int temp;
    node* root;
    cin >> temp;
    root = init_node(temp);
    while(cin >> temp)
    {
        make_subtree(root, temp);
    }
    postorder(root);
    return 0;
}