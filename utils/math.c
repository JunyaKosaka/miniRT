#include "../includes/miniRT.h"

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

double	abs_double(double x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

double	max_abs_3(double x, double y, double z)
{
	double	ret;

	ret = abs_double(x);
	if (ret < abs_double(y))
		ret = abs_double(y);
	if (ret < abs_double(z))
		ret = abs_double(z);
	return (ret);
}

double dot_product(t_vector v1, t_vector v2) {
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
