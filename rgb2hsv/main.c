#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double max(double a, double b)
{
    if (a > b ) return a;
    return b;
}

double min(double a, double b)
{
    if (a < b ) return a;
    return b;
}

void rgb_to_hsv(double r, double g, double b)
{
    r = r / 255.0;
    g = g / 255.0;
    b = b / 255.0;

    double cmax = max(r, max(g, b));
    double cmin = min(r, min(g, b));
    double delta = cmax - cmin;
    double h = -1, s = -1;


    if (cmax == cmin)
        h = 0;

    else if (cmax == r)
        h = fmod(60 * ((g - b) / delta) + 360, 360);

    else if (cmax == g)
        h = fmod(60 * ((b - r) / delta) + 120, 360);

    else if (cmax == b)
        h = fmod(60 * ((r - g) / delta) + 240, 360);

    if (cmax == 0)
        s = 0;
    else
        s = (delta / cmax) * 100;

    double v = cmax * 100;

    printf("HUE: %f, SAT: %f, VAL: %f\n", h, s, v);

}

int main(int argc, char **argv)
{

    if(argc != 4)
    {
        printf("Usage: rgb2hsv <red>[0-255] <green>[0-255] <blue>[0-255]\n");
        return -1;
    }

    rgb_to_hsv((double) atoi(argv[1]),(double) atoi(argv[2]),(double) atoi(argv[3]));
}

