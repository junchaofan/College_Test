int a,b,c;
int a;
float m,n;
int d[10];
struct A{
	int a;
	int b;
};
int fibo(int a)
{
    if (a == 1 || a == 2) return (a-1);
    return fibo(a-1)+fibo(a-2);
}
int main()
{
    int m,n,i;
    // int c[10];
    char ch;
    while(i<=m)
    {
        n = fibo(i,i);
        i=i+ch;
    }
    return 1;
}
