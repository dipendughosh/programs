--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   01:44:11 04/15/2011
-- Design Name:   
-- Module Name:   D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/alu4bit/alu4bittb.vhd
-- Project Name:  alu4bit
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu4bitvhd
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
 
ENTITY alu4bittb IS
END alu4bittb;
 
ARCHITECTURE behavior OF alu4bittb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu4bitvhd
    PORT(
         M : IN  std_logic;
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         Operation : IN  std_logic_vector(2 downto 0);
         Flag : OUT  std_logic;
         Result : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal M : std_logic :=  '0';
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');
   signal Operation : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal Flag : std_logic;
   signal Result : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   --constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu4bitvhd PORT MAP (
          M => M,
          A => A,
          B => B,
          Operation => Operation,
          Flag => Flag,
          Result => Result
        );

   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--   end process;
 

   -- Stimulus process
--   stim_proc: process
--   begin		
--      -- hold reset state for 100 ns.
--      wait for 100 ns;	
--
--      wait for <clock>_period*10;
--
--      -- insert stimulus here 
--
--      wait;
--   end process;

END;
