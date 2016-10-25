#pragma once

class Rectangle2D
{
	double x, y, width, height;
public:
	double getX();
	double getY();
	double getHeight();
	double getWidth();
	void setX(double);
	void setY(double);
	void setWidth(double);
	void setHeight(double);
	Rectangle2D();
	Rectangle2D(double, double, double, double);
	const double getArea();
	const double getPerimeter();
	const bool contains(double, double);
	const bool contains(const Rectangle2D& r);
	const bool overlaps(const Rectangle2D& r);
};