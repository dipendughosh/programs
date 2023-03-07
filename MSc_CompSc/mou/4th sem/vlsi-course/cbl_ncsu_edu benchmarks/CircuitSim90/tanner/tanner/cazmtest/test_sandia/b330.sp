mspice driven run, uid = 230119c7.00000419                                    
.model pmod pmos(                                                               
+ vto        = -1.26e+00                                                        
+ uo         =  1.68e+02                                                        
+ kappa      =  2.00e-02                                                        
+ eta        =  2.02e+00                                                        
+ theta      =  7.77e-02                                                        
+ vmax       =  7.95e+05                                                        
+ delta      =  7.03e-01                                                        
+ nsub       =  2.39e+15                                                        
+ tox        =  4.50e-08                                                        
+ tpg        = -1.00e+00                                                        
+ xj         =  6.00e-07                                                        
+ js         =  1.000e-07     cj=     1.300e-04     pb=    0.900e-00            
+ rs         =  6.920e+00     rd=     6.920e+00                                 
+ rsh        =  1.290e+02     level=3)                                          
* seq. #:   50 process: b4506ap 3153 wafer: 18 loc: 18; 51 date: 10jan83        
.model nmod nmos(                                                               
+ vto        =  9.25e-01                                                        
+ uo         =  6.34e+02                                                        
+ kappa      =  2.00e-02                                                        
+ eta        =  1.45e+00                                                        
+ theta      =  6.96e-02                                                        
+ vmax       =  3.66e+05                                                        
+ delta      =  7.23e+00                                                        
+ nsub       =  3.43e+16                                                        
+ tox        =  4.50e-08                                                        
+ tpg        =  1.00e+00                                                        
+ xj         =  6.00e-07                                                        
+ js         =  1.000e-07     cj=     4.000e-04     pb=    0.920e-00            
+ rs         =  4.750e+00     rd=     4.750e+00                                 
+ rsh        =  3.650e+01     level=3)                                          
* seq. #:   25 process: b3908an 3123 wafer: 19 loc: 13; 87 date: 14may82        
.model dnpw d(cjo 4.0e-4 vj 0.92 is 1.0e-7 n 3.17)                              
.model dppn d(cjo 1.3e-4 vj 0.90 is 1.0e-7 n 3.42)                              
v$d33  114 0 dc 5.0                                                             
v$d32  115 0 dc 5.0                                                             
v$d31  116 0 dc 5.0                                                             
v$d30  117 0 dc 5.0                                                             
v$d29  118 0 dc 5.0                                                             
v$d28  119 0 dc 5.0                                                             
v$d27  120 0 dc 5.0                                                             
v$d26  121 0 dc 5.0                                                             
v$d25  122 0 dc 5.0                                                             
v$d24  123 0 dc 5.0                                                             
v$d23  124 0 dc 0.0                                                             
v$d22  125 0 dc 5.0                                                             
v$d21  126 0 dc 0.0                                                             
v$d20  127 0 dc 5.0                                                             
v$d19  128 0 dc 0.0                                                             
v$d18  129 0 dc 0.0                                                             
v$d17  130 0 dc 5.0                                                             
v$d16  131 0 dc 0.0                                                             
v$d15  132 0 dc 5.0                                                             
v$d14  133 0 dc 0.0                                                             
v$d13  144 0 dc 5.0                                                             
v$d12  145 0 dc 0.0                                                             
v$d11  146 0 dc 5.0                                                             
v$d10  147 0 dc 0.0                                                             
v$d9  148 0 dc 5.0                                                              
v$d8  149 0 dc 5.0                                                              
v$d7  150 0 dc 0.0                                                              
v$d6  151 0 dc 5.0                                                              
v$d5  152 0 dc 0.0                                                              
v$d4  153 0 dc 5.0                                                              
v$d3  113 0 pulse(0.0 5.0 1.0e-9 5.0e-9 5.0e-9 2.0e-8 6.0e-8)                   
v$d2  42 0 pulse(0.0 5.0 4.5e-8 5.0e-9 5.0e-9 8.0e-8 1.6e-7)                    
v$d1  41 0 dc 5.0                                                               
m$830 163 102 1 41 pmod w=56u l=3u ad=504p as=504p                        
m$829 52 2 1 41 pmod w=56u l=3u ad=504p as=504p                           
m$828 143 102 3 41 pmod w=56u l=3u ad=504p as=504p                        
m$827 82 4 3 41 pmod w=56u l=3u ad=504p as=504p                           
m$826 162 100 5 41 pmod w=56u l=3u ad=504p as=504p                        
m$825 50 6 5 41 pmod w=56u l=3u ad=504p as=504p                           
m$824 142 100 7 41 pmod w=56u l=3u ad=504p as=504p                        
m$823 80 8 7 41 pmod w=56u l=3u ad=504p as=504p                           
m$822 161 99 9 41 pmod w=56u l=3u ad=504p as=504p                         
m$821 49 10 9 41 pmod w=56u l=3u ad=504p as=504p                          
m$820 141 99 11 41 pmod w=56u l=3u ad=504p as=504p                        
m$819 79 12 11 41 pmod w=56u l=3u ad=504p as=504p                         
m$818 160 98 13 41 pmod w=56u l=3u ad=504p as=504p                        
m$817 48 14 13 41 pmod w=56u l=3u ad=504p as=504p                         
m$816 140 98 15 41 pmod w=56u l=3u ad=504p as=504p                        
m$815 78 16 15 41 pmod w=56u l=3u ad=504p as=504p                         
m$814 159 97 17 41 pmod w=56u l=3u ad=504p as=504p                        
m$813 47 18 17 41 pmod w=56u l=3u ad=504p as=504p                         
m$812 139 97 19 41 pmod w=56u l=3u ad=504p as=504p                        
m$811 77 20 19 41 pmod w=56u l=3u ad=504p as=504p                         
m$810 158 96 21 41 pmod w=56u l=3u ad=504p as=504p                        
m$809 46 22 21 41 pmod w=56u l=3u ad=504p as=504p                         
m$808 138 96 23 41 pmod w=56u l=3u ad=504p as=504p                        
m$807 76 24 23 41 pmod w=56u l=3u ad=504p as=504p                         
m$806 157 95 25 41 pmod w=56u l=3u ad=504p as=504p                        
m$805 45 26 25 41 pmod w=56u l=3u ad=504p as=504p                         
m$804 137 95 27 41 pmod w=56u l=3u ad=504p as=504p                        
m$803 75 28 27 41 pmod w=56u l=3u ad=504p as=504p                         
m$802 156 94 29 41 pmod w=56u l=3u ad=504p as=504p                        
m$801 44 30 29 41 pmod w=56u l=3u ad=504p as=504p                         
m$800 136 94 31 41 pmod w=56u l=3u ad=504p as=504p                        
m$799 74 32 31 41 pmod w=56u l=3u ad=504p as=504p                         
m$798 155 93 33 41 pmod w=56u l=3u ad=504p as=504p                        
m$797 43 34 33 41 pmod w=56u l=3u ad=504p as=504p                         
m$796 135 93 35 41 pmod w=56u l=3u ad=504p as=504p                        
m$795 73 36 35 41 pmod w=56u l=3u ad=504p as=504p                         
m$794 154 101 37 41 pmod w=56u l=3u ad=504p as=504p                       
m$793 51 38 37 41 pmod w=56u l=3u ad=504p as=504p                         
m$792 134 101 39 41 pmod w=56u l=3u ad=504p as=504p                       
m$791 81 40 39 41 pmod w=56u l=3u ad=504p as=504p                         
m$790 114 71 81 41 pmod w=56u l=3u ad=504p as=504p                        
m$789 124 61 81 41 pmod w=56u l=3u ad=504p as=504p                        
m$788 115 63 73 41 pmod w=56u l=3u ad=504p as=504p                        
m$787 125 53 73 41 pmod w=56u l=3u ad=504p as=504p                        
m$786 116 64 74 41 pmod w=56u l=3u ad=504p as=504p                        
m$785 126 54 74 41 pmod w=56u l=3u ad=504p as=504p                        
m$784 117 65 75 41 pmod w=56u l=3u ad=504p as=504p                        
m$783 127 55 75 41 pmod w=56u l=3u ad=504p as=504p                        
m$782 118 66 76 41 pmod w=56u l=3u ad=504p as=504p                        
m$781 128 56 76 41 pmod w=56u l=3u ad=504p as=504p                        
m$780 119 67 77 41 pmod w=56u l=3u ad=504p as=504p                        
m$779 129 57 77 41 pmod w=56u l=3u ad=504p as=504p                        
m$778 120 68 78 41 pmod w=56u l=3u ad=504p as=504p                        
m$777 130 58 78 41 pmod w=56u l=3u ad=504p as=504p                        
m$776 121 69 79 41 pmod w=56u l=3u ad=504p as=504p                        
m$775 131 59 79 41 pmod w=56u l=3u ad=504p as=504p                        
m$774 122 70 80 41 pmod w=56u l=3u ad=504p as=504p                        
m$773 132 60 80 41 pmod w=56u l=3u ad=504p as=504p                        
m$772 123 72 82 41 pmod w=56u l=3u ad=504p as=504p                        
m$771 133 62 82 41 pmod w=56u l=3u ad=504p as=504p                        
m$770 163 2 1 0 nmod w=23u l=3u ad=207p as=207p                           
m$769 52 102 1 0 nmod w=23u l=3u ad=207p as=207p                          
m$768 143 4 3 0 nmod w=23u l=3u ad=207p as=207p                           
m$767 82 102 3 0 nmod w=23u l=3u ad=207p as=207p                          
m$766 162 6 5 0 nmod w=23u l=3u ad=207p as=207p                           
m$765 50 100 5 0 nmod w=23u l=3u ad=207p as=207p                          
m$764 142 8 7 0 nmod w=23u l=3u ad=207p as=207p                           
m$763 80 100 7 0 nmod w=23u l=3u ad=207p as=207p                          
m$762 161 10 9 0 nmod w=23u l=3u ad=207p as=207p                          
m$761 49 99 9 0 nmod w=23u l=3u ad=207p as=207p                           
m$760 141 12 11 0 nmod w=23u l=3u ad=207p as=207p                         
m$759 79 99 11 0 nmod w=23u l=3u ad=207p as=207p                          
m$758 160 14 13 0 nmod w=23u l=3u ad=207p as=207p                         
m$757 48 98 13 0 nmod w=23u l=3u ad=207p as=207p                          
m$756 140 16 15 0 nmod w=23u l=3u ad=207p as=207p                         
m$755 78 98 15 0 nmod w=23u l=3u ad=207p as=207p                          
m$754 159 18 17 0 nmod w=23u l=3u ad=207p as=207p                         
m$753 47 97 17 0 nmod w=23u l=3u ad=207p as=207p                          
m$752 139 20 19 0 nmod w=23u l=3u ad=207p as=207p                         
m$751 77 97 19 0 nmod w=23u l=3u ad=207p as=207p                          
m$750 158 22 21 0 nmod w=23u l=3u ad=207p as=207p                         
m$749 46 96 21 0 nmod w=23u l=3u ad=207p as=207p                          
m$748 138 24 23 0 nmod w=23u l=3u ad=207p as=207p                         
m$747 76 96 23 0 nmod w=23u l=3u ad=207p as=207p                          
m$746 157 26 25 0 nmod w=23u l=3u ad=207p as=207p                         
m$745 45 95 25 0 nmod w=23u l=3u ad=207p as=207p                          
m$744 137 28 27 0 nmod w=23u l=3u ad=207p as=207p                         
m$743 75 95 27 0 nmod w=23u l=3u ad=207p as=207p                          
m$742 156 30 29 0 nmod w=23u l=3u ad=207p as=207p                         
m$741 44 94 29 0 nmod w=23u l=3u ad=207p as=207p                          
m$740 136 32 31 0 nmod w=23u l=3u ad=207p as=207p                         
m$739 74 94 31 0 nmod w=23u l=3u ad=207p as=207p                          
m$738 155 34 33 0 nmod w=23u l=3u ad=207p as=207p                         
m$737 43 93 33 0 nmod w=23u l=3u ad=207p as=207p                          
m$736 135 36 35 0 nmod w=23u l=3u ad=207p as=207p                         
m$735 73 93 35 0 nmod w=23u l=3u ad=207p as=207p                          
m$734 154 38 37 0 nmod w=23u l=3u ad=207p as=207p                         
m$733 51 101 37 0 nmod w=23u l=3u ad=207p as=207p                         
m$732 134 40 39 0 nmod w=23u l=3u ad=207p as=207p                         
m$731 81 101 39 0 nmod w=23u l=3u ad=207p as=207p                         
m$730 153 72 52 0 nmod w=23u l=3u ad=207p as=207p                         
m$729 152 70 50 0 nmod w=23u l=3u ad=207p as=207p                         
m$728 151 69 49 0 nmod w=23u l=3u ad=207p as=207p                         
m$727 150 68 48 0 nmod w=23u l=3u ad=207p as=207p                         
m$726 149 67 47 0 nmod w=23u l=3u ad=207p as=207p                         
m$725 148 66 46 0 nmod w=23u l=3u ad=207p as=207p                         
m$724 147 65 45 0 nmod w=23u l=3u ad=207p as=207p                         
m$723 146 64 44 0 nmod w=23u l=3u ad=207p as=207p                         
m$722 145 63 43 0 nmod w=23u l=3u ad=207p as=207p                         
m$721 144 71 51 0 nmod w=23u l=3u ad=207p as=207p                         
m$720 62 72 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$719 72 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$718 102 113 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$717 60 70 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$716 70 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$715 100 113 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$714 59 69 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$713 69 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$712 99 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$711 58 68 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$710 68 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$709 98 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$708 57 67 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$707 67 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$706 97 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$705 56 66 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$704 66 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$703 96 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$702 55 65 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$701 65 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$700 95 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$699 54 64 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$698 64 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$697 94 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$696 53 63 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$695 63 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$694 93 113 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$693 61 71 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$692 71 42 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$691 101 113 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$690 51 61 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$689 43 53 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$688 44 54 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$687 45 55 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$686 46 56 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$685 47 57 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$684 48 58 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$683 49 59 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$682 50 60 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$681 52 62 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$680 40 101 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$679 91 39 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$678 134 91 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$677 38 101 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$676 111 37 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$675 154 111 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$674 36 93 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$673 83 35 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$672 135 83 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$671 34 93 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$670 103 33 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$669 155 103 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$668 32 94 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$667 84 31 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$666 136 84 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$665 30 94 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$664 104 29 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$663 156 104 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$662 28 95 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$661 85 27 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$660 137 85 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$659 26 95 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$658 105 25 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$657 157 105 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$656 24 96 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$655 86 23 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$654 138 86 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$653 22 96 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$652 106 21 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$651 158 106 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$650 20 97 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$649 87 19 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$648 139 87 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$647 18 97 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$646 107 17 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$645 159 107 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$644 16 98 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$643 88 15 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$642 140 88 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$641 14 98 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$640 108 13 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$639 160 108 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$638 12 99 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$637 89 11 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$636 141 89 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$635 10 99 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$634 109 9 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$633 161 109 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$632 8 100 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$631 90 7 41 41 pmod w=56u l=3u ad=504p as=504p                          
m$630 142 90 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$629 6 100 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$628 110 5 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$627 162 110 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$626 4 102 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$625 92 3 41 41 pmod w=56u l=3u ad=504p as=504p                          
m$624 143 92 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$623 2 102 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$622 112 1 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$621 163 112 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$620 153 62 52 41 pmod w=56u l=3u ad=504p as=504p                        
m$619 152 60 50 41 pmod w=56u l=3u ad=504p as=504p                        
m$618 151 59 49 41 pmod w=56u l=3u ad=504p as=504p                        
m$617 150 58 48 41 pmod w=56u l=3u ad=504p as=504p                        
m$616 149 57 47 41 pmod w=56u l=3u ad=504p as=504p                        
m$615 148 56 46 41 pmod w=56u l=3u ad=504p as=504p                        
m$614 147 55 45 41 pmod w=56u l=3u ad=504p as=504p                        
m$613 146 54 44 41 pmod w=56u l=3u ad=504p as=504p                        
m$612 145 53 43 41 pmod w=56u l=3u ad=504p as=504p                        
m$611 144 61 51 41 pmod w=56u l=3u ad=504p as=504p                        
m$610 62 72 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$609 72 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$608 102 113 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$607 60 70 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$606 70 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$605 100 113 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$604 59 69 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$603 69 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$602 99 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$601 58 68 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$600 68 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$599 98 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$598 57 67 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$597 67 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$596 97 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$595 56 66 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$594 66 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$593 96 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$592 55 65 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$591 65 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$590 95 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$589 54 64 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$588 64 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$587 94 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$586 53 63 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$585 63 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$584 93 113 41 41 pmod w=56u l=3u ad=504p as=504p                        
m$583 61 71 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$582 71 42 41 41 pmod w=56u l=3u ad=504p as=504p                         
m$581 101 113 41 41 pmod w=56u l=3u ad=504p as=504p                       
m$580 114 61 81 0 nmod w=23u l=3u ad=207p as=207p                         
m$579 124 71 81 0 nmod w=23u l=3u ad=207p as=207p                         
m$578 115 53 73 0 nmod w=23u l=3u ad=207p as=207p                         
m$577 125 63 73 0 nmod w=23u l=3u ad=207p as=207p                         
m$576 116 54 74 0 nmod w=23u l=3u ad=207p as=207p                         
m$575 126 64 74 0 nmod w=23u l=3u ad=207p as=207p                         
m$574 117 55 75 0 nmod w=23u l=3u ad=207p as=207p                         
m$573 127 65 75 0 nmod w=23u l=3u ad=207p as=207p                         
m$572 118 56 76 0 nmod w=23u l=3u ad=207p as=207p                         
m$571 128 66 76 0 nmod w=23u l=3u ad=207p as=207p                         
m$570 119 57 77 0 nmod w=23u l=3u ad=207p as=207p                         
m$569 129 67 77 0 nmod w=23u l=3u ad=207p as=207p                         
m$568 120 58 78 0 nmod w=23u l=3u ad=207p as=207p                         
m$567 130 68 78 0 nmod w=23u l=3u ad=207p as=207p                         
m$566 121 59 79 0 nmod w=23u l=3u ad=207p as=207p                         
m$565 131 69 79 0 nmod w=23u l=3u ad=207p as=207p                         
m$564 122 60 80 0 nmod w=23u l=3u ad=207p as=207p                         
m$563 132 70 80 0 nmod w=23u l=3u ad=207p as=207p                         
m$562 123 62 82 0 nmod w=23u l=3u ad=207p as=207p                         
m$561 133 72 82 0 nmod w=23u l=3u ad=207p as=207p                         
m$560 40 101 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$559 91 39 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$558 134 91 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$557 38 101 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$556 111 37 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$555 154 111 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$554 36 93 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$553 83 35 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$552 135 83 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$551 34 93 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$550 103 33 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$549 155 103 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$548 32 94 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$547 84 31 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$546 136 84 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$545 30 94 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$544 104 29 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$543 156 104 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$542 28 95 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$541 85 27 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$540 137 85 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$539 26 95 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$538 105 25 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$537 157 105 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$536 24 96 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$535 86 23 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$534 138 86 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$533 22 96 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$532 106 21 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$531 158 106 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$530 20 97 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$529 87 19 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$528 139 87 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$527 18 97 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$526 107 17 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$525 159 107 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$524 16 98 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$523 88 15 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$522 140 88 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$521 14 98 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$520 108 13 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$519 160 108 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$518 12 99 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$517 89 11 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$516 141 89 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$515 10 99 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$514 109 9 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$513 161 109 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$512 8 100 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$511 90 7 0 0 nmod w=23u l=3u ad=207p as=207p                            
m$510 142 90 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$509 6 100 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$508 110 5 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$507 162 110 0 0 nmod w=23u l=3u ad=207p as=207p                         
m$506 4 102 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$505 92 3 0 0 nmod w=23u l=3u ad=207p as=207p                            
m$504 143 92 0 0 nmod w=23u l=3u ad=207p as=207p                          
m$503 2 102 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$502 112 1 0 0 nmod w=23u l=3u ad=207p as=207p                           
m$501 163 112 0 0 nmod w=23u l=3u ad=207p as=207p                         
.opt acct                                                                       
.temp 27.0                                                                      
.print tran v(113) v(154) v(155) v(160) v(161) v(162) v(163)
.plot tran v(42) v(142) v(143)
.tran 6.0e-10 1.2e-7 0.0                                                        
.end                                                                            
