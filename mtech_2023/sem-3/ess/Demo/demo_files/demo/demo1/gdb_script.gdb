# Set breakpoints at lines 17 and 18
break 17
shell echo "Set breakpoint at line 17."
shell echo "Press Enter to continue..." && read

break 18
shell echo "Set breakpoint at line 18."
shell echo "Press Enter to continue..." && read

# Run the program
run
shell echo "Running the program."
shell echo "Press Enter to continue..." && read

# Print the content of large_string[4] with a size of 35
p/x large_string[4]@35
shell echo "Printed content of large_string[4] with size 35."
shell echo "Press Enter to continue..." && read

# Display information about the current function
info frame
shell echo "Displayed information about the current function."
shell echo "Press Enter to continue..." && read

# Print stack content
x/10x $sp
shell echo "Printed stack content."
shell echo "Press Enter to continue..." && read

# Single-step 5 instructions
si 5
shell echo "Stepped through 5 instructions."
shell echo "Press Enter to continue..." && read


# Single-step once before finishing
si
shell echo "Stepped through one instruction before finishing."
shell echo "Press Enter to continue..." && read

# Finish the current function
finish
shell echo "Finishing the current function."
shell echo "Press Enter to continue..." && read

# Print stack content again
x/10x $sp
shell echo "Printed stack content again."
shell echo "Press Enter to continue..." && read

# Single-step 6 more instructions
si 6
shell echo "Stepped through 6 more instructions."
