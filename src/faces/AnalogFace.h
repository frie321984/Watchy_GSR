
#ifndef ANALOG_FACE_H
#define ANALOG_FACE_H

  #include "./Face.h"

  class AnalogFace: public Face {

    public:
      String name() override;
      void draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display) override;
    
    private:
      void drawHand(int centerX, int centerY, uint16_t angle, int length, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display);
  };
#endif // ANALOG_FACE_H