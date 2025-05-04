

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> strengths(n);
        for (int i = 0; i < n; i++) {
            cin >> strengths[i];
        }
        
        for (int i = 0; i < n; i++) {
            int max_other = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    max_other = max(max_other, strengths[j]);
                }
            }
            
            cout << strengths[i] - max_other;
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}