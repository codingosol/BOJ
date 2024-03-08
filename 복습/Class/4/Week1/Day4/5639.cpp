#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int v;
    node* l;
    node* r;
    node* init_node(int num);
    node* make_subtree(node* root, int num);
};

node* init_node(int num)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->v = num;
    newnode->l = nullptr;
    newnode->r = nullptr;
    return newnode;
}

void make_subtree(node* root, int num)
{
    if(num > root->v)
    {
        if(root->r == nullptr)
        {
            root->r = init_node(num);
        }
        else{
            make_subtree(root->r,num);
        }
    }
    else if(num < root->v)
    {
        if(root->l == nullptr)
        {
            root->l = init_node(num);
        }
        else{
            make_subtree(root->l,num);
        }
    }
}

void postorder(node* curnode) // 왼 오 중
{
    if(curnode->l != nullptr){
        postorder(curnode->l);
    }
    if(curnode->r != nullptr){
        postorder(curnode->r);
    }
    cout << curnode->v << '\n';
}

int main(void)
{
    int temp;
    node* root;
    cin >> temp;
    root = init_node(temp);
    while(cin >> temp){
        make_subtree(root,temp);
    }
    postorder(root);
    return 0;
}