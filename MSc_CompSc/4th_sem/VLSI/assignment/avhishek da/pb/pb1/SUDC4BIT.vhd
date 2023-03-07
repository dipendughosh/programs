----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:40:41 05/13/2010 
-- Design Name: 
-- Module Name:    SUDC4BIT - Behavioral 
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

entity SUDC4BIT is
    Port ( S : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (3 downto 0));
end SUDC4BIT;

architecture Behavioral of SUDC4BIT is
COMPONENT MUX2 
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           S : in  STD_LOGIC;
           Z : out  STD_LOGIC);
end COMPONENT;
COMPONENT TFLIPFLOP
    Port ( T : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC;
           Q_INV : out  STD_LOGIC);
end COMPONENT;
SIGNAL Y_INV,Y:STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL M:STD_LOGIC_VECTOR(2 DOWNTO 0);
begin
T0 : TFLIPFLOP PORT MAP('1',CLK,'0',Y(0),Y_INV(0));
M(0) <= '1' AND Y(0);
T1 : TFLIPFLOP PORT MAP(M(0),CLK,'0',Y(1),Y_INV(1));
M(1) <= M(0) AND Y(1);
T2 : TFLIPFLOP PORT MAP(M(1),CLK,'0',Y(2),Y_INV(2));
M(2) <= M(1) AND Y(2);
T3 : TFLIPFLOP PORT MAP(M(2),CLK,'0',Y(3),Y_INV(3));
MO : MUX2 PORT MAP(Y(0),Y_INV(0),S,Q(0));
M1 : MUX2 PORT MAP(Y(1),Y_INV(1),S,Q(1));
M2 : MUX2 PORT MAP(Y(2),Y_INV(2),S,Q(2));
M3 : MUX2 PORT MAP(Y(3),Y_INV(3),S,Q(3));

end Behavioral;

