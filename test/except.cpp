#include <bits/stdc++.h>

using namespace std;

class tiny {
public: 
    tiny() {
        printf("tiny()\n");
    }
    ~tiny() {
        printf("~tiny()\n");
    }
};

class A {
public: 
    A() : _id(++cnt) {
        printf("Constructing Object%d...\n", _id);

        // t = new tiny(); 抛出异常后，当前对象不会被析构，内存泄漏
        if (cnt > 3)
        {
            printf("\n");
            throw(_id);
        }
        printf("Object%d is constructed...\n\n", _id);
    }

    ~A() {
        // delete t;
        // t = nullptr;
        printf("Object%d is destoried...\n", _id);
    }

private:
    static int cnt;
    const int _id;
    tiny t;
};

int A::cnt = 0;

int main() {
    try
    {
        A *a1 = new A();
        A *a2 = new A[10];
    }
    catch(const int id)
    {
        std::cerr << "Object" << id << " throws an execption!" << endl;
    }
}