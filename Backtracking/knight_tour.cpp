#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> chess)
{
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess.size(); j++)
        {
        cout << chess[i][j] << " ";
        }
        cout << endl;
  }
  cout << endl;
}


void knightTour(vector<vector<int>>& chess,int n,int row,int col,int move)
{
    if(row<0 || row>=n || col<0 || col>=n || chess[row][col])
    return;

    chess[row][col]=move;

    if(move==n*n)
    {
        display(chess);
    }

    knightTour(chess,n,row-2,col+1,move+1);
    knightTour(chess,n,row-1,col+2,move+1);
    knightTour(chess,n,row+1,col+2,move+1);
    knightTour(chess,n,row+2,col+1,move+1);
    knightTour(chess,n,row+2,col-1,move+1);
    knightTour(chess,n,row+1,col-2,move+1);
    knightTour(chess,n,row-1,col-2,move+1);
    knightTour(chess,n,row-2,col-1,move+1);

    chess[row][col]=0;


}


int main()
{
    int n,row,col;
    cin>>n>>row>>col;

    vector<vector<int>> chess(n,vector<int>(n,0));

    knightTour(chess,n,row,col,1);
}