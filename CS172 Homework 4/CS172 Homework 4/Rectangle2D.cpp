# include"Rectangle2D.h"
#include<iostream>

using namespace std;

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

Rectangle2D::Rectangle2D()
{
	x = 0; y = 0; width = 1; height = 1;
}
Rectangle2D::Rectangle2D(double xc, double yc, double w, double h)
{
	x = xc; y = yc; width = w; height = h;
}
const double Rectangle2D::getArea()
{
	return height * width;
}
const double Rectangle2D::getPerimeter()
{
	return 2 * width + 2 * height;
}
const bool Rectangle2D::contains(double xc, double yc)
{
	if ((x - width / 2) <= xc && xc <= (x + width / 2) && (y - height / 2) <= yc && yc <= (y + height / 2))
		return true;
	else
		return false;
}
const bool Rectangle2D::contains(const Rectangle2D& r)
{
	
}
const bool Rectangle2D::overlaps(const Rectangle2D& r)
{
	return false;
}