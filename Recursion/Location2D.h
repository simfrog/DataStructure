struct Location2D
{
    int row;
    int col;
    Location2D(int r = 0, int c = 0) { row = r; col = c; }
    
    /* 위치 p가 자신의 이웃인지 검사하는 함수 */
    bool isNeightbor(Location2D &p) {
        return ((row==p.row && (col==p.col-1 || col==p.col+1))
            || (col==p.col && (row==p.row-1 || row==p.row+1)));
    }
    
    /* 위치 p가 자신과 같은 위치인지를 검사하는 함수(연산자 오버로딩 사용) */
    bool operator==(Location2D &p) { return row==p.row && col==p.col; }
};
