#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int D=10;
void print(int board[D][D],int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		cout<<setw(3)<<board[i][j]<<" ";
		cout<<endl;
	}
}
bool canPlace(int board[D][D],int n,int Row,int Col,int num)
{
	for(int i=0; i<n; i++)
    {
		if(board[Row][i]==num)
    	return false;
    	
    	if(board[i][Col]==num)
    	return false;
    }
    int rootn=sqrt(n);
    int boxRow=Row/rootn;
    int boxCol=Col/rootn;
    int boxStartCellRow=boxRow*rootn;
    int boxStartCellCol=boxCol*rootn;
    for(int i=boxStartCellRow; i<boxStartCellRow+rootn; i++)
    {
    	for(int j=boxStartCellCol; j<boxStartCellCol+rootn; j++)
    	{
    		if(board[i][j]==num)
    		return false;
		}
	}
	return true;
	
}

bool sudokuSolver(int board[D][D],int n,int Row,int Col)
{
	if(Row==n)
	return true;
	
	int rootn=sqrt(n);
	
	if(Col==n)
	return sudokuSolver(board,n,Row+1,0);
	
	if(board[Row][Col]!=0)
	return sudokuSolver(board,n,Row,Col+1);
	
	for(int curNum=1; curNum<=9; curNum++)
	{
		if(canPlace(board,n,Row,Col,curNum))
		{
			board[Row][Col]=curNum;
			bool success=sudokuSolver(board,n,Row,Col+1);
			if(success==true)
			return true;
			board[Row][Col]=0;
			
		}
	}
	return false;
}
int main()
{
	int board[D][D]={
		{0,0,0,2,6,0,7,0,1},
		{6,8,0,0,7,0,0,9,0},
		{1,9,0,0,0,4,5,0,0},
		{8,2,0,1,0,0,0,4,0},
		{0,0,4,6,0,2,9,0,0},
		{0,5,0,0,0,3,0,2,8},
		{0,0,9,3,0,0,0,7,4},
		{0,4,0,0,5,0,0,3,6},
		{7,0,3,0,1,8,0,0,0}
		
	};
	int n; 
	cin>>n;
	bool solve=sudokuSolver(board,n,0,0);
	if(solve==true)
	{
		print(board,n);
	}
	else
	cout<<"soory not able to solve it";
}

