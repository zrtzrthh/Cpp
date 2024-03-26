/*------------------------------------------------------------------------------
 * @file    LEARNOPERATORS.CPP
 * @author  ZhouRongTao
 * @date    2023/12/12 15:56:57
------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class speed
{
public:
    float x, y;

public:
    speed(float x, float y)
        : x(x), y(y){};
    speed Add(const speed &other) const
    {
        return speed(x + other.x, x + other.y);
    }

    speed operator+(const speed &other) const
    {
        return Add(other);
    }

    bool operator==(const speed &other) const
    {
        return x == other.x && y == other.y;
    }
};

ostream &operator<<(ostream &stream, const speed &other)
{
    stream << other.x << "," << other.y << endl;
    return stream;
}

int main()
{
    speed a(100, 20);
    speed b(70, 20);
    speed c1 = b.Add(a);
    speed c2 = a + b;
    cout << c1;
    bool d = c == b;
    cout << d;
}
