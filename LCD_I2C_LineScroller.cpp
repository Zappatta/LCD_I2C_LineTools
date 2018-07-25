

#include "Arduino.h"
#include "LCD_I2C_LineScroller.h"
const unsigned int LINE_LENGTH = 20;

LineScroller::LineScroller()
{
  clear();
}

void LineScroller::setLine(byte* line, unsigned int length)
{
  _totalLength+= length;

  char strPayload[length +1];
  strPayload[length] = '\0';
  for(int i=0;i<length;i++){
    strPayload[i] = line[i];
  }
  this->setLine(strPayload);
  
}

void LineScroller::setLine(String line) {
  Serial.println("line");
  Serial.println(line);
  _strLine += line;
}

void LineScroller::clear()
{
  _pos = 0;
  _totalLength = 0;
  _strLine = String("");
}

String LineScroller::next() {
  if(_strLine.length() <= LINE_LENGTH){
    return _strLine;
  }

  if(_pos + LINE_LENGTH >= _totalLength){
    _pos = 0;
  }

  String retVal = _strLine.substring(_pos, LINE_LENGTH + _pos);
  _pos ++;
  return retVal;
}


