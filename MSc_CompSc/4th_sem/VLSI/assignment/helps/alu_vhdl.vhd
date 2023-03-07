----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:17:02 04/10/2011 
-- Design Name: 
-- Module Name:    ALU_VHDL - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU_VHDL is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           Operation : in  STD_LOGIC_VECTOR (2 downto 0);
           Flag : out  STD_LOGIC;
           Result : out  STD_LOGIC_VECTOR (3 downto 0));
			  
end ALU_VHDL;

architecture Behavioral of ALU_VHDL is
signal temp: std_logic_vector(4 downto 0);
begin
 process(A, B, Operation, temp) is
   begin
      Flag <= '0';
      case Operation is
         when "000" => -- res = nib1 + nib2, flag = carry = overflow
            result   <= std_logic_vector((unsigned(A) + unsigned(B)));
           -- Result <= temp(3 downto 0);
            -- Flag   <= temp(4);
				
				
			
         when "001" => -- res = |nib1 - nib2|, flag = 1 iff nib2 > nib1
            if (A >= B) then
               Result <= std_logic_vector(unsigned(A) - unsigned(B));
               Flag   <= '0';
            else
               Result <= std_logic_vector(unsigned(B) - unsigned(A));
               Flag   <= '1';
            end if;
         when "010" =>
            Result <= A and B;
         when "011" =>
            Result <= A or B;
         when "100" =>
            Result <= A xor B;
         when "101" =>
            Result <= not A;
         when "110" =>
            Result <= not B;
         when others => -- invalid option
            Result <= "XXXX";
            
      end case;
   end process;

end Behavioral;

