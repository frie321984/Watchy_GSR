#include "Watchy_GSR.h"
#include "antique.h"
// Place all of your data and variables here.

RTC_DATA_ATTR uint8_t MyStyle;  // Remember RTC_DATA_ATTR for your variables so they don't get wiped on deep sleep.


class AnalogWatchface : public WatchyGSR {
/*
 * Keep your functions inside the class, but at the bottom to avoid confusion.
 * Be sure to visit https://github.com/GuruSR/Watchy_GSR/blob/main/Override%20Information.md for full information on how to override
 * including functions that are available to your override to enhance functionality.
*/
  public:
    AnalogWatchface() : WatchyGSR() {}

    void InsertAddWatchStyles(){
      MyStyle = AddWatchStyle("Analog");
    };

    void InsertInitWatchStyle(uint8_t StyleID){
      if (StyleID == MyStyle){
          Design.Menu.Top = 72;
          Design.Menu.Header = 25;
          Design.Menu.Data = 66;
          Design.Menu.Gutter = 3;
          Design.Menu.Font = &aAntiCorona12pt7b;
          Design.Menu.FontSmall = &aAntiCorona11pt7b;
          Design.Menu.FontSmaller = &aAntiCorona10pt7b;
          Design.Face.Bitmap = nullptr;
          Design.Face.SleepBitmap = nullptr;
          Design.Face.Gutter = 4;
          Design.Face.Time = 56;
          Design.Face.TimeHeight = 45;
          Design.Face.TimeColor = GxEPD_BLACK;
          Design.Face.TimeFont = &aAntiCorona36pt7b;
          Design.Face.TimeLeft = 0;
          Design.Face.TimeStyle = WatchyGSR::dCENTER;
          Design.Face.Day = 101;
          Design.Face.DayGutter = 4;
          Design.Face.DayColor = GxEPD_BLACK;
          Design.Face.DayFont = &aAntiCorona16pt7b;
          Design.Face.DayFontSmall = &aAntiCorona15pt7b;
          Design.Face.DayFontSmaller = &aAntiCorona14pt7b;
          Design.Face.DayLeft = 0;
          Design.Face.DayStyle = WatchyGSR::dCENTER;
          Design.Face.Date = 143;
          Design.Face.DateGutter = 4;
          Design.Face.DateColor = GxEPD_BLACK;
          Design.Face.DateFont = &aAntiCorona15pt7b;
          Design.Face.DateFontSmall = &aAntiCorona14pt7b;
          Design.Face.DateFontSmaller = &aAntiCorona13pt7b;
          Design.Face.DateLeft = 0;
          Design.Face.DateStyle = WatchyGSR::dCENTER;
          Design.Face.Year = 186;
          Design.Face.YearLeft = 99;
          Design.Face.YearColor = GxEPD_BLACK;
          Design.Face.YearFont = &aAntiCorona16pt7b;
          Design.Face.YearLeft = 0;
          Design.Face.YearStyle = WatchyGSR::dCENTER;
          Design.Status.WIFIx = 5;
          Design.Status.WIFIy = 193;
          Design.Status.BATTx = 155;
          Design.Status.BATTy = 178;
      }
    };

    void InsertDrawWatchStyle(uint8_t StyleID){
      int16_t X, Y;
      X = display.width()/2;
      Y = display.height()/2;

      if (StyleID == MyStyle){
        if (SafeToDraw()){
            display.drawBitmap(0, 0, analog, 200, 200, GxEPD_BLACK, GxEPD_WHITE);

            uint16_t minutenprozent = (WatchTime.Local.Minute/60)*100;
            uint16_t hourAngle = ((360 * (WatchTime.Local.Hour%12)) / 12) + (WatchTime.Local.Minute * 0.5);
            uint16_t minuteAngle = ((360 * WatchTime.Local.Minute) / 60);
            
            drawHand(X, Y, hourAngle, 36);
            drawHand(X+1, Y, hourAngle, 36);
            drawHand(X, Y+1, hourAngle, 36);

            drawHand(X, Y, minuteAngle, 66);
        }
      }
    };

    void drawMyText(int16_t x, int16_t y, String dData){
      uint16_t w, Width, Height, Ind;
        int16_t X, Y;
        
        display.getTextBounds(dData, x, y, &X, &Y, &Width, &Height);
        
        display.setFont(Design.Face.DayFontSmall);
        setFontColor(Design.Face.TimeColor);
        display.setTextSize(2);
        display.setCursor(x-(Width/2),y-(Height/2));
        display.print(dData);
    }

    void drawHand(int centerX, int centerY, uint16_t angle, int length)
    {
        float adjustedAngle = 90 - angle;
        float rad = adjustedAngle * (PI / 180);
        int x = centerX + cos(rad) * length;
        int y = centerY - sin(rad) * length;
        display.drawLine(centerX, centerY, x, y, ForeColor());
    }

};