class line implements Comparable<line>{
    float k;
    float b;
    point p1;
    point p2;

    line(float k_,float b_,point p1_,point p2_){
        k=k_;
        b=b_;
        p1=p1_;
        p2=p2_;
    }

    public int compareTo(line l){
        if(Math.abs(k - l.k)<=0){
            if(Math.abs(b-l.b)<=0){
                return 0;
            }else{
                if(b<=l.b) return -1;
                else return 1;
            }
        }else{
            if(k <= l.k) return -1;
            else return 1;
        }
    }
}