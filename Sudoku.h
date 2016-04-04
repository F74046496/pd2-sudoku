#include<iostream>

class Sudoku
{
public:
	Sudoku();
	void giveQuestion();
	void readIn();
	void solve();
	void changeNum(int a, int b);
	void changeRow(int a, int b);
	void changeCol(int a, int b);
	void rotate(int n);
	void flip(int n);
	void transform();
private:
	bool unsolvable;
	int times;
	int ans;
	int sudo[9][9];
	int ansBoard[9][9];
};
