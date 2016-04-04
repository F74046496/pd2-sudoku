#include<iostream>
#include<ctime>
#include<cstdio>
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
			ansBoard[i][j]=0;
		}
	}
	times=0;
	unsolvable=false;
	ans=0;
}
void Sudoku::giveQuestion()
{
	int i, j;
	int give[9][9]={
					{5,3,0,0,7,0,0,0,0},
					{6,0,0,1,9,5,0,0,0},
					{0,9,8,0,0,0,0,6,0},
					{8,0,0,0,6,0,0,0,3},
					{4,0,0,8,0,3,0,0,1},
					{7,0,0,0,2,0,0,0,6},
					{0,6,0,0,0,0,2,8,0},
					{0,0,0,4,1,9,0,0,5},
					{0,0,0,0,8,0,0,7,9}
					};
	srand(time(NULL));
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			sudo[i][j]=give[i][j];
		}
	}
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			give[i][j]=sudo[i][j];
			sudo[i][j]=0;
		}
	}
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
	int i, j, k, l, m;
    bool row[10], col[10], block[10];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>sudo[i][j];
		}
	}
	   for(i=0;i<10;i++)
    {
        row[i]=false;
        col[i]=false;
        block[i]=false;
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sudo[i][j]!=0&&row[sudo[i][j]]==true)
            {
                //cout<<"0"<<endl;
                unsolvable=true;
                //return;
			}
            else if(sudo[i][j]!=0&&row[sudo[i][j]]==false)
                row[sudo[i][j]]=true;
        }
        for(k=1;k<10;k++)
        {
            row[k]=false;
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sudo[j][i]!=0&&col[sudo[j][i]]==true)
            {
                //cout<<"0"<<endl;
                unsolvable=true;
                //return;
            }
            else if(sudo[j][i]!=0&&col[sudo[j][i]]==false) 
 				col[sudo[j][i]]=true;
        }
        for(k=1;k<10;k++)
        {
            col[k]=false;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=i*3;k<(i+1)*3;k++)
            {
                for(l=(j)*3;l<(j+1)*3;l++)
                {
                    if(sudo[k][l]!=0&&block[sudo[k][l]]==true)
                    {
                       // cout<<"0"<<endl;
                        unsolvable=true;
                       // return;
                    }
                    else if(sudo[k][l]!=0&&block[sudo[k][l]]==false)
					  	block[sudo[k][l]]=true;
                }
            }
            for(m=1;m<10;m++)
            {
                block[m]=false;
            }
        }
    }
	/*if(unsolvable==true)
		cout<<"true";
	else
		cout<<"false";*/
}
void Sudoku::solve()
{
	int i, j, x, y, zero;
	bool row[10], col[10], block[10], findZero;
	/*for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudo[i][j]<<" ";
		}
		cout<<endl;
	}*/
	zero=0;
	if(unsolvable==true)
	{    
		cout<<"0"<<endl;
		return;
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudo[i][j]==0)
				zero++;
		}
	}
	for(i=1;i<10;i++)
	{
		row[i]=false;
		col[i]=false;
		block[i]=false;
	}
	if(zero==0)
	{
		ans++;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				ansBoard[i][j]=sudo[i][j];
			}
		}
		if(times==0)
		{
			cout<<"1"<<endl;
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					sudo[i][j]=ansBoard[i][j];
				}
			}
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
		return;
	}
	else if(zero==81)
	{
		cout<<"2"<<endl;
		return;
	}
	findZero=false;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sudo[i][j]==0)
			{
				x=i;
				y=j;
				findZero=true;
				break;
			}
		}
		/*if(sudo[i][j]==0)
		  {
		  	break;
		  }
		  ps.j may become 9, then seg fault
*/
		if(findZero==true)
			break;
	}
	for(i=0;i<9;i++)
	{
		if(sudo[x][i]==0)
			continue;
		else if(row[sudo[x][i]]==false)
		{
			row[sudo[x][i]]=true;
		}
	}
	for(i=0;i<9;i++)
	{
		if(sudo[i][y]==0)
			continue;
		else if(col[sudo[i][y]]==false)
		{
			col[sudo[i][y]]=true;
		}
	}
	for(i=(x/3)*3;i<((x/3)+1)*3;i++)
	{
		for(j=(y/3)*3;j<((y/3)+1)*3;j++)
		{
			if(sudo[i][j]==0)
				continue;
			else if(block[sudo[i][j]]==false)
			{
				block[sudo[i][j]]=true;
			}
		}
	}
	for(i=1;i<10;i++)
	{
		if(row[i]==false&&col[i]==false&&block[i]==false)
		{
			sudo[x][y]=i;
			times++;
			solve();
			sudo[x][y]=0;
			times--;
			if(ans>=2&&times==0)
			{
				cout<<"2"<<endl;
				return;
			}
			else if(ans>=2&&times!=0)
				return;
		}
	}
	/*if(ans>=2)
	{
		cout<<"2"<<endl;
		return;
	}*/
	if(ans==1&&times==0)
	{
		cout<<"1"<<endl;
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudo[i][j]=ansBoard[i][j];
			}
		}
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
	else if(ans==0&&times==0)
	{
		cout<<"0"<<endl;
		return;
	}
/*	cout<<"1"<<endl;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<ansBoard[i][j]<<" ";
		}
		cout<<endl;
	}*/
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
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			temp[i][j]=sudo[i][j];
		}
	}
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
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			temp[i][j]=sudo[i][j];
		}
	}
	if(a!=b)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(a+b==1&&j<3)
					temp[i][j]=sudo[i][j+3];
				else if(a+b==1&&j<6&&j>=3)
					temp[i][j]=sudo[i][j-3];
				else if(a+b==2&&j<3)
					temp[i][j]=sudo[i][j+6];
				else if(a+b==2&&j<9&&j>=6)
					temp[i][j]=sudo[i][j-6];
				else if(a+b==3&&j<6&&j>=3)
					temp[i][j]=sudo[i][j+3];
				else if(a+b==3&&j<9&&j>=6)
					temp[i][j]=sudo[i][j-3];
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
			temp[i][j]=sudo[i][j];
		}
	}for(i=0;i<9;i++)
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
			temp[i][j]=sudo[i][j];
		}
	}for(i=0;i<9;i++)
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
	int i, j;
	srand(time(NULL));
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<sudo[i][j]<<" ";
		}
		cout<<endl;
	}
}
