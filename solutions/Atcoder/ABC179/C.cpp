#include <iostream>

using namespace std;

int solve(int N)
{
    int cnt = 0;
    // bruteforce
    /*for (int a = 1; a < N; a++) {
        for (int b = 1; b*a < N; b++) {
            cnt++;
        }
    }*/
    for (int a = 1; a <= N; a++) {
        cnt += N/a - (N%a == 0);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    cout << solve(N) << '\n';
    return 0;
}
