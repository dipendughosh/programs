--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:44:08 04/24/2011
-- Design Name:   
-- Module Name:   D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/processor3/processor_tb.vhd
-- Project Name:  processor3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: processor_vhd
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
 
ENTITY processor_tb IS
END processor_tb;
 
ARCHITECTURE behavior OF processor_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT processor_vhd
    PORT(
         A : INOUT  std_logic_vector(7 downto 0);
         B : INOUT  std_logic_vector(7 downto 0);
         C : INOUT  std_logic_vector(7 downto 0);
         D : INOUT  std_logic_vector(7 downto 0);
         E : INOUT  std_logic_vector(7 downto 0);
         H : INOUT  std_logic_vector(7 downto 0);
         L : INOUT  std_logic_vector(7 downto 0);
         I : INOUT  std_logic_vector(7 downto 0);
         SP : INOUT  std_logic_vector(7 downto 0);
         PC : INOUT  std_logic_vector(7 downto 0);
         Operation : IN  std_logic_vector(7 downto 0);
         Flag : INOUT  std_logic_vector(7 downto 0);
         AD : INOUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Operation : std_logic_vector(7 downto 0) := (others => '0');

	--BiDirs
   signal A : std_logic_vector(7 downto 0);
   signal B : std_logic_vector(7 downto 0);
   signal C : std_logic_vector(7 downto 0);
   signal D : std_logic_vector(7 downto 0);
   signal E : std_logic_vector(7 downto 0);
   signal H : std_logic_vector(7 downto 0);
   signal L : std_logic_vector(7 downto 0);
   signal I : std_logic_vector(7 downto 0);
   signal SP : std_logic_vector(7 downto 0);
   signal PC : std_logic_vector(7 downto 0);
   signal Flag : std_logic_vector(7 downto 0);
   signal AD : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   --constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: processor_vhd PORT MAP (
          A => A,
          B => B,
          C => C,
          D => D,
          E => E,
          H => H,
          L => L,
          I => I,
          SP => SP,
          PC => PC,
          Operation => Operation,
          Flag => Flag,
          AD => AD
        );

--   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--   end process;
-- 
--
--   -- Stimulus process
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
