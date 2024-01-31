#include <iostream>

using namespace std;

struct node{
    node* front; // 앞에 있는 노드 가리키는 포인터
    node* next; // 뒤에 있는 노드 가리키는 포인터
    char c; // 이 노드가 가지는 문자열
    node* init_node(char ch);
};

node* init_node(char ch) // 노드 생성
{
    node* nodeptr = (node*)malloc(sizeof(node));
    nodeptr->c = ch;
    nodeptr->next = nullptr;
    nodeptr->front = nullptr;
    return nodeptr;
}

// 커서가 D를 가리키고 있다면 각각 D를 지워야 함, D 다음에 노드를 추가해야 함
void addnode(node* cursor, node* nodeptr) // 커서 왼쪽에 노드 추가
{
    node* next = cursor->next;
    if(next != nullptr) // 커서가 맨 끝을 가리키는게 아니라면 ex) a b(커서) c -> a b d c 이렇게 추가
    {
        cursor->next = nodeptr;
        nodeptr->front = cursor;
        nodeptr->next = next;
        next->front = nodeptr;
    }
    else { // 맨 끝을 가리킨다면
        cursor->next = nodeptr;
        nodeptr->front = cursor;
    }
}

void delnode(node* cursor) // 커서 왼쪽에 있는 노드 삭제(커서가 가리키고 있는 노드 삭제임)
{
    if(cursor->c == ' ') // 커서가 nullptr이라면
    {
        return;
    }
    node* front = cursor->front;
    node* next = cursor->next;
    if(next != nullptr)
    {
        front->next = next;
        next->front = front;
    }
    else { // 커서가 맨 왼쪽에 있는 노드를 가리키고 있었다면
        front->next = nullptr;
    }
}

int main(void)
{
    string str;
    cin >> str;
    node* head = init_node(' '); // 맨 앞에 있는 가짜 노드
    node* cursor = head; // 커서는 일단 머리를 가리키게 함
    for(int i = 0; i < str.length(); i++) // 문자열을 연결 리스트화함 -> 초기화를 어떻게 해야 좋을까
    {
        node* newnode = init_node(str[i]);
        cursor->next = newnode; // 새로운 노드 연결
        newnode->front = cursor; // 연결
        cursor = cursor->next; // 커서 한칸 뒤로 옮김
    }
    // 커서는 자신의 왼쪽에 있는 노드를 가리키고 있는 상태임!!!!
    int n;
    cin >> n;
    char ch;
    // 명령어 수행 전 커서는 문자열 맨 끝에 위치함
    while(n--)
    {
        cin >> ch;
        if(ch == 'L') // 커서 왼쪽으로(커서가 맨 왼쪽이면 무시)
        {
            if(cursor->front != nullptr)
                cursor = cursor->front;
            //cout << "cursor points : " << cursor->c << '\n';
        }
        else if(ch == 'D') // 커서 오른쪽으로(커서가 끝이면 무시)
        {
            if(cursor->next != nullptr)
                cursor = cursor->next;
            //cout << "cursor points : " << cursor->c << '\n';
        }
        else if(ch == 'B') // 커서 왼쪽에 있는 문자 삭제
        {
            delnode(cursor);
            if(cursor->front != nullptr)
                cursor = cursor->front;
            //cout << "cursor points : " << cursor->c << '\n';
        }
        else if(ch == 'P') // 커서 왼쪽에 문자 하나 추가
        {
            cin >> ch;
            node* newnode = init_node(ch);
            // cout << cursor->c << '\n';
            addnode(cursor, newnode);
            cursor = cursor->next;
            //cout << "cursor points : " << cursor->c << '\n';
        }
    }
    node* temp = head;
        while(temp->next != nullptr)
        {   
            cout << temp->next->c;
            temp = temp->next;
        }
        cout << '\n';
    return 0;
}