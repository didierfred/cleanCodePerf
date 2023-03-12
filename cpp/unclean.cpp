#include <iostream>
#include <array>
using namespace std;
#include <ctime>

#include <cstdint>
typedef float f32;
typedef uint32_t u32;
constexpr f32 Pi32 = 3.141592653589793238462643383279502884f;

enum shape_type : u32
{
    Shape_Square,
    Shape_Rectangle,
    Shape_Triangle,
    Shape_Circle,
    
    Shape_Count,
};

struct shape_union
{
    shape_type Type;
    f32 Width;
    f32 Height;
};

double GetAreaSwitch(shape_union Shape)
{
    double Result = 0.0f;
    
    switch(Shape.Type)
    {
        case Shape_Square: {Result = Shape.Width*Shape.Width;} break;
        case Shape_Rectangle: {Result = Shape.Width*Shape.Height;} break;
        case Shape_Triangle: {Result = 0.5f*Shape.Width*Shape.Height;} break;
        case Shape_Circle: {Result = Pi32*Shape.Width*Shape.Width;} break;
        
        case Shape_Count: {} break;
    }
    
    return Result;
}

int main()
{
    srand (time(NULL));
    shape_union *shapes[400000];


    for (int i = 0; i < 100000; i++)
    {
        shape_union square;
        square.Width = ((float)rand());
        square.Type = Shape_Square;
        shapes[4 * i] = &square;

        shape_union rectangle;
        rectangle.Width = ((float)rand());
        rectangle.Height = ((float)rand());
        rectangle.Type = Shape_Rectangle;
        shapes[4 * i+1] = &rectangle;

        shape_union triangle;
        triangle.Width = ((float)rand());
        triangle.Height = ((float)rand());
        triangle.Type = Shape_Triangle;
        shapes[4 * i+2] = &triangle;

        shape_union circle;
        square.Width = ((float)rand());
        square.Type = Shape_Circle;
        shapes[4 * i+3] = &circle;
    }

    f32 area = 0;

    clock_t begin = clock();

    for (int j = 0; j < 10; j++)
        for (int i = 0; i < 400000; i++)
        {
            area += GetAreaSwitch(*shapes[i]);
        }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Processing time in ms =" << elapsed_secs*1000;
    cout << "\n";
    return 0;
}
