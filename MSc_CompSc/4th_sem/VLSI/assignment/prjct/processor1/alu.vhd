----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:37:57 04/22/2011 
-- Design Name: 
-- Module Name:    alu - Behavioral 
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
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;  
use work.constant_lib.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity alu is
port (	num_A: 	in std_logic_vector(15 downto 0);
		num_B: 	in std_logic_vector(15 downto 0);
		jpsign:	in std_logic;
		ALUs:	in std_logic_vector(1 downto 0);
		ALUz:	out std_logic;
		ALUout:	out std_logic_vector(15 downto 0)
);
end alu;

architecture behv of alu is

signal alu_tmp: std_logic_vector(15 downto 0);

begin

	process(num_A, num_B, ALUs)
	begin			
		case ALUs is
		  when "00" => alu_tmp <= num_A;
		  when "01" => alu_tmp <= num_B;
		  when "10" => alu_tmp <= num_A + num_B;
		  when "11" => alu_tmp <= num_A - num_B;
		  when others =>
	    end case; 					  
	end process;
	
	process(jpsign, alu_tmp)
	begin
		if (jpsign = '1' and alu_tmp = ZERO) then
			ALUz <= '1';
		else
			ALUz <= '0';
		end if;
	end process;					
	
	ALUout <= alu_tmp;
	
end behv;
