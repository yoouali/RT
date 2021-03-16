#include "../../includes/image.h"

t_col       int_to_rgb_yatak(int val)
{
    t_col       col;

    col.r = (val >> 16) & 255;
    col.g = (val >> 8) & 255;
    col.b = val & 255;
    return (col);
}

int         rgb_to_int_yatak(t_col col)
{
    return ((int)(col.r) << 16 | (int)(col.g) << 8 | (int)(col.b));
}

t_col       alpha_compositing(t_col c1, t_col c2, double a1, double a2)
{
    t_col   col;
    double  alpha;

    alpha = a2 + a1 * (1.0 - a2);
    col.r = (c2.r * a2 + c1.r * a1 * (1 - a2)) / alpha;
    col.g = (c2.g * a2 + c1.g * a1 * (1 - a2)) / alpha;
    col.b = (c2.b * a2 + c1.b * a1 * (1 - a2)) / alpha;
    return (col);
}