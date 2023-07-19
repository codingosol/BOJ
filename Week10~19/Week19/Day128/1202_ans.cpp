#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 300001
using namespace std;

int N; // 보석 수
int K; // 가방수


pair<int, int> jewel[MAX];
int bag[MAX];
priority_queue<int, vector<int>, less<int>> pq;


long long solve() {
    sort(jewel, jewel+N);
    sort(bag, bag+K);

    int index = 0;
    long long sum = 0;

    for (int i = 0; i < K; i++) {
        while (index < N && bag[i] >= jewel[index].first) {
            pq.push(jewel[index].second);
            index++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for (int i = 0; i < K; ++i) {
        cin >> bag[i];
    }
    cout << solve() << '\n';
    return 0;
}