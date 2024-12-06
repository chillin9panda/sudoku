public class SudokuBoard {
    private int[][] board;

    public SudokuBoard() {
        board = new int[9][9]; // 9x9 Sudoku board
    }

    public int[][] getBoard() {
        return board;
    }

    public void setCell(int row, int col, int value) {
        board[row][col] = value;
    }

    public boolean isValid(int row, int col, int num) {
        // Check row
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }

        // Check column
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }

        // Check 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }

        return true;
    }
}
