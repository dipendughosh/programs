----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:47:17 04/22/2011 
-- Design Name: 
-- Module Name:    bigmux - Behavioral 
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity bigmux is
port( 	Ia: 	in std_logic_vector(15 downto 0);
	Ib: 	in std_logic_vector(15 downto 0);	  
	Ic:	in std_logic_vector(15 downto 0);
	Id:	in std_logic_vector(15 downto 0);
	Option:	in std_logic_vector(1 downto 0);
	Muxout:	out std_logic_vector(15 downto 0)
);
end bigmux;

architecture behv of bigmux is

begin
    
    process(Ia, Ib, Ic, Id, Option)
    begin
      case Option is
	when "00" => Muxout <= Ia;
        when "01" => Muxout <= Ib;
	when "10" => Muxout <= Ic; 
	when "11" => Muxout <= Id;
	when others =>  
      end case;
    end process;

end behv;
