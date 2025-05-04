#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    if(1<t<250)
    {
    while (t--) 
    {
        int k, q;
        cin >> k>>q;
        if(1<k<100 && 1<q<100)
        {
        int a1;
        cin >> a1;
        for (int i = 1; i < k; i++) 
        {
            int dummy;
            cin >> dummy;
        }
        for (int i = 0; i < q; i++) 
        {
            int n;
            cin >> n;
            cout << (n < a1 ? n : a1 - 1) << " ";
        }
        cout << "\n";
        }
    }
    }
    return 0;
}