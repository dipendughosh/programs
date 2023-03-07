#include<stdio.h>

//Power function
//result=x^y
long int powdef(long int x,long int y)
{
    long int i,res=1;
    
	for(i=1;i<=y;i++)
    {
      res=res*x;
    }
    
	return res;
}

//Hash Array to store the hashed key
int hash[10];

//JPake Parameters to be used
struct JPakeParameters
{
      long int p;
      long int g;
};

//JPake User structure variables
struct JPakeUser
{
	  //Must be unique
      const char *name;              
	  //3 for Alice 7 for Bob
      long int base;                 
	  //The shared secret
      long int secret;               
	  //The calculated(shared) Secret
      long int key;                  
	  //Alice's x1 or Bob's x3
      long int xa;                   
	  //Alice's x2 or Bob's x4
      long int xb;                   
	  //Alice's g^x3 or Bob's g^x1
      long int stp1c;                
	  //Alice's g^x4 or Bob's g^x2
      long int stp1d;                
	  //Alice's A or Bob's B
      long int stp2;		
	  
      //Variables for passing the Knowledge Proofs
	  long int r1,c1,s1;
      long int r2,c2,s2;
      long int r3,c3,s3;
	  
	  //For the session key after hashing
      long int sessionk;
};

//Initializing the JPake Parameters
void JPakeParameters_Init(struct JPakeParameters *param)
{
      int i;
      
      for(i=0;i<10;i++)
            hash[i]=-999;
      
      //prime number(p)
      printf("\nEnter a prime number :- ");
      scanf("%d",&param->p);
      //generator(g)
      printf("\nEnter a generator :- ");
      scanf("%d",&param->g);
}

//Changing the base for the JPake User Parameters for proper displaying
void changebase(long int no,long int base)
{
      long int i,b,x=0;
      char stringhold[20];
      
	  //Converting from decimal to the given base
      if(no==0)
      {
          stringhold[x]=(char)(no+48);
          x++;
      }
      else
      {
          while(no!=0)
          {
              b=no%base;
              no=no/base;
              if(b>=0 && b<=9)
              {
                  stringhold[x]=(char)(b+48);
                  x++;
              }
              if(b>9 && b<16)
              {
                  stringhold[x]=(char)(b+55);
                  x++;
              }
          }
      }
      stringhold[x]='\0';
      
      for(i=x-1;i>=0;i--)
          printf("%c",stringhold[i]);
}

//Displaying the JPake User variables
void show(struct JPakeUser *user)
{
      /*printf("\nName\t:\t%s",user->name);
      printf("\nBase\t:\t%d",user->base);
      printf("\nSecret\t:\t");
      changebase(user->secret,user->base);
      printf("\nKey\t:\t");
      changebase(user->key,user->base);
      printf("\nxa\t:\t");
      changebase(user->xa,user->base);
      printf("\nxb\t:\t");
      changebase(user->xb,user->base);
      printf("\nstp1c\t:\t");
      changebase(user->stp1c,user->base);
      printf("\nstp1d\t:\t");
      changebase(user->stp1d,user->base);
      printf("\nstp2\t:\t");
      changebase(user->stp2,user->base);
      printf("\n");*/
      printf("\nName\t:\t%s\nBase\t:\t%ld\nSecret\t:\t%ld\nKey\t:\t%ld\nxa\t:\t%ld\nxb\t:\t%ld\nstp1c\t:\t%ld\nstp1d\t:\t%ld\nstp2\t:\t%ld\nsession key\t:\t%ld\nhash value\t:\t%ld\n",
               user->name,user->base,user->secret,user->key,user->xa,user->xb,user->stp1c,user->stp1d,user->stp2,user->sessionk,hash[user->sessionk]);

}

//To calculate random numbers starting from the given number
long int genrand(long int n)
{
      long int x;
	  
	  //Defining the starting point
      srand(n*rand());
	  //Generating the random number
      x=rand();
      
	  return x;
}

//To select the secret values for the users
//Alice selects x1 and x2
//Bob selects x3 and x4
void genknp(struct JPakeUser *user)
{
	  //If user is Alice the x1 and x2 are selected
      if(strcmp(user->name,"Alice"))
      {
		  do
		  {
				user->xa=genrand(3)%10;
				user->xb=genrand(5)%10;
		  }while(user->xa!=0 && user->xb!=0);
      }
	  //Else If user is Bob the x3 and x4 are selected
      else if(strcmp(user->name,"Bob"))
      {
           do
		  {
				user->xa=genrand(13)%10;
				user->xb=genrand(17)%10;
		  }while(user->xa!=0 && user->xb!=0);
      }
}

//verifier(Alice or Bob,send step,verification step,generator,r,c,s=r+c^x,y=g^x)
long int verifier(long int user,long int ss,long int sss,long int g,long int r,long int c,long int s,long int y)
{
      long int t1,t2,t;
      
	  //For send step 1
      if(ss==1)
      {
		  //Challenge of x1 for Alice or Challenge of x3 for Bob
          if(sss==1)
          {
              if(user==1)
                  c=genrand(29);
              else if(user==2)
                  c=genrand(31);
          }
		  //Challenge of x2 for Alice or Challenge of x4 for Bob
          else if(sss==2)
          {
              if(user==1)
                  c=genrand(37);
              else if(user==2)
                  c=genrand(41);
          }
          
          c=c%10;
          
          return c;
      }
	  //For step 1 send verification
      else if(ss==2)
      {
		  //Checking if g^=t*y^c of x1 and x2 for Alice and Checking if g^=t*y^c of x3 and x4 for Bob  
          t1=powdef(g,s);
          t=powdef(g,r);
          t2=powdef(y,c);
          t2=t2*t;
          
          if(t1==t2)
              return 1;
      }
	  //For send step 2
	  //Challenge of x2*secret for Alice or Challenge of x4*secret for Bob
      else if(ss==3)
      {
          if(user==1)
              c=genrand(51);
          else if(user==2)
              c=genrand(53);
          
          c=c%10;
          
          return c;
      }
	  //For step 2 send verification
      else if(ss==4)
      {
		  //Checking if g^=t*y^c of x2*secret for Alice and Checking if g^=t*y^c of x4*secret for Bob
          t1=powdef(g,s);
          t=powdef(g,r);
          t2=powdef(y,c);
          t2=t2*t;
          
          if(t1==t2)
              return 1;
      }
      return 0;
}

//prover(Alice or Bob,parameters,send step,substep)
void prover(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param,long int ss,long int sss)
{
      long int u,t,r,c,s,y,f;
      
      if(strcmp(from->name,"Alice"))
          u=1;
      else if(strcmp(from->name,"Bob"))
          u=2;
      
	  //Calculating Knowledge Proofs for step 1 send
      if(ss==1)
      {   
		  //Knowledge proof of x1 for Alice or Knowledge proof of x3 for Bob
          if(sss==1)
          {
              if(u==1)
                  r=genrand(7);
              else if(u==2)
                  r=genrand(11);
              
			  //Random number for Commitment by prover
              to->r1=r%10;
              
			  //Random number which is the challange by the verifier 
              to->c1=verifier(u,1,1,0,0,0,0,0);
      
			  //The last message by the prover s=r+c*x
              to->s1=to->r1+to->c1*from->xa;
          }
		  //Knowledge proof of x3 for Alice or Knowledge proof of x4 for Bob
          else if(sss==2)
          {
              if(u==1)
                  r=genrand(43);
              else if(u==2)
                  r=genrand(47);
              
			  //Random number for Commitment by prover
              to->r2=r%10;
              
			  //Random number which is the challange by the verifier 
              to->c2=verifier(u,1,2,0,0,0,0,0);
      
			  //The last message by the prover s=r+c*x
              to->s2=to->r2+to->c2*from->xb;
          }
      }
      //Calculating Knowledge Proofs for step 2 send
	  //Knowledge proof of x2*secret for Alice or Knowledge proof of x4*secret for Bob
	  else if(ss=3)
      {
          if(u==1)
              r=genrand(19);
          else if(u==2)
              r=genrand(23);
          
		  //Random number for Commitment by prover
          to->r3=r%10;
              
		  //Random number which is the challange by the verifier 
          to->c3=verifier(u,3,0,0,0,0,0,0);
      
		 //The last message by the prover s=r+c*x
          to->s3=to->r3+to->c3*from->xb*from->secret;
      }
}

//zkp(Alice or Bob,parameter,send step) 
long int zkp(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param,long int ss)
{
      long int f1=1,f2=1,u;
            
	  //It is step 1 send then calculating the knowlwdge proofs of x1 and x2 for Alice or the knowlwdge proofs of x3 and x4 for Bob 
      if(ss==1)
      {
		  //Knowledge proof for x1 of Alice or knowledge proof for x3 of Bob
          prover(from,to,param,1,1);            
          //Knowledge proof for x1 of Bob or knowledge proof for x3 of Alice
		  prover(from,to,param,1,2);
          
          return 0;
      }
	  //It is the verification of step 1 send then calling verifier to verify if g^s=t*y^c for Alice or Bob
      else if(ss==2)
      {         
          if(strcmp(from->name,"Alice"))
              u=1;
          else if(strcmp(from->name,"Bob"))
              u=2;
          
		  //Verifying the knowledge proof of x1 for Alice or x3 for Bob
          f1=verifier(u,2,0,param->g,to->r1,to->c1,to->s1,to->stp1c);
          //Verifying the knowledge proof of x4 for Alice or x4 for Bob
		  f2=verifier(u,2,0,param->g,to->r2,to->c2,to->s2,to->stp1d);
      
          if(f1==1 && f2==1)
              return 1;
      }
	  //It is step 2 send then calculating the knowlwdge proof of x2*secret for Alice or the knowlwdge proof of x4*secret for Bob 
      else if(ss==3)
      {
		  //Knowlwdge proof of x2*secret for Alice or knowlwdge proof of x4*secret for Bob 
          prover(from,to,param,3,0);
          
          return 0;
      }
	  //It is the verification of step 2 send then calling verifier to verify if g^s=t*y^c for Alice or Bob
      else if(ss==4)
      {
          if(strcmp(from->name,"Alice"))
              u=1;
          else if(strcmp(from->name,"Bob"))
              u=2;
          
		  //Verifying the knowledge proof of x2*secret for Alice or x4*secret for Bob
          f1=verifier(u,4,0,param->g,to->r3,to->c3,to->s3,(from->xb*from->secret));
      
          if(f1==1)
              return 1;
      }
      return 0;
}

//Step 1 Send
//Alice sends g^x1 and g^x2 and zero knowlwdge proofs of x1 and x2 to Bob
//Bob sends g^x3 and g^x4 and zero knowlwdge proofs of x3 and x4 to Alice
void sendstep1(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      long int f=1;
 
	  //Alice sends g^x1 to Bob and Bob sends g^x3 to Alice
      to->stp1c=powdef(param->g,from->xa);
      //Alice sends g^x2 to Bob and Bob sends g^x4 to Alice
	  to->stp1d=powdef(param->g,from->xb);
	  
	  //Alice sends knowledge proofs of x1 and x2 to Bob and Bob sends knowledge proofs of x3 and x4 to Alice
	  f=zkp(from,to,param,1);
}

//Verify step 1 send
//Verifies the step 1 send to check if the transmission was successful
void verifysendstep1(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
	  long int f=1;
      
	  //Verifying the sending of knowledge proofs of x1 and x2 by Alice to Bob or knowledge proofs of x3 and x4 by Bob to Alice 
	  f=zkp(from,to,param,2);
      
      if(f2==1)
          printf("\nStep 1 successful\n");
      else
      {
          printf("\nStep 1 Fail\nExitting\n");
          exit(0);
      }
}

//Step 2 Send
//Alice sends A=g^{(x1+x3+x4)*x2*secret} and zero knowlwdge proof of x2*secret to Bob
//Bob sends B=g^{(x1+x2+x3)*x4*secret} and zero knowlwdge proof of x4*secret to Alice
void sendstep2(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      long int f=1;
      
	  //Alice sends A=g^{(x1+x3+x4)*x2*secret} to Bob and Bob sends B=g^{(x1+x2+x3)*x4*secret} to Alice
      to->stp2=(powdef(param->g,from->xa)*from->stp1c*from->stp1d);
      to->stp2=powdef(to->stp2,from->xb*from->secret)%10;
	  
	  //Alice sends knowledge proof of x2*secret to Bob and Bob sends knowledge proof of x4*secret to Alice
	  f=zkp(from,to,param,3);
}

//Verify step 2 send
//Verifies the step 2 send to check if the transmission was successful
void verifysendstep2(struct JPakeUser *from,struct JPakeUser *to,struct JPakeParameters *param)
{
      long int f=1;
  
	  //Verifying the sending of knowledge proof of x2*secret by Alice to Bob or knowledge proof of x4*secret by Bob to Alice 
      f=zkp(from,to,param,4);
      
      if(f==1)
          printf("\nStep 2 successful\n");
      else
      {
          printf("\nStep 2 Fail\nExitting\n");
          //exit(0);
      }
}

//Computeing the keys for Alice and Bob after step 1 send and step 2 send are successful 
void compute_key(struct JPakeUser *user,struct JPakeParameters *param)
{
	  float temp;
      
	  //For Alice K=(B/g^{x2*x4*secret})^x2
	  //For Bob K=(A/g^{x2*x4*secret})^x4
	  temp=powdef(user->stp1d,(user->xb*user->secret));
      temp=user->stp2/temp;
      user->key=powdef(temp,user->xb);
}

//Hashing the computed keys to their positions in the hash table
void hashing(struct JPakeUser *user)
{
      long int k=user->key,i,s;
      
	  //Using sum of digits until it is between 0 and 10
      while(k>10)
      {
            s=0;
            while(k>0)
            {
                  s=s+k%10;
                  k=k/10;
            }
            k=s;
      }
      
	  //Finding the appropriate hashed position in the hash table
      do
      {
            if(hash[k]==-999)
            {
                   hash[k]=user->key;
                   user->sessionk=k;
                   break;
            }
            else
                   k++;
      }while(1);
}

int main()
{       
      //Declaring the structure variables for the parameters and the uers
	  struct JPakeParameters param;
      struct JPakeUser alice,bob;
      
	  //Initializing the parameters
      JPakeParameters_Init(&param);
      
	  //Initializing the variables for user Alice
      alice.name = "Alice";
      alice.base=5;
      alice.key=0;
      
	  //Initializing the variables for user Bob      
      bob.name = "Bob";
      bob.base=7;
      bob.key=0;
      
	  //The secret key for the users are created and shared by both the users
      alice.secret=genrand(1)%10;
      bob.secret=alice.secret;
      
      //Generate secret values for Alice and Bob
      
      //Alice's x1 and x2
      genknp(&alice);
      
      //Bob's x3 and x4
      genknp(&bob);
      
      //Step 1 send
      sendstep1(&alice,&bob,&param);
      sendstep1(&bob,&alice,&param);
	
	  //Verify step 1 send
      verifysendstep1(&alice,&bob,&param);
      verifysendstep1(&bob,&alice,&param);
	  
      //Step 2 send
      sendstep2(&alice,&bob,&param);
      sendstep2(&bob,&alice,&param);

	  //Verify step 2 send
      verifysendstep2(&alice,&bob,&param);
      verifysendstep2(&bob,&alice,&param);

	  //Compute keys
      compute_key(&alice,&param);
      compute_key(&bob,&param);

      //Generating session key
      hashing(&alice);
      hashing(&bob);
      
	  //Displaying the attributes of Alice and Bob
      show(&alice);
      show(&bob);
	  
      printf("\nTerminating Successfully\n");
      
      return 0;
}