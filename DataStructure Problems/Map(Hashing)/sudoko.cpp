#include<iostream>
using namespace std;
#include<map>
#include<vector>

void helper(int r, int c, vector<vector<char>>&a, map<pair<int,int>, map<int, int>>&mp, vector<map<int,int>> &row, vector<map<int,int>> &col){

    //*Stopping Criteria
    if(r==9){
        for(auto i:a){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    //* If all columns are filled or tried
    if(c==9){
        helper(r+1,0,a,mp,row,col);
        return;
    }

    //* If a cell is filled so move to next cell in that same row
    if(a[r][c] != '.'){
        helper(r,c+1,a,mp,row,col);
        return;
    }

    //* If it is empty then check for all number from 1 to 9 to get which number is legal in that cell
    for(int i=0;i<9;i++){
        int rw=r/3, cw=c/3;

        if(!mp[{rw,cw}][i] and !row[r][i] and !col[c][i]){

            //* Assign that legal number to that cell and mark it filled
            mp[{rw,cw}][i]=1;
            row[r][i]=1;
            col[c][i]=1;
            a[r][c]=i+'0';

            helper(r, c+1, a, mp, row, col);

            //* Backtracking
            mp[{rw,cw}][i]=0;
            row[r][i]=0;
            col[c][i]=0;
            a[r][c]='.';
        }
    }

}

//* Function to solve the sudoku
void solveSudoku(vector<vector<char>>&a){
    //* Here first map will track a number at a position in mini matrix of 3 X 3  where pair represents co-ordinates and map inside represents a number from 1 to 9 is present so if pos(0,2) which means this cell is in grid which lies in 0th row and 2nd column 
    map<pair<int,int>, map<int, int>>mp;
    vector<map<int,int>> row(9);  //* Track a number from 1 to 9 in row of main matrix of sudoku
    vector<map<int,int>> col(9);  //* Track a number from 1 to 9 in column of main matrix of sudoku

    //* Build map for initial values in sudoku
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]!='.'){
                mp[{i/3,j/3}][a[i][j]-'0']=1;
                row[i][a[i][j]-'0']=1;
                col[j][a[i][j]-'0']=1;
            }
        }
    }
    //* Calling helper function get the result
    helper(0,0,a,mp,row,col);
}

int main(){
    vector<vector<char>> sudoku ={

        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},

        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},

        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

    };

    solveSudoku(sudoku);
}