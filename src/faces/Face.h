
#ifndef FACE_H
#define FACE_H

  #include <WString.h>
  #include <GxEPD2_BW.h>

  class Face {

    public:
      /**
       * @return the name of your Watchface. will be displayed in the menu
       */
      virtual String name(){return "Unknown"; };
      
      /**
       * @param hour current Hour
       * @param minute current Minute
       * @param display You get a pointer the static display. So dont mess it up ;)
       */
      virtual void draw(uint8_t hour, uint8_t minute, GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>& display){};
  };
#endif // FACE_H