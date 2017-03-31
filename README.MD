[Version française / French version](https://github.com/pigetArduino/utest/blob/master/README.fr.MD)

UTest : Make USB Devices with Arduino
-------------------
![UTestpython app](https://github.com/pigetArduino/utest/raw/master/doc/utestapp.png)   
Demo : https://www.youtube.com/watch?v=jTq_U3kP7iU

Utest is a base to make **python** application to control arduinos on Windows.   
This application turn on/off the internal led on an arduino nano (clone)   
A **python module** manages the arduino    
The application can be saved as an executable to be easily share.   

# Usage
* Install drivers for arduino nano (clone ch340g)  : http://nano.madnerd.org
* Download arduino/python code : http://utest.madnerd.org
* Upload sketch **utest.ino**
* Download application : http://utestapp.madnerd.org   

How to install drivers : https://www.youtube.com/watch?v=m3CsftsfiQU

# Features
* Easy to understand and modify code 
* Serial port autodetection
* Auto reconnection even if the serial port change
* You don't need to manage detection and serial communication.
* Control multiples arduinos

# Issues
The application might not work on Windows 7 due to missing .dll   
This shouldn't happen if your computer is up to date
* Why?: http://stackoverflow.com/questions/34218333/pyinstaller-onefile-does-not-start-on-some-windows-7-machines
* Update needed: https://support.microsoft.com/en-gb/kb/2999226

# Create your own application
This application use *tkinter* (which is included in python) to manage the gui    
Documentation : http://www.tkdocs.com/tutorial/index.html

## Prerequisites
* Download python 3 : https://www.python.org/downloads/
* During the installation, tick **Add Python 3.5 to PATH**   
![Python Path](https://github.com/pigetArduino/utest/raw/master/doc/python_install_path.jpg)

* Open a command prompt (Windows Key + cmd) and install pyserial
```
pip install pyserial
```

## Start the application
* Open a command prompt (Windows key + cmd)
* Go to the source code (apps/utest/)
* Type:
```
python utest.py
```

## Compile
You can compile the application to share it as an .exe file    
However, You need to install **pyinstaller**

```
pip install pyinstaller
```
Then you can compile it using the script **compile.bat** or 
```
pyinstaller --onefile --noconsole utest.py 
```
If you wan't to display debug messages
```
pyinstaller --onefile utest.py 
```

# How to use the library : USB.py
In order to manage the arduino the easiest way possible, everything is handle by the module usb.py    
Check the source code (in apps/utest and /utest) for more information

## Windows
The module only has two commands

Manage arduino serial communication
```
from lib import USB
device_name = "CH340" #Device name in Windows
device_type = "UTest" #Device type (in the arduino sketch)
device_return_string = "OK" #Answer when a response is correct
device_baudrate = 115200 #Baudrate
usb = USB.Device(device_name,device_type,device_return_string,device_baudrate)
```

Send a string to the arduino
```
usb.write("ON")
```

## Arduino
Define device type
```
const String usb_name = "UTest";
```

Usage
```
void loop() {
  serialManager(); //This function manages serial

  //If string received
     if (readString.length() > 0) {
      serialCheck(); //Check arduino type

      //Insert actions list here
      if (readString == "ON"){
        digitalWrite(13,1);
      }
      if (readString == "OFF"){
        digitalWrite(13,0);
      }
      
    }

  //Clear serial buffer
  readString = "";
}
```

# Licences
Software by Rémi Sarrailh (madnerd.org)
Licence: MIT
