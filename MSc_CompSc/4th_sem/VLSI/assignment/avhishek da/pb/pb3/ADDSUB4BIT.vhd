----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:37:41 05/09/2010 
-- Design Name: 
-- Module Name:    ADDSUB4BIT - Behavioral 
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

entity ADDSUB4BIT is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           M : in  STD_LOGIC;
           Result : out  STD_LOGIC_VECTOR (3 downto 0);
           Cout : out  STD_LOGIC);
end ADDSUB4BIT;

architecture Behavioral of ADDSUB4BIT is
component ripple4adder
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : in  STD_LOGIC_VECTOR (3 downto 0);
       Cin : in  STD_LOGIC;
       S : out  STD_LOGIC_VECTOR (3 downto 0);
       Cout : out  STD_LOGIC);
end component;
signal BX: std_logic_vector(3 downto 0);
begin
BX(0) <= B(0) xor M;
BX(1) <= B(1) xor M;
BX(2) <= B(2) xor M;
BX(3) <= B(3) xor M;

RCA : ripple4adder port map(A, BX, M, Result, Cout);

end Behavioral;

