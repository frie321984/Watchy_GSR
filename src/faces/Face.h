
#ifndef FACE_H
#define FACE_H

  #include <WString.h>
  #include <GxEPD2_BW.h>

  class Face {

    public:
      virtual String name(){};
      virtual void draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display){};
  };
#endif // FACE_H