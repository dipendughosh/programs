----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:36:01 04/22/2011 
-- Design Name: 
-- Module Name:    reg_file - Behavioral 
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
use work.constant_lib.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity reg_file is
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
end reg_file;

architecture behv of reg_file is			

  type rf_type is array (0 to 15) of 
        std_logic_vector(15 downto 0);
  signal tmp_rf: rf_type;
  --signal ZERO: rf_type;

begin

  write: process(clock, rst, RFwa, RFwe, RFw)
  begin
    if rst='1' then				-- high active
        tmp_rf <= (tmp_rf'range => ZERO);
    else
	if (clock'event and clock = '1') then
	  if RFwe='1' then
	    tmp_rf(conv_integer(RFwa)) <= RFw;
	  end if;
	end if;
    end if;
  end process;						   
	
  read1: process(clock, rst, RFr1e, RFr1a)
  begin
    if rst='1' then
	RFr1 <= ZERO;
    else
	if (clock'event and clock = '1') then
	  if RFr1e='1' then								 
	    RFr1 <= tmp_rf(conv_integer(RFr1a));
	  end if;
	end if;
    end if;
  end process;
	
  read2: process(clock, rst, RFr2e, RFr2a)
  begin
    if rst='1' then
	RFr2<= ZERO;
    else
	if (clock'event and clock = '1') then
	  if RFr2e='1' then								 
	    RFr2 <= tmp_rf(conv_integer(RFr2a));
	  end if;
	end if;
    end if;
  end process;
	
end behv;
