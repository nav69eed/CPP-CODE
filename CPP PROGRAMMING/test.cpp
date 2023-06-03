#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    char x[5];
    int xx;

    // cout<<xx<<endl<<xx+1;
    fstream i;
    i.open("t.txt", ios::in);
    char xxx;
    char q[5];
    int j = 0;
    i >> xxx;
    while (xxx != '$')
    {
        // cout<<xxx;
        q[j] = xxx;
        i >> xxx;
        j++;
    }
    xx=atoi(q);
    cout<<xx<<endl<<xx+1;
    // cout << q[0];
    // cout << q[1];
    getchar();
    return 0;
}