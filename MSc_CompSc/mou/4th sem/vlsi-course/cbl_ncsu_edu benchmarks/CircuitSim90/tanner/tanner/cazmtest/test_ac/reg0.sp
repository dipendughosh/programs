*Title - Hybrid-Pi model of 3.3 Volt Regulator
VIN	 5	 0	2.5  ac     1
GM1	 9	 10      8	10	-3.85 
GM2	 10	 12	 12	11	-115
GM3	 3	 4	 4	2	-0.265	
GM4	 9	 4	 6	4	 0.265	
GM5	 4	 0	 0	13	-0.529	
GM6	 14	 0	 15	0	 0.529
RL  12  0  5 
CL  12  0  100U 

CPI2  11  12  0.2U 
RX2  9  11  0.45 
RMU2  11  10  0.5MEG 
RO3  3  4  1.5MEG 
RO4  9  4  1.5MEG 
RO5  4  0  1.5MEG 
RO6  14  0  1.5MEG 
RX5  14  13  100 
RX6  15  14  100 
R4  7  0  1000 
R2  10  3  150 
RPI1  10  8  195 
RO1  10  9  1MEG 
RO2  10  12  1MEG 
RMU1  8  9  1MEG 
RMU3  2  3  2.27MEG 
RMU4  9  6  2.27MEG 
RMU5  13  4  2.27MEG 
RMU6  14  15  2.27MEG 
RPI2  11  12  2.30 
CPI3  2  4  207P 
CPI1  10  8  2440P 
CPI4  6  4  270P 
RPI5  13  0  283 
RPI6  15  0  283 
R1  10  14  300 
CMU1  8  9  300P 
R3  12  7  332 
CPI5  13  0  417P 
CPI6  15  0  417P 
CMU3  2  3  4P 
CMU4  9  6  4P 
CMU5  13  4  4P 
CMU6  14  15  4P 
RX1  3  8  5 
RI  5  1  50
RPI3  2  4  567 
RPI4  6  4  567 
CMU2  11  10  600P 
RX3 1 2  83 
RX4 6 7  83 
.ac dec 50 .1 100MEG
.options limpts=10000
.print ac vm(12)
.end
