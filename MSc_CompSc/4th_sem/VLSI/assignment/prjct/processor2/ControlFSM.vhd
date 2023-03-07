----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:28:24 04/23/2011 
-- Design Name: 
-- Module Name:    ControlFSM - Behavioral 
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

ENTITY ControlFSM IS
	PORT 	(	clk, rst_n : IN std_ulogic;
				instr_31_26 : IN std_ulogic_vector(5 downto 0);
				RegDst, RegWrite, ALUSrcA, MemRead, MemWrite, MemtoReg, IorD, IRWrite, PCWrite, PCWriteCond : OUT std_ulogic;
				ALUOp, ALUSrcB, PCSource : OUT std_ulogic_vector(1 downto 0)
			);
END ControlFSM;

ARCHITECTURE behave OF ControlFSM IS
-------------------------------------------------------------------------------
-- Definition of the state names

TYPE state_type IS (InstDec, MemAddComp, MemAccL, MemReadCompl, MemAccS, Exec, RCompl, BranchCompl, JumpCompl, ErrState, InstFetch);
SIGNAL state, next_state : state_type;
BEGIN
-------------------------------------------------------------------------------
-- State process
	state_reg : PROCESS(clk, rst_n)
	
	BEGIN
		IF rst_n = '0' THEN
			state <= InstFetch;
		ELSIF RISING_EDGE(clk) THEN
			state <= next_state;
		END IF;
	END PROCESS;
-------------------------------------------------------------------------------
-- Logic Process
	logic_process : PROCESS(state, instr_31_26)
-- RegDst RegWrite ALUSrcA MemRead MemWrite MemtoReg IorD IRWrite PCWrite PCWriteCond 10x1bit
-- ALUOp ALUSrcB PCSource 3x2bit
		VARIABLE control_signals : std_ulogic_vector(15 downto 0);
-- Defintion of Constants for the value of the Inst_Funct_Field
		Constant LOADWORD : std_ulogic_vector(5 Downto 0) := "100011";
		Constant STOREWORD : std_ulogic_vector(5 Downto 0) := "101011";
		Constant RTYPE : std_ulogic_vector(5 Downto 0) := "000000";
		Constant BEQ : std_ulogic_vector(5 Downto 0) := "000100";
		Constant JMP : std_ulogic_vector(5 Downto 0) := "000010";
		BEGIN
		CASE state IS
-- Instruction Fetch
			WHEN InstFetch =>
				control_signals := "0001000110000100";
				next_state <= InstDec;
-- Instruction Decode and Register Fetch
			WHEN InstDec =>
				control_signals := "0000000000001100";
				IF instr_31_26 = LOADWORD OR instr_31_26 = STOREWORD THEN
					next_state <= MemAddComp;
				ELSIF instr_31_26 = RTYPE THEN
					next_state <= Exec;
				ELSIF instr_31_26 = BEQ THEN
					next_state <= BranchCompl;
				ELSIF instr_31_26 = JMP THEN
					next_state <= JumpCompl;
				ELSE
					next_state <= ErrState;
				END IF;
-- Memory Address Computation
			WHEN MemAddComp =>
				control_signals := "0010000000001000";
				IF instr_31_26 = LOADWORD THEN
					next_state <= MemAccL;
				ELSIF instr_31_26 = STOREWORD THEN
					next_state <= MemAccS;
				ELSE
					next_state <= ErrState;
				END IF;
-- Memory Access Load Word
			WHEN MemAccL =>
				control_signals := "0011001000001000";
				next_state <= MemReadCompl;
-- Memory Read Completion
			WHEN MemReadCompl =>
				control_signals := "0110010000001000";
				next_state <= InstFetch;
-- Memory Access Store Word
			WHEN MemAccS =>
				control_signals := "0010101000001000";
				next_state <= InstFetch;
-- Execution
			WHEN Exec =>
				control_signals := "0010000000100000";
				next_state <= RCompl;
-- R-type Completion
			WHEN RCompl =>
				control_signals := "1110000000100000";
				next_state <= InstFetch;
-- Branch Completion
			WHEN BranchCompl =>
				control_signals := "0010000001010001";
				next_state <= InstFetch;
-- Jump Completion
			WHEN JumpCompl =>
				control_signals := "0000000010001110";
				next_state <= InstFetch;
			WHEN OTHERS =>
				control_signals := (others => 'X');
				next_state <= ErrState;
		END case;
		RegDst <= control_signals(15);
		RegWrite <= control_signals(14);
		ALUSrcA <= control_signals(13);
		MemRead <= control_signals(12);
		MemWrite <= control_signals(11);
		MemtoReg <= control_signals(10);
		IorD <= control_signals(9);
		IRWrite <= control_signals(8);
		PCWrite <= control_signals(7);
		PCWriteCond <= control_signals(6);
		ALUOp <= control_signals(5 downto 4);
		ALUSrcB <= control_signals(3 downto 2);
		PCSource <= control_signals(1 downto 0);
	END process;
END behave;