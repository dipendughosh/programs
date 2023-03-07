----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:53:28 04/23/2011 
-- Design Name: 
-- Module Name:    mips - Behavioral 
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

ENTITY mips IS
	PORT (	clk, rst_n : IN std_ulogic;
				mem_data : IN std_ulogic_vector(width-1 downto 0);
				reg_B, mem_address : OUT std_ulogic_vector(width-1 downto 0);
				MemRead, MemWrite : OUT std_ulogic
			);
END mips;

ARCHITECTURE behave OF mips IS
	COMPONENT control
		PORT (
					clk, rst_n : IN std_ulogic;
					instr_31_26 : IN std_ulogic_vector(5 downto 0);
					instr_15_0 : IN std_ulogic_vector(15 downto 0);
					zero : IN std_ulogic;
					ALUopcode : OUT std_ulogic_vector(2 downto 0);
					RegDst, RegWrite, ALUSrcA, MemRead, MemWrite, MemtoReg, IorD, IRWrite : OUT std_ulogic;
					ALUSrcB, PCSource : OUT std_ulogic_vector(1 downto 0);
					PC_en : OUT std_ulogic
				);
	END COMPONENT;

	COMPONENT data
		PORT (
					clk, rst_n : IN std_ulogic;
					PC_en, IorD, MemtoReg, IRWrite, ALUSrcA, RegWrite, RegDst : IN std_ulogic;
					PCSource, ALUSrcB : IN std_ulogic_vector(1 downto 0);
					ALUopcode : IN std_ulogic_vector(2 downto 0);
					mem_data : IN std_ulogic_vector(width-1 downto 0);
					reg_B, mem_address : OUT std_ulogic_vector(width-1 downto 0);
					instr_31_26 : OUT std_ulogic_vector(5 downto 0);
					instr_15_0 : OUT std_ulogic_vector(15 downto 0);
					zero : OUT std_ulogic
				);
	END COMPONENT;
-- internal signals for connection of components
	SIGNAL instr_31_26_intern : std_ulogic_vector(5 downto 0);
	SIGNAL instr_15_0_intern : std_ulogic_vector(15 downto 0);
	SIGNAL zero_intern : std_ulogic;
	SIGNAL ALUopcode_intern : std_ulogic_vector(2 downto 0);
	SIGNAL RegDst_intern : std_ulogic;
	SIGNAL RegWrite_intern : std_ulogic;
	SIGNAL ALUSrcA_intern : std_ulogic;
	SIGNAL MemtoReg_intern : std_ulogic;
	SIGNAL IorD_intern : std_ulogic;
	SIGNAL IRWrite_intern : std_ulogic;
	SIGNAL ALUSrcB_intern : std_ulogic_vector(1 downto 0);
	SIGNAL PCSource_intern : std_ulogic_vector(1 downto 0);
	SIGNAL PC_en_intern : std_ulogic;
	BEGIN
		inst_control : control
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						instr_31_26 => instr_31_26_intern,
						instr_15_0 => instr_15_0_intern,
						zero => zero_intern,
						ALUopcode => ALUopcode_intern,
						RegDst => RegDst_intern,
						RegWrite => RegWrite_intern,
						ALUSrcA => ALUSrcA_intern,
						MemRead => MemRead,
						MemWrite => MemWrite,
						MemtoReg => MemtoReg_intern,
						IorD => IorD_intern,
						IRWrite => IRWrite_intern,
						ALUSrcB => ALUSrcB_intern,
						PCSource => PCSource_intern,
						PC_en => PC_en_intern
					);
		inst_data: data
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						PC_en => PC_en_intern,
						IorD => IorD_intern,
						MemtoReg => MemtoReg_intern,
						IRWrite => IRWrite_intern,
						ALUSrcA => ALUSrcA_intern,
						RegWrite => RegWrite_intern,
						RegDst => RegDst_intern,
						PCSource => PCSource_intern,
						ALUSrcB => ALUSrcB_intern,
						ALUopcode => ALUopcode_intern,
						mem_data => mem_data,
						reg_B => reg_B,
						mem_address => mem_address,
						instr_31_26 => instr_31_26_intern,
						instr_15_0 => instr_15_0_intern,
						zero => zero_intern
					);
END behave;