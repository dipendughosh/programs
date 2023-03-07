----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    03:00:58 04/23/2011 
-- Design Name: 
-- Module Name:    procmem - Behavioral 
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

ENTITY procmem IS
	PORT (	clk, rst_n : IN std_ulogic
			);
END procmem;

ARCHITECTURE behave OF procmem IS
	COMPONENT mips
		PORT (
					clk, rst_n : IN std_ulogic;
					mem_data : IN std_ulogic_vector(width-1 downto 0);
					reg_B, mem_address : OUT std_ulogic_vector(width-1 downto 0);
					MemRead, MemWrite : OUT std_ulogic
				);
	END COMPONENT;

	COMPONENT memory
	PORT (
				clk : IN STD_ULOGIC;
				rst_n : IN STD_ULOGIC;
				MemRead : IN STD_ULOGIC;
				MemWrite : IN STD_ULOGIC;
				mem_address : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				data_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				data_out : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0)
			);
	END COMPONENT;

	SIGNAL mem_data : std_ulogic_vector(width-1 downto 0);
	signal reg_B : std_ulogic_vector(width-1 downto 0);
	signal mem_address : std_ulogic_vector(width-1 downto 0);
	signal MemRead : std_ulogic;
	signal MemWrite : std_ulogic;
	BEGIN
		inst_mips : mips
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						mem_data => mem_data,
						reg_B => reg_B,
						mem_address => mem_address,
						MemRead => MemRead,
						MemWrite => MemWrite
					);
		inst_memory : memory
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						MemRead => MemRead,
						MemWrite => MemWrite,
						mem_address => mem_address,
						data_in => reg_B,
						data_out => mem_data
					);
END behave;