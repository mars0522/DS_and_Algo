#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>res;

void fun(vector<int>& ip, int i, int sum, int target, vector<int> op)
{
    if (sum == target)
    {

        res.push_back(op);
        return;
    }
    else if (i == ip.size())
    {
        return;
    }
    else
    {
        vector<int> op1(op);
        vector<int> op2(op);
        op1.push_back(ip[i]);

        fun(ip, i + 1, sum + ip[i], target, op1);
        fun(ip, i + 1, sum, target, op2);
    }
}

int main()
{



    int n, target;
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> target;

    vector<int>op;

    fun(v, 0, 0, target, op);

    for (auto v : res)
    {
        for (auto i : v)
            cout << i << ",";

        cout << ".";
        cout << endl;
    }

    return 0;


}