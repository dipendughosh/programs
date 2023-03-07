----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:40:45 04/11/2011 
-- Design Name: 
-- Module Name:    udc1 - Behavioral 
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
use ieee.std_logic_unsigned.all; 


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity udc1 is
    Port ( C : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           U_D : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0));
end udc1;

architecture Behavioral of udc1 is
signal tmp: std_logic_vector(3 downto 0); 

begin
	process (C, CLR) 
	begin 

		if (CLR='1') then 
          tmp <= "0000"; 
        elsif (C'event and C='1') then 
          if (U_D='1') then 
            tmp <= tmp + 1; 
          else 
            tmp <= tmp - 1; 
          end if; 
        end if; 
    end process; 
    Q <= tmp; 


end Behavioral;

