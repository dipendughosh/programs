----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:42:30 04/23/2011 
-- Design Name: 
-- Module Name:    ALUControl - Behavioral 
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

ENTITY ALUControl IS
	PORT 	(	instr_15_0 : IN std_ulogic_vector(15 downto 0);
				ALUOp : IN std_ulogic_vector(1 downto 0);
				ALUopcode : OUT std_ulogic_vector(2 downto 0)
			);
END ALUControl;

ARCHITECTURE behave OF ALUControl IS
BEGIN
	Alu_Control : PROCESS(instr_15_0, ALUOp)
		CONSTANT cADD : std_ulogic_vector(5 downto 0) := "100000";
		CONSTANT cSUB : std_ulogic_vector(5 downto 0) := "100010";
		CONSTANT cAND : std_ulogic_vector(5 downto 0) := "100100";
		CONSTANT cOR : std_ulogic_vector(5 downto 0) := "100101";
		CONSTANT cSLT : std_ulogic_vector(5 downto 0) := "101010";
		BEGIN
		case ALUOp is
			when "00" => ALUopcode <= "010"; -- add
			when "01" => ALUopcode <= "110"; -- subtract
			when "10" => -- operation depends on function field
			case instr_15_0(5 downto 0) is
				when cADD => ALUopcode <= "010"; -- add
				when cSUB => ALUopcode <= "110"; -- subtract
				when cAND => ALUopcode <= "000"; -- AND
				when cOR => ALUopcode <= "001"; -- OR
				when cSLT => ALUopcode <= "111"; -- slt
				when others => ALUopcode <= "000";
			end case;
			when others => ALUopcode <= "000";
		end case;
	END PROCESS;
END behave;