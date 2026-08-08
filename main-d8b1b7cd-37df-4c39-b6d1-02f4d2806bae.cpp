#include <iostream>
#include "TextGraphics.h"
#include "Shapes.h"

int main()
{
    srand(time(0));  //seed RNG with current time
    char input = 0;
    TextGraphics graphics;

    std::vector<Shape*> v;

    unsigned long long frameCount = 0;

    while (input != ESCAPE)  //frame loop
    {
        ///input////////////////////////////////////////////////////////
        input = graphics.readKey();

        if(input == 'R') //restart
        {
            deleteVector(v);
        }

        if (input == 'c')
        {
            v.push_back(new Circle(rand() % 5 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        if (input == 'r')
        {
            v.push_back(new Rect(rand() % 6 + 1, rand() % 6 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        if (input == 't')
        {
            v.push_back(new Triangle(rand() % 6 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        ///update///////////////////////////////////////////////////////

        for(Shape* p : v)
        {
            p->moveCenter(rand() % 3 - 1, 1);
        }

        ///Clear and draw////////////////////////////////////////////////

        graphics.clearScreen();  //Clear the previous frame

        std::string s = "c: circle | r: rectangle | t: triangle | R: reset";
        graphics.putStringAt(0, graphics.width() / 2 - s.size() / 2, s, Color::Yellow);

        for(Shape* p : v)
        {
            p->draw(graphics);
        }

        graphics.draw();  //Display current frame on the screen

        ///sleep////////////////////////////////////////////////////////
        frameCount++;
        graphics.sleepMs(20);  //50 fps
    }

    return 0;
}
