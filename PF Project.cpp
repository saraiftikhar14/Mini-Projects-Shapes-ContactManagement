#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a;
	printf("Press 1 to display Shapes\tPress 2 display Contact Management System:");
	scanf("%d",&a);
if(a==1)
{
    int k;
    printf("Select a shape[1 for Square\t2 for Rectangle\t3 for Inverted right triangle]:");
    scanf("%d",&k);	
if (k==1) 
{
    int s,i,j;
    printf("Enter side of square:");
    scanf("%d",&s);
    for(i=0;i<s;i++)
	{
       for(j=0;j<s;j++)
        {
          printf("*");
        }
    printf("\n");
    }
}
else if(k==2)
{
    int rows,cols,c,d;
    printf("Enter rows and columns of rectangle:");
    scanf("%d %d", &rows, &cols);
    for(c= 0;c<rows;c++)
	{
        for(d= 0;d<cols;d++)
		{
           printf("*");
        }
        printf("\n");
    }
}
else if(k==3)
{
    int e,f,rows;
    printf("Enter the number of rows for inverted right triangle :");
    scanf("%d",&rows);
    for(e=0;e<rows;e++)
	{
       for(f=0;f<rows-e;f++) 
	   {
        printf("*");
       }
        printf("\n");
    }
}
return 0;
}
struct contact
{
long ph;
char name[50],add[30],email[40];
} 
list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
{
main:   
printf("\n\t*Welcome to Contact Management System*");
printf("\n\tMAIN MENU\n\t========================\n\t(1).Add a Contact\n\t(2).Search for contact\n\t(3).Delete Contact\n\t(0).Exit\n\t=================\n\t");
printf("Enter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 0:
    printf("\n\n\tAre you sure you want to exit?");
    break;
case 1:
    fp=fopen("contact.dll","a");
	for (;;)
{
    fflush(stdin);
    printf("Name(Use identical):");
    scanf("%[^\n]",&list.name);
    if(stricmp(list.name,"")==0||stricmp(list.name," ")==0)
    break;
    fflush(stdin);
    printf("Phone:");
    scanf("%ld",&list.ph);
    fflush(stdin);
    printf("address:");
    scanf("%[^\n]",&list.add);
    fflush(stdin);
	printf("email address:");
    gets(list.email);
    printf("\n");
    fwrite(&list,sizeof(list),1,fp);
}
    fclose(fp);
    break;
case 2:
    do
{
    found=0;
    printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
    fflush(stdin);
    scanf("%[^\n]",&query);
    l=strlen(query);
    fp=fopen("contact.dll","r");
    printf("\n\n..::Search result for'%s'\n===================================================\n",query);
    while(fread(&list,sizeof(list),1,fp)==1)
{
    for(i=0;i<=l;i++)
    name[i]=list.name[i];
    name[l]='\0';
    if(stricmp(name,query)==0)
{
    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);
    found++;
    if (found%4==0)
{
    printf("..::Press any key to continue...");
    getch();
}
}
}
    if(found==0)
    printf("\n..::No match found!");
    else
    printf("\n..::%d match(s) found!",found);
	fclose(fp);
	printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
	scanf("%d",&ch);
}
    while(ch==1);
	break;
case 3:
    fflush(stdin);
    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
	scanf("%[^\n]",&name);
	fp=fopen("contact.dll","r");
	ft=fopen("temp.dat","w");
	while(fread(&list,sizeof(list),1,fp)!=0)
	if (stricmp(name,list.name)!=0)
	fwrite(&list,sizeof(list),1,ft);
	fclose(fp);
	fclose(ft);
	remove("contact.dll");
	rename("temp.dat","contact.dll");
	break;
	default:
	printf("Invalid choice");
	break;
}
    printf("\n\n\n..::Enter the Choice:\n\n\t(1).Main Menu\t\t(0).Exit\n");
    scanf("%d",&ch);
	switch (ch)
{
    case 1:
    goto main;
	case 0:
	break;
	default:
	printf("Invalid choice");
	break;
}
return 0;
}
}
