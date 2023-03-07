----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:38:44 04/23/2011 
-- Design Name: 
-- Module Name:    ram - Behavioral 
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
--LIBRARY alters_mf;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
-- use altera_mf library for RAM block

--USE altera_mf.ALL;
-- use package
USE work.procmem_definitions.ALL;

ENTITY ram IS
	GENERIC (	adrwidth : positive := ram_adrwidth;
					datwidth : positive := ram_datwidth;
					ramfile : string := ramfile_std -- initial RAM content
-- in IntelHEX Format
				);
	PORT (	address : IN std_logic_vector(ram_adrwidth-1 DOWNTO 0);
				data : IN std_logic_vector(ram_datwidth-1 DOWNTO 0);
				inclock : IN std_logic; -- used to write data in RAM cells
				wren_p : IN std_logic;
				q : OUT std_logic_vector(ram_datwidth-1 DOWNTO 0)
			);
END ram;

ARCHITECTURE rtl OF ram IS
	TYPE MEM IS ARRAY(0 TO (2**ram_adrwidth)-1) OF std_logic_vector(ram_datwidth-1 DOWNTO 0);
	SIGNAL ram_block : MEM;
	SIGNAL read_address_reg : std_logic_vector(ram_adrwidth-1 DOWNTO 0);
	BEGIN
		PROCESS (inclock)
		BEGIN
			IF rising_edge(inclock) THEN
				IF (wren_p = '1') THEN
					ram_block(to_integer(unsigned(address))) <= data;
				END IF;
-- address is registered at rising edge
-- not used, because asynchronous data output is needed for MIPS design
--read_address_reg <= address;
			END IF;
		END PROCESS;
-- registered address is used for synchronous data output
--q <= ram_block(to_integer(unsigned(read_address_reg)));
-- asynchronous memory output (needed for MIPS design according to [PaHe98])
-- address is unregistered
		q <= ram_block(to_integer(unsigned(address)));
END rtl;