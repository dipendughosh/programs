----------------------------------------------------------------------------------
-- Company: 		M.Sc Computer and Information Science
-- Engineer: 		Dipendu Ghosh
-- 
-- Create Date:    	00:47:30 04/15/2011 
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	alu4bitvhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	Input :- 4-bit Input Port
--					Clock :- At positive clock Pulse the counter changes its state
--					Load :- To load the Input Initially,Works when Load = 1
--					Reset :- To reset the counter when Reset = 1
--					UpDown :- Count UP when UpDown = 0
--							  Count DOWN when UpDown = q
--					Output :- 4-bit output ofthe counter
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

entity counter4bitvhd is
		port(	 	Input: in std_logic_vector(0 to 3);
					Clock: in std_logic;
					Load: in std_logic;
					Reset: in std_logic;
					UpDown: in std_logic;
					Output: out std_logic_vector(0 to 3) );
end counter4bitvhd;

architecture Behavioral of counter4bitvhd is
	signal temp: std_logic_vector(0 to 3);
begin
	process(Clock,Reset)
   begin
      if Reset='1' then
         temp <= "0000";
      elsif ( Clock'event and Clock='1') then
         if Load='1' then
            temp <= Input;
         elsif (Load='0' and UpDown='0') then
            temp <= temp + 1;
         elsif (Load='0' and UpDown='1') then
            temp <= temp - 1;
         end if;
      end if;
   end process;
   Output <= temp;
end Behavioral;

