#include "Shapes.h"

Shape::Shape(double x, double y) :xCenter(x), yCenter(y) {}

void Shape::moveCenter(double dx, double dy)
{
    xCenter += dx;
    yCenter += dy;
}

void Circle::draw(TextGraphics& tg) const
{
    for (int i = 0; i < tg.height(); i++)
    {
        for (int j = 0; j < tg.width(); j++)
        {
            if (((j - xCenter) * (j - xCenter)) / (1.0 * radius * radius) + ((i - yCenter) * (i - yCenter)) / (1.0 * radius * radius) <= 1.0)
            {
                tg.putCharAt(i, j, '*', Color::Cyan);
            }
        }
    }
}

Circle::Circle(double r, double x, double y) :Shape(x, y), radius(r) {}

void Rect::draw(TextGraphics& tg) const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int row = yCenter + i;
            int col = xCenter + j;

            // stay inside screen bounds
            if (row >= 0 && row < tg.height() && col >= 0 && col < tg.width())
            {
                tg.putCharAt(row, col, '$', Color::Red);
            }
        }
    }
}

Rect::Rect(double w, double h, double x, double y) :Shape(x, y), width(w), height(h) {}

Square::Square(double s, double x, double y) :Rect(s, s, x, y) {}


void deleteVector(vector<Shape*>& v)
{
    for (auto p : v)
    {
        delete p;
    }
    v.clear();
}

Triangle::Triangle(double s, double x, double y)
    : Shape(x, y), size(s) {
}

void Triangle::draw(TextGraphics& tg) const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int row = yCenter + i;
            int col = xCenter + j;

            if (row >= 0 && row < tg.height() && col >= 0 && col < tg.width())
            {
                tg.putCharAt(row, col, '*', Color::Green);
            }
        }
    }
}