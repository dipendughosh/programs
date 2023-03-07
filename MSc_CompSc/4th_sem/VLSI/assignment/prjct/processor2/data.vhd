----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:28:12 04/23/2011 
-- Design Name: 
-- Module Name:    data - Behavioral 
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

ENTITY data IS
	PORT 	(	clk, rst_n : IN std_ulogic;
				PC_en, IorD, MemtoReg, IRWrite, ALUSrcA, RegWrite, RegDst : IN std_ulogic;
				PCSource, ALUSrcB : IN std_ulogic_vector(1 downto 0);
				ALUopcode : IN std_ulogic_vector(2 downto 0);
				mem_data : IN std_ulogic_vector(width-1 downto 0);
				reg_B, mem_address : OUT std_ulogic_vector(width-1 downto 0);
				instr_31_26 : OUT std_ulogic_vector(5 downto 0);
				instr_15_0 : OUT std_ulogic_vector(15 downto 0);
				zero : OUT std_ulogic
			);
END data;

ARCHITECTURE behave OF data IS
	COMPONENT data_fetch
		PORT (
					clk : IN STD_ULOGIC;
					rst_n : IN STD_ULOGIC;
					pc_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					alu_out : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					mem_data : IN std_ulogic_vector(width-1 DOWNTO 0);
					PC_en : IN STD_ULOGIC;
					IorD : IN STD_ULOGIC;
					IRWrite : IN STD_ULOGIC;
					reg_memdata : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					instr_31_26 : OUT STD_ULOGIC_VECTOR(5 DOWNTO 0);
					instr_25_21 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_20_16 : OUT STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_15_0 : OUT STD_ULOGIC_VECTOR(15 DOWNTO 0);
					mem_address : OUT std_ulogic_vector(width-1 DOWNTO 0);
					pc_out : OUT std_ulogic_vector(width-1 DOWNTO 0)
				);
	END COMPONENT;

	COMPONENT data_decode
		PORT (
					clk : IN STD_ULOGIC;
					rst_n : IN STD_ULOGIC;
					instr_25_21 : IN STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_20_16 : IN STD_ULOGIC_VECTOR(4 DOWNTO 0);
					instr_15_0 : IN STD_ULOGIC_VECTOR(15 DOWNTO 0);
					reg_memdata : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					alu_out : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					RegDst : IN STD_ULOGIC;
					RegWrite : IN STD_ULOGIC;
					MemtoReg : IN STD_ULOGIC;
					reg_A : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					reg_B : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					instr_15_0_se : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					instr_15_0_se_sl : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0)
				);
	END COMPONENT;

	COMPONENT data_execution
		PORT (
					instr_25_21 : IN std_ulogic_vector(4 downto 0);
					instr_20_16 : IN std_ulogic_vector(4 downto 0);
					instr_15_0 : IN std_ulogic_vector(15 downto 0);
					ALUSrcA : IN std_ulogic;
					ALUSrcB : IN std_ulogic_vector(1 downto 0);
					ALUopcode : IN std_ulogic_vector(2 downto 0);
					reg_A, reg_B : IN std_ulogic_vector(width-1 downto 0);
					pc_out : IN std_ulogic_vector(width-1 downto 0);
					instr_15_0_se : IN std_ulogic_vector(width-1 downto 0);
					instr_15_0_se_sl : IN std_ulogic_vector(width-1 downto 0);
					jump_addr : OUT std_ulogic_vector(width-1 downto 0);
					alu_result : OUT std_ulogic_vector(width-1 downto 0);
					zero : OUT std_ulogic
				);
	END COMPONENT;

	COMPONENT data_memwriteback
		PORT (
					clk, rst_n : IN std_ulogic;
					jump_addr : IN std_ulogic_vector(width-1 downto 0);
					alu_result : IN std_ulogic_vector(width-1 downto 0);
					PCSource : IN std_ulogic_vector(1 downto 0);
					pc_in : OUT std_ulogic_vector(width-1 downto 0);
					alu_out : OUT std_ulogic_vector(width-1 downto 0)
				);
	END COMPONENT;

	SIGNAL pc_in_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL alu_out_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL reg_memdata_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL instr_25_21_intern : std_ulogic_vector(4 downto 0);
	SIGNAL instr_20_16_intern : std_ulogic_vector(4 downto 0);
	SIGNAL instr_15_0_intern : std_ulogic_vector(15 downto 0);
	SIGNAL pc_out_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL reg_A_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL reg_B_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL instr_15_0_se_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL instr_15_0_se_sl_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL jump_addr_intern : std_ulogic_vector(width-1 downto 0);
	SIGNAL alu_result_intern : std_ulogic_vector(width-1 downto 0);
	BEGIN
		inst_data_fetch: data_fetch
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						pc_in => pc_in_intern,
						alu_out => alu_out_intern,
						mem_data => mem_data,
						PC_en => PC_en,
						IorD => IorD,
						IRWrite => IRWrite,
						reg_memdata => reg_memdata_intern,
						instr_31_26 => instr_31_26,
						instr_25_21 => instr_25_21_intern,
						instr_20_16 => instr_20_16_intern,
						instr_15_0 => instr_15_0_intern,
						mem_address => mem_address,
						pc_out => pc_out_intern
					);
		inst_data_decode : data_decode
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						instr_25_21 => instr_25_21_intern,
						instr_20_16 => instr_20_16_intern,
						instr_15_0 => instr_15_0_intern,
						reg_memdata => reg_memdata_intern,
						alu_out => alu_out_intern,
						RegDst => RegDst,
						RegWrite => RegWrite,
						MemtoReg => MemtoReg,
						reg_A => reg_A_intern,
						reg_B => reg_B_intern,
						instr_15_0_se => instr_15_0_se_intern,
						instr_15_0_se_sl => instr_15_0_se_sl_intern
					);
		inst_data_execution: data_execution
		PORT MAP (
						instr_25_21 => instr_25_21_intern,
						instr_20_16 => instr_20_16_intern,
						instr_15_0 => instr_15_0_intern,
						ALUSrcA => ALUSrcA,
						ALUSrcB => ALUSrcB,
						ALUopcode => ALUopcode,
						reg_A => reg_A_intern,
						reg_B => reg_B_intern,
						pc_out => pc_out_intern,
						instr_15_0_se => instr_15_0_se_intern,
						instr_15_0_se_sl => instr_15_0_se_sl_intern,
						jump_addr => jump_addr_intern,
						alu_result => alu_result_intern,
						zero => zero
					);
		inst_data_memwriteback : data_memwriteback
		PORT MAP (
						clk => clk,
						rst_n => rst_n,
						jump_addr => jump_addr_intern,
						alu_result => alu_result_intern,
						PCSource => PCSource,
						pc_in => pc_in_intern,
						alu_out => alu_out_intern
					);
		reg_B <= reg_B_intern;
		instr_15_0 <= instr_15_0_intern;
END behave;