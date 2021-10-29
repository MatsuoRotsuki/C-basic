#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	double x;
	double y;
} point_t;

typedef struct circle{
	point_t center;
	double radius;
} circle_t ;

int is_in_circle (point_t p, circle_t c)
{
	double x_dist, y_dist;
	x_dist = p.x - c.center.x;
	y_dist = p.y - c.center.y;
	
	return (x_dist * x_dist + y_dist*y_dist <= c.radius * c.radius); 
}

int main ()
{
	point_t p;
	circle_t c;
	
	printf("Enter point: ");
	scanf("%lf&lf",&p.x,&p.y);
	printf("Enter circle: ");
	scanf("%lf%lf%lf", &c.center.x, &c.center.y, &c.radius);
	if (is_in_circle(p,c) ) 
	    printf("P o trong duongtron.\n");
    else printf("Ngoai duong tron.\n");
}
