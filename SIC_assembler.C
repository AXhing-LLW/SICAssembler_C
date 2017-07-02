#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef unsigned int uint;
char filename1[20],filename2[20],filename3[20];
char statement[20],statement_part[100][3][20],line[50];
char temp1[5],temp2[5];
int loc_n[20];
int loc_c[20]; 
int loc_d[20]; 
int op_1[20];
int op_2[20];
int ads[20];
int	ads_1[20];
int ads_2[20];
FILE *fp1,*fp2;
int obtop=44;
int op_3[20];
int op_4[20];
int	ads_3[20];
int ads_4[20];

int main(int argc, char* argv[]) 
{
    int i,j=100,num_part,len,line_no,position,y=0,top,two=0,z=1,o=0,END_1,END_2,k=0;
	int zero_no=0,one_no=0,two_no=0,max_no=0,table_no=0,loop_no=0,w=0;
	// 將外部參數 (原始程式碼檔名) 讀入
    

    strcpy(filename1,argv[1]);
    fp1=fopen(filename1,"r");
    
	strcpy(filename2,"output.obj");
    fp2=fopen(filename2,"w");
  
    line_no=0;
	len=0;
    
	while (!feof(fp1))
	{	 
		len=0;
        fscanf(fp1,"%c",&line[len]);
 
		while (line[len]!='\n')
		{
			len++; 
		    fscanf(fp1,"%c",&line[len]);
		}
		len++;
		line[len]='\0';


        // 將 line 切塊
  
		i=0; 
		num_part=0;
		
        while (line[i]!='\0')
		{
			position=0;

		  while (line[i]==' ') 
			  i++;

          while ((line[i]!=' ') && (line[i]!='\0'))
			{
              statement_part[line_no][num_part][position]=line[i];
              position++;
			  i++;
			  
			  if(strcmp(statement_part[line_no][num_part], "ZERO\n") == 0)
			  		{
			  			ads[line_no]=0;
					  }
			  if(strcmp(statement_part[line_no][num_part], "ONE\n") == 0)
			  		{
			  			ads[line_no]=1;
					  }
			  if(strcmp(statement_part[line_no][num_part], "TWO\n") == 0)
			  		{
			  			ads[line_no]=2;
					  }
			  if(strcmp(statement_part[line_no][num_part], "MAX\n") == 0)
			  		{
			  			ads[line_no]=3;
					  }
			  if(strcmp(statement_part[line_no][num_part], "TABLE,X\n") == 0)
			  		{
			  			ads[line_no]=4;
					  }
			  if(strcmp(statement_part[line_no][num_part], "100\n") == 0)
			  		{
			  			ads[line_no]=100;
					  }
			  if(strcmp(statement_part[line_no][num_part], "LOOP\n") == 0)
			  		{
			  			ads[line_no]=5;
					  }
			  if(strcmp(statement_part[line_no][num_part], "1024\n") == 0)
			  		{ads[line_no]=1024;}
			  	if(strcmp(statement_part[line_no][num_part], "0\n") == 0)
			  		{ads[line_no]=1000;}
				if(strcmp(statement_part[line_no][num_part], "1\n") == 0)
			  		{ads[line_no]=2000;}
			  	if(strcmp(statement_part[line_no][num_part], "2\n") == 0)
			  		{ads[line_no]=3000;}
			  		if(strcmp(statement_part[line_no][num_part], "END") == 0)
			  		{	END_1=line_no;
			  			END_2=num_part;  }
			  		if(strcmp(statement_part[line_no][num_part], "STA") == 0)
			  		{	op_1[line_no]=0;
			  			op_2[line_no]='C';  }
					if(strcmp(statement_part[line_no][num_part], "LDA") == 0)
			  		{	op_1[line_no]=0;
			  			op_2[line_no]=0;  }
					if(strcmp(statement_part[line_no][num_part], "LDX") == 0)
			  		{	op_1[line_no]=0;
			  			op_2[line_no]=4;  }
					if(strcmp(statement_part[line_no][num_part], "ADD") == 0)
			  		{	op_1[line_no]=1;
			  			op_2[line_no]=8;	}
					if(strcmp(statement_part[line_no][num_part], "TIX") == 0)
			  		{	op_1[line_no]=2;
			  			op_2[line_no]=67;  }
					if(strcmp(statement_part[line_no][num_part], "JLT") == 0)
			  		{	op_1[line_no]=3;
			  			op_2[line_no]=8;  }
					if(strcmp(statement_part[line_no][num_part], "RESB") == 0)
			  		{	op_1[line_no]=0;
			  			op_2[line_no]=50;	
						ads[line_no]=50; }  
					if(strcmp(statement_part[line_no][num_part],"RSUB\n") == 0)
			  		{	op_1[line_no]=4;
			  			op_2[line_no]=67;
			  			j=line_no;
			  			  	}
				    if(strcmp(statement_part[line_no][num_part],"ONE") == 0)
			  		{  //one_no=line_no;
					   one_no=11; w=0; }
			  		if(strcmp(statement_part[line_no][num_part],"ZERO") == 0)
			  		{ //zero_no=line_no;
					  zero_no=10; w=0; }
			  		if(strcmp(statement_part[line_no][num_part],"TWO") == 0)
			  		{ //two_no=line_no;
					  two_no=12; w=0; }
			  		if(strcmp(statement_part[line_no][num_part],"MAX") == 0)
			  		{ //max_no=line_no;
					  max_no=9; w=0; }
			  		if(strcmp(statement_part[line_no][num_part],"TABLE") == 0)
			  		{ //table_no=line_no;
					  table_no=8; w=0; }
					  if(strcmp(statement_part[line_no][num_part],"LOOP") == 0)
			  		{ loop_no=3; w=1;}
			  		
			  if(strcmp(statement_part[line_no][num_part], "4000\n") == 0) {
			  	
			  		int loc_no=line_no;
			  		top=40;
			  	
    			}
			  	
			}    
					
         
           statement_part[line_no][num_part][position]='\0';
		   num_part++;
		   loc_n[1]=0;
			  		for(int x=2;x<20;x++)
			  		{	if(x==j+2){
	   					loc_n[x]=loc_n[x-1];
	   					loc_c[x]=loc_n[x];  }
						else{
						loc_n[x]=loc_n[x-1]+3;
	   					loc_c[x]=loc_n[x];	}}
	   				for(int x=2;x<20;x++)
			  		{	if(loc_c[x]>=16)
							loc_d[x]=1;
						if(loc_c[x]>=32)
							loc_d[x]=2;
			  			while(loc_c[x]>=16)
						   		loc_c[x]=loc_c[x]-16; //  printf("%d\n",loc_c[x]);	
	   					if(loc_c[x]>=10)
						{	if(loc_c[x]==10)
							loc_c[x]=65;
							else if(loc_c[x]%10==1)
							loc_c[x]=66;
							else if(loc_c[x]%10==2)
							loc_c[x]=67;
							else if(loc_c[x]%10==3)
							loc_c[x]=68;
							else if(loc_c[x]%10==4)
							loc_c[x]=69;
							else if(loc_c[x]%10==5)
							loc_c[x]=70;
						}
					
						
						/*if(loc_d[]x]>10)
						{
							if(loc_d[x]%10==0)
							loc_d[x]=a;
							if(loc_d[x]%10==1)
							loc_d[x]=b;
							if(loc_d[x]%10==2)
							loc_d[x]=c;
							if(loc_d[x]%10==3)
							loc_d[x]=d;
							if(loc_d[x]%10==4)
							loc_d[x]=e;
							if(loc_d[x]%10==5)
							loc_d[x]=f;
						}*/	   
	   				}
	   				
      
					}  // end of while
		
					for(int x=0;x<20;x++)
					{
					if(ads[x]==0)
					{	ads_1[x]=loc_d[zero_no];
						ads_2[x]=loc_c[zero_no];}
					else if(ads[x]==1)
					{	ads_1[x]=loc_d[one_no];
						ads_2[x]=loc_c[one_no];}
					else if(ads[x]==2)
					{	ads_1[x]=loc_d[two_no];
						ads_2[x]=loc_c[two_no];}
					else if(ads[x]==3)
					{	ads_1[x]=loc_d[max_no];
						ads_2[x]=loc_c[max_no];}
					else if(ads[x]==4)
					{	ads_1[x]=loc_d[table_no];
						ads_2[x]=loc_c[table_no];}
					else if(ads[x]==5)
					{	ads_1[x]=loc_d[loop_no];
						ads_2[x]=loc_c[loop_no];}
					else if(ads[x]==100)
					{	ads_1[x]=6;
						ads_2[x]=4;}
					else if(ads[x]==1024)
					{	ads_1[x]=040;
						ads_2[x]=0;}
					else if(ads[x]==1000)
					{	ads_1[x]=0;
						ads_2[x]=0;}
					else if(ads[x]==2000)
					{	ads_1[x]=0;
						ads_2[x]=1;}
					else if(ads[x]==3000)
					{	ads_1[x]=0;
						ads_2[x]=2;}
					
						
				}
		
		if(y==j+2){		
			top=obtop;
			}
		if(y==j+1)
			obtop=40;
		if(y==0)
		{
			printf("LOC     ");
			while(1)
			{	
				if(line[k]!='\n'){
				printf("%c",line[k]);k++;}
				else{
				break; k++;}
			}
			k=0;
			printf("     Object Code");
		}
		else if(o<END_1-10){
		if(loc_c[y]>60){
		printf("\n%d%d%c    ",top,loc_d[y],loc_c[y]); // 螢幕上列印
		while(1)
			{	
				if(line[k]!='\n'){
				printf("%c",line[k]);k++;}
				else{
				break; k++;}
			}
			while(k<25)
			{
				printf(" ");k++;
			}
			
			if(op_1[y]>60)
				printf("%c%d",op_1[y],op_2[y]);
			else if(op_2[y]>60)
				printf("%d%c",op_1[y],op_2[y]);
			else if(op_2[y]==50)
				printf(" ");
			else
				printf("%d%d",op_1[y],op_2[y]);
				
			if(ads_1[y]>60)
				printf("%d%c%d",obtop,ads_1[y],ads_2[y]);
			else if(y==j)
				printf("0000");
			else if(ads_2[y]>60)
				printf("%d%d%c",obtop,ads_1[y],ads_2[y]);
			else if(op_2[y]==50)
				printf(" ");
			else if(y>j)
				printf("00%d%d",ads_1[y],ads_2[y]);
			else if(ads[y]==4)
				printf("C0%d%d",ads_1[y],ads_2[y]);
			else if(w==1)
				printf("%d%d%d",top,ads_1[y],ads_2[y]);
			else
				printf("%d%d%d",obtop,ads_1[y],ads_2[y]);
		k=0;	
		}
		else{
		printf("\n%d%d%d    ",top,loc_d[y],loc_c[y]);
		while(1)
			{	if(line[k]!='\n'){
				printf("%c",line[k]);	k++;}
				else{break;k++;}
			}
			while(k<25)
			{
				printf(" ");k++;
			}
			
			if(op_1[y]>60)
				printf("%c%d",op_1[y],op_2[y]);
			else if(op_2[y]>60)
				printf("%d%c",op_1[y],op_2[y]);
			else if(op_2[y]==50)
				printf(" ");
			else
				printf("%d%d",op_1[y],op_2[y]);
				
			if(ads_1[y]>60)
				printf("%d%c%d",obtop,ads_1[y],ads_2[y]);
			else if(y==j)
				printf("0000");
			else if(ads_2[y]>60)
				printf("%d%d%c",obtop,ads_1[y],ads_2[y]);
			else if(w==1)
				printf("%d%d%d",top,ads_1[y],ads_2[y]);
			else if(ads[y]==4)
				printf("C0%d%d",ads_1[y],ads_2[y]);
			else if(op_2[y]==50)
				printf(" ");
			else if(y>j)
				printf("00%d%d",ads_1[y],ads_2[y]);
			else
				printf("%d%d%d",obtop,ads_1[y],ads_2[y]);
				
				
			/*strcat(op_1,op_2);
			printf("%s\n",op_1);*/
			
		k=0;
		o++;
		printf("\n");
		}
		}
		else
		printf("\n        %s",line);
		fprintf(fp2,"%s",line); // 輸出至 output.obj
		
	 	op_3[y]=op_1[y];
		op_4[y]=op_2[y];
		ads_3[y]=ads_1[y];
		ads_4[y]=ads_2[y];
		
		line_no++;
		y++;
	
		obtop=44;


	}

	int t=y;
	int f=t-3;
	f=f*3;
	int u=0;
	if(f>10)
	{
		while(f>=16)
		{
			u++;
			f-=16;
			
		}
		
			if(f>=10)
				{	if(f==10)
					f=65;
					else if(f%10==1)
					f=66;
					else if(f%10==2)
					f=67;
					else if(f%10==3)
					f=68;
					else if(f%10==4)
					f=69;
					else if(f%10==5)
					f=70;
				}
		
	}
	printf("\n \n \n");
	top-=4;
	printf("H^%s  ^00%d%d%d^000423\n",statement_part[0][1],top,loc_d[1],loc_c[1]);
	if(f<60)
	printf("T^00%d%d%d^%d%d^",top,loc_d[1],loc_c[1],u,f);
	else
	printf("T^00%d%d%d^%d%c^",top,loc_d[1],loc_c[1],u,f);
	for(y=1;y<t-1;y++)
	{
		if(y==j-1){		
			obtop=40;	
		}
		if(op_3[y]>60)
				printf("%c%d",op_3[y],op_4[y]);
			else if(op_2[y]>60)
				printf("%d%c",op_3[y],op_4[y]);
			else if(op_2[y]==50)
				printf("");
			else
				printf("%d%d",op_3[y],op_4[y]);
				
			if(ads_3[y]>60)
				printf("%d%c%d",obtop,ads_3[y],ads_4[y]);
			else if(y==j)
				printf("0000");
			else if(ads_4[y]>60)
				printf("%d%d%c",obtop,ads_3[y],ads_4[y]);
			else if(op_4[y]==50)
				printf("");
			else if(ads[y]==4)
				printf("C0%d%d",ads_3[y],ads_4[y]);
			else if(w==1)
				printf("%d%d%d",top,ads_3[y],ads_4[y]);
			else if(y>j)
				printf("00%d%d",ads_3[y],ads_4[y]);
			else
				printf("%d%d%d",obtop,ads_3[y],ads_4[y]);
			if((op_4[y]!=50)&&(y!=t-2))
			printf("^");
				
	}
	printf("\nE^00%d%d%d\nx",top,loc_d[1],loc_c[1]);
	
 /*  for (i=0;i<=line_no;i++)
   {
	   for (j=0;j<=num_part;j++)
	   {
		
	     printf("%s",statement_part[i][j]);
	
	   }
   }*/
	
     fclose(fp2);
	 fclose(fp1);
}
