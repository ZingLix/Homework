import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Form {
    private JPanel panel1;
    private JTextPane textPane1;
    private JPanel ButtonArea;
    private JButton Button_7;
    private JButton Button_8;
    private JButton Button_9;
    private JButton Button_times;
    private JButton Button_leftBracket;
    private JButton Button_rightBracket;
    private JButton Button_backspace;
    private JButton Button_divide;
    private JButton Button_4;
    private JButton Button_5;
    private JButton Button_6;
    private JButton Button_add;
    private JButton Button_1;
    private JButton Button_2;
    private JButton Button_3;
    private JButton Button_minus;
    private JButton Button_ac;
    private JButton Button_0;
    private JButton Button_dot;
    private JButton Button_equal;

    public Form() {
        Button_leftBracket.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"(");
            }
        });
        Button_rightBracket.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+")");
            }
        });
        Button_backspace.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String str=textPane1.getText();
                str=str.substring(0,str.length()-1);
                textPane1.setText(str);
            }
        });
        Button_divide.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"/");
            }
        });
        Button_7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"7");
            }
        });
        Button_8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"8");
            }
        });
        Button_9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"9");
            }
        });
        Button_6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"6");
            }
        });
        Button_5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"5");
            }
        });
        Button_4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"4");
            }
        });
        Button_3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"3");
            }
        });
        Button_2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"2");
            }
        });
        Button_1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"1");
            }
        });
        Button_0.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"0");
            }
        });
        Button_times.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"*");
            }
        });
        Button_add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"+");
            }
        });
        Button_minus.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText(textPane1.getText()+"-");
            }
        });
        Button_ac.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textPane1.setText("");
            }
        });
        Button_equal.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ExpressionProcessor p=new ExpressionProcessor(textPane1.getText());
                Float ans = p.process();
                textPane1.setText(ans.toString());
            }
        });

    }

    private void createUIComponents() {
        // TODO: place custom component creation code here
    }


    public static void main(String[] args) {
        JFrame frame = new JFrame("Experiment 2");
        frame.setContentPane(new Form().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
