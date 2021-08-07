#include <bits/stdc++.h>
using namespace std;
int cs(int n, vector<int>& qb) {

// with memoization method
    // write your code here
//     if(n<0)
//     return 0;
//     else if(n==0)
//     return 1;

//   else if(qb[n]!=0)
//   return qb[n];

//   qb[n] = cs(n-1,qb)+cs(n-2,qb)+cs(n-3,qb);
//   return qb[n];

//     return 0;

// with tabulation method
    qb[0] = qb[1] = 1;
    qb[2] = qb[0] + qb[1];

    for (int i = 3; i <= n; i++)
        qb[i] = qb[i - 1] + qb[i - 2] + qb[i - 3];

    return qb[n];

}

int main() {
    int n;
    cin >> n;
    vector<int>qb(n + 1);
    cout << cs(n, qb) << endl;
}