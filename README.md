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


![screen1](https://github.com/techmadman/RadioScan/assets/130900888/1a1e7a76-d27c-4c03-b4a2-1254b4069570)
![screen2](https://github.com/techmadman/RadioScan/assets/130900888/0e515a62-c832-4b85-9699-ef3520943f5c)
![screen3](https://github.com/techmadman/RadioScan/assets/130900888/132f74d7-2c17-43b9-930b-40b1d9f245ad)

![Без имени](https://github.com/techmadman/RadioScan/assets/130900888/af68cbba-bb8d-4935-aced-256a89b74bac)
