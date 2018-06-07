import javafx.util.Pair;

import java.sql.Struct;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class ExpressionProcessor {
    ExpressionProcessor(String str){
        experssion=str;
    }
    String experssion;

    Stack<Character> operatorStack;
    Queue<container> output;

    class container{
        boolean is_number;
        Integer num;
        Character ch;

        container(Integer i){
            is_number=true;
            num=i;
        }

        container(Character c){
            is_number=false;
            ch=c;
        }

    }

    void setExperssion(String str){
        experssion=str;
    }

    float ans(){
        return  process();
    }

    float process(){
        infix_to_postfix();
        Stack<Float> s=new Stack<>();
        while (!output.isEmpty()){
            container c=output.remove();
            if(c.is_number){
                s.push(new Float(c.num));
            }else {
                calcu_oper(c.ch,s);
            }
        }
        return s.pop();
    }

    float calcu_oper(char c,Stack<Float> s){
        Float num1=s.pop();
        Float num2=s.pop();
        Float ans;
        switch (c){
            case '+':
                ans=num1+num2;
                break;
            case '-':
                ans=num2-num1;
                break;
            case '*':
                ans=num2*num1;
                break;
            case '/':
                ans=num2/num1;
                break;
            default:
                return 0;
        }
        s.push(ans);
        return ans;
    }

    void infix_to_postfix(){
        operatorStack=new Stack<>();
        output=new LinkedList<>();
        for(int i=0;i<experssion.length();++i){
            switch (get_type(experssion.charAt(i))){
                case 1:
                    process_operator(i);
                    break;
                case 2:
                    process_bracket(i);
                    break;
                case 3:
                    int offset = process_number(i);
                    i+=offset;
                    break;
                default:
                    break;
            }
        }
        while (!operatorStack.empty()) {
            output.add(new container(operatorStack.pop()));
        }
    }

    void process_operator(int idx){
        if(operatorStack.empty()){ operatorStack.push(experssion.charAt(idx)); return;}
        if(compare(experssion.charAt(idx),operatorStack.peek())){
            operatorStack.push(experssion.charAt(idx));
        }else{
            _process_operator(experssion.charAt(idx));
        }
    }

    void _process_operator(char c){
        while (!operatorStack.isEmpty()&& !compare(c,operatorStack.peek())){
            char ch=operatorStack.pop();
            output.add(new container(ch));
        }
        operatorStack.add(c);
    }

    void process_bracket(int idx){
        if(experssion.charAt(idx)=='('){
            operatorStack.push('(');
        }else {
            while (operatorStack.peek()!='('){
                char c=operatorStack.pop();
                output.add(new container(c));
            }
            operatorStack.pop();
        }
    }

    int process_number(int idx){
        int num=0,index=idx;
        while(index<experssion.length()&&Character.isDigit(experssion.charAt(index))){
            num=num*10+experssion.charAt(index)-'0';
            ++index;
        }
        output.add(new container(num));
        return index-idx-1;
    }

    boolean compare(char c1,char c2){
        return getPriority(c1)<getPriority(c2);
    }

    int getPriority(char c){
        switch (c){
            case '*':
            case '/':
                return 1;
            case '+':
            case '-':
                return 2;
            case '(':
            case ')':
                return 3;
            default:
                return 0;
        }
    }

    int get_type(char c){
        switch (c){
            case '+':
            case '-':
            case '*':
            case '/':
                return 1;
            case '(':
            case ')':
                return 2;
            default:
                return 3;
        }
    }
    void print(){
        while(!output.isEmpty()){
            container c=output.peek();
            if(c.is_number){
                System.out.print(c.num);
            }else {
                System.out.print(c.ch);
            }
            output.remove();
        }
    }
}
