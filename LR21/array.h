class Array {
private:
    int lenght;
    int *arr;
public:
    Array();
    Array(int len, int *array);
    ~Array();
    void enter();
    void set(int len, int *array);
    void print();
    int count(int a, int);
    int sumAfterLastMax();
};