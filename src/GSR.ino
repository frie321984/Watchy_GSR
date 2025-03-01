#include "Watchy_GSR.h"
#include "../Watchface Addons/WeatherIcons.h"
#include "../Watchface Addons/Collections/Watchy Classics/WatchyClassicsAddOn.h"
#include "faces/AnalogFace.h"
#include "faces/BinaryFace.h"

RTC_DATA_ATTR uint8_t styleA, styleB;  // Remember RTC_DATA_ATTR for your variables so they don't get wiped on deep sleep.


class MyWatchy : public WatchyGSR {
  AnalogFace a;
  BinaryFace b;

  public:
    MyWatchy() : WatchyGSR() {}

    void InsertAddWatchStyles(){
      styleA = AddWatchStyle(a.name());
      styleB = AddWatchStyle(b.name());
    };

    void InsertDrawWatchStyle(uint8_t StyleID){
      if (!SafeToDraw()){ return; }
      
      if (StyleID == styleA) {
        a.draw(WatchTime.Local.Hour, WatchTime.Local.Minute, WatchyGSR::display);
      } else if (StyleID == styleB) {
        b.draw(WatchTime.Local.Hour, WatchTime.Local.Minute, WatchyGSR::display);
      }

    };
};

MyWatchy watchy;

void setup(){
  watchy.init();
  
}

void loop(){}
