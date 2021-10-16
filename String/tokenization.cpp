
#include<bits/stdc++.h>


using namespace std;

int main()
{

    // for fast input output"
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif

    string input;
    getline(cin, input);

    stringstream ss(input);

    string token;
    vector<string> tokens;

    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    for (auto i : tokens)
        cout << i << endl;
}