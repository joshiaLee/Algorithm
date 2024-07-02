#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int sort_arr[10];


void func(int k){
    if(k==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){

 
            
            arr[k] = sort_arr[i];
            func(k+1);

        
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> sort_arr[i];
    }

    sort(sort_arr, sort_arr + n);
    func(0);

}