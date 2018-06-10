public class point {
    float x;
    float y;

    point(float x_,float y_){
        x=x_;
        y=y_;
    }

    @Override
    public boolean equals(Object obj)
    {
        point p=(point) obj;
        return Math.abs(x-p.x)<=0&&Math.abs(y-p.y)<=0;
    }
}
