#include <cstddef>
#include <iostream>

using namespace std;

struct node{
    char name;
    node* init_node(char ch);
    node* make_rightsubtree(char ch);
    node* make_leftsubtree(char ch);
    node* left_child;
    node* right_child;
};

node* tree[27]; // 1은 A, Z는 26

node* init_node(char ch)
{
    node* nodeptr = (node*)malloc(sizeof(node));
    nodeptr->name = ch;
    nodeptr->right_child = nullptr;
    nodeptr->left_child = nullptr;
    return nodeptr;
}

node* make_rightsubtree(char ch, node* parent)
{
    node* childnode = init_node(ch);
    parent->right_child = childnode;
    return childnode;
}

node* make_leftsubtree(char ch, node* parent)
{
    node* childnode = init_node(ch);
    parent->left_child = childnode;
    return childnode;
}

void preorder(node* rootnode) // 전위 순회함
{
    // 루트 -> 왼쪽 노드 -> 오른쪽 노드
    cout << rootnode->name;
    if(rootnode->left_child != nullptr)
    {
        preorder(rootnode->left_child);
    }
    if(rootnode->right_child != nullptr)
    {
        preorder(rootnode->right_child);
    }
}

void inorder(node* rootnode)
{
    // 왼쪽 -> 루트 -> 오른쪽
    if(rootnode->left_child != nullptr)
    {
        inorder(rootnode->left_child);
    }
    cout << rootnode->name;
    if(rootnode->right_child != nullptr)
    {
        inorder(rootnode->right_child);
    }
}

void postorder(node* rootnode)
{
    // 왼 -> 오 -> 루
    if(rootnode->left_child != nullptr)
    {
        postorder(rootnode->left_child);
    }
    if(rootnode->right_child != nullptr)
    {
        postorder(rootnode->right_child);
    }
    cout << rootnode->name;
}

int main(void)
{
    int n;
    cin >> n;
    char parent, left_child, right_child;
    // N이 알파벳 개수만 존재함
    for(int i = 1; i <= n; i++)
    {
        tree[i] = init_node(char(i + 64)); // 노드 init 실행
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> parent >> left_child >> right_child;
        if(left_child != '.')
            tree[parent - 64]->left_child = tree[left_child - 64];
        if(right_child != '.')
            tree[parent - 64]->right_child = tree[right_child - 64];
        // cout << parent << "'s leftnode is : " << tree[parent - 64]->left_child->name << " and rightnode is : " << tree[parent - 64]->right_child->name << '\n';
    }
    preorder(tree[1]);
    cout << '\n';
    inorder(tree[1]);
    cout << '\n';
    postorder(tree[1]);
    cout << '\n';
    return 0;
}