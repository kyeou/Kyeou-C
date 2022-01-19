import java.util.Arrays

class Grid {
  var grids = Array(7) {Array(7) {Piece(1)}  }
  fun setPiece(color: Int, x: Int, y: Int) {
    grids
  }
}

class Piece constructor(color: Int) {
   //empty = 1, yellow = 2, red = 3
    var c = color; 
    fun setColor(a: Int) {
        c = a;
    }
}

