----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:19:39 04/23/2011 
-- Design Name: 
-- Module Name:    data_execution - Behavioral 
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

ENTITY data_execution IS
	PORT 	(	instr_25_21 : IN std_ulogic_vector(4 downto 0);
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
END data_execution;

ARCHITECTURE behave OF data_execution IS
	COMPONENT alu
		PORT (
					a, b : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					opcode : IN STD_ULOGIC_VECTOR(2 DOWNTO 0);
					result : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
					zero : OUT STD_ULOGIC
				);
	END COMPONENT;
	
	SIGNAL mux_A_out : std_ulogic_vector(width-1 downto 0);
	SIGNAL mux_B_out : std_ulogic_vector(width-1 downto 0);
	BEGIN
		alu_inst: alu
		PORT MAP (
						a => mux_A_out,
						b => mux_B_out,
						opcode => ALUopcode,
						result => alu_result,
						zero => zero
					);
-- Multiplexor for ALU input A:
		mux_A : PROCESS (ALUSrcA, PC_out, reg_A)
		BEGIN
			CASE ALUSrcA IS
				WHEN '0' => mux_A_out <= PC_out;
				WHEN '1' => mux_A_out <= reg_A;
				WHEN OTHERS => mux_A_out <= (OTHERS => 'X');
			END CASE;
		END PROCESS;
-- Multiplexor for AlU input B:
		mux_B : PROCESS (ALUSrcB, reg_B, instr_15_0_se, instr_15_0_se_sl)
		BEGIN
			CASE ALUSrcB IS
				WHEN "00" => mux_B_out <= reg_B;
				WHEN "01" => mux_B_out <= STD_ULOGIC_VECTOR(TO_UNSIGNED(4, width)); --constant 4
				WHEN "10" => mux_B_out <= instr_15_0_se;
				WHEN "11" => mux_B_out <= instr_15_0_se_sl;
				WHEN OTHERS => mux_B_out <= (OTHERS => 'X');
			END CASE;
		END PROCESS;
-- Computation of Jump Address:
		jump_addr <= PC_out(width-1 downto width-4) & instr_25_21 & instr_20_16 & instr_15_0 & "00";
END behave;