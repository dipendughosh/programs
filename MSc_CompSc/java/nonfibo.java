class nonfibo
{
        public static void main(String argv[])
        {
                int n=Integer.parseInt(argv[0]);
                int i,j,a=0,b=1,c;
                for(i=2;i<n;i++)
                {
                        for(j=a+1;j<b;j++)
                        {
                                System.out.print(","+j);
                        }
                        c=a+b;
                        a=b;
                        b=c;
                }
        }
}
