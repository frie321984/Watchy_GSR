#include <WString.h>

class WatchyWrap {

  public:
    virtual int getDisplay(){};
    virtual uint8_t AddWatchFace(String name){};
    virtual bool SafeToDraw(){};
};