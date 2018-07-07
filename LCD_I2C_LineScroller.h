#ifndef LCD_I2C_LineTools_Scroller
#define LCD_I2C_LineTools_Scroller

class LineScroller
{
  public:
    LineScroller();
    void setLine(byte* line, unsigned int length);
    void setLine(String line);
    String next();
    void clear();
  private:
    String _strLine;
    int _pos;
    unsigned _totalLength;
    int _direction;
    
};

#endif

