------------------------------------------------------------------------------
-- Company: 		M.Sc Computer and Information Science
-- Engineer: 		Hirakjyoti Banerjee
-- 
-- Create Date:    	00:47:30 04/15/2011 
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	alu4bitvhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	Entity - alu4bitvhd
--					Nibble1 and Nibble2 :- 4-bit Inputs
--					Operation :- 3-bit Input for operations
--										000 - Result = A + B
--										001 - Result = A - B
--										010 - Result = A and B
--										011 - Result = A or B
--										100 - Result = A xor B
--										101 - Result = not A
--										110 - Result = not B
--										others - Result = XXXX
--					Flag :- 1-bit to hold the flag bit
--					Carry_out :- 1-bit to hold the carry bit
--					Result :- 4-bit output to hold the output

-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
 
entity ALU_4_bit is
   port( Carry_Out: out std_logic;
         Flag: out std_logic;
         Nibble1: in std_logic_vector(3 downto 0);
         Nibble2: in std_logic_vector(3 downto 0);
         Operation: in std_logic_vector(2 downto 0);
         result: out std_logic_vector(3 downto 0));
end ALU_4_bit;
 
architecture Behavioral of ALU_4_bit is
   signal temp: std_logic_vector(4 downto 0);
   
begin
   process(Nibble1,Nibble2,Operation,temp)
   begin
      Flag <= '0';
      case Operation is 
         when "000" => 
            temp <= conv_std_logic_vector((conv_integer(Nibble1) + conv_integer(Nibble2)),5);
            result <= temp(3 downto 0);
            Carry_Out <= temp(4);
         when "001" =>
            if Nibble1 >= Nibble2 then
               result <= Nibble1 - Nibble2;
               Flag <= '0';
            else
               result <= Nibble2 - Nibble1;
               Flag <= '1';
            end if;
         when "010" =>
            result <= Nibble1 and Nibble2;
         when "011" =>   
            result <= Nibble1 or Nibble2;
         when "100" =>
            result <= Nibble1 xor Nibble2;
         when "101" =>
            result <= not Nibble1;
         when "110" =>
            result <= not Nibble2;
         when others =>
            temp <= conv_std_logic_vector((conv_integer(Nibble1) + conv_integer(not Nibble2)) + 1,  5);
            result <= temp(3 downto 0);
      end case;
   end process;
end Behavioral;