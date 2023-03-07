
wave precharg bit	{11111111111111110111011101110111} pw=25ns
wave write bit		{11110000} pw=100ns
wave writebar bit	{00001111} pw=100ns
* 
wave bit1  bit		{2(0000111100001111)} pw = 25ns
wave bitbar  bit		{2(1111000011110000)} pw = 25ns
* 
wave select0  bit	{01100000000000000110000000000000} pw=25ns

plot { bit1 precharg write select0 bitout }

transient 800n powerup



