#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int arr[N];
int prefix[N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        prefix[i] = prefix[i - 1] + arr[i];
    }
    for (int i = 0; i < q; i++) {
        int tipo, k, p;
        scanf("%d", &tipo);
        if (tipo == 0) {
            scanf("%d %d", &k, &p);
            arr[k] = p;
            prefix[k] = prefix[k - 1] + arr[k];
        } else {
            scanf("%d", &k);
            printf("%d\n", prefix[k]);
        }
    }
    return 0;
}