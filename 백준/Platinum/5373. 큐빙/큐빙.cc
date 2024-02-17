#include <bits/stdc++.h>
using namespace std;
#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5

string cube[6][3];
string temp[3];
string store;
string write;

void anticlock(int area){
    for(int i=0; i<3; i++)
        temp[i] = cube[area][i];

    cube[area][2][0] = temp[0][0];
    cube[area][2][1] = temp[1][0];
    cube[area][2][2] = temp[2][0];
    cube[area][1][2] = temp[2][1];
    cube[area][0][2] = temp[2][2];
    cube[area][0][1] = temp[1][2];
    cube[area][0][0] = temp[0][2];
    cube[area][1][0] = temp[0][1];

}

void clock(int area){
    for(int i=0; i<3; i++)
        temp[i] = cube[area][i];

    cube[area][2][2] = temp[0][2];
    cube[area][2][1] = temp[1][2];
    cube[area][2][0] = temp[2][2];
    cube[area][1][0] = temp[2][1];
    cube[area][0][0] = temp[2][0];
    cube[area][0][1] = temp[1][0];
    cube[area][0][2] = temp[0][0];
    cube[area][1][2] = temp[0][1];
    
}

void u_clock(){
    
    clock(U);

    for(int i=0; i<3; i++) write[i] = cube[F][0][i]; // 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[L][0][i]; // 왼쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[L][0][i] = write[i]; // 왼쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[B][0][i]; // 뒷쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[B][0][i] = write[i]; // 뒷쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[R][0][i]; // 오른쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[R][0][i] = write[i]; // 오른쪽면 쓴다
    
    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) cube[F][0][i] = write[i]; // 앞쪽면에 쓴다 (이미 처음에 옮겼으므로 저장할필요는 없다.)
}

void u_anticlock(){
    
    anticlock(U);
    for(int i=0; i<3; i++) write[i] = cube[F][0][i]; // 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[R][0][i]; // 오른쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[R][0][i] = write[i]; // 오른쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[B][0][i]; // 뒷쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[B][0][i] = write[i]; // 뒷쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[L][0][i]; // 왼면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[L][0][i] = write[i]; // 왼쪽면 쓴다
    
    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) cube[F][0][i] = write[i]; // 앞쪽면에 쓴다 (이미 처음에 옮겼으므로 저장할필요는 없다.)
}

void d_anticlock(){

    anticlock(D);
    for(int i=0; i<3; i++) write[i] = cube[F][2][i]; // 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[L][2][i]; // 왼쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[L][2][i] = write[i]; // 왼쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[B][2][i]; // 뒷쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[B][2][i] = write[i]; // 뒷쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[R][2][i]; // 오른쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[R][2][i] = write[i]; // 오른쪽면 쓴다
    
    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) cube[F][2][i] = write[i]; // 앞쪽면에 쓴다 (이미 처음에 옮겼으므로 저장할필요는 없다.)

}

void d_clock(){
    clock(D);
    for(int i=0; i<3; i++) write[i] = cube[F][2][i]; // 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[R][2][i]; // 오른쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[R][2][i] = write[i]; // 오른쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[B][2][i]; // 뒷쪽면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[B][2][i] = write[i]; // 뒷쪽면 쓴다

    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) store[i] = cube[L][2][i]; // 왼면 쓰기전에 저장
    for(int i=0; i<3; i++) cube[L][2][i] = write[i]; // 왼쪽면 쓴다
    
    for(int i=0; i<3; i++) write[i] = store[i]; // 저장했던놈 -> 쓸놈
    for(int i=0; i<3; i++) cube[F][2][i] = write[i]; // 앞쪽면에 쓴다 (이미 처음에 옮겼으므로 저장할필요는 없다.)

}

void f_clock(){
    clock(F);
    for(int i=0; i<3; i++) write[i] = cube[U][2][i];
    for(int i=0; i<3; i++) store[i] = cube[R][i][0];
    for(int i=0; i<3; i++) cube[R][i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][2][i];
    for(int i=0; i<3; i++) cube[D][2][i] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[L][i][2];
    for(int i=0; i<3; i++) cube[L][2-i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][2][2-i] = write[i];
}

void f_anticlock(){

    anticlock(F);
    for(int i=0; i<3; i++) write[i] = cube[U][2][i];
    for(int i=0; i<3; i++) store[i] = cube[L][i][2];
    for(int i=0; i<3; i++) cube[L][2-i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][2][i];
    for(int i=0; i<3; i++) cube[D][2][2-i] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[R][i][0];
    for(int i=0; i<3; i++) cube[R][i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][2][i] = write[i];
       
}

void b_anticlock(){

    anticlock(B);
    for(int i=0; i<3; i++) write[i] = cube[U][0][i];
    for(int i=0; i<3; i++) store[i] = cube[R][i][2];
    for(int i=0; i<3; i++) cube[R][i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][0][i];
    for(int i=0; i<3; i++) cube[D][0][i] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[L][i][0];
    for(int i=0; i<3; i++) cube[L][2-i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][0][2-i] = write[i];

}


void b_clock(){

    clock(B);
    for(int i=0; i<3; i++) write[i] = cube[U][0][i];
    for(int i=0; i<3; i++) store[i] = cube[L][i][0];
    for(int i=0; i<3; i++) cube[L][2-i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][0][i];
    for(int i=0; i<3; i++) cube[D][0][2-i] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[R][i][2];
    for(int i=0; i<3; i++) cube[R][i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][0][i] = write[i];

}
// finish

void l_clock(){
    
    clock(L);

    for(int i=0; i<3; i++) write[i] = cube[U][i][0];
    for(int i=0; i<3; i++) store[i] = cube[F][i][0];
    for(int i=0; i<3; i++) cube[F][i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][i][2];
    for(int i=0; i<3; i++) cube[D][2-i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[B][i][2];
    for(int i=0; i<3; i++) cube[B][i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][2-i][0] = write[i]; 
}

void l_anticlock(){

    anticlock(L);
    for(int i=0; i<3; i++) write[i] = cube[U][i][0];
    for(int i=0; i<3; i++) store[i] = cube[B][i][2];
    for(int i=0; i<3; i++) cube[B][2-i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][i][2];
    for(int i=0; i<3; i++) cube[D][i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[F][i][0];
    for(int i=0; i<3; i++) cube[F][2-i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][i][0] = write[i]; 

}

void r_clock(){

    clock(R);
    for(int i=0; i<3; i++) write[i] = cube[U][i][2];
    for(int i=0; i<3; i++) store[i] = cube[B][i][0];
    for(int i=0; i<3; i++) cube[B][2-i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][i][0];
    for(int i=0; i<3; i++) cube[D][i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[F][i][2];
    for(int i=0; i<3; i++) cube[F][2-i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][i][2] = write[i]; 

}

void r_anticlock(){

    anticlock(R);
    for(int i=0; i<3; i++) write[i] = cube[U][i][2];
    for(int i=0; i<3; i++) store[i] = cube[F][i][2];
    for(int i=0; i<3; i++) cube[F][i][2] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[D][i][0];
    for(int i=0; i<3; i++) cube[D][2-i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) store[i] = cube[B][i][0];
    for(int i=0; i<3; i++) cube[B][i][0] = write[i];

    for(int i=0; i<3; i++) write[i] = store[i];
    for(int i=0; i<3; i++) cube[U][2-i][2] = write[i]; 

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    write = "temporary";
    store = "temporary";
    while(t--){
        for(int i=0; i<3; i++)
                cube[U][i] = "www";
        
        for(int i=0; i<3; i++)
                cube[D][i] = "yyy";
        
        for(int i=0; i<3; i++)
                cube[F][i] = "rrr";

        for(int i=0; i<3; i++)
                cube[B][i] = "ooo";
        
        for(int i=0; i<3; i++)
                cube[L][i] = "ggg";

        for(int i=0; i<3; i++)
                cube[R][i] = "bbb";

        int n;
        cin >> n;
        while(n--){
            string s;
            cin >> s;
            if(s == "U+") u_clock();
            else if(s == "U-") u_anticlock();
            else if(s == "D+") d_clock();
            else if(s == "D-") d_anticlock();
            else if(s == "F+") f_clock();
            else if(s == "F-") f_anticlock();
            else if(s == "B+") b_clock();
            else if(s == "B-") b_anticlock();
            else if(s == "L+") l_clock();
            else if(s == "L-") l_anticlock();
            else if(s == "R+") r_clock();
            else if(s == "R-") r_anticlock();
 
        }
        // for(int z=0; z<6; z++){
        //     if(z==0) cout << "윗" << '\n';
        //     if(z==1) cout << "아" << '\n';
        //     if(z==2) cout << "앞" << '\n';
        //     if(z==3) cout << "뒷" << '\n';
        //     if(z==4) cout << "왼" << '\n';
        //     if(z==5) cout << "오" << '\n';
        //     for(int i=0; i<3; i++){
        //         for(int j=0; j<3; j++){
                    
        //             cout << cube[z][i][j];
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << cube[U][i][j];
            }
            cout << '\n';
        }
    }   
}