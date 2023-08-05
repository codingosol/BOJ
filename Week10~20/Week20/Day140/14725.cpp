#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Trie
{
    string name; // 자신의 데이터 
    vector<Trie> child; // 자식 노드들 저장

    Trie* find_child(string str); // 자식 찾는 함수(있으면 true 반환)
    void add_child(string str);
};

Trie* Trie::find_child(string str)
{
    for(int i = 0; i < child.size(); i++)
    {
        if(str == child[i].name)
        {
            //cout << "found\n";
            return &child[i]; // 있다면 그 주소 리턴
        }
    }
    //cout << "none\n";
    return nullptr; // 없으면 nullptr 리턴
}

void Trie::add_child(string str) // 현재 부모 노드와 같은 이름의 자식 노드 추가시 오류 발생
{
    //cout << "making newnode\n";
    Trie* newTrie = new Trie; // 여기서 오류 발생
    newTrie->name = str;
    child.push_back(*newTrie);
    //cout << "Added : " << str << '\n'; 
}

bool cmp(Trie a, Trie b)
{
    return a.name < b.name;
}

void dfs(Trie* cur, int depth)
{
    sort(cur->child.begin(),cur->child.end(),cmp);
    for(int i = 0; i < cur->child.size(); i++)
    {
        // 현재 출력
        for(int j = 0; j < depth; j++)
        {
            cout << "--";
        }
        cout << cur->child[i].name << '\n';
        dfs(&cur->child[i],depth+1);
    }
}

int main(void)
{
    // 잘 썻는데 이거 사전순으로 어케하농?
    // 사전순으로 ㅆ1발 어떻게출력하냐?
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Trie* head = new Trie; // 개미굴 입구 생성
    Trie* cur = head;
    for(int i = 0; i < n; i++)
    {
        cur = head;
        //dfs(head,0);
        //cout << i << '\n';
        int depth;
        cin >> depth;
        for(int j = 0; j < depth; j++)
        {
            string temp;
            cin >> temp;
            if(cur->find_child(temp) != nullptr) // 이미 찾는 노드가 있다면
            {
                //cout << "already exist\n";
                cur = cur->find_child(temp); // 이동
            }
            else { // 없다면 추가
                //cout << "new node added\n";
                cur->add_child(temp);
                // cout << "done\n";
                cur = cur->find_child(temp);
            }
        }
    } // 추가 끝났으면 이제 탐색
    // 탐색은 dfs로 해야함
    dfs(head,0);
    return 0;
}