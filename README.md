# brake-temp
 Brake temperature sensors using thermocouples and Arduino
# thermocouple-types
Type K	Chromel/Alumel	0 ℃ to 1260 ℃	Neutral atmosphere
Type J	Iron/Constanton	0 ℃ to 760 ℃	Vacuum, reducing and oxidizing atmosphere
Type T	Copper/Constanton	– 200 ℃ to 370 ℃	Vacuum condition and reducing atmosphere
Type E	Chromel/Constanton	0 ℃ to 870 ℃	Continuously oxidizing and inert atmosphere 
Type N 	Nicrosil/Nisil	0 ℃ to 1260 ℃	Where there is a need for longer life and stability 
Type S/R	Platinum/Platinum (13% Rhodium)	538 ℃ to 1481℃	High-temperature applications
Type B	Platinum (6% Rhodium)/Platinum (30% Rhodium)	871 ℃ to 1704 ℃	High-temperature applications
# thermocouple-sensitivity
Thermocouple Type	Sensitivity (µV/℃)	Cold Junction sensitivity (µV/℃)
K	41.276	40.73
J	57.953	52.136
N	36.256	27.171
S	9.587	6.181
T	52.18	41.56
E	76.373	44.123
R	10.506	6.158
# MAX31855-pinout to Arduino
Pin Number	Pin Function	Pin Function
1	GND	Ground
2	T-	Thermocouple input
3	T+	Thermocouple input
4	VCC	Power supply voltage
5	SCK	Serial clock input
6	CS#	Active low chip select. Set CS# low to enable the serial interface
7	SO	Serial-Data Output
# MAX31885 IC variants
MAX31855K	where K is the thermocouple type
MAX31885J
MAX31885N
MAX31855T
MAX31855E
MAX31855R
MAX31855S
# MAX31855-pinout
           +---------------------------+
  VCC ---- |1                         8| ---- GND
  DO  ---- |2                         7| ---- NC
  NC  ---- |3       MAX31855          6| ---- NC
  CS  ---- |4                         5| ---- CLK
           +---------------------------+
VCC: Power supply voltage input. Connect to a 3.3VDC supply.
DO: Data Output. This pin provides digital temperature data from the MAX31855 to the microcontroller.
NC (Not Connected): This pin is not connected and can be left unconnected.
CS (Chip Select): Chip Select input. This pin is used to enable communication with the MAX31855. It is typically connected to a digital output pin on the microcontroller.
CLK: Clock input. This pin receives clock pulses from the microcontroller to synchronize data transfer between the microcontroller and the MAX31855.
GND: Ground connection. Connect to the ground of your system.

              +---------------------------+       +---------------+
    +---------| VCC                       |       |               |
    |         |                           |       |    ARDUINO    |
    |         |        MAX31855           |       |               |
   0.1µF      |                           |       |               |
    |         |                           |       |               |
    |         |                           |       |               |
    +---------|          GND              |       |               |
    |         |                        SO |-------| MISO          |
   GND        |                           |       |               |
              |                       SCK |-------| SCK           |
 +3.3VDC -----| T+                        |       |               |
              |                        CS |-------| SS            |
 -3.3VDC -----| T-                        |       |               |
              +---------------------------+       +---------------+
