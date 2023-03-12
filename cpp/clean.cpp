#include <iostream>
#include <array>
using namespace std;
#include <ctime>
typedef float f32;
constexpr f32 Pi32 = 3.141592653589793238462643383279502884f;

class shape_base
{
public:
    shape_base() {}
    virtual f32 Area() = 0;
};

class square : public shape_base
{
public:
    square() {}
    square(f32 SideInit) : Side(SideInit) {}
    virtual f32 Area() { return Side * Side; }

private:
    f32 Side;
};

class rectangle : public shape_base
{
public:
    rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
    virtual f32 Area() { return Width * Height; }

private:
    f32 Width, Height;
};

class triangle : public shape_base
{
public:
    triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
    virtual f32 Area() { return 0.5f * Base * Height; }

private:
    f32 Base, Height;
};

class circle : public shape_base
{
public:
    circle() {}
    circle(f32 RadiusInit) : Radius(RadiusInit) {}
    virtual f32 Area() { return Pi32 * Radius * Radius; }

private:
    f32 Radius;
};

int main()
{


    shape_base *shapes[400000];
    srand (time(NULL));



  bool continueAdding=true;
  int i =0;

    //Using a for loop get core dump when using -03 optimization with g++ 
    while(continueAdding) {
        square mySquare((double)rand());
        rectangle myRectangle((double)rand(), (double)rand());
            circle myCircle((double)rand());
        triangle myTriangle((double)rand(), (double)rand());

            shapes[4 * i] = &mySquare;
            shapes[4 * i + 1] = &myRectangle;
            shapes[4 * i + 2] = &myCircle;
            shapes[4 * i + 3] = &myTriangle;
            i++;
            if (i==100000) continueAdding = false;
    }

    f32 area = 0;

    clock_t begin = clock();

    for (int j = 0; j < 10; j++)
        for (int i = 0; i < 400000; i++)
        {
            area += shapes[i]->Area();
        }

    clock_t end = clock();


    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Processing time in ms =" << elapsed_secs*1000;
    cout << "\n";
    
    return 0;
}
