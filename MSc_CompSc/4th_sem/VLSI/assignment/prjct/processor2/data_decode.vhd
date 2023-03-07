----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:11:32 04/23/2011 
-- Design Name: 
-- Module Name:    data_decode - Behavioral 
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

ENTITY data_decode IS
	PORT 	(
-- inputs
				clk : IN STD_ULOGIC;
				rst_n : IN STD_ULOGIC;
				instr_25_21 : IN STD_ULOGIC_VECTOR(4 DOWNTO 0);
				instr_20_16 : IN STD_ULOGIC_VECTOR(4 DOWNTO 0);
				instr_15_0 : IN STD_ULOGIC_VECTOR(15 DOWNTO 0);
				reg_memdata : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				alu_out : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
-- control signals
				RegDst : IN STD_ULOGIC;
				RegWrite : IN STD_ULOGIC;
				MemtoReg : IN STD_ULOGIC;
-- outputs
				reg_A : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				reg_B : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				instr_15_0_se : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				instr_15_0_se_sl : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0)
			);
END data_decode;

ARCHITECTURE behave OF data_decode IS
	COMPONENT regfile IS
		PORT 	(	clk,rst_n : IN std_ulogic;
					wen : IN std_ulogic; -- write control
					writeport : IN std_ulogic_vector(width-1 DOWNTO 0); -- register input
					adrwport : IN std_ulogic_vector(regfile_adrsize-1 DOWNTO 0);-- address write
					adrport0 : IN std_ulogic_vector(regfile_adrsize-1 DOWNTO 0);-- address port 0
					adrport1 : IN std_ulogic_vector(regfile_adrsize-1 DOWNTO 0);-- address port 1
					readport0 : OUT std_ulogic_vector(width-1 DOWNTO 0); -- output port 0
					readport1 : OUT std_ulogic_vector(width-1 DOWNTO 0) -- output port 1
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
-- internal signals
	SIGNAL write_reg : STD_ULOGIC_VECTOR(regfile_adrsize-1 DOWNTO 0);
	SIGNAL write_data : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
	SIGNAL data_1 : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
	SIGNAL data_2 : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
	BEGIN
		A : tempreg
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						reg_in => data_1,
						reg_out => reg_A 
					);
		B : tempreg
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						reg_in => data_2,
						reg_out => reg_B 
					);
		inst_regfile : regfile
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						wen => RegWrite,
						writeport => write_data,
						adrwport => write_reg,
						adrport0 => instr_25_21,
						adrport1 => instr_20_16,
						readport0 => data_1,
						readport1 => data_2 
					);
-- multiplexer for write register
		write_reg <= instr_20_16 WHEN RegDst = '0' ELSE
		instr_15_0(15 DOWNTO 11) WHEN RegDst = '1' ELSE
		(OTHERS => 'X');
-- multiplexer for write data
		write_data <= alu_out WHEN MemtoReg = '0' ELSE
		reg_memdata WHEN MemtoReg = '1' ELSE
		(OTHERS => 'X');
-- sign extension and shift
		proc_sign_ext : PROCESS(instr_15_0)
-- variables needed for reading result of sign extension
		VARIABLE temp_instr_15_0_se : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
		VARIABLE temp_instr_15_0_se_sl : STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
		BEGIN
-- sign extend instr_15_0 to 32 bits
			temp_instr_15_0_se := STD_ULOGIC_VECTOR(RESIZE(SIGNED(instr_15_0),
			instr_15_0_se'LENGTH));
-- shift left 2
			temp_instr_15_0_se_sl := temp_instr_15_0_se(width-3 DOWNTO 0) & "00";
			instr_15_0_se <= temp_instr_15_0_se;
			instr_15_0_se_sl <= temp_instr_15_0_se_sl;
	END PROCESS;
END behave;