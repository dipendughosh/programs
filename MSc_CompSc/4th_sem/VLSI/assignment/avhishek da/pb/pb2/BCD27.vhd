----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:35:29 05/15/2010 
-- Design Name: 
-- Module Name:    BCD27 - Behavioral 
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

entity BCD27 is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           D : in  STD_LOGIC;
           HU : out  STD_LOGIC;
           VRU : out  STD_LOGIC;
           VRL : out  STD_LOGIC;
           HL : out  STD_LOGIC;
           VLL : out  STD_LOGIC;
           VLU : out  STD_LOGIC;
           HM : out  STD_LOGIC);
end BCD27;

architecture Behavioral of BCD27 is
COMPONENT MUX8x1
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
end COMPONENT;

begin
M1 : MUX8x1 PORT MAP ('1', A, '1', '1', A, '1', '1', '1', D, C, B, HU);
M2 : MUX8x1 PORT MAP ('1', '1', '1', '1', '1', A, A, '1', D, C, B, VRU);
M3 : MUX8x1 PORT MAP ('1', '1', A, '1', '1', '1', '1', '1', D, C, B, VRL);
M4 : MUX8x1 PORT MAP ('1', A, '1', '1', A, '1', '1', A, D, C, B, HL);
M5 : MUX8x1 PORT MAP ('1', '0', '1', A, A, A, '1', A, D, C, B, VLL);
M6 : MUX8x1 PORT MAP ('1', A, A, A, '1', '1', '1', A, D, C, B, VLU);
M7 : MUX8x1 PORT MAP (A, A, '1', '1', '1', '1', '1', A, D, C, B, HM);
end Behavioral;

