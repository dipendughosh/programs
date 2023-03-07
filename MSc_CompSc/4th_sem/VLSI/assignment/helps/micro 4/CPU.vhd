--------------------------------------------------------
-- Simple Microprocessor Design 
--
-- Microprocessor composed of
-- Ctrl_Unit, Data_Path and Memory
-- structural modeling
-- microprocessor.vhd
--------------------------------------------------------

library	ieee;
use ieee.std_logic_1164.all;  
use ieee.std_logic_arith.all;			   
use ieee.std_logic_unsigned.all;


entity microprocessor is
port( 	cpu_clk:	in std_logic;
		cpu_rst:	in std_logic;
		cpu_output:	out std_logic_vector(15 downto 0)
);
end microprocessor;

architecture structure of microprocessor is


component memory is
port ( 	clock	: 	in std_logic;
		rst		: 	in std_logic;
		Mre		:	in std_logic;
		Mwe		:	in std_logic;
		address	:	in std_logic_vector(7 downto 0);
		data_in	:	in std_logic_vector(15 downto 0);
		data_out:	out std_logic_vector(15 downto 0)
);
end component;

signal addr_bus,mdin_bus,mdout_bus,immd_bus,rfout_bus: std_logic_vector(15 downto 0);  
signal mem_addr: std_logic_vector(7 downto 0);
signal RFwa_s, RFr1a_s, RFr2a_s: std_logic_vector(3 downto 0);
signal RFwe_s, RFr1e_s, RFr2e_s: std_logic;
signal ALUs_s, RFs_s: std_logic_vector(1 downto 0);
signal IRld_s, PCld_s, PCinc_s, PCclr_s: std_logic;
signal Mre_s, Mwe_s, jpz_s, oe_s: std_logic;

begin
	
	mem_addr <="00001010"; 
	Mre_s<='1';
	Mwe_s<='0';
	
	Unit2: memory port map(	cpu_clk,cpu_rst,Mre_s,Mwe_s,mem_addr,mdin_bus,mdout_bus);

cpu_output<=mdout_bus;
end structure;


