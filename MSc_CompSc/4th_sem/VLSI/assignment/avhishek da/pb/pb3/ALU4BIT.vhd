----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:46:15 05/09/2010 
-- Design Name: 
-- Module Name:    ALU4BIT - Behavioral 
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

entity ALU4BIT is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           ARLO : in  STD_LOGIC;
           ADSU : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           Result : out  STD_LOGIC_VECTOR (3 downto 0);
           Cout : out  STD_LOGIC);
end ALU4BIT;

architecture Behavioral of ALU4BIT is
COMPONENT AXON4BIT
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : in  STD_LOGIC_VECTOR (3 downto 0);
       S0 : in  STD_LOGIC;
       S1 : in  STD_LOGIC;
       Result : out  STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT;
COMPONENT ADDSUB4BIT is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           M : in  STD_LOGIC;
           Result : out  STD_LOGIC_VECTOR (3 downto 0);
           Cout : out  STD_LOGIC);
end COMPONENT;
SIGNAL RA, RL : STD_LOGIC_VECTOR (3 DOWNTO 0);
begin

AU : ADDSUB4BIT PORT MAP(A, B, ADSU, RA, Cout);
LU : AXON4BIT PORT MAP(A, B, S0, S1, RL);

Result <= RA when arlo='0' else
			 RL;

end Behavioral;

