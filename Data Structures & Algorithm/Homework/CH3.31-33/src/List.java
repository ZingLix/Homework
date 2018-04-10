public interface List<T> {
    int size();
    boolean isEmpty();
    T get(int idx);
    void set(int idx,T val);
    void add(T val);
    void add(int idex,T val);
    T remove(int idx);
}
