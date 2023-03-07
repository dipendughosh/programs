





wave precharg bit	{11111111111111110111011101110111} pw=25ns
wave write bit		{11110000} pw=100ns
wave writebar bit	{00001111} pw=100ns
* 
wave d  bit		{2(0000111100001111)} pw = 25ns
wave d1  bit		{2(0000000011111111)} pw = 25ns
wave dbar  bit		{2(1111000011110000)} pw = 25ns
wave dbar1  bit		{2(1111111100000000)} pw = 25ns
* 
wave select1  bit	{01100000000000000110000000000000} pw=25ns
wave select2  bit	{00000110000000000000011000000000} pw=25ns
wave select3  bit	{00000000011000000000000001100000} pw=25ns
wave select4  bit	{00000000000001100000000000000110} pw=25ns

plot { d d1 precharg write select1 select2 dout dout1 }

transient 800n 



