#include<stdio.h>
#include<conio.h>
#define ALL -1
#define MAXCITIES 10

enum BOOL{FALSE,TRUE};
long *visited;//visited nodes set here
long *min_circuit;//min inner circuit for given node as start node at position indexed 0
long *ham_circuit;//optimal circuit with length stored at position indexed 0
long min_circuit_length;//min circuit lenth for given start node
int n;//city count
long matrix[MAXCITIES][MAXCITIES];//nondirectional nXn symmetric matrix
//to store path distances as sourceXdestination
long INFI;// INFINITY value to be defined by user

// function resets minimum circuit for a given start node
//with setting its id at index 0 and setting furthr node ids to -1
void reset_min_circuit(int s_v_id)
{
	int i;
	min_circuit[0]=s_v_id;

	for(i=1;i<n;i++)
	{
		min_circuit[i]=-1;
	}
}

// marks given node id with given flag
// if id==ALL it marks all nodes with given flag
void set_visited(int v_id,BOOL flag)
{
	int i;
	if(v_id==ALL)
	{
		for(i=0;i<n;i++)
		{
			visited[i]=flag;
		}
	}
	else	
	{
		visited[v_id]=flag;
	}
}

// function sets hamiltonion circuit for a given path length
//with setting it at index 0 and setting furthr nodes from current min_circuit
void SET_HAM_CKT(long pl)
{
	ham_circuit[0]=pl;
	for(int i=0;i<n;i++)
	{
		ham_circuit[i+1]=min_circuit[i];
	}
	ham_circuit[n+1]=min_circuit[0];
}

//function sets a valid circuit by finiding min inner path for a given
//combination start vertex and next vertex to start vertex such that
// the 2nd vertex of circuits is always s_n_v and start and dest node is
//always s_v for all possible values of s_n_v, and then returns the
// valid circuit length for this combination

long get_valid_circuit(int s_v,int s_n_v)
{
	int next_v,min,v_count=1;
	long path_length=0;
	
	min_circuit[0]=s_v;
	min_circuit[1]=s_n_v;
	set_visited(s_n_v,TRUE);
	path_length+=matrix[s_v][s_n_v];
	
	for(int V=s_n_v;v_count<n-1;v_count++)
	{   
		min=INFI;
		for(int i=0;i<n;i++)
		{	
			if(	matrix[V][i]<INFI && !visited[i] && matrix[V][i]<=min )
			{
				min=matrix[V][next_v=i];
			}
		}
		set_visited(next_v,TRUE);
		V=min_circuit[v_count+1]=next_v;
		path_length+=min;
	}
	path_length+=matrix[min_circuit[n-1]][s_v];
	return(path_length);
}

void main()
{
	int pathcount,i,j,source,dest;
	long dist=0;
	long new_circuit_length=INFI;
	
	clrscr();
	
	printf("Make sure that infinity value < sum of all path distances\nSet Infinity at (signed long):");
	scanf("%ld",&INFI);
	printf("Enter no. of cities(MAX:%d):",MAXCITIES);
	scanf("%d",&n);
	printf("Enter path count:");
	scanf("%d",&pathcount);
	printf("Enter paths:< source_id destination_id distance >\n ids varying from 0 to %d\n",n-1);

	//init all matrix distances to infinity
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j]=INFI;
		}
	}

	//populate the matrix
	for(i=0;i<pathcount;i++)
	{
		printf("[path %d]:",i);
		scanf("%d %d %ld",&source,&dest,&dist);
	
		if(source!=dest)
		{
			matrix[source][dest]=matrix[dest][source]=dist;
		}
	}

	visited=new long[n];
	min_circuit=new long[n];
	ham_circuit=new long[n+2];
	min_circuit_length=INFI;
	
	// algorithm
	//for each vertex, S_V as a staring node
	for(int S_V_id=0;S_V_id<n;S_V_id++)
	{       
		//for each and non start vertex as i
		for(i=0;i<n;i++)
		{      
			//set all to unvisited
			set_visited(ALL,FALSE);
			// set staring vertex as visited
			set_visited(S_V_id,TRUE);
			//reset/init minimum circuit
			reset_min_circuit(S_V_id);
			// obtain circuit for combination of S_V and i
			new_circuit_length=get_valid_circuit(S_V_id,i);
			// if newer length is less than the previously
			//calculated min then set it as min and set the
			//current circuit in hamiltonion circuit
			if(new_circuit_length<=min_circuit_length)
			{
				SET_HAM_CKT(min_circuit_length=new_circuit_length);
			}
		}
	}
	
	// if any circuit found
	if(min_circuit_length<INFI)
	{
		printf("\n\nMinimum circuit length is: %ld\nCircuit is:\n",min_circuit_length);
		for(i=1;i<n+2;i++)
		{
			printf("<%ld> ",ham_circuit[i]);
		}
	}
	else
	{
		printf("\n\nNo hamiltonian circuit !");
	}
	getch();
	delete []visited;
	delete []min_circuit;
	delete []ham_circuit;
}