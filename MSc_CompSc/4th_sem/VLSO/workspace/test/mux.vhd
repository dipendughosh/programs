----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:19:18 04/22/2010 
-- Design Name: 
-- Module Name:    mux - Behavioral 
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

entity mux is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           d : in  STD_LOGIC;
           s0 : in  STD_LOGIC;
           s1 : in  STD_LOGIC;
           x : out  STD_LOGIC);
end mux;

architecture Behavioral of mux is

begin
--PROCESS(a,b,c,d,s0,s1)
--begin   	
--   if (s0 = '0') and (s1 = '0') then
--      x <= a;
--   elsif (s0 = '0') and (s1 = '1') then
--      x <= b;
--   elsif (s0 = '1') and (s1 = '0') then
--      x <= c;
--		elsif (s0 = '1') and (s1 = '1') then 
--		 x <= d;
--   end if;
--end process;
x <= a when s0 = '0' and s1 = '0' else
     b when s0 = '0' and s1 = '1' else
     c when s0 = '1' and s1 = '0' else
     d; 	  


end Behavioral;



