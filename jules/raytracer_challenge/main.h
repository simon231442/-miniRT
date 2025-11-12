#include <stdio.h>
#include <unistd.h>

#define EPSILON 0.0001

typedef struct s_tuples
{
	double	x;
	double	y;
	double	z;
	double	w; //0 is a vector / 1 is a point
}	t_tuples;

/*exemple 
  point
  a <- tuple(4.3, -4.2, -3.1, 1.0)
  vector
  a <- tuple(4.3, -4.2, -3.1, 0.0)
