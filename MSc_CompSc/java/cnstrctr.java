class constr
{
        int n;
        public constr()
        {
                System.out.println("Non parameterized constructor Called");
                n=5;
        }
        public constr(int x)
        {
                System.out.println("Parameterized constructor Called");
                n=x;
        }

        public void output()
        {
                System.out.print("Output Called "+n+"\n");
        }
        
}

class Mainc
{
        public static void main(String argv[])
        {
                int x;
                constr c1=new constr();
                c1.output();
                x=Integer.parseInt(argv[0]);
                constr c2=new constr(x);
                c2.output();
        }

}

