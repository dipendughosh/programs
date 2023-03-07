----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:46:38 05/13/2010 
-- Design Name: 
-- Module Name:    TFLIPFLOP - Behavioral 
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

entity TFLIPFLOP is
    Port ( T : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC;
           Q_INV : out  STD_LOGIC);
end TFLIPFLOP;

architecture Behavioral of TFLIPFLOP is
SIGNAL S : STD_LOGIC;
begin
PROCESS
BEGIN
WAIT UNTIL CLK='1' AND CLK'EVENT;
IF (RESET='1') THEN S<= '0';
ELSIF T='1' THEN S<=NOT S;
END IF ;
IF (S/='0' and S/='1') then S<='0';
END IF;
END PROCESS;
Q<=S;
Q_INV<=NOT S;

end Behavioral;

