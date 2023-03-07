--	Package File Template
--
--	Purpose: This package defines supplemental types, subtypes, 
--		 constants, and functions 


library IEEE;
use IEEE.STD_LOGIC_1164.all;

PACKAGE ProcMem_definitions IS
-- globals
	CONSTANT width : NATURAL := 32;
-- definitions for regfile
	CONSTANT regfile_depth : positive := 32; -- register file depth = 2**adrsize
	CONSTANT regfile_adrsize : positive := 5; -- address vector size = log2(depth)
-- definitions for memory
	CONSTANT ram_adrwidth : positive := 8; -- m x n - RAM Block
	CONSTANT ram_datwidth : positive := 8;
-- initial RAM content in IntelHEX Format
	CONSTANT ramfile_std : string := "./simulation/ram_256x8.hex";
	CONSTANT ramfile_block0 : string := "./simulation/ram0_256x8.hex";
	CONSTANT ramfile_block1 : string := "./simulation/ram1_256x8.hex";
	CONSTANT ramfile_block2 : string := "./simulation/ram2_256x8.hex";
	CONSTANT ramfile_block3 : string := "./simulation/ram3_256x8.hex";
END ProcMem_definitions;