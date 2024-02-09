#ifndef tone_generator.hpp
#define tone_generator.hpp
#include <M5Cardputer.h>

void tone_generator_setup(m5::M5_CARDPUTER M5Cardputer);
void run_tone_generator(m5::M5_CARDPUTER M5Cardputer);
void volume_check();
void frequency_up();
void frequency_down();
void master_volume_up();
void master_volume_down();
void drawStaticUI();

#endif