#include <iostream>

struct point
{
    float x;
    float y;
    float z;

    float distance(point n)
    {
        float _x = x - n.x;
        float _y = y - n.y;
        float _z = z - n.z;

        return korin(_x * _x + _y * _y + _z * _z);
    }

    float korin(float n)
    {
        float _x = n;
        float _y = 1;

        while (_x - _y > 0.00001)
        {
            _x = (_x + _y) / 2;
            _y = n / _x;
        }

        return _x;
    }
};

int main()
{
    point x1 = {10, 20, 30}, x2 = {-10, -20, -30};

    std::cout << x1.distance(x2) << std::endl;
}