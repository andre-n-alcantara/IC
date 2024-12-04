#include <iostream>
#include <vector>

using namespace std;

int dp[5001]; // dp[i] é o número de formas de entregar i reais
int values[] = {2, 5, 10, 20, 50, 100};

int main() {
    int S, N2, N5, N10, N20, N50, N100;
    cin >> S >> N2 >> N5 >> N10 >> N20 >> N50 >> N100;

    fill(dp, dp + 5001, 0);
    dp[0] = 1; // uma forma de entregar 0 reais (não entregar nada)

    for (int i = 0; i < 6; i++) {
        for (int j = values[i]; j <= S; j++) {
            for (int k = 1; k <= (i == 0 ? N2 : (i == 1 ? N5 : (i == 2 ? N10 : (i == 3 ? N20 : (i == 4 ? N50 : N100))))); k++) {
                if (j - k * values[i] >= 0)
                    dp[j] += dp[j - k * values[i]];
            }
        }
    }

    cout << dp[S] << endl;

    return 0;
}