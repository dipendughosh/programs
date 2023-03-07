class fibo
{
        public static void main(String argv[])
        {
                int n=Integer.parseInt(argv[0]);
                int i,a=0,b=1,c;
                System.out.print(a+","+b);
                for(i=2;i<n;i++)
                {
                        c=a+b;
                        a=b;
                        b=c;
                        System.out.print(","+c);
                }
        }
}
