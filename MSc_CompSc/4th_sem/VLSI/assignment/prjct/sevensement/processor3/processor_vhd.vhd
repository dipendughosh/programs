----------------------------------------------------------------------------------
-- Company: 		M.Sc Computer and Information Science
-- Engineer: 		Dipendu Ghosh
-- 
-- Create Date:    	18:57:16 04/23/2011
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	processor_vhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	Entity - alu4bitvhd
--					M Input Port :- 0 for Logic Operations
--									    1 for Arithematic Operations
--					A and B :- 4-bit Inputs
--					Operation :- 3-bit Input for operations
--									Logic Operations:-
--										000 - Result8 = A and B
--										001 - Result8 = A or B
--										010 - Result8 = A xor B
--										011 - Result8 = A xnor B
--										100 - Result8 = A nand B
--										101 - Result8 = A nor B
-- 									110 - Result8 = not A
--										111 - Result8 = not B
--										others - Result8 = XXXX
--									Arithematic Operations:-
--										000 - Result8 = A + B
--										001 - Result8 = A - B
--										010 - Result8 = A
--										011 - Result8 = A + 1
--										100 - Result8 = A + B + 1
--										101 - Result8 = A + B'
--										110 - Result8 = A' + B
--										111 - Result8 = B - A
--										others - Result8 = XXXX
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
--USE IEEE.std_logic_arith.ALL;

entity processor_vhd is
	Port ( 	
				--Registers
				A : inout  STD_LOGIC_VECTOR (7 downto 0);
				B : inout  STD_LOGIC_VECTOR (7 downto 0);
				C : inout  STD_LOGIC_VECTOR (7 downto 0);
				D : inout  STD_LOGIC_VECTOR (7 downto 0);
				E : inout  STD_LOGIC_VECTOR (7 downto 0);
				H : inout  STD_LOGIC_VECTOR (7 downto 0);
				L : inout  STD_LOGIC_VECTOR (7 downto 0);
				
				--Memory
				M : inout  STD_LOGIC_VECTOR (7 downto 0);
				
				--Result8
				Result8 : inout  STD_LOGIC_VECTOR (7 downto 0);
				
				--Result16
				Result16 : inout  STD_LOGIC_VECTOR (15 downto 0);
				
				--Immediate value
				I : inout  STD_LOGIC_VECTOR (7 downto 0);
				
				--Counters
				SP : inout  STD_LOGIC_VECTOR (7 downto 0);
				PC : inout  STD_LOGIC_VECTOR (7 downto 0);
 
				--Operations
				Operation : in  STD_LOGIC_VECTOR (7 downto 0);

				--Flags(S,Z,-,AC,-,P,-,CY)
				Flag : inout  STD_LOGIC_VECTOR (7 downto 0);

				--Address and Data lines
				AD : inout  STD_LOGIC_VECTOR (7 downto 0)
			);
end processor_vhd;

architecture Behavioral of processor_vhd is
	signal Temp: std_logic_vector(8 downto 0);
	signal T: std_logic_vector(8 downto 0);
	type Mem_type is array (((2**8) - 1) downto 0,7 downto 0) of std_logic;
--	type mem_type is array (7 downto 0) of std_logic_vector((2**8) - 1 downto 0);
	signal Memory: Mem_type; 
--	signal s: std_logic;
begin
	process(A, B, C, D, E, H, L, M, Result8, Result16, SP, PC, Operation, Flag, AD, Temp, T) is
   begin
		
		case Operation is
----------------------------------------------------------------------------------		
			--ADD :-
			--------
			--Result8 = A + B (80)
			when "10000000" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(B)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
			
			--Result8 = A + C (81)
			when "10000001" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(C)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
				
			--Result8 = A + D (82)
			when "10000010" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(D)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
				
			--Result8 = A + E (83)
			when "10000011" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(E)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
				
			--Result8 = A + H (84)
			when "10000100" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(H)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
				
			--Result8 = A + L (85)
			when "10000101" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(L)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
			
			--Result8 = A + M (86)
			when "10000110" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(M)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
				
			--Result8 = A + A (87)
			when "10000111" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(A)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8);
----------------------------------------------------------------------------------
			--ADI :- 
			--------
			--Result8 = A + I (C6)
			when "11000110" => 
				Temp <= std_logic_vector((unsigned("0" & A) + unsigned(I)));
				Result8<= temp(7 downto 0);
				Flag(0) <= temp(8); 
----------------------------------------------------------------------------------
			--ANA :-
			--------
			--Result8 = A and B (A0)
			when "10100000" =>
				Result8 <= A and B;
			
			--Result8 = A and C (A1)
			when "10100001" =>
				Result8 <= A and C;
			
			--Result8 = A and D (A2)
			when "10100010" =>
				Result8 <= A and D;
			
			--Result8 = A and E (A3)
			when "10100011" =>
				Result8 <= A and E;
			
			--Result8 = A and H (A4)
			when "10100100" =>
				Result8 <= A and H;
			
			--Result8 = A and L (A5)
			when "10100101" =>
				Result8 <= A and L;
			
			--Result8 = A and M (A6)
			when "10100110" =>
				Result8 <= A and M;
			
			--Result8 = A and A (A7)
			when "10100111" =>
				Result8 <= A and A;
----------------------------------------------------------------------------------
			--ANI :-
			--------
			--Result8 = A and I (E6)
			when "11100110" =>
				Result8 <= A and I;
----------------------------------------------------------------------------------
			--CMA :-
			--------
			--Result8 = not A (2F)
			when "00101111" =>
				Result8 <= not A;
----------------------------------------------------------------------------------
			--CMP :-
			--------
			--Flag = A cmp B (B8)
			when "10111000" =>
				if( A < B) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > B) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = B) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;

			--Flag = A cmp C (B9)
			when "10111001" =>
				if( A < c) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > C) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = C) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp D (BA)
			when "10111010" =>
				if( A < D) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > D) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = D) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp E (BB)
			when "10111011" =>
				if( A < E) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > E) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = E) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp H (BC)
			when "10111100" =>
				if( A < H) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > H) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = H) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp L (BD)
			when "10111101" =>
				if( A < L) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > L) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = L) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp M (BE)
			when "10111110" =>
				if( A < M) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > M) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = M) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
				
			--Flag = A cmp A (BF)
			when "10111111" =>
				if( A < A) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > A) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = A) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
----------------------------------------------------------------------------------
			--CPI :-
			--------
			--Flag = A cmp I (FE)
			when "11111110" =>
				if( A < I) then
					Flag(6) <= '0';
					Flag(0) <= '1';
				end if;
				if( A > I) then
					Flag(6) <= '0';
					Flag(0) <= '0';
				end if;
				if( A = I) then
					Flag(6) <= '1';
					Flag(0) <= '0';
				end if;
----------------------------------------------------------------------------------
			--DAD :-
			--------
			--Result16 = HL + BC (09)
			when "00001001" =>
				T <= std_logic_vector((unsigned("0" & L) + unsigned(C)));
				Result8(7 downto 0) <= T(7 downto 0);
				Result16(7 downto 0) <= T(7 downto 0);
				Flag(0) <= T(8);
				if(T(8) = '1') then
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(B) + 1));
				else
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(B)));
				end if;
				Result16(15 downto 8) <= Temp(7 downto 0);
				Flag(0) <= Temp(8);
				
			--Result16 = HL + DE (19)
			when "00011001" =>
				T <= std_logic_vector((unsigned("0" & L) + unsigned(E)));
				Result8(7 downto 0) <= T(7 downto 0);
				Result16(7 downto 0) <= T(7 downto 0);
				Flag(0) <= T(8);
				if(T(8) = '1') then
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(D) + 1));
				else
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(D)));
				end if;
				Result16(15 downto 8) <= Temp(7 downto 0);
				Flag(0) <= Temp(8);
				
			--Result16 = HL + HL (29)
			when "00101001" =>
				T <= std_logic_vector((unsigned("0" & L) + unsigned(L)));
				Result8(7 downto 0) <= T(7 downto 0);
				Result16(7 downto 0) <= T(7 downto 0);
				Flag(0) <= T(8);
				if(T(8) = '1') then
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(H) + 1));
				else
					Temp <= std_logic_vector((unsigned("0" & H) + unsigned(H)));
				end if;
				Result16(15 downto 8) <= Temp(7 downto 0);
				Flag(0) <= Temp(8);
----------------------------------------------------------------------------------
			--DCR :-
			--------
			--Result8 = B - 1 (05)
			when "00000101" =>
				if( B > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(B) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( B = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(B) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( B < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(B));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
				
			--Result8 = C - 1 (0D)
			when "00001101" =>
				if( C > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(C) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( C = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(C) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( C < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(C));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
				
			--Result8 = D - 1 (15)
			when "00010101" =>
				if( D > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(D) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( D = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(D) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( D < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(D));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
			
			--Result8 = E - 1 (1D)
			when "00011101" =>
				if( E > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(E) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( E = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(E) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( E < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(E));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
			
			--Result8 = H - 1 (25)
			when "00100101" =>
				if( H > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(H) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( H = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(H) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( H < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(H));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
				
			--Result8 = L - 1 (2D)
			when "00101101" =>
				if( L > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(L) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( L = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(L) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( L < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(L));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
			
			--Result8 = M - 1 (35)
			when "00110101" =>
				if( M > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(M) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( M = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(M) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( M < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(M));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
			
			--Result8 = A - 1 (3D)
			when "00111101" =>
				if( A > "00000001" ) then
					Result8 <= std_logic_vector(unsigned(A) - 1);
					Flag(6) <= '0';
					Flag(7) <= '0';
				end if;
				if ( A = "00000001" ) then
					Result8 <= std_logic_vector(unsigned(A) - 1);
					Flag(6) <= '1';
					Flag(7) <= '0';
				end if;
				if ( A < "00000000" ) then
					Result8 <= std_logic_vector(1 - unsigned(A));
					Flag(6) <= '0';
					Flag(7) <= '1';
				end if;
----------------------------------------------------------------------------------
			--DCX :-
			--------
			--Result16 = BC - 1 (0B)
			when "00001011" =>
				if( C > "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(unsigned(C) - 1);
					Result16(15 downto 8) <= B;
				end if;
				if ( C = "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(1 - unsigned(C));
					if( B > "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(unsigned(B) - 1);
					end if;
					if( B = "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(1 - unsigned(B));
					end if;						
				end if;
				
			--Result16 = DE - 1 (1B)
			when "00011011" =>
				if( E > "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(unsigned(E) - 1);
					Result16(15 downto 8) <= D;
				end if;
				if ( E = "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(1 - unsigned(E));
					if( D > "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(unsigned(D) - 1);
					end if;
					if( D = "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(1 - unsigned(D));
					end if;						
				end if;
				
			--Result8 = HL - 1 (2B)
			when "00101011" =>
				if( L > "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(unsigned(L) - 1);
					Result16(15 downto 8) <= H;
				end if;
				if ( L = "00000000" ) then
					Result16(7 downto 0) <= std_logic_vector(1 - unsigned(L));
					if( H > "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(unsigned(H) - 1);
					end if;
					if( H = "00000000" ) then
						Result16(15 downto 8) <= std_logic_vector(1 - unsigned(H));
					end if;						
				end if;
----------------------------------------------------------------------------------				
			when others =>
				Result8 <= "XXXXXXXX";
				Result16 <= "XXXXXXXXXXXXXXXX";
			end case;
			
			
   end process;

end Behavioral;

