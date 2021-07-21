#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string op) {
    // write your code here
    if (sr == dr and sc == dc)
        cout << op << endl;

    else if ( sr > dr or sc > dc)
        return ;

    else
    {
        for (int i = 1; i <= dc - sc ; i++)
            printMazePaths(sr, sc + i, dr, dc, op + "h" + to_string(i));

        for (int i = 1; i <= dr - sr ; i++)
            printMazePaths(sr + i, sc, dr, dc, op + "v" + to_string(i));

        for (int i = 1; i <= dc - sc and i <= dr - sr ; i++)
            printMazePaths(sr + i, sc + i, dr, dc, op + "d" + to_string(i));
    }

}

int main() {
    int n ;
    int m ; cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}