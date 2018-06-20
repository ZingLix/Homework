## 需求分析

实现一个可以计算中缀表达式的计算器。

## 相关知识和技术分析

中缀和后缀表达式的转换，对后缀表达式的处理

## 系统架构分析

先将输入的字符串分割成数字与字符，将其转换成后缀表达式后，利用栈计算结果。

## 功能模块设计

``` java
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
}
```

## 系统界面设计

界面由两部分构成。上面一个输入框负责表达式的输入和结果的输出，下面的按钮用于输入字符。

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%202/img/1.png)

## 系统测试

利用按钮可以完成所有字符的输入。

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%202/img/2.png)

按下等号按钮后可以产生正确结果。

![](https://github.com/ZingLix/Homework/blob/master/Data%20Structures%20%26%20Algorithm/Experiment/Exp%202/img/3.png)