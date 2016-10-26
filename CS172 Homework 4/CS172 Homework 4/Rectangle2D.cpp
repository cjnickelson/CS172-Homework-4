# include"Rectangle2D.h"
#include<iostream>

using namespace std;

// all get functions return their respective values and all set functions set their respective values to those in the parameters
double Rectangle2D::getX()
{
	return x;
}

double Rectangle2D::getY()
{
	return y;
}

double Rectangle2D::getWidth()
{
	return width;
}

double Rectangle2D::getHeight()
{
	return height;
}

void Rectangle2D::setX(double coordinate)
{
	x = coordinate;
}

void Rectangle2D::setY(double coordinate)
{
	y = coordinate;
}

void Rectangle2D::setWidth(double length)
{
	width = length;
}

void Rectangle2D::setHeight(double length)
{
	height = length;
}

// constructor sets default rectangle to be centered at the origin with height and width 1
Rectangle2D::Rectangle2D()
{
	x = 0; y = 0; width = 1; height = 1;
}

// constructor with four arguments sets the x coordinate, y coordinate, width and height to specified values
Rectangle2D::Rectangle2D(double xc, double yc, double w, double h)
{
	x = xc; y = yc; width = w; height = h;
}
// calculates and returns the area of a given rectangle using a=w*h
const double Rectangle2D::getArea()
{
	return height * width;
}
// calculates and returns the perimeter of a rectangle
const double Rectangle2D::getPerimeter()
{
	return 2 * width + 2 * height;
}
// checks to see if a point is contained within a rectangle
const bool Rectangle2D::contains(double xc, double yc)
{
	// the point is contained if its x value is between the leftmost point of the rectangle and the rightmost, and same goes for the y coordinate and the verticle limits
	if ((x - width / 2) <= xc && xc <= (x + width / 2) && (y - height / 2) <= yc && yc <= (y + height / 2))
		return true;
	else
		return false;
}
// determines whether a given rectangle is contained by another
const bool Rectangle2D::contains(Rectangle2D& r)
{
	// create a pointer to the parameter rectangle
	Rectangle2D* p = &r;
	// find the maximum rightward, leftward, upper and lower values of this rectangle
	double leftmax = p->getX() - (p->getWidth() / 2);
	double rightmax = p->getX() + (p->getWidth() / 2);
	double lowest = p->getY() - (p->getHeight() / 2);
	double highest = p->getY() + (p->getHeight() / 2);
	// determine the same bounds for the other rectangle
	double leftbound = x - width / 2;
	double rightbound = x + width / 2;
	double lowerbound = y - height / 2;
	double upperbound = y + height / 2;
	// parameter rectangle is contained if its bounds are between those of the outer rectangle
	if (leftbound <= leftmax && rightmax <= rightbound && lowerbound <= lowest && highest <= upperbound)
		return true;
	else
		return false;
}
// determines if a given rectangle intersects (overlaps) with another
const bool Rectangle2D::overlaps(Rectangle2D& r)
{
	// create a pointer to the parameter rectangle
	Rectangle2D* p = &r;
	// find the outward bounds, as above
	double leftmax = p->getX() - (p->getWidth() / 2);
	double rightmax = p->getX() + (p->getWidth() / 2);
	double lowest = p->getY() - (p->getHeight() / 2);
	double highest = p->getY() + (p->getHeight() / 2);
	// find the other rectangles bounds, as above
	double leftbound = x - width / 2;
	double rightbound = x + width / 2;
	double lowerbound = y - height / 2;
	double upperbound = y + height / 2;
	// the rectangles do NOT intersect if 
	// 1) the minimum y bound of one rectangle is greater than the maximum y bound of the other
	// 2) the minumum x bound of one rectangle is greater than the maximum x bound of the other
	if (leftmax > rightbound || rightmax < leftbound || highest<lowerbound || lowest>upperbound)
		return false;
	else
		return true;

}