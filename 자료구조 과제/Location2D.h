#pragma once
struct Location2D {
	int row;//현재 위치의 행 번호 
	int col;//현재 위치의 열 번호 
	Location2D(int r = 0, int c = 0) {
		row = r;
		col = c;
	}
	bool isNeighor(Location2D& p) {//위치 p가 자신의 이웃인지 검사하는 함수 
		return (row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1));
		//true를 반환하면 이웃
		//false를 반환하면 이웃이 아니다
	}
	//연산자 오버로딩을 사용해서 위치q가 자신과 같은 위치인지를 검사하는 함수이다. 
	bool operator==(Location2D& p)
	{
		return row == p.row && col == p.col;
	}
};