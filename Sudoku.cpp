#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	int i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			sudo[i][j]=0;
		}
	}
	ans=0;
	zeroNum=0;
	//solve=false;
}
void Sudoku::giveQuestion()
{
	int i, j;
	int give[9][9]={5,3,0,0,7,0,0,0,0,
					6,0,0,1,9,5,0,0,0,
					0,9,8,0,0,0,0,6,0,
					8,0,0,0,6,0,0,0,3,
					4,0,0,8,0,3,0,0,1,
					7,0,0,0,2,0,0,0,6,
					0,6,0,0,0,0,2,8,0,
					0,0,0,4,1,9,0,0,5,
					0,0,0,0,8,0,0,7,9};
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<give[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Sudoku::readIn()
{
	int i, j;
	//int rCheck=9, cCheck=9, bCheck=9;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>sudo[i][j];
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudo[i][j]==0)
			zeroNum++;
		}
	}

	/*	for(i=0;i<9;i++)
	{
		if(rCheck==1&&row[i]==false)
			sudo[x][y]=i;
		if(cCheck==1&&col[i]==false)
			sudo[x][y]=i;
		if(bCheck==1&&block[i]==false)
			sudo[x][y]=i;
	}
*/	
}
void Sudoku::solve()
{
	int i, j, x, y;
	bool row[9], col[9], block[9];
	
	
	if(ans>=1)
	{
		cout<<"1"<<endl;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				cout<<sudo[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			row[j]=false;
			col[j]=false;
			block[j]=false;
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudo[i][j]==0)
			{
				x=i;
				y=j;			
			}
		}
	}
	for(i=0;i<9;i++)
	{
		if(row[sudo[x][i]-1]==true)
		{
			cout<<"0"<<endl;
			return;
		}
		else if(sudo[x][i]!=0)
		{
			row[sudo[x][i]-1]=true;
			//rCheck--;
		}
	}
	for(i=0;i<9;i++)
	{
		if(col[sudo[i][y]-1]==true)
		{
			cout<<"0"<<endl;
			return;
		}
		else if(sudo[i][y]!=0)
		{
			col[sudo[i][y]-1]=true;
			//cCheck--;
		}
	}
	for(i=(x/3)*3;i<(x/3+1)*3;i++)
	{
		for(j=(y/3)*3;j<(y/3+1)*3;j++)
		{
			if(block[sudo[i][j]-1]==true)
			{
				cout<<"0"<<endl;
				return;
			}
			else if(sudo[i][j]!=0)
			{
				block[sudo[i][j]-1]=true;
				//bCheck--;
			}
		}
	}
	for(i=0;i<9;i++)
	{
		if(row[i]==false)
		{
			sudo[x][y]=i;
			solve();
			zeroNum--;
		}
	}
	for(i=0;i<9;i++)
	{
		if(col[i]==false)
		{
			sudo[x][y]=i;
			solve();
			zeroNum--;
		}
	}
	for(i=0;i<9;i++)
	{
		if(block[i]==false)
		{
			sudo[x][y]=i;
			solve();
			zeroNum--;
		}
	}
	if(zeroNum==0)
		ans++;	
}
void Sudoku::changeNum(int a, int b)
{
	int i, j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudo[i][j]==a)
				sudo[i][j]=b;
			else if(sudo[i][j]==b)
				sudo[i][j]=a;
		}
	}
}
void Sudoku::changeRow(int a, int b)
{
	int i, j;
	int temp[9][9];	
	if(a!=b)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a+b==1&&i<3)
					temp[i+3][j]=sudo[i][j];
				else if(a+b==1&&i<6&&i>=3)
					temp[i-3][j]=sudo[i][j];
				else if(a+b==2&&i<3)
					temp[i+6][j]=sudo[i][j];
				else if(a+b==2&&i<9&&i>=6)
					temp[i-6][j]=sudo[i][j];
				else if(a+b==3&&i<6&&i>=3)
					temp[i+3][j]=sudo[i][j];
				else if(a+b==3&&i<9&&i>=6)
					temp[i-3][j]=sudo[i][j];
			}	
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudo[i][j]=temp[i][j];
			}
		}
	}
}
void Sudoku::changeCol(int a, int b)
{
	int i, j;
	int temp[9][9];	
	if(a!=b)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a+b==1&&j<3)
					temp[i][j+3]=sudo[i][j];
				else if(a+b==1&&j<6&&j>=3)
					temp[i][j-3]=sudo[i][j];
				else if(a+b==2&&j<3)
					temp[i][j+6]=sudo[i][j];
				else if(a+b==2&&j<9&&j>=6)
					temp[i][j-6]=sudo[i][j];
				else if(a+b==3&&j<6&&j>=3)
					temp[i][j+3]=sudo[i][j];
				else if(a+b==3&&j<9&&j>=6)
					temp[i][j-3]=sudo[i][j];
			}	
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudo[i][j]=temp[i][j];
			}
		}
	}
}
void Sudoku::rotate(int n)
{
	int i, j;
	int temp[9][9];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(n%4==1)
				temp[i][j]=sudo[9-j-1][i];
			else if(n%4==2)
				temp[9-i-1][j]=sudo[i][9-j-1];
			else if(n%4==3)
				temp[j][i]=sudo[i][9-j-1];
		}
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			sudo[i][j]=temp[i][j];
		}
	}
}
void Sudoku::flip(int n)
{
	int i, j;
	int temp[9][9];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(n==0)
				temp[9-i-1][j]=sudo[i][j];
			else if(n==1)
				temp[i][9-j-1]=sudo[i][j];
		}
	}	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			sudo[i][j]=temp[i][j];
		}
	}
}
void Sudoku::transform()
{
	srand(time(NULL));
	readIn();
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
