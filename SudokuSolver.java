public class SudokuSolver {
    public boolean solve(SudokuBoard board) {
        int[][] grid = board.getBoard();
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (grid[row][col] == 0) { // Find an empty cell
                    for (int num = 1; num <= 9; num++) {
                        if (board.isValid(row, col, num)) {
                            grid[row][col] = num; // Place the number
                            if (solve(board)) {
                                return true; // Recursively solve
                            }
                            grid[row][col] = 0; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Solved
    }
}
