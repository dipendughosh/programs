----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:56:40 04/23/2011 
-- Design Name: 
-- Module Name:    data_fetch - Behavioral 
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

ENTITY data_fetch IS
	PORT 	(
-- inputs
				clk : IN STD_ULOGIC;
				rst_n : IN STD_ULOGIC;
				pc_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				alu_out : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				mem_data : IN std_ulogic_vector(width-1 DOWNTO 0);
-- control signals
				PC_en : IN STD_ULOGIC;
				IorD : IN STD_ULOGIC;
				IRWrite : IN STD_ULOGIC;
-- outputs
				reg_memdata : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				instr_31_26 : OUT STD_ULOGIC_VECTOR(5 DOWNTO 0);
				instr_25_21 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
				instr_20_16 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
				instr_15_0 : OUT STD_ULOGIC_VECTOR(15 DOWNTO 0);
				mem_address : OUT std_ulogic_vector(width-1 DOWNTO 0);
				pc_out : OUT std_ulogic_vector(width-1 DOWNTO 0)
			);
END data_fetch;

ARCHITECTURE behave OF data_fetch IS
	COMPONENT instreg IS
		PORT 	(
					clk : IN STD_ULOGIC;
					rst_n : IN STD_ULOGIC;
					memdata : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					IRWrite : IN STD_ULOGIC;
					instr_31_26 : OUT STD_ULOGIC_VECTOR(5 DOWNTO 0);
					instr_25_21 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_20_16 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_15_0 : OUT STD_ULOGIC_VECTOR(15 DOWNTO 0) 
				);
	END COMPONENT;

	COMPONENT tempreg IS
		PORT 	(
					clk : IN STD_ULOGIC;
					rst_n : IN STD_ULOGIC;
					reg_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					reg_out : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0) 
				);
	END COMPONENT;

	COMPONENT pc IS
		PORT 	(
					clk : IN STD_ULOGIC;
					rst_n : IN STD_ULOGIC;
					pc_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					PC_en : IN STD_ULOGIC;
					pc_out : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0) 
				);
	END COMPONENT;
-- signals for components
	SIGNAL pc_out_intern : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
	BEGIN
-- instances of components
		proc_cnt: pc
		PORT MAP 	(
							clk => clk,
							rst_n => rst_n,
							pc_in => pc_in,
							PC_en => PC_en,
							pc_out => pc_out_intern
						);
		instr_reg : instreg
		PORT MAP (
							clk => clk,
							rst_n => rst_n,
							memdata => mem_data,
							IRWrite => IRWrite,
							instr_31_26 => instr_31_26,
							instr_25_21 => instr_25_21,
							instr_20_16 => instr_20_16,
							instr_15_0 => instr_15_0 
					);
		mem_data_reg : tempreg
		PORT MAP (
							clk => clk,
							rst_n => rst_n,
							reg_in => mem_data,
							reg_out => reg_memdata 
					);
-- multiplexer
		addr_mux : PROCESS(IorD, pc_out_intern, alu_out)
		VARIABLE mem_address_temp : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
		BEGIN
				IF IorD = '0' THEN
					mem_address_temp := pc_out_intern;
				ELSIF IorD = '1' THEN
					mem_address_temp := alu_out;
				ELSE
					mem_address_temp := (OTHERS => 'X');
				END IF;
				mem_address <= mem_address_temp;
	END PROCESS;
	pc_out <= pc_out_intern;
END behave;