#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)){
            return a > b;
        }
        else{
            return abs(a) > abs(b);
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,cmp> pq;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0){
            if(pq.empty())
            {
                cout << "0\n";
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(temp);
    }
    return 0;
}