class Grid() {
    //1 = empty, 2 = yellow, 3 = red
    public:
    Grid();
    Piece[][] spots = new Piece [7][7];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            spots[i][j] = new Piece(1);
        }
    }//end for

    private:
    bool mark(bool[][] gr, int a, int b, int c ) {
            gr[a][b] = c;
    }
}//class ends
class Piece() {
    public: 
    Piece(int c) {
        setColor(c);
    }

    private: 
    int color;
    void setColor(int a) {
        color = a
    }
}//class ends

//playing the game
//a piece is made, the color is established, then placed in the grid
//yellow goes first