#include <bits/stdc++.h>

using namespace std;

int sudoku[9][9];

void input(){
    for(int i=0;i<9;i++){
        string line;
        cin >> line;
        for(int j=0;j<9;j++){
            sudoku[i][j] = line[j] - '0';
        }
    }
}

bool check(int x,int y,int num){
    for(int i=0;i<9;i++){
        if(num == sudoku[x][i]) return false;
    }
    for(int i=0;i<9;i++){
        if(num == sudoku[i][y]) return false;
    }
    int boxRow = x/3*3;
    int boxCol = y/3*3;
    for(int i=boxRow;i<boxRow+3;i++){
        for(int j=boxCol;j<boxCol+3;j++){
            if(sudoku[i][j] == num) return false;
        }
    }

    return true;
}

bool solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j] == 0){
                for(int num=1;num<=9;num++){
                    if(check(i,j,num)){
                        sudoku[i][j] = num;

                        if(solve()){
                            return true;
                        }

                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input(); 
    solve();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout << "\n";
    }


    return 0;
}
