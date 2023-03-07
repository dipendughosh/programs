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
-- Description: 	Clock :- At positive clock Pulse the counter changes its state
--					Input :- 4-bit Input Port
--					Output :- 7-bit Output Port to give the output for the given input
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

entity sevensegmentvhd is
		PORT (	Clock : IN  STD_LOGIC;
				Input : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
				Output : OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
end sevensegmentvhd;

architecture Behavioral of sevensegmentvhd is

begin
	PROCESS (Clock,Input)
		BEGIN
			IF (Clock'event and Clock='1') then
				CASE Input IS
					WHEN "0000"=>Output<="1111110";
					WHEN "0001"=>Output<="0110000";
					WHEN "0010"=>Output<="1101101";
					WHEN "0011"=>Output<="1111001";
					WHEN "0100"=>Output<="0110011";
					WHEN "0101"=>Output<="1011011";
					WHEN "0110"=>Output<="1011111";
					WHEN "0111"=>Output<="1110000";
					WHEN "1000"=>Output<="1111111";
					WHEN "1001"=>Output<="1111011";
					WHEN OTHERS=>Output<="XXXXXXX";
				END CASE;
			END IF;
	END PROCESS;

end Behavioral;

