----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:44:20 04/22/2011 
-- Design Name: 
-- Module Name:    IR - Behavioral 
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

entity IR is
port(	IRin:	  in std_logic_vector(15 downto 0);
	IRld:	  in std_logic;
	dir_addr: out std_logic_vector(15 downto 0);
	IRout: 	  out std_logic_vector(15 downto 0)
);
end IR;

architecture behv of IR is

begin
  process(IRld, IRin)
  begin
    if IRld = '1' then
	IRout <= IRin;
	dir_addr <= "00000000" & IRin(7 downto 0);
    end if;
  end process;
end behv;
