class Test
{
public:
    void foo();
};
 
 
void Test::foo()
{
    delete this;
}
 
int main()
{
    Test *t1 = new Test();
    t1->foo();
    return 0;
}