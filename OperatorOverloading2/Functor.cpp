#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    Point operator+(const Point &pos) const
    {
        return Point(this->xpos + pos.xpos, this->ypos + pos.ypos);
    }
    friend ostream &operator<<(ostream &os, const Point &ref);
};

ostream &operator<<(ostream &os, const Point &ref)
{
    os << '[' << ref.xpos << ", " << ref.ypos << ']' << endl;
    return os;
}

class Adder
{
public:
    int operator()(const int &n1, const int &n2)
    {
        return n1 + n2;
    }
    double operator()(const double &d1, const double &d2)
    {
        return d1 + d2;
    }
    Point operator()(const Point &pos1, const Point &pos2)
    {
        return pos1 + pos2;
    }
};

int main(void)
{
    Adder adder;

    cout << adder(1, 3) << endl;
    cout << adder(1.5, 3.7) << endl;
    cout << adder(Point(3, 4), Point(7, 9));

    return 0;
}
