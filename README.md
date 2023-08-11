# RadioScan
This app is designed  on cross platform framework Python Kivy to display radiation activity on the screen  
interacting with arduino board and built in Geiger conter.
The project consists from 2 parts: software and hardware.
Software part is written on Python kivy and includes usage such libraries as pyserial, pandas, kivy-garden, matplotlib
and additional software for element's design.
Hardware is combination of Arduino Modules. The system is builded thus, the main board is esp8266 which can get wi fi 
connection and access to cloud server database, pass data to there and colect it the tables. Additional modules are
- dht11 temperature sensor
- bluetooth HC-05
- Arduino Geiger counter kit with J305 tube
Software reads data via serial comunication through bluetooth or usb-connemction and displays retrieved information on the screen. There are available 3 windows:
- real time measurement
- real time activity in plot mode
- reaching data from databese and build plot with information within desirable scopes



![Без имени](https://github.com/techmadman/RadioScan/assets/130900888/fdebc2a3-95cb-487e-a8b3-9edc7f53eafa)
![screen1](https://github.com/techmadman/RadioScan/assets/130900888/90e84dd2-be47-470e-8bc5-65019d8214a1)
![screen2](https://github.com/techmadman/RadioScan/assets/130900888/42cbea03-68c0-45c8-9eb9-9d9091a21167)
![screen3](https://github.com/techmadman/RadioScan/assets/130900888/eb431987-3545-45a8-adde-d5e86271e191)
