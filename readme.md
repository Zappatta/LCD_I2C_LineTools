# I2C LCD Line Tools

## About
This library is intended to be used with I2C LCD Panels. It can be used to scroll text in a single line on the screen. The motivation behind it was an 20 x 4 I bought which behaves weirdly, overflowing text to the wrong lines. This library will allow to set text for each line, and have overflowing text scroll in that line.


## Installing
Just copy this library to your Arduino IDE libraries file

## Usage

### LineScroller
The only tool we have right now is the line scroller. Since it is intended to be used with MQTT, it expects to get the string as byte*, and expects to get the length in the second argument:
``` c
#include <LCD_I2C_LineScroller.h>

LineScroller line0;
LineScroller line1;

void setup() {
	line0.setLine("Welcome to the world of tomorrow!")
}

void mqtt_callback(topic, payload, length) {
	//also accepts byte* and length, in case you are updating from MQTT callback
	line1.setLine(payload, length);
}

void loop() {
    lcd.clear();
    lcd.setCursor ( 0, 0 ); 
    lcd.print(line0.next());
    lcd.setCursor ( 0, 1 ); 
    lcd.print(line1.next());
}
```

## License

The MIT License (MIT)

Copyright (c) 2017

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.