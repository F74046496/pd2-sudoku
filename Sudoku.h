#include<iostream>

class Sudoku
{
public:
	Sudoku();
	void giveQuestion();
	void readIn();
	//void preview();
	void solve();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
private:
	//bool solve;
	int ans;
	int zeroNum;
	int sudo[9][9];
};
