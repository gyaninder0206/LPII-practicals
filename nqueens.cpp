// #include <iostream>
// using namespace std;

// class NQueen {
//     int board[20][20];
//     int n;

// public:

//     NQueen() 
//     {
//         for(int i=0;i<20;i++) {
//             for(int j=0;j<20;j++) {
//                 board[i][j]=0;
//             }
//         }
//     }
// // ======================================
//     bool isSafe(int row,int col) {
//         for(int i=0;i<row;i++) {
//             if(board[i][col]==1) {
//                 return false;
//             }
//         }

//             // check left diagonal

//     for(int i=row,j=col;i>=0 &&j>=0;i--,j--) {
//         if(board[i][j]==1) {
//             return false;
//         }
//     }

//     //check right diagonal
//     for(int i=row,j=col;i>=0 &&j<n;i--,j++) {
//         if(board[i][j]==1) {
//             return false;
//         }
//     }
    
//     return true;
//     }

// bool solve(int row) {
//     if(row==n) {
//         return true;
//     }

//     for(int col=0;col<n;col++) {
//         //branch and bound check
//         if(isSafe(row,col)) {
//             // place queen
//             board[row][col]=1;

//             if(solve(row+1)) {
//                 return true;
//             }
//             board[row][col]=0;
//         }
//     }
//     return false;
// }

//     void display()
//     {
//         cout<<"\nSolution Board:\n";
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }

//         void start()
//     {
//         cout<<"Enter number of Queens: ";
//         cin>>n;

//         if(solve(0))
//         {
//             // 0 because start placing the queens from the first row
//             display();
//         }
//         else
//         {
//             cout<<"Solution not possible";
//         }
//     }

// };

// int main()
// {
//     NQueen q;

//     q.start();

//     return 0;
// }




#include<iostream>
using namespace std;

class NQueen{
    int n;
    int board[20][20];
    public:
    NQueen(){
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                board[i][j]=0;
            }
        }
    }

    bool isSafe(int row, int col){
        for(int i=0; i<row; i++){
            if(board[i][col]==1){
                return false;
            }
        }

        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }

        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]==1){
                return false;
            }
        }
        return true;
    }

    bool solve(int row){
        if(row==n){
            return true;
        }

        for(int col=0; col<n; col++){
            if(isSafe(row,col)){
                board[row][col]=1;
                if(solve(row+1)){
                    return true;
                }
                board[row][col]=0;
            }
        }
        return false;
    }

    void display(){
        cout<<"Solution is "<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void start(){
        cout<<"Enter no of queens";
        cin>>n;
        if(solve(0)){
            display();
        }
        else{
            cout<<"Solution not possible";
        }
    }
};

int main(){
    NQueen q;
    q.start();
    return 0;
}