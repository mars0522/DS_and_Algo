
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

    // strtok works on the character array only

    char arr[1000];

    cin.getline(arr, 1000);

    char *token = strtok(arr, " ");

    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}