# avr-cpp-LCD // LCD1602 driver for V4 Prototype Board - ATMega32 LCD driver

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/830ab9c0c1c34111aaa730ce0307c6ad)](https://app.codacy.com/manual/ViktorMaximilian-H/avr-cpp-LCD?utm_source=github.com&utm_medium=referral&utm_content=ViktorMaximilian-H/avr-cpp-LCD&utm_campaign=Badge_Grade_Dashboard)

/*
LCD1602 standard pin connections:

1       VSS     /ground                 @ GND

2		    VDD		  /Power				          @	5V

3		    V0		  /contrast			          @	10kOhm

4		    RS		  /register select	      @	PD2

5		    R/W		  /read/write			        @	PD7

6		    E		    /enable				          @	PD5

7-10	  D0-D3	  /low data			          @	PB0-3

11-14	  D4-D7	  /high data			        @	PB4-7

15		  A		    /back light anode	      @	5v

16		  K		    /back light cathode	    @	GND

*/
