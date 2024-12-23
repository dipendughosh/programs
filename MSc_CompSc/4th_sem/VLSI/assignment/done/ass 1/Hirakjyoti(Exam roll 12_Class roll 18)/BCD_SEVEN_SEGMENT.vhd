----------------------------------------------------------------------------------
-- Company: 		M.Sc Computer and Information Science
-- Engineer: 		Hirakjyoti Banerjee
-- 
-- Create Date:    	00:47:30 04/15/2011 
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	alu4bitvhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	D :- 4-bit Input Port
--					O :- 7-bit Output Port to give the output for the given input
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY BCD_SEVEN_SEGMENT IS
	PORT (	D:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			O:OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END BCD_SEVEN_SEGMENT;

ARCHITECTURE RTL OF BCD_SEVEN_SEGMENT IS

BEGIN
	PROCESS (D)
		BEGIN
			CASE D IS
				WHEN "0000"=>O<="1111110";
				WHEN "0001"=>O<="0110000";
				WHEN "0010"=>O<="1101101";
				WHEN "0011"=>O<="1111001";
				WHEN "0100"=>O<="0110011";
				WHEN "0101"=>O<="1011011";
				WHEN "0110"=>O<="1011111";
				WHEN "0111"=>O<="1110000";
				WHEN "1000"=>O<="1111111";
				WHEN "1001"=>O<="1111011";
				WHEN OTHERS=>O<="XXXXXXX";
			END CASE;
	END PROCESS;
END RTL;