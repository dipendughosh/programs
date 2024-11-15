----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:27:41 04/22/2011 
-- Design Name: 
-- Module Name:    datapath - Behavioral 
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
library	ieee;
use ieee.std_logic_1164.all;  
use ieee.std_logic_arith.all;			   
use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity datapath is				
port(	clock_dp:	in 	std_logic;
	rst_dp:		in 	std_logic;
	imm_data:	in 	std_logic_vector(15 downto 0);
	mem_data: 	in 	std_logic_vector(15 downto 0);
	RFs_dp:		in 	std_logic_vector(1 downto 0);
	RFwa_dp:	in 	std_logic_vector(3 downto 0);
	RFr1a_dp:	in 	std_logic_vector(3 downto 0);
	RFr2a_dp:	in 	std_logic_vector(3 downto 0);
	RFwe_dp:	in 	std_logic;
	RFr1e_dp:	in 	std_logic;
	RFr2e_dp:	in 	std_logic;
	jp_en:		in 	std_logic;
	ALUs_dp:	in 	std_logic_vector(1 downto 0);
	oe_dp:		in 	std_logic;
	ALUz_dp:	out 	std_logic;
	RF1out_dp:	out 	std_logic_vector(15 downto 0);
	ALUout_dp:	out 	std_logic_vector(15 downto 0);
	bufout_dp:	out 	std_logic_vector(15 downto 0)
);
end datapath;

architecture struct of datapath is

component smallmux is
port( 	I0: 	in std_logic_vector(15 downto 0);
	I1: 	in std_logic_vector(15 downto 0);	  
	I2:	in std_logic_vector(15 downto 0);
	Sel:	in std_logic_vector(1 downto 0);
	O: 	out std_logic_vector(15 downto 0)
);
end component;

component reg_file is
port ( 	clock	: 	in std_logic;
	rst	: 	in std_logic;
	RFwe	: 	in std_logic;
	RFr1e	: 	in std_logic;
	RFr2e	: 	in std_logic;
	RFwa	: 	in std_logic_vector(3 downto 0);
	RFr1a	: 	in std_logic_vector(3 downto 0);
	RFr2a	: 	in std_logic_vector(3 downto 0);
	RFw	: 	in std_logic_vector(15 downto 0);
	RFr1	: 	out std_logic_vector(15 downto 0);
	RFr2	:	out std_logic_vector(15 downto 0)
);
end component;

component alu is
port (	num_A: 	in std_logic_vector(15 downto 0);
	num_B: 	in std_logic_vector(15 downto 0);
	jpsign:	in std_logic;
	ALUs:	in std_logic_vector(1 downto 0);
	ALUz:	out std_logic;
	ALUout:	out std_logic_vector(15 downto 0)
);
end component;

component obuf is
port(	O_en: 		in std_logic;
	obuf_in: 	in std_logic_vector(15 downto 0);
	obuf_out: 	out std_logic_vector(15 downto 0)
);
end component;

signal mux2rf, rf2alu1: std_logic_vector(15 downto 0); 
signal rf2alu2, alu2memmux: std_logic_vector(15 downto 0);

begin		

  U1: smallmux port map(alu2memmux, mem_data, 
			imm_data, RFs_dp, mux2rf);
  U2: reg_file port map(clock_dp, rst_dp, RFwe_dp, 
			RFr1e_dp, RFr2e_dp, 
			RFwa_dp, RFr1a_dp, RFr2a_dp, 
			mux2rf, rf2alu1, rf2alu2 );
  U3: alu port map( rf2alu1, rf2alu2, jp_en, ALUs_dp, 
		    ALUz_dp, alu2memmux);
  U4: obuf port map(oe_dp, mem_data, bufout_dp);
	
  ALUout_dp <= alu2memmux;
  RF1out_dp <= rf2alu1;
	
end struct;