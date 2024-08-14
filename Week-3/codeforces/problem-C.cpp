#include <iostream>
using namespace std;


int main() {
    

    unsigned int n, q; cin >> n >> q;
    int a[n];
    unsigned short start, end;

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for (int i = 1 ; i < n ; i++){
        a[i] = a[i-1]+a[i];
    }
    for (int j = 0; j < q; j++) {
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