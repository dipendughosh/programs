
import java.io.*;

class CALENDAR
{   void main()throws IOException
    {	
        InputStreamReader reader=new InputStreamReader(System.in);
        BufferedReader input=new BufferedReader(reader);
        
        System.out.println("Enter the year::");
        String v1=input.readLine();
        int year=Integer.parseInt(v1);
        
        System.out.println("Enter 2 for month.Enter 1 for all the months::");
        String v4=input.readLine();
        int optionm=Integer.parseInt(v4);
        
        System.out.println("Enter the month::");
        String v2=input.readLine();
        int month=Integer.parseInt(v2);
        
        System.out.println("Enter 1 for horizontal print & 2 for vertical print::");
        String v3=input.readLine();
        int option=Integer.parseInt(v3);
        
        int fac,p,m,date,j,e_month=0,e_day=0,n,c,k,i1,j1,l,esday=0,gfday=0;
        
        System.out.println("YEAR::"+year);
        switch(year)
        {   case 2005:
                System.out.println("INTERNATIONAL YEAR OF MICROCREDIT");    	
                System.out.println("INTERNATIONAL YEAR OF PHYSICS");   
                System.out.println("INTERNATIONAL YEAR OF SPORTS AND PHYSICAL EDUCATION");   
            break;
            case 2006:
                System.out.println("INTERNATIONAL YEAR OF DESERTS AND DESERTIFICATION");   
            break;
        }
        for(month=month;month<=12;month=month+1)
        {   j=1;
            switch(month)
            {   case 1:
                    System.out.println("JANUARY");   
                break;
                case 2:
                    System.out.println("FEBRUARY");   
                break;    
                case 3:
                    System.out.println("MARCH");   
                break;
                case 4:
                    System.out.println("APRIL");   
                break;
                case 5:
                    System.out.println("MAY");   
                break;
                case 6:
                    System.out.println("JUNE");   
                break;
                case 7:
                    System.out.println("JULY");   
                break;
                case 8:
                    System.out.println("AUGUST");   
                break;
                case 9:
                    System.out.println("SEPTEMBER");   
                break;
                case 10:
                    System.out.println("OCTOBER");   
                break;
                case 11:
                    System.out.println("NOVEMBER");   
                break;
                case 12:
                    System.out.println("DECEMBER");   
                break;
                default:
                    System.out.println("Wrong month");   
            }
            m=31;
            if(month==4 || month==6 || month==9 || month==11)
                m=30;
            if(month==2)
            {   if(year%4==0 && year%100!=0 || year%400==0)
                    m=29;
                else
                    m=28;
            }
            if(month==3|| month==4)
            {   c=year/100;
                n=year-19*(year/19);
                k=(c-17)/25;
                i1=c-c/4-(c-k)/3+19*n+15;
                i1=i1-30*(i1/30);
                i1=i1-(i1/28)*(1-(i1/28)*(29/(i1+1))*((21-n)/11));
                j1=year+year/4+i1+2-c+c/4;
                j1=j1-7*(j1/7);
                l=i1-j1;
                e_month=3+(l+40)/44;
                e_day=l+28-31*(e_month/4);
                esday=e_day-1;
                gfday=e_day-2;
            }
            for(int i=1;i<=m;i=i+1)
            {   date=i;
                fac=0;
                fac=year+(month-14)/12;
                p=((13*(month+10-(month+10)/13*12)-1)/5+date+77+5*(fac%100)/4+fac/400-fac/100*2)%7+1;
                switch(p)
                {   case 2:
                        System.out.print(i+"Mon");
                    break;    
                    case 3:
                        System.out.print(i+"Tue");
                    break; 
                    case 4:
                        System.out.print(i+"Wed");
                    break; 
                    case 5:
                        System.out.print(i+"Thu");
                    break; 
                    case 6:
                        System.out.print(i+"Fri");
                    break; 
                    case 7:
                        System.out.print(i+"Sat");
                    break; 
                    case 1:
                        System.out.print(i+"Sun");
                    break; 
                    default:
                        System.out.print("You have entered wrong data");
                }
                if(option==2)
                {   switch(month)
                    {   case 1:
                            switch(date)
                            {   case 1:
                                    System.out.print("[Acharya S N Bose's Birthday]");
                                break; 
                                case 16:
                                    System.out.print("[Martin Luther King's Birthday]");
                                break; 
                                case 12:
                                    System.out.print("[Swamiji's Birthday]");
                                break; 
                                case 26:
                                    System.out.print("[Republic Day]");
                                break; 
                                case 23:
                                    System.out.print("[Netaji's Birthday]");
                                break; 
                            }
                        break;
                        case 2:
                            if(date==17)
                                System.out.print("[Rama Krishna's Birthday]");    
                        break;
                        case 3:
                            if(e_month==3 && date==e_day)
                                System.out.print("[Easter Day]");
                            else if(e_month==3 && date==esday)
                                System.out.print("[Easter Saturday]");
                            else if(e_month==3 && date==gfday)
                                System.out.print("[Good Friday]");    
                            else 
                                switch(date)
                                {   case 8:
                                        System.out.print("[INTERNATIONAL Day for Women's Rights and INTERNATIONAL Peace]");
                                    break;
                                    case 21:
                                        System.out.print("[INTERNATIONAL Day for Elemination of Racial Discrimination]");
                                    break;
                                    case 22:
                                        System.out.print("[INTERNATIONAL Day for Water]");
                                    break;
                                    case 14:
                                        System.out.print("[Einstine's birthday]");
                                    break;
                                }
                        break;
                        case 4:
                            if(e_month==4 && date==e_day)
                                System.out.print("[Easter Day]");
                            else if(e_month==4 && date==esday)
                                System.out.print("[Easter Saturday]");
                            else if(e_month==4 && date==gfday)
                                System.out.print("[Good Friday]");    
                            else if(date==7)
                                System.out.print("[INTERNATIONAL Health Day]");
                        break;
                        case 5:
                            if(date==9)
                                System.out.print("[Tagore's birthday]");
                            else if(date==1)
                                System.out.print("[May Day]");
                            else if(date==8)
                                System.out.print("[Mother's Day]");
                            else if(date==15)
                                System.out.print("[Buddha Purnima]");
                        break;
                        case 6:
                            if(date==5)
                                System.out.print("[World Environmental Day]");
                        break;
                        case 7:
                            if(date==1)
                                System.out.print("[Birth day and Death day of Dr.B.C.Roy]");
                        break;
                        case 8:
                            if(date==15)
                                System.out.print("[INDEPENDENCE Day]");
                        break;
                        case 9:
                            if(date==5)
                                System.out.print("[Teacher's Day]");
                        break;
                        case 10:
                            if(date==2)
                                System.out.print("[Gandhiji's birthday]");
                            else if(date==16)
                                System.out.print("[INERNATIONAL Day for Food]");
                        break;
                        case 11:
                            if(date==14)
                                System.out.print("[Children's Day]");
                            else if(date==15)
                                System.out.print("[Guru Nanak's birthday]");
                        break;
                        case 12:
                            if(date==25)
                                System.out.print("[Christmas Day]");
                            else if(date==22)
                                System.out.print("[Sarada Devi's birthday]");
                            else if(date==1)
                                System.out.print("[World AIDS Day]");
                        break;
                    }
                } 
                if(option==2)
                {   System.out.println();
                }
                else if(option==1)
                {   if(date<9)
                    {   System.out.print(" ");
                        System.out.print(" ");
                    }
                    else
                        System.out.print(" ");
                    j+=1;
                    if(j>7)
                    {   System.out.println();
                        j=1;
                    }
                }
            }
            System.out.println("");
            if(option==1)
            {   System.out.println("Memorable Date(s)");
                for(int i=1;i<=m;i=i+1)
                {   date=i;
                    switch(month)
                    {   case 1:
                            switch(date)
                            {   case 1:
                                    System.out.println(i+"[Acharya S N Bose's Birthday]");
                                break; 
                                case 16:
                                    System.out.println(i+"[Martin Luther King's Birthday]");
                                break; 
                                case 12:
                                    System.out.println(i+"[Swamiji's Birthday]");
                                break; 
                                case 26:
                                    System.out.println(i+"[Republic Day]");
                                break; 
                                case 23:
                                    System.out.println(i+"[Netaji's Birthday]");
                                break; 
                            }
                        break;
                        case 2:
                            if(date==17)
                                System.out.println(i+"[Rama Krishna's Birthday]");    
                        break;
                        case 3:
                            if(e_month==3 && date==e_day)
                                System.out.println(i+"[Easter Day]");
                            else if(e_month==3 && date==esday)
                                System.out.println(i+"[Easter Saturday]");
                            else if(e_month==3 && date==gfday)
                                System.out.println(i+"[Good Friday]");    
                            else 
                                switch(date)
                                {   case 8:
                                        System.out.println(i+"[INTERNATIONAL Day for Women's Rights and INTERNATIONAL Peace]");
                                    break;
                                    case 21:
                                        System.out.println(i+"[INTERNATIONAL Day for Elemination of Racial Discrimination]");
                                    break;
                                    case 22:
                                        System.out.println(i+"[INTERNATIONAL Day for Water]");
                                    break;
                                    case 14:
                                        System.out.println(i+"[Einstine's birthday]");
                                    break;
                                }
                        break;
                        case 4:
                            if(e_month==4 && date==e_day)
                                System.out.println(i+"[Easter Day]");
                            else if(e_month==4 && date==esday)
                                System.out.println(i+"[Easter Saturday]");
                            else if(e_month==4 && date==gfday)
                                System.out.println(i+"[Good Friday]");    
                            else if(date==7)
                                System.out.println(i+"[INTERNATIONAL Health Day]");
                        break;
                        case 5:
                            if(date==9)
                                System.out.println(i+"[Tagore's birthday]");
                            else if(date==1)
                                System.out.println(i+"[May Day]");
                            else if(date==8)
                                System.out.println(i+"[Mother's Day]");
                            else if(date==15)
                                System.out.println(i+"[Buddha Purnima]");
                        break;
                        case 6:
                            if(date==5)
                                System.out.println(i+"[World Environmental Day]");
                        break;
                        case 7:
                            if(date==1)
                                System.out.println(i+"[Birth day and Death day of Dr.B.C.Roy]");
                        break;
                        case 8:
                            if(date==15)
                                System.out.println(i+"[INDEPENDENCE Day]");
                        break;
                        case 9:
                            if(date==5)
                                System.out.println(i+"[Teacher's Day]");
                        break;
                        case 10:
                            if(date==2)
                                System.out.println(i+"[Gandhiji's birthday]");
                            else if(date==16)
                                System.out.println(i+"[INERNATIONAL Day for Food]");
                        break;
                        case 11:
                            if(date==14)
                                System.out.println(i+"[Children's Day]");
                            else if(date==15)
                                System.out.println(i+"[Guru Nanak's birthday]");
                        break;
                        case 12:
                            if(date==25)
                                System.out.println(i+"[Christmas Day]");
                            else if(date==22)
                                System.out.println(i+"[Sarada Devi's birthday]");
                            else if(date==1)
                                System.out.println(i+"[World AIDS Day]");
                        break;
                    }
                }  
            }
            if(optionm==1)
                continue;
            else if(optionm==2)
                break;
        }
    }
}