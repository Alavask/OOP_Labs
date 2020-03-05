#include <iostream>

using namespace std;

class Expr
{
public:
    virtual int eval() = 0;
};

class Num : public Expr
{
private:
    int number;
public:
    Num(int n) : number(n) {};

    int eval() override { return number; };
};

class Add : public Expr
{
private:
    Expr* l;
    Expr* r;
public:
    Add(Expr* left, Expr* right) : l(left), r(right) {};

    int eval() override { return l->eval() + r->eval(); };
};

class Subtract : public Expr
{
private:
    Expr* l;
    Expr* r;
public:
    Subtract(Expr* left, Expr* right) : l(left), r(right) {};

    int eval() override { return l->eval() - r->eval(); };
};


int main2() {
    
    auto tree = new Add(new Add(new Num(4), new Num(5)), new Subtract(new Num(9), new Num(1))); //=(4+5)+(9-1)
    cout << tree->eval() << endl;
    delete tree;
    return 0;
}
