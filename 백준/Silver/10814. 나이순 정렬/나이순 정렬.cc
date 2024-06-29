#include <bits/stdc++.h>
using namespace std;

pair<int,string> arr[100005];
pair<int,string> tmp[100005];

void merge(int st, int en){
    int mid = (st+en) / 2;
    int lidx = st;
    int ridx = mid;

    for(int i=st; i<en; i++){
        if(lidx == mid) tmp[i] = arr[ridx++];
        else if(ridx == en) tmp[i] = arr[lidx++];
        else if(arr[lidx].first <= arr[ridx].first) tmp[i] = arr[lidx++];
        else if(arr[lidx].first > arr[ridx].first) tmp[i] = arr[ridx++];
    }

    for(int i=st; i<en; i++){
        arr[i] = tmp[i];
    }

}


void merge_sort(int st, int en){
    if(st+1 == en)  return;
    int mid = (st+en)/2;

    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);

}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a;
    string s;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    merge_sort(0,n);

    for(int i=0; i<n; i++){
        cout << arr[i].first << ' ';
        cout << arr[i].second << '\n';
    }
}