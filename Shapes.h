#pragma once
#include "TextGraphics.h"
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void draw(TextGraphics& tg) const = 0;
    void moveCenter(double dx, double dy);
    Shape(double x, double y);
    virtual ~Shape() {};
protected:
    double xCenter, yCenter;
};

class Circle : public Shape
{
public:
    void draw(TextGraphics& tg) const override;
    Circle(double r, double x, double y);
private:
    double radius;
};

class Rect : public Shape
{
public:
    void draw(TextGraphics& tg) const override;
    Rect(double w, double h, double x, double y);
protected:
    double width, height;
};

class Square : public Rect
{
public:
    Square(double s, double x, double y);
};

void deleteVector(vector<Shape*>& v);

class Triangle : public Shape
{
public:
    Triangle(double s, double x, double y);
    void draw(TextGraphics& tg) const override;
private:
    double size;
};