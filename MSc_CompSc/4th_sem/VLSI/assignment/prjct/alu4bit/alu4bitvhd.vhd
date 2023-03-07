----------------------------------------------------------------------------------
-- Company: 		M.Sc Computer and Information Science
-- Engineer: 		Dipendu Ghosh
-- 
-- Create Date:    	00:47:30 04/15/2011 
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	alu4bitvhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	Entity - alu4bitvhd
--					M Input Port :- 0 for Logic Operations
--									    1 for Arithematic Operations
--					A and B :- 4-bit Inputs
--					Operation :- 3-bit Input for operations
--									Logic Operations:-
--										000 - Result = A and B
--										001 - Result = A or B
--										010 - Result = A xor B
--										011 - Result = A xnor B
--										100 - Result = A nand B
--										101 - Result = A nor B
-- 									110 - Result = not A
--										111 - Result = not B
--										others - Result = XXXX
--									Arithematic Operations:-
--										000 - Result = A + B
--										001 - Result = A - B
--										010 - Result = A
--										011 - Result = A + 1
--										100 - Result = A + B + 1
--										101 - Result = A + B'
--										110 - Result = A' + B
--										111 - Result = B - A
--										others - Result = XXXX
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

entity alu4bitvhd is
	Port ( 		M : in  STD_LOGIC;
				A : in  STD_LOGIC_VECTOR (3 downto 0);
				B : in  STD_LOGIC_VECTOR (3 downto 0);
				Operation : in  STD_LOGIC_VECTOR (2 downto 0);
				Flag : out  STD_LOGIC;
				Result : out  STD_LOGIC_VECTOR (3 downto 0)
			);
end alu4bitvhd;

architecture Behavioral of alu4bitvhd is
	signal Temp: std_logic_vector(4 downto 0);
	signal T: std_logic_vector(3 downto 0);
begin
	process(M, A, B, Operation, temp) is
   begin
		case M is
			when '0' =>
				Flag <= '0';
				case Operation is
					when "000" => 
						Result <= A and B;
					when "001" => 
						Result <= A or B;
					when "010" =>
						Result <= A xor B;
					when "011" =>
						Result <= A xnor B;
					when "100" =>
						Result <= A nand B;
					when "101" =>
						Result <= A nor B;
					when "110" =>
						Result <= not A;
					when "111" =>
						Result <= not B;
					when others =>
						Result <= "XXXX";
				end case;
			when '1' =>
				Flag <= '0';
				case Operation is
					when "000" => -- res = nib1 + nib2, flag = carry = overflow
						Temp   <= std_logic_vector((unsigned("0" & A) + unsigned(B)));
						Result <= temp(3 downto 0);
						Flag   <= temp(4);
					when "001" => -- res = |nib1 - nib2|, flag = 1 iff nib2 > nib1
						if (A >= B) then
							Result <= std_logic_vector(unsigned(A) - unsigned(B));
							Flag   <= '0';
						else
							Result <= std_logic_vector(unsigned(B) - unsigned(A));
							Flag   <= '1';
						end if;
					when "010" => -- res = A
						Result <= A;
					when "011" => -- res = A + 1
						Result <= std_logic_vector(unsigned(A) + 1);
					when "100" => -- res = A + B + 1 
						Temp   <= std_logic_vector((unsigned("0" & A) + unsigned(B) + 1));
						--T <= temp(3 downto 0);
						--f <= temp(4);
						--temp  <= std_logic_vector(unsigned(T) + 1);
						Result <= temp(3 downto 0);
						Flag   <= temp(4);
					when "101" => -- res = A + B'
						T  <= not B;
						Temp   <= std_logic_vector((unsigned("0" & A) + unsigned(T)));
						Result <= temp(3 downto 0);
						Flag   <= temp(4);
					when "110" => -- res = B + A'
						T  <= not A;
						Temp   <= std_logic_vector((unsigned(B) + unsigned(T)));
						Result <= temp(3 downto 0);
						Flag   <= temp(4);
					when "111" => -- res = B - A
						if (B >= A) then
							Result <= std_logic_vector(unsigned(B) - unsigned(A));
							Flag   <= '0';
						else
							Result <= std_logic_vector(unsigned(A) - unsigned(B));
							Flag   <= '1';
						end if;
					when others =>
						Result <= "XXXX";
				end case;
			when others =>
				Result <= "XXXX";
		end case;
   end process;

end Behavioral;

