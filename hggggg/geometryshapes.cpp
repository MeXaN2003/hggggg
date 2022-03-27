#include "geometryshapes.h"
#include <math.h>
#include <stdio.h>
#define kPi 3.14159

double CircleArea(double input_array[])
{
    double input_radius = input_array[2], area;
    area = kPi * input_radius * input_radius;
    return area;
}

double CirclePerimeter(double input_array[]) {
    double input_radius = input_array[2], perimeter;
    perimeter = 2 * input_radius * kPi;
    return perimeter;
}

double TrianglePerimeter(double triangle_points[]) {
    double perimeter = 0, side_a = 0, side_b = 0, side_c = 0;
    side_a
        = sqrt(powf(triangle_points[0] - triangle_points[2], 2)
            + powf(triangle_points[1] - triangle_points[3], 2));
    side_b
        = sqrt(powf(triangle_points[0] - triangle_points[4], 2)
            + powf(triangle_points[1] - triangle_points[5], 2));
    side_c
        = sqrt(powf(triangle_points[2] - triangle_points[4], 2)
            + powf(triangle_points[3] - triangle_points[5], 2));
    perimeter = side_a + side_b + side_c;
    return perimeter;
}

double TriangleArea(double triangle_points[])
{
    double area = 0, side_a = 0, side_b = 0, side_c = 0;
    side_a
        = sqrt(powf(triangle_points[0] - triangle_points[2], 2)
            + powf(triangle_points[1] - triangle_points[3], 2));
    side_b
        = sqrt(powf(triangle_points[0] - triangle_points[4], 2)
            + powf(triangle_points[1] - triangle_points[5], 2));
    side_c
        = sqrt(powf(triangle_points[2] - triangle_points[4], 2)
            + powf(triangle_points[3] - triangle_points[5], 2));;
    double semi_per = (side_a + side_b + side_c) / 2;
    area
        = sqrt(semi_per * (semi_per - side_a) * (semi_per - side_b)
            * (semi_per - side_c));
    return area;
}