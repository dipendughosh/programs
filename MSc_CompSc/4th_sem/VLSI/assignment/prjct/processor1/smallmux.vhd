----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:34:52 04/22/2011 
-- Design Name: 
-- Module Name:    smallmux - Behavioral 
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

entity smallmux is
port( 	I0: 	in std_logic_vector(15 downto 0);
		I1: 	in std_logic_vector(15 downto 0);	  
		I2:		in std_logic_vector(15 downto 0);
		Sel:	in std_logic_vector(1 downto 0);
		O: 		out std_logic_vector(15 downto 0)
	);
end smallmux;

architecture behv of smallmux is

begin
	process(I0, I1, I2, Sel)
    begin
        case Sel is
            when "00" =>	O <= I0;
            when "01" =>    O <= I1;
			when "10" =>	O <= I2;
            when others =>  
        end case;
    end process;
end behv;

