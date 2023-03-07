----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:38:58 04/22/2011 
-- Design Name: 
-- Module Name:    obuf - Behavioral 
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
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use work.constant_lib.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity obuf is
port(	O_en: 		in std_logic;
	obuf_in: 	in std_logic_vector(15 downto 0);
	obuf_out: 	out std_logic_vector(15 downto 0)
);
end obuf;

architecture behv of obuf is
begin

  process (O_en, obuf_in)
  begin
    if O_en = '1' then
	obuf_out <= obuf_in;
    else
	obuf_out <= HIRES;
    end if;
  end process;

end behv;
