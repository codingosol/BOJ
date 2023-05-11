#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[51];

int find_p(int parent[], int x){
    if(x != parent[x])
        return parent[x] = find_p(parent, parent[x]);
    else
        return parent[x];
}
// x와 y를 같은 그룹으로 만들어줌
void mer(int parent[], int x, int y){
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);
    if(px != py){
        if(px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}

int main(void)
{
    /*  첫째 줄에 사람의 수 N과 파티의 수 M이 주어진다.
        둘째 줄에는 이야기의 진실을 아는 사람의 수와 번호가 주어진다. 진실을 아는 사람의 수가 먼저 주어지고 그 개수만큼 사람들의 번호가 주어진다. 사람들의 번호는 1부터 N까지의 수로 주어진다.
        셋째 줄부터 M개의 줄에는 각 파티마다 오는 사람의 수와 번호가 같은 방식으로 주어진다.
        N, M은 50 이하의 자연수이고, 진실을 아는 사람의 수는 0 이상 50 이하의 정수, 각 파티마다 오는 사람의 수는 1 이상 50 이하의 정수이다.
    */
    // 출력값은 걸리지 않고 허풍을 떨 수 있는 파티의 최대 개수!
    // 찾아보니 유니온 파인드란 개념을 쓰는 거 같음...
    cin >> n >> m;
    int true_num;
    cin >> true_num;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i; // 각자 자신의 그룹으로 분류
    }
    int temp;
    for(int i = 0; i < true_num; i++)
    {
        cin >> temp;
        parent[temp] = 0; // 진실을 아는 사람들은 0집합으로 분류
    } 
    int Pnum;
    int temp2;
 
    int arr[53][53]; // 파티번호, 파티 사람 번호
    int arrsiz[53]; // 각 파티의 인원수 저장
    for(int i = 0; i < m; i++)
    {
        cin >> Pnum; // 파티에 오는 사람 수 
        cin >> temp; // 파티에 오는 첫번째 사람
        arrsiz[i] = Pnum; // 각 파티의 인원 수 저장
        arr[i][0] = temp; 
        // 첫번째 사람만 올 경우 혼자 오는 것이기 때문에
        // 다른 사람과 그룹을 합치지 않아도 돼서 분류
        for(int j = 1; j < Pnum; j++){
            cin >> temp2; // 파티에 오는 사람 번호
            arr[i][j] = temp2; // 파티에 오는 사람 번호 저장
            mer(parent, temp ,temp2); // 파티에 오는 사람 그룹 합침
        }
    }
    int answer = m; // 전부 거짓말을 할 경우 수 부터 시작
    
    // 각 파티마다 진실을 아는 사람이 한명이라도 있으면 거짓말을 할 수 없음
    // -> 하나 빼줌
    for(int i = 0; i < m; i++){ // 파티 검사
        for(int j = 0; j < arrsiz[i]; j++){ // 파티 인원수 검사 후 진실을 아는 사람이 있다면
            if(find_p(parent, parent[arr[i][j]]) == 0){
                answer--;
                break;
            }
        }
    }
    cout << answer;
    return 0;
    return 0;
}