class mainc
{
        int n;
        public void input1()
        {                
                n=5;
                System.out.println("Input with no argument called Called");
        }
        public void input2(int x)
        {
                n=x;
                System.out.println("Input with argument called Called");
        }

        public void output()
        {
                System.out.print("Output Called "+n+"\n");
        }
        public static void main(String argv[])
        {
                int x=Integer.parseInt(argv[0]);
                mainc c1=new mainc();
                c1.input1();
                c1.output();
                mainc c2=new mainc();
                c2.input2(x);
                c2.output();


        }

}

