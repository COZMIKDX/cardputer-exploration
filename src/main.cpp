/**
 * @file main.cpp
 * @author COZMIKDX
 * @brief M5Cardputer Tone generator app
 * @version 0.1
 * @date 2024-2-02
 *
 *
 * @Hardwares: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 * 
 * Description: Plays a tone at a user adjustable frequency.
 *  As I am still getting started, I'm borrowing a lot of ideas from the M5Unified and M5Cardputer examples.
 */

#include <Arduino.h>
#include <M5Cardputer.h>

void setup(void)
{
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);
   
}

void loop(void)
{

}