18 :- #include<iostream>
17 :- #include<fstream>
16 :- #include<math.h>
18 :- #include<string.h>
0 :- 
20 :- using namespace std;
0 :- 
27 :- class ConvertFromPPMBtoPPMA
1 :- {
9 :- 	private:
18 :- 		FILE *fin,*fout;
8 :- 	public:
25 :- 		ConvertFromPPMBtoPPMA()
3 :- 		{
3 :- 		}
1 :- 	
19 :- 		void openFiles();
19 :- 		void readwrite();
20 :- 		void closeFiles();
23 :- 		int convert(char []);
0 :- 
26 :- 		~ConvertFromPPMBtoPPMA()
3 :- 		{
3 :- 		}
2 :- };
0 :- 
39 :- void ConvertFromPPMBtoPPMA::openFiles()
1 :- {
58 :- 	/*fin=fopen("C:\\images\\MATLAB Screenshot(b).ppm","rb");
60 :- 	fin=fopen("C:\\images\\MATLAB Screenshot(acpp).ppm","w");*/
39 :- 	fin=fopen("C:\\images\\03b.ppm","rb");
44 :- 	fout=fopen("C:\\images\\03(acpp).ppm","w");
1 :- }
0 :- 
39 :- void ConvertFromPPMBtoPPMA::readwrite()
1 :- {
11 :- 	int i = 0;
11 :- 	int j = 0;
18 :- 	int charCntr = 0;
11 :- 	char s[2];
12 :- 	char c[10];
18 :- 	char h[10],w[10];
15 :- 	char intn[10];
14 :- 	int ht,wt,it;
0 :- 
17 :- 	cout<<"Start\n";
0 :- 
12 :- 	while(true)
2 :- 	{
23 :- 		fscanf(fin,"%s\n",c);
28 :- 		if(c[0]!='#' && c[0]!=' ')
9 :- 			break;
2 :- 	}
1 :- 	
12 :- 	while(true)
2 :- 	{
21 :- 		fscanf(fin,"%s",h);
28 :- 		if(h[0]!='#' && h[0]!=' ')
9 :- 			break;
2 :- 	}
15 :- 	ht=convert(h);
1 :- 	
12 :- 	while(true)
2 :- 	{
23 :- 		fscanf(fin,"%s\n",w);
28 :- 		if(w[0]!='#' && w[0]!=' ')
9 :- 			break;
2 :- 	}
15 :- 	wt=convert(w);
0 :- 
12 :- 	while(true)
2 :- 	{
26 :- 		fscanf(fin,"%s\n",intn);
34 :- 		if(intn[0]!='#' && intn[0]!=' ')
9 :- 			break;
2 :- 	}
18 :- 	it=convert(intn);
0 :- 
47 :- 	fprintf(fout,"%s\n%s %s\n%s\n","P3",h,w,intn);
1 :- 	
21 :- 	for(i=0;i<4*ht;i++) 
2 :- 	{
19 :- 		for(j=0;j<wt;j++)
4 :- 		{	
18 :- 			fgets(s,2,fin);
14 :- 			if(s=="\n")
4 :- 			{
19 :- 				fgets(s,2,fin);
4 :- 			}
14 :- 			charCntr++;
0 :- 
20 :- 			if(charCntr > 24)
4 :- 			{
28 :- 				fprintf(fout,"%s","\n");
15 :- 				charCntr=0;
4 :- 			}
35 :- 			if((int)s == 10 || (int)s == 32)
4 :- 			{
18 :- 				fputs(s,fout);
4 :- 			}
7 :- 			else
4 :- 			{
19 :- 				if((int)s[0]<0)
5 :- 				{
40 :- 					fprintf(fout,"%d ",(int)s[0]+it+1);
5 :- 				}
8 :- 				else
5 :- 				{
35 :- 					fprintf(fout,"%d ",(int)s[0]);
5 :- 				}
4 :- 			}
3 :- 		}
2 :- 	}
3 :- 			
18 :- 	cout<<"Finish\n";
1 :- }
0 :- 
44 :- int ConvertFromPPMBtoPPMA::convert(char a[])
1 :- {
23 :- 	int len,i,n=0,b,x=0,c;
0 :- 
15 :- 	len=strlen(a);
0 :- 
24 :- 	for(i=(len-1);i>=0;i--)
3 :- 	{	
9 :- 		b=a[i];
9 :- 		b=b-48;
18 :- 		c=(pow(10,x))*b;
8 :- 		n=n+c;
6 :- 		x++;
2 :- 	}
11 :- 	return(n);
1 :- }
0 :- 
40 :- void ConvertFromPPMBtoPPMA::closeFiles()
1 :- {
13 :- 	fclose(fin);
14 :- 	fclose(fout);
1 :- }
0 :- 
11 :- void main()
1 :- {
26 :- 	ConvertFromPPMBtoPPMA ob;
16 :- 	ob.openFiles();
16 :- 	ob.readwrite();
17 :- 	ob.closeFiles();
1 :- }
0 :- 
