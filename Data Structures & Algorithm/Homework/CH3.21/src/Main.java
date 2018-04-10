import java.util.Stack;

public class Main {
    public static boolean judge(String str){
        Stack<Character> s=new Stack<>();
        boolean commentMode=false;
        for (int i=0;i<str.length();i++){
            Character c=str.charAt(i);
            if(commentMode==false){
                switch (c){
                    case '(':
                    case '[':
                    case '{':
                        s.push(c);
                        break;

                    case '/':
                        if(str.charAt(i+1)=='*'){
                            commentMode=true;
                            s.push('/');
                            i++;
                        }
                        break;

                    case ')':
                    case ']':
                    case '}':
                        if(s.empty()) return false;
                        if(s.pop()!=pair(c)) return false;
                        break;
                }
            }else {
                if(str.charAt(i)=='*'&&str.charAt(i+1)=='/'){
                    if(!s.empty()&&s.pop()=='/'){
                        commentMode=false;
                        i++;
                    }
                }
            }
        }
        if(s.empty()) return true;
        else return false;
    }

    public static Character pair(Character c){
        switch (c){
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
            default: return null;
        }
    }

    public static void main(String[] args) {
        String str=new String("{dfi}/*}asdf{*/{[asdf]asdf}");
        System.out.println("字符串："+str);
        System.out.println(judge(str));
        str="{[/*asd*/}]";
        System.out.println("字符串："+str);
        System.out.print(judge(str));
    }
}
