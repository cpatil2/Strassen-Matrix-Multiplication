#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Function Declarations
void Strassens_matrix_multiply(int n,int *, int *,int *);
int* add(int ,int *,int *);
int* sub(int ,int *,int *);
int* mul(int n,int *a, int *b);

int main(){
        
		int n,x,k;
		printf("\nEnter the Matrix Size (Value of n): ");
		scanf("%d",&n);
		x=n;
		if(n>=1 && n<=1024){
			while (((x % 2) == 0) && x > 1) 
   				x=x/2; 
        	if (x == 1){
				printf("\nWell done! You entered n which is a valid power of 2");
				
				
				
				int *a = (int *)malloc(n * n * sizeof(int));
				int *b = (int *)malloc(n * n * sizeof(int));
				int *c = (int *)malloc(n * n * sizeof(int));
				
				srand(time(0));
				printf("\n\nGenerating and Printing Your I/P Matrix A:\n");   
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
					{  
						k=rand()%10;
    					a[i * n+j]=k;
				    }
				 
				
				for(int i=0;i<n;i++)
				{
					printf("\n");
					for(int j=0;j<n;j++)
					{  
				       printf("%d\t",a[i * n+j]);
				    }
				}
				
				printf("\n\nGenerating and Printing Your I/P Matrix B:\n"); 
				
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
					{  
						k=rand()%10;
    					b[i * n+j]=k;
				    }
				    
				    
				
				for(int i=0;i<n;i++)
				{
					printf("\n");
					for(int j=0;j<n;j++)
					{  
				       printf("%d\t",b[i * n+j]);
				    }
				}
				
				printf("\n\n");
				
				Strassens_matrix_multiply(n,a,b,c);
				
				printf("\nFinal Multiplication Result (Matrix C):\n");
				
				for(int i=0;i<n;i++)
				{
					printf("\n");
					for(int j=0;j<n;j++)
					{  
				       printf("%d\t",c[i * n+j]);
				    }
				}
				
				printf("\n\n");
				
			}
			else
				printf("\nInvalid power of 2");
			
		}
		else
				printf("\nSorry! You have to enter n in the range 1<=n<=1024");

        return 0;

}

 
 
 void Strassens_matrix_multiply(int n,int *a, int *b, int *c)
 {
				
		    // creating temporary matrices to store 4 quadrants of each matices a,b and c		
				
		    int *a11 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *a12 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *a21 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *a22 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
		
			int *b11 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *b12 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *b21 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *b22 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
		
			int *c11 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *c12 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *c21 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *c22 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			
		
			
			// Retrieving a11 from first quadrant of matrix a
			// Retrieving b11 from first quadrant of matrix b
			int k=0;
			for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
				       	a11[k]=a[i * n+j];         
				       	b11[k]=b[i * n+j];
				       	k++;
				       
				    }
				}
				
		    // Retrieving a12 from second quadrant of matrix a
			// Retrieving b12 from second quadrant of matrix b		
			
		    k=0;
			for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=(int)n/2;j<n;j++)
					{  
					        
				       	a12[k]=a[i * n+j];
				       	b12[k]=b[i * n+j];
				       	k++;
				    }
				}
				
			
			// Retrieving a21 from first quadrant of matrix a
			// Retrieving b21 from first quadrant of matrix b		
		    k=0;	
			for(int i=(int)n/2;i<n;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
				       	a21[k]=a[i *n+j];
				       	b21[k]=b[i * n+j];
				       	k++;
				       
				    }
				}
				
		
			// Retrieving a22 from first quadrant of matrix a
			// Retrieving b22 from first quadrant of matrix b	
				
		    k=0;		
			for(int i=(int)n/2;i<n;i++)
				{
					for(int j=(int)n/2;j<n;j++)
					{  
				       	a22[k]=a[i*n+j];
				       	b22[k]=b[i * n+j];
				       	k++;
				    }
				}
		
				
				
		//Now all quadrants are ready!
		//Decide weather is is base condition?
		//if n==2 current base condition in below code then use normal methods for matrix multiplication without involvement of any Strassens Logic		
		//but if n>2 then its not base condition. Goto else part and use D&C approach with the help of Strassens Matrix Multiplication
				
				
				
		if(n==2){	
			
			//"**************    Inside Base condition *****************************
			
			
			//calculate resultant quadrants c11,c12,c21,c22 for resultant matrix C. // remember its base condition mul function used below is normal multiplication.
			
			c11=add((int)n/2, mul((int)n/2,a11,b11), mul((int)n/2,a12,b21)   );
			c12=add((int)n/2, mul((int)n/2,a11,b12), mul((int)n/2,a12,b22)  );
			c21=add((int)n/2, mul((int)n/2,a21,b11),  mul((int)n/2,a22,b21)  );
			c22=add((int)n/2, mul((int)n/2,a21,b12),  mul((int)n/2,a22,b22)  );
			
			
			//Composing C from c11,c12,c13,c14 using 4 for loops below one-by-one
			
		    
		    
		 	k=0;
			for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
				       	c[i * n+j]=c11[k];         
				       	k++;
				       
				    }
				}
				
				
		    k=0;
			for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=(int)n/2;j<n;j++)
					{  
					      c[i * n+j]=c12[k];    
				          	k++;
				    }
				}
				
			
					
		    k=0;	
			for(int i=(int)n/2;i<n;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
					     c[i * n+j]=c21[k];  
				        	k++;
				       
				    }
				}
				
		
				
			printf("\n\n");		
		    k=0;		
			for(int i=(int)n/2;i<n;i++)
				{
					
					for(int j=(int)n/2;j<n;j++)
					{  
				       	c[i * n+j]=c22[k];  
				          	k++;
				    }
				}
		    
		        
		   
		}
		
		else{
		
		
		    //Well finally we have to go for D&C. using Strassens Matrix Multiplication Logic
		    
		    
		    //create m1 to m7 matrices
		
		    int *m1 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *m2 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *m3 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *m4 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
		
			int *m5 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *m6 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			int *m7 = (int *)malloc((int)n/2 * (int)n/2 * sizeof(int));
			
				
			Strassens_matrix_multiply((int)n/2,add((int)n/2,a11,a22),add((int)n/2,b11,b22),m1); //recursion to get m1
			
			printf("\n----------  Printing M1 -------------------");
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m1[i * (int)n/2+j]);
				    }
				}
				
			
			
			Strassens_matrix_multiply((int)n/2,add((int)n/2,a21,a22), b11,m2);    //recursion to get m2
			
			printf("\n----------  Printing M2 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m2[i * (int)n/2+j]);
				    }
				}
			
			Strassens_matrix_multiply((int)n/2,a11,sub((int)n/2,b12,b22), m3);     //recursion to get m3
			
			printf("\n----------  Printing M3 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m3[i * (int)n/2+j]);
				    }
				}
			
			
			Strassens_matrix_multiply((int)n/2,a22,sub((int)n/2,b21,b11), m4);    ////recursion to get m4
			
			printf("\n----------  Printing M4 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m4[i * (int)n/2+j]);
				    }
				}
			
			
			Strassens_matrix_multiply((int)n/2,add((int)n/2,a11,a12),b22, m5);      //recursion to get m5
			
			printf("\n----------  Printing M5 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m5[i * (int)n/2+j]);
				    }
				}
			
			
			Strassens_matrix_multiply((int)n/2,sub((int)n/2,a21,a11),add((int)n/2,b11,b12), m6);    ////recursion to get m6
			
			printf("\n----------  Printing M6 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m1[i * (int)n/2+j]);
				    }
				}
			
			
			Strassens_matrix_multiply((int)n/2,sub((int)n/2,a12,a22),add((int)n/2,b21,b22), m7);    ////recursion to get m7
			
			printf("\n----------  Printing M7 -------------------");
			
			
			for(int i=0;i<(int)n/2;i++)
				{
					printf("\n");
					for(int j=0;j<(int)n/2;j++)
					{  
				       printf("%d\t",m7[i * (int)n/2+j]);
				    }
				}
			
		
			
			//calculate resultant quadrants c11,c12,c21,c22 for resultant matrix C. // remember its base condition mul function used below is normal multiplication.
			
			c11=sub((int)n/2,  add(  (int)n/2,  add((int)n/2,m1,m4),  m7), m5);
			
			c12=add((int)n/2,m3,m5);
			
			c21=add((int)n/2,m2,m4);
			
		    c22=sub((int)n/2,  add(  (int)n/2,  add((int)n/2,m1,m3),  m6), m2);
		
		     //Composing C from c11,c12,c13,c14
			
		    
		    
		    k=0;
			for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
				       	c[i * n+j]=c11[k];         
				       	k++;
				       
				    }
				}
				
				
		     k=0;
			 for(int i=0;i<(int)n/2;i++)
				{
					
					for(int j=(int)n/2;j<n;j++)
					{  
					      c[i * n+j]=c12[k];    
				       	  k++;
				    }
				}
				
			
					
		    k=0;	
			for(int i=(int)n/2;i<n;i++)
				{
					
					for(int j=0;j<(int)n/2;j++)
					{  
					     c[i * n+j]=c21[k];  
				      	 k++;
				       
				    }
				}
				
		
				
				
		    k=0;		
			for(int i=(int)n/2;i<n;i++)
				{
					printf("\n");
					for(int j=(int)n/2;j<n;j++)
					{  
				       	c[i * n+j]=c22[k];  
				       	k++;
				    }
				}
		}
 		
 }
 
 //---------------------------------------------------------------------------------------------
 
 //add matrix a and b and return result in c
 
 int * add(int n,int *a,int *b){
        int *c = (int *)malloc(n * n * sizeof(int));
        
  		for(int i=0;i<n;i++)
				{
					
					for(int j=0;j<n;j++)
					{  
				       c[i * n + j]=a[i * n + j] + b[i * n + j];
				    }
				}
				
				
        return c;
 
 
 }
 
//--------------------------------------------------------------------------------------------

 //Substract matrix b from a and return result in c
 
  
 int* sub(int n,int *a,int *b){
    int *c = (int *)malloc(n * n * sizeof(int));
    for(int i=0;i<n;i++)
				{
					
					for(int j=0;j<n;j++)
					{  
				       c[i * n + j]=a[i * n + j] - b[i * n + j];
				    }
				}
 
     return c;
 
 
 }
 
 
 //--------------------------------------------------------------------------------------------

  //normal multiplication of matrix a and b and return result in c (used only for base condition)
 
 int* mul(int n,int *a, int *b){
 
      int *c = (int *)malloc(n * n * sizeof(int));
      int k1=0;
    	for(int i=0;i<n;i++)
				{
					
					for(int j=0;j<n;j++)            
					{    c[k1]=0;                           
					    for(int k=0;k<n;k++)
				       	{	c[k1]=c[k1]+a[i * n + k] * b[k * n + j];
				       		
				       	}
				       	k1++;
				    }
				}
 
     return c;
 
 
 
 }
