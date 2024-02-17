#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        // 그냥 deque는 정렬되어있지 않으므로 불가능
        // 정렬되어야 하며 양방향에서 입출력이 가능해야 함
        // priority_queue에서 vector 대신 deque로 선언 가능한가? -> 안됨
        // 그럼 중복을 허용하고 정렬되는 multiset? -> 출력이 힘듬
        int n;
        cin >> n;
        char oper;
        int num;
        multiset<int> ms;
        for(int j = 0; j < n; j++)
        {
            cin >> oper >> num;
            if(oper == 'I')
            {
                ms.insert(num);
            }
            else if(oper == 'D')
            {
                if(!ms.empty()) // 비어 있다면 연산은 무시
                {
                    if(num == -1){ // 작은 값 삭제
                        ms.erase(ms.begin());
                    }
                    else if(num == 1){
                        auto iter = ms.end();
                        iter--;
                        ms.erase(iter);
                    }
                }
            }
        }
        if(ms.empty()){
            cout << "EMPTY\n";
        }
        else{
            auto iter = ms.end();
            iter--;
            cout << *iter << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}