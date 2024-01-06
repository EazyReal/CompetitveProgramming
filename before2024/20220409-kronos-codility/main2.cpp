#include <bits/stdc++.h>

using namespace std;

class Woof
{
public:
    Woof()
    {
        cout << "Woof";
    }
    Woof(const Woof &)
    {
        cout << "called";
    }
};

class Foo
{
public:
    Foo()
    {
        cout << "Foo";
    }
};

class Bar : public Foo
{
public:
    Bar() : woof(new Woof())
    {
        cout << "Bar";
    }
    Woof *woof;
};

// void f(const vector<int> &x)
// {
//     return;
// }

int *f()
{
    return new int[1000000000000000];
}

Woof getA()
{
    Woof w = Woof();
    return w;
}

int main()
{
    double a = 5;
    // double &b = a;
    // int &c = b;
    // double *b = &a;
    // int *c = b;
    // Bar *bar = new Bar();
    Woof w = getA();
    return 0;
}