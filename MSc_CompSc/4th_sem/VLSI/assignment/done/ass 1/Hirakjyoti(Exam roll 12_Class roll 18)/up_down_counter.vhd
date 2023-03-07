----------------------------------------------------------------------------------
-- Company: 		M.Sc Computber and Information Science
-- Engineer: 		Hirakjyoti Banerjee
-- 
-- Create Date:    	00:47:30 04/15/2011 
-- Design Name: 	Four Bit Arithematic Logic Unit
-- Module Name:    	alu4bitvhd - Behavioral 
-- Project Name:	Four Bit Arithematic Logic Unit 
-- Target Devices: 
-- Tool versions: 	XILINX ISE 12.3
-- Description: 	Clk :- At positive clock Pulse the counter changes its state
--					Rst :- To reset the counter when Reset = 1
--					u_d :- Count UP when UpDown = 0
--						   Count DOWN when UpDown = 1
--					q :- 4-bit output ofthe counter
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

entity up_down_counter is
	Port ( 	clk,rst : in STD_LOGIC;
			u_d : in STD_LOGIC;
			q : out STD_LOGIC_VECTOR (3 downto 0));
end up_down_counter;

architecture Behavioral of up_down_counter is
	signal cnt: std_logic_vector (3 downto 0);
	signal en : std_logic;
begin
	q <= cnt;
	P1:process(clk)
	begin
		if(clk ' event and clk = '1') then
			if (rst = '1') then cnt <= "0000";
			elsif (u_d = '1' and en = '1') then cnt <= cnt + 1;
			elsif (en = '0') then cnt <= cnt - 1;
			end if;
		end if;
	end process P1;
	P2: process(cnt)
	begin
		if (cnt = "0000") then en <= '1';
		elsif (cnt = "1111") then en <= '0';
		end if;
	end process P2;
end Behavioral; 