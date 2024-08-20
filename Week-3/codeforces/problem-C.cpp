#include <iostream>
#include <vector>
using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned int n, q; cin >> n >> q;
    vector<long long> a(n);

    cin >> a[0];
    for (int i = 1; i < n; i++) 
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    

    for (int j = 0; j < q; j++) {
        unsigned long long start, end;
        cin >> start >> end;
        
        if(start == 0){
                
            cout << a[end] << endl;
        }
        
        else{
            
            cout << a[end] - a[start-1] << endl;
        }
    }

    return 0;
}