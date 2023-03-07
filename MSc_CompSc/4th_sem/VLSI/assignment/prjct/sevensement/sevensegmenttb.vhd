--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   00:40:57 04/15/2011
-- Design Name:   
-- Module Name:   D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/sevensement/sevensegmenttb.vhd
-- Project Name:  sevensement
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: sevensegmentvhd
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY sevensegmenttb IS
END sevensegmenttb;
 
ARCHITECTURE behavior OF sevensegmenttb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT sevensegmentvhd
    PORT(
         Clock : IN  std_logic;
         Input : IN  std_logic_vector(3 downto 0);
         Output : OUT  std_logic_vector(6 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Clock : std_logic := '0';
   signal Input : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Output : std_logic_vector(6 downto 0);

   -- Clock period definitions
   --constant Clock_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: sevensegmentvhd PORT MAP (
          Clock => Clock,
          Input => Input,
          Output => Output
        );

   -- Clock process definitions
--   Clock_process :process
--   begin
--		Clock <= '0';
--		wait for Clock_period/2;
--		Clock <= '1';
--		wait for Clock_period/2;
--   end process;
 

   -- Stimulus process
--   stim_proc: process
--   begin		
--      -- hold reset state for 100 ns.
--      wait for 100 ns;	
--
--      wait for Clock_period*10;
--
--      -- insert stimulus here 
--
--      wait;
--   end process;

END;
