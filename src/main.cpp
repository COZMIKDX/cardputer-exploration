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
   
   /*
    Put your setup function calls here.
    The current general structure I chose is for called called in this file to have a setup function placed here
    and some sort of run function that is to be placed in the loop function.
    I'm open to running functions that do more than set things up here in setup() but I don't want them infinitely looping here.
   */
}

void loop(void)
{
    /*
    Put your run function calls here.
    If you would put it in this loop() function in a normal arduino project, put it here.
    Just don't put infinite or long while loops in them.
    I would like this to be able to call several functions If I need to. For example, one app function could be simply placing 
    a clock at the top of the screen and another would be my tone generator app. The result would be my tone generator app but 
    with a clock at the top.
    I suppose this could be a sort of app builder or more like feature compositor. 
    I don't want to get too far into using it like that without thinking it over and making a written plan first.
    */
}