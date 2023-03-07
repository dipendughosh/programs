----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:32:22 05/09/2010 
-- Design Name: 
-- Module Name:    AXON4BIT - Behavioral 
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

entity AXON4BIT is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           Result : out  STD_LOGIC_VECTOR (3 downto 0));
end AXON4BIT;

architecture Behavioral of AXON4BIT is
COMPONENT AND4BIT
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : in  STD_LOGIC_VECTOR (3 downto 0);
       C : out  STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT;
COMPONENT XOR4BIT
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : in  STD_LOGIC_VECTOR (3 downto 0);
       C : out  STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT;
COMPONENT OR4BIT
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : in  STD_LOGIC_VECTOR (3 downto 0);
       C : out  STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT;
COMPONENT NOT4BIT
Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
       B : out  STD_LOGIC_VECTOR (3 downto 0));
end COMPONENT;

SIGNAL RA, RX, RO, RN : STD_LOGIC_VECTOR (3 downto 0);

begin

LOGAND : AND4BIT PORT MAP(A, B, RA);
LOGXOR : XOR4BIT PORT MAP(A, B, RX);
LOGOR : OR4BIT PORT MAP(A, B, RO);
LOGNOT : NOT4BIT PORT MAP(A, RN);

Result <= RA when S0='0' and S1='0' else
          RX when S0='1' and S1='0' else
          RO when S0='0' and S1='1' else
		    RN;

end Behavioral;

