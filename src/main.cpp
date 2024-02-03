/**
 * @file mic.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Cardputer Microphone Record Test
 * @version 0.1
 * @date 2023-10-09
 *
 *
 * @Hardwares: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include <Arduino.h>
#include <M5Cardputer.h>

void volume_check();

uint8_t master_volume = 128;

void setup(void)
{
    auto cfg = M5.config();

    M5Cardputer.begin(cfg);

    M5Cardputer.Display.startWrite();
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextDatum(top_center);
    M5Cardputer.Display.setTextColor(WHITE);
    M5Cardputer.Display.setFont(&fonts::FreeSansBoldOblique12pt7b);
    M5Cardputer.Speaker.setVolume(master_volume);

    /// Since the microphone and speaker cannot be used at the same time,
    // turn
    /// off the speaker here.
    M5Cardputer.Speaker.begin();
    M5Cardputer.Display.drawString("Tone Generator", 100, 3);
    M5Cardputer.Display.drawString("Volume: ", 100, 3);
}

float freq = 50;
void loop(void)
{
    M5Cardputer.update();
    // M5Cardputer.Display.drawString("Tone Generator", 100, 3);
    //M5Cardputer.Speaker.tone(freq);
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
                    if (i == ';') { 
                        freq = freq + 10;
                        // M5Cardputer.Speaker.stop();
                        M5Cardputer.Speaker.tone(freq, 1000, 1);
                    }

                    if (i == '.') {
                        freq = freq - 10;
                        // M5Cardputer.Speaker.stop();
                        M5Cardputer.Speaker.tone(freq, 1000, 1);
                    }

                    if (i == '_') {
                        master_volume -= 5;
                        volume_check();
                        M5Cardputer.Speaker.setVolume(master_volume);
                    }

                    if (i == '=')
                    {
                        master_volume += 5;
                        volume_check();
                        M5Cardputer.Speaker.setVolume(master_volume);
                    }
                }
            }
        }

    } while (M5Cardputer.Speaker.isPlaying());
}

void master_volume_up() {
    int volume = M5Cardputer.Speaker.getVolume() + 1;
    if (volume < 256)
    {
        M5.Speaker.setVolume(volume);
    }
}

void m_volume_down(bool)
{
    int volume = M5Cardputer.Speaker.getVolume() - 1;
    if (volume >= 0)
    {
        M5.Speaker.setVolume(volume);
    }
}