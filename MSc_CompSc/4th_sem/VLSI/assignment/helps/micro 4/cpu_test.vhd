--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   01:10:34 04/29/2011
-- Design Name:   
-- Module Name:   E:/VHDL_angana/processor/cpu_test.vhd
-- Project Name:  processor
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: microprocessor
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
 
ENTITY cpu_test IS
END cpu_test;
 
ARCHITECTURE behavior OF cpu_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT microprocessor
    PORT(
         cpu_clk : IN  std_logic;
         cpu_rst : IN  std_logic;
         cpu_output : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal cpu_clk : std_logic := '0';
   signal cpu_rst : std_logic := '0';

 	--Outputs
   signal cpu_output : std_logic_vector(15 downto 0);

   -- Clock period definitions
   constant cpu_clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: microprocessor PORT MAP (
          cpu_clk => cpu_clk,
          cpu_rst => cpu_rst,
          cpu_output => cpu_output
        );

   -- Clock process definitions
   cpu_clk_process :process
   begin
		cpu_clk <= '0';
		wait for cpu_clk_period/2;
		cpu_clk <= '1';
		wait for cpu_clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for cpu_clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
