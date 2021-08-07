#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<int>& qb) {
    // write your code here
    if (n == 0 or n == 1)
        return n;
    else if (qb[n] != 0)
        return qb[n];
    else
    {
        int i = fib(n - 1, qb);
        int j = fib(n - 2, qb);
        qb[n] = i + j;
        return qb[n];
    }


    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int>qb(n + 1);
    cout << fib(n, qb) << endl;
    return 0;
}