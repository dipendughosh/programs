----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:44:49 04/23/2011 
-- Design Name: 
-- Module Name:    memory - Behavioral 
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

ENTITY memory IS
	PORT (
				clk : IN STD_ULOGIC;
				rst_n : IN STD_ULOGIC;
				MemRead : IN STD_ULOGIC;
				MemWrite : IN STD_ULOGIC;
				mem_address : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				data_in : IN STD_ULOGIC_VECTOR(width-1 DOWNTO 0);
				data_out : OUT STD_ULOGIC_VECTOR(width-1 DOWNTO 0) 
			);
END memory;

ARCHITECTURE behave OF memory IS
	COMPONENT ram IS
		GENERIC (	adrwidth : positive := 8;
						datwidth : positive := 8;
-- initial RAM content in IntelHEX Format
						ramfile : string := "../simulation/ram256x8.hex"
					);
		PORT (
					address : IN std_logic_vector(adrwidth-1 DOWNTO 0
				);
		data : IN std_logic_vector(datwidth-1 DOWNTO 0);
		inclock : IN std_logic; -- used to write data in RAM cells
		wren_p : IN std_logic;
		q : OUT std_logic_vector(datwidth-1 DOWNTO 0));
	END COMPONENT;
-- internal signals
	SIGNAL wren_p : STD_LOGIC;
	SIGNAL data_in_0 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_in_1 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_in_2 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_in_3 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_out_0 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_out_1 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_out_2 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL data_out_3 : STD_LOGIC_VECTOR(ram_datwidth-1 DOWNTO 0);
	SIGNAL address_0 : STD_LOGIC_VECTOR(ram_adrwidth-1 DOWNTO 0);
	SIGNAL address_1 : STD_LOGIC_VECTOR(ram_adrwidth-1 DOWNTO 0);
	SIGNAL address_2 : STD_LOGIC_VECTOR(ram_adrwidth-1 DOWNTO 0);
	SIGNAL address_3 : STD_LOGIC_VECTOR(ram_adrwidth-1 DOWNTO 0);
	BEGIN
-- instances of 4 ram blocks
		mem_block0 : ram
-- generic map used for definition of different ramfiles
		GENERIC MAP (
							adrwidth => ram_adrwidth,
							datwidth => ram_datwidth,
							ramfile => ramfile_block0)
							PORT MAP (
											address => address_0,
											data => data_in_0,
											inclock => clk,
											wren_p => wren_p,
											q => data_out_0
										);
		mem_block1 : ram
-- generic map used for definition of different ramfiles
							GENERIC MAP (
												adrwidth => ram_adrwidth,
												datwidth => ram_datwidth,
												ramfile => ramfile_block1)
												PORT MAP (
																address => address_1,
																data => data_in_1,
																inclock => clk,
																wren_p => wren_p,
																q => data_out_1 
															);
		mem_block2 : ram
-- generic map used for definition of different ramfiles
							GENERIC MAP (
												adrwidth => ram_adrwidth,
												datwidth => ram_datwidth,
												ramfile => ramfile_block2)
												PORT MAP (
																address => address_2,
																data => data_in_2,
																inclock => clk,
																wren_p => wren_p,
																q => data_out_2 
															);
		mem_block3 : ram
-- generic map used for definition of different ramfiles
							GENERIC MAP (
												adrwidth => ram_adrwidth,
												datwidth => ram_datwidth,
												ramfile => ramfile_block3)
												PORT MAP (
																address => address_3,
																data => data_in_3,
																inclock => clk,
																wren_p => wren_p,
																q => data_out_3 
															);
-- create a write_enable for instances
		wren_p <= '1' WHEN MemWrite = '1' AND MemRead = '0' ELSE
		'0' WHEN MemWrite = '0' AND MemRead = '1' ELSE
		'0' WHEN MemWrite = '0' AND MemRead = '0' ELSE
		'X';
-- assert address to ram blocks (pure logic)
		addr_assert: PROCESS(mem_address)
			VARIABLE temp_ram_address : STD_ULOGIC_VECTOR(ram_adrwidth-1 DOWNTO 0);
			BEGIN
-- read/write only words: A1 A0 --> not used for address
-- note: ram blocks can be addressed with mulitple addresses
				temp_ram_address := mem_address(ram_adrwidth-1+2 DOWNTO 2);
				address_0 <= TO_STDLOGICVECTOR(temp_ram_address);
				address_1 <= TO_STDLOGICVECTOR(temp_ram_address);
				address_2 <= TO_STDLOGICVECTOR(temp_ram_address);
				address_3 <= TO_STDLOGICVECTOR(temp_ram_address);
			END PROCESS;
-- assert data_in to ram blocks (pure logic)
-- separate bytes out of data_in
		data_in_3 <= TO_STDLOGICVECTOR(data_in(4*ram_datwidth-1 DOWNTO 3*ram_datwidth));
		data_in_2 <= TO_STDLOGICVECTOR(data_in(3*ram_datwidth-1 DOWNTO 2*ram_datwidth));
		data_in_1 <= TO_STDLOGICVECTOR(data_in(2*ram_datwidth-1 DOWNTO ram_datwidth));
		data_in_0 <= TO_STDLOGICVECTOR(data_in(ram_datwidth-1 DOWNTO 0));
-- assert output of memory blocks to data_out (pure logic)
		data_out <= TO_STDULOGICVECTOR(data_out_3 & data_out_2 & data_out_1 & data_out_0);
END behave;