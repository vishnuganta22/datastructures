#include <iostream>

using namespace std;

struct Vertex
{
    int x,y,z;

    Vertex(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vertex addition(const Vertex& v) const{
        return operator+(v);
    }

    Vertex multiplication(const Vertex& v) const{
        return operator*(v);
    }

    Vertex add(const Vertex& v) const{
        return *this + v;
    }

    Vertex multiply(const Vertex& v) const{
        return *this * v;
    }

    Vertex operator+(const Vertex& v) const{
        return Vertex(this->x + v.x, this->y + v.y, this->z + v.z);
    }

    Vertex operator*(const Vertex& v) const{
        return Vertex(this->x * v.x, this->y * v.y, this->z * v.z);
    }

    bool operator==(const Vertex& v) const{
        return (this->x == v.x && this->y == v.y && this->z == v.z);
    }
};

ostream& operator<<(ostream& stream, const Vertex& v){
    stream << " X :: " << v.x << " Y :: " << v.y << " Z :: " << v.z;
    return stream;
}


int main(){
    Vertex v(1, 2, 3);
    Vertex b(4, 5, 6);

    Vertex result = v.operator*(b);
    Vertex result1 = v + b;
    bool isEqual = v == b;
    cout << " isEqual :: " << isEqual << endl;

    cout << result << endl;
    operator<<(cout, result1);
    cout << endl;

    return 0;
}