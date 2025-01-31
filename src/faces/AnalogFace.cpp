#include "./AnalogFace.h"
   
String AnalogFace::name(){
    return "Analog";
};

void AnalogFace::draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display){
    display.drawLine(0,0,200,200,0xff);
};
