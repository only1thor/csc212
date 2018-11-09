#include <iostream>
using namespace std;

class Point3D{
    private:
        int x,y,z;
    public:
    // default constructors
    Point3D();
    Point3D(int a, int b, int c);
    //default Destructor
    ~Point3D();

    // Methods
    void translate(int);
    void print();
};

Point3D::Point3D(){// default constructor
    x=0;
    y=0;
    z=0;
}
Point3D::Point3D(int a, int b, int c){// 
    x=a;
    y=b;
    z=c;
}
Point3D::~Point3D(){}

void Point3D::translate(int a){
    x+=a;
    y+=a;
    z+=a;
}

void Point3D::print(){
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
}

int main(int argc, char* argv[]){
    Point3D* myPoint = new Point3D;
    myPoint->print();
    cout << "Translate(2):" << endl;
    myPoint->translate(2);
    myPoint->print();
    delete myPoint;
    return 0; 
}