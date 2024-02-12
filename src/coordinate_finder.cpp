#include "coordinate_finder.hpp"
#include <M5Cardputer.h>

void coordinate_finder_setup(m5::M5_CARDPUTER M5Cardputer);
void run_coordinate_finder(m5::M5_CARDPUTER M5Cardputer);
void draw_pointer(m5::M5_CARDPUTER M5Cardputer);

    struct coordinate
{
    uint x;
    uint y;
};

coordinate point;

void coordinate_finder_setup(m5::M5_CARDPUTER M5Cardputer) {
    M5Cardputer.Display.setRotation(1);
    point.x = M5Cardputer.Display.width() / 2;
    point.y = M5Cardputer.Display.height() / 2;
    M5Cardputer.Display.drawPixel(point.x, point.y);
    M5Cardputer.Display.drawCircle(point.x, point.y, 10);
}

void run_coordinate_finder(m5::M5_CARDPUTER M5Cardputer)
{
    delay(1); // Later I'll see if I do need need this delay and if I do, replace it with a timer check.
    M5Cardputer.update();

    if (M5Cardputer.Keyboard.isChange())
    {
        if (M5Cardputer.Keyboard.isPressed())
        {
            Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

            // Todo: Figure out how I should check presses.
            for (auto i : status.word)
            {
                if (i == 'e')
                {
                    point.y = point.y + 1;
                    M5Cardputer.Speaker.tone(100, 500, 1);
                }

                if (i == 's')
                {
                    point.y = point.y - 1;
                }

                if (i == 'a')
                {
                    point.x = point.x - 1;
                }

                if (i == 'd')
                {
                    point.x = point.x + 1;
                }
            }
            draw_pointer(M5Cardputer);
        }
    }
}

void draw_pointer(m5::M5_CARDPUTER M5Cardputer)
{
    M5Cardputer.Display.drawPixel(point.x, point.y);
    M5Cardputer.Display.drawCircle(point.x, point.y, 10);
}