#include <iostream>

using namespace std;

int n, m;
int arr[500001];
int temp[500001];
int cnt = 0;

// a[p..q]와 a[q+1..r]을 병합하여 a[p..r]을 오름차순 정렬된 상태로 만든다.
// a[p..q]와 a[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int arr[], int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j])
            temp[t++] = arr[i++]; // temp[t] = a[i]; t++; i++;
        else 
            temp[t++] = arr[j++]; // temp[t] = a[j]; t++; j++;
    }
    while (i <= q)  // # 왼쪽 배열 부분이 남은 경우
        temp[t++] = arr[i++];
    while (j <= r)  //# 오른쪽 배열 부분이 남은 경우
        temp[t++] = arr[j++];
    i = p;
    t = 1;
    while (i <= r)  //# 결과를 a[p..r]에 저장
    {
        arr[i++] = temp[t++];
        cnt++;
        if(cnt == m)
        {
            cout << temp[t-1] << '\n';
        }
    }
}

void merge_sort(int arr[], int p, int r) { // a[p..r]을 오름차순 정렬한다.
    if (p < r){
        int q = (p+r) / 2; // q는 p, r의 중간 지점
        merge_sort(arr, p, q); // 전반부 정렬
        merge_sort(arr, q + 1, r); // 후반부 정렬
        merge(arr, p, q, r); // 병합
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // 수가 n개 주어짐
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } // 수 입력
    merge_sort(arr, 1, n);
    /*for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';*/
    if(cnt < m)
        cout << "-1\n";
    return 0;
}