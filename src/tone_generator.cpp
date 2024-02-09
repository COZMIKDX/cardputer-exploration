
#include "tone_generator.hpp"
#include <M5Cardputer.h>

void volume_check();
void frequency_up();
void frequency_down();
void master_volume_up();
void master_volume_down();
void drawStaticUI();

uint8_t master_volume = 128;
struct menu_item
{
    const char *title;
    void (*func)();
};

const menu_item menus[]{
    {"frequency up", frequency_up},
    {"frequency down", frequency_down},
    {"volume up", master_volume_up},
    {"volume down", master_volume_down},
};

void tone_generator_setup(m5::M5_CARDPUTER M5Cardputer) {
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextDatum(top_left); // where the anchor point is.
    M5Cardputer.Display.setTextColor(WHITE);
    M5Cardputer.Display.setFont(&fonts::FreeSansBoldOblique12pt7b);
    M5Cardputer.Speaker.setVolume(master_volume);

    /// Since the microphone and speaker cannot be used at the same time,
    // turn
    /// off the speaker here.
    M5Cardputer.Speaker.begin();
    drawStaticUI();
    M5Cardputer.Display.endWrite();
}

void run_tone_generator(m5::M5_CARDPUTER M5Cardputer)
{
    M5Cardputer.update();
    // M5Cardputer.Display.drawString("Tone Generator", 100, 3);
    // M5Cardputer.Speaker.tone(freq);
    do
    {
        delay(1);
        M5Cardputer.update();

        if (M5Cardputer.Keyboard.isChange())
        {
            if (M5Cardputer.Keyboard.isPressed())
            {
                Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

                // Todo: Figure out how I should check presses.
                for (auto i : status.word)
                {
                    if (i == ';')
                    {
                        frequency_up();
                    }

                    if (i == '.')
                    {
                        frequency_down();
                    }

                    if (i == '_')
                    {
                        master_volume_down();
                    }

                    if (i == '=')
                    {
                        master_volume_up();
                    }
                }
            }
        }

    } while (M5Cardputer.Speaker.isPlaying());
}

void master_volume_up()
{
    int volume = M5Cardputer.Speaker.getVolume() + 1;
    if (volume < 256)
    {
        M5.Speaker.setVolume(volume);
    }
}

void master_volume_down()
{
    int volume = M5Cardputer.Speaker.getVolume() - 1;
    if (volume >= 0)
    {
        M5.Speaker.setVolume(volume);
    }
}

// todo: See if these libraries give me a way to see if a button is being held.
void frequency_up()
{
    freq = freq + 10;
    // M5Cardputer.Speaker.stop();
    M5Cardputer.Speaker.tone(freq, UINT32_MAX, 1);
}

void frequency_down()
{
    freq = freq - 10;
    // M5Cardputer.Speaker.stop();
    M5Cardputer.Speaker.tone(freq, UINT32_MAX, 1);
}

void drawStaticUI()
{
    M5Cardputer.Display.setTextSize(1.0);
    M5Cardputer.Display.drawString("Tone Generator", 0, 3);

    M5Cardputer.Display.setTextSize(0.5);
    M5Cardputer.Display.setFont(&fonts::FreeSans9pt7b);
    M5Cardputer.Display.drawString("Volume: ", 0, 32);
    M5Cardputer.Display.drawString("Frequency: ", 0, 48);
}