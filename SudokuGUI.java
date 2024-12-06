import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SudokuGUI extends JFrame {
    private JTextField[][] cells = new JTextField[9][9];
    private SudokuBoard board = new SudokuBoard();
    private SudokuSolver solver = new SudokuSolver();

    public SudokuGUI() {
        setTitle("Sudoku Solver");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(9, 9));

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                cells[row][col] = new JTextField();
                cells[row][col].setHorizontalAlignment(JTextField.CENTER);
                add(cells[row][col]);
            }
        }

        JButton solveButton = new JButton("Solve");
        solveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                readInput();
                if (solver.solve(board)) {
                    updateGUI();
                } else {
                    JOptionPane.showMessageDialog(null, "No solution exists!");
                }
            }
