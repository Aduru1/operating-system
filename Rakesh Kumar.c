#include<conio.h>
#include<stdio.h>
int main()
{
 int n;    //n number of process
 int m;      // numbem of resources
 int i,j,k,pmf,kgf;
 int avail[10],p[10];
 int need[10][10],alloc[10][10],max[10][10];

 printf("\nEnter number of process :");
 scanf("%d",&n);
 printf("\n Enter  resources available : ");
 scanf("%d",&m);
 printf("\nEnter insatnces for resources :\n");
 for(i=0;i<m;i++)
 {  printf("R%d ",i+1);
  scanf("%d",&avail[i]);
  }
 printf("\n Enter allocation matrix  \n");
 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);          p[i]=0;
 for(j=0;j<m;j++)
 {
  scanf("%d",&alloc[i][j]);
 }
}
  printf("\n Enter MAX matrix  \n");

 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);
 for(j=0;j<m;j++)
 {
  scanf("%d",&max[i][j]);
 }
 }

 for(i=0;i<n;i++)
 {
 printf("\np%d\t",i+1) ;
 for(j=0;j<m;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("\t%d",need[i][j]);
  }
 }
 k=0;     kgf=0;
 printf("\n\n");
 while(k<15)
 {
 for(i=0;i<n;i++)
 {  pmf=0;
 for(j=0;j<m;j++)
 {
  if(p[i]==1) break;
  if(need[i][j]<=avail[j])
  {
  pmf++;
  }
  if(pmf==m)
  {
  for(j=0;j<m;j++)
  {
  avail[j]+=alloc[i][j];
  }
  printf("p%d\t",i+1);  p[i]=1;     kgf++;
  }
 }
 } k++;
 }
 if(kgf<n-1)
 {
 printf("\n deadlock ");
 }
      getch();
 }
