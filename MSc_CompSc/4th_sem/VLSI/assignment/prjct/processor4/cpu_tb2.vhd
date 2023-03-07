--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:20:57 05/01/2011
-- Design Name:   
-- Module Name:   D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/processor4/cpu_tb2.vhd
-- Project Name:  processor4
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: memory
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
 
ENTITY cpu_tb2 IS
END cpu_tb2;
 
ARCHITECTURE behavior OF cpu_tb2 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT memory
    PORT(
         clock : IN  std_logic;
         rst : IN  std_logic;
         Mre : IN  std_logic;
         Mwe : IN  std_logic;
         address : IN  std_logic_vector(7 downto 0);
         data_in : IN  std_logic_vector(15 downto 0);
         data_out : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clock : std_logic := '0';
   signal rst : std_logic := '0';
   signal Mre : std_logic := '0';
   signal Mwe : std_logic := '0';
   signal address : std_logic_vector(7 downto 0) := (others => '0');
   signal data_in : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal data_out : std_logic_vector(15 downto 0);

   -- Clock period definitions
   --constant clock_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: memory PORT MAP (
          clock => clock,
          rst => rst,
          Mre => Mre,
          Mwe => Mwe,
          address => address,
          data_in => data_in,
          data_out => data_out
        );

   -- Clock process definitions
--   clock_process :process
--   begin
--		clock <= '0';
--		wait for clock_period/2;
--		clock <= '1';
--		wait for clock_period/2;
--   end process;
-- 

   -- Stimulus process
--   stim_proc: process
--   begin		
--      -- hold reset state for 100 ns.
--      wait for 100 ns;	
--
--      wait for clock_period*10;
--
--      -- insert stimulus here 
--
--      wait;
--   end process;

END;
