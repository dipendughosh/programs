----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:23:26 05/15/2010 
-- Design Name: 
-- Module Name:    MUX8x1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MUX8x1 is
    Port ( I0 : in  STD_LOGIC;
           I1 : in  STD_LOGIC;
           I2 : in  STD_LOGIC;
           I3 : in  STD_LOGIC;
           I4 : in  STD_LOGIC;
           I5 : in  STD_LOGIC;
           I6 : in  STD_LOGIC;
           I7 : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           S2 : in  STD_LOGIC;
           OP : out  STD_LOGIC);
end MUX8x1;

architecture Behavioral of MUX8x1 is

begin
OP <= I0 WHEN S0='0' AND S1='0' AND S2='0' ELSE
      I1 WHEN S0='1' AND S1='0' AND S2='0' ELSE
		I2 WHEN S0='0' AND S1='1' AND S2='0' ELSE
		I3 WHEN S0='1' AND S1='1' AND S2='0' ELSE
		I4 WHEN S0='0' AND S1='0' AND S2='1' ELSE
		I5 WHEN S0='1' AND S1='0' AND S2='1' ELSE
		I6 WHEN S0='0' AND S1='1' AND S2='1' ELSE
		I7;
end Behavioral;

