----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:55:15 04/23/2011 
-- Design Name: 
-- Module Name:    tempreg - Behavioral 
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
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
-- use package
USE work.procmem_definitions.ALL;

ENTITY tempreg IS
	PORT 	(
				clk : IN STD_ULOGIC;
	 			rst_n : IN STD_ULOGIC;
				reg_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				reg_out : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0) 
			);
END tempreg;

ARCHITECTURE behave OF tempreg IS
BEGIN
	temp_reg: PROCESS(clk, rst_n)
	BEGIN
		IF rst_n = '0' THEN
			reg_out <= (OTHERS => '0');
		ELSIF RISING_EDGE(clk) THEN
-- write register input to output at rising edge
			reg_out <= reg_in;
		END IF;
	END PROCESS;
END behave;