----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:47:42 04/23/2011 
-- Design Name: 
-- Module Name:    control - Behavioral 
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

ENTITY control IS
	PORT 	(	clk, rst_n : IN std_ulogic;
				instr_31_26 : IN std_ulogic_vector(5 downto 0);
				instr_15_0 : IN std_ulogic_vector(15 downto 0);
				zero : IN std_ulogic;
				ALUopcode : OUT std_ulogic_vector(2 downto 0);
				RegDst, RegWrite, ALUSrcA, MemRead, MemWrite, MemtoReg, IorD, IRWrite : OUT std_ulogic;
				ALUSrcB, PCSource : OUT std_ulogic_vector(1 downto 0);
				PC_en : OUT std_ulogic
			);
END control;

ARCHITECTURE behave OF control IS

COMPONENT ControlFSM
	PORT (
				clk, rst_n : IN std_ulogic;
				instr_31_26 : IN std_ulogic_vector(5 downto 0);
				RegDst, RegWrite, ALUSrcA, MemRead, MemWrite, MemtoReg, IorD, IRWrite, PCWrite, PCWriteCond : OUT std_ulogic;
				ALUOp, ALUSrcB, PCSource : OUT std_ulogic_vector(1 downto 0)
			);
END COMPONENT;

COMPONENT ALUControl
	PORT (
				instr_15_0 : IN std_ulogic_vector(15 downto 0);
				ALUOp : IN std_ulogic_vector(1 downto 0);
				ALUopcode : OUT std_ulogic_vector(2 downto 0)
			);
END COMPONENT;

SIGNAL ALUOp_intern : std_ulogic_vector(1 downto 0);
SIGNAL PCWrite_intern : std_ulogic;
SIGNAL PCWriteCond_intern : std_ulogic;

BEGIN
	inst_ControlFSM : ControlFSM
	PORT MAP (
					clk => clk,
					rst_n => rst_n,
					instr_31_26 => instr_31_26,
					RegDst => RegDst,
					RegWrite => RegWrite,
					ALUSrcA => ALUSrcA,
					MemRead => MemRead,
					MemWrite => MemWrite,
					MemtoReg => MemtoReg,
					IorD => IorD,
					IRWrite => IRWrite,
					PCWrite => PCWrite_intern,
					PCWriteCond => PCWriteCond_intern,
					ALUOp => ALUOp_intern,
					ALUSrcB => ALUSrcB,
					PCSource => PCSource
				);
	inst_ALUControl : ALUControl
	PORT MAP (
					instr_15_0 => instr_15_0,
					ALUOp => ALUOp_intern,
					ALUopcode => ALUopcode
				);
	PC_en <= PCWrite_intern OR (PCWriteCond_intern AND zero);
END behave;