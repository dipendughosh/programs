----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:04:35 05/09/2010 
-- Design Name: 
-- Module Name:    ripple4adder - Behavioral 
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ripple4adder is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           Cin : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (3 downto 0);
           Cout : out  STD_LOGIC);
end ripple4adder;

architecture Behavioral of ripple4adder is
component fulladder
port(A,B,Cin : in std_logic; Sum, Cout : out std_logic);
end component;
signal CT1, CT2, CT3 : std_logic;
begin
FA1: fulladder port map(A(0), B(0), Cin, S(0), CT1);
FA2: fulladder port map(A(1), B(1), CT1, S(1), CT2);
FA3: fulladder port map(A(2), B(2), CT2, S(2), CT3);
FA4: fulladder port map(A(3), B(3), CT3, S(3), Cout);
end Behavioral;

