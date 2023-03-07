--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:19:25 04/14/2011
-- Design Name:   
-- Module Name:   D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/counter4bit/counter4bittb.vhd
-- Project Name:  counter4bit
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: counter4bitvhd
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
 
ENTITY counter4bittb IS
END counter4bittb;
 
ARCHITECTURE behavior OF counter4bittb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT counter4bitvhd
    PORT(
         Input : IN  std_logic_vector(0 to 3);
         Clock : IN  std_logic;
         Load : IN  std_logic;
         Reset : IN  std_logic;
         UpDown : IN  std_logic;
         Output : OUT  std_logic_vector(0 to 3)
        );
    END COMPONENT;
    

   --Inputs
   signal Input : std_logic_vector(0 to 3) := (others => '0');
   signal Clock : std_logic := '0';
   signal Load : std_logic := '0';
   signal Reset : std_logic := '0';
   signal UpDown : std_logic := '0';
	--signal Output : std_logic_vector(0 to 3) := (others => '0');

 	--Outputs
   signal Output : std_logic_vector(0 to 3);

   -- Clock period definitions
   --constant Clock_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: counter4bitvhd PORT MAP (
          Input => Input,
          Clock => Clock,
          Load => Load,
          Reset => Reset,
          UpDown => UpDown,
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
--       hold reset state for 100 ns.
--      wait for 100 ns;	
--
--      wait for Clock_period*10;
--
--       insert stimulus here 
--
--      wait;
--   end process;

END;
