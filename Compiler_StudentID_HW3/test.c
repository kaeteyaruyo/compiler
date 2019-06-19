int fib(int a){
    if(a > 1){
        int a1 = a - 1;
        int f1 = fib(a1);
        int a2 = a - 2;
        int f2 = fib(a2);
        int f = f1 + f2;
        return f;
    }
    return 1;
}

void main(){
    int a = 1;
    while(a <= 20){
        int b = fib(a);
        print(b);
        a++;
    }
    return;
}