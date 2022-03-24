#include "geometryshapes.h"
#include <math.h>
#include <stdio.h>
#define kPi 3.14159

void Circle(float input_array[])
{
    float input_radius = input_array[2], perimeter = 0, area = 0;
    perimeter = 2 * input_radius * kPi;
    area = kPi * input_radius * input_radius;
    printf("Perimeter : %f\n", perimeter);
    printf("Area: %f\n", area);
}

void Triangle(float triangle_points[])
{
    float perimeter = 0, side_a = 0, side_b = 0, side_c = 0, area = 0,
        semi_per = 0;
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
    semi_per = perimeter / 2;
    area
        = sqrt(semi_per * (semi_per - side_a) * (semi_per - side_b)
            * (semi_per - side_c));
    printf("Perimeter: %f\n", perimeter);
    printf("Area: %f\n", area);
}

