#include <stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
int check_c(char c,char* x)
{
    int i=0;
    while(x[i]!='\0')
    {
        if(x[i]==' ')
        {
            i++;
        continue;
        }
    if(c==x[i])
    return 1;
    i++;
    }
    return 0;
}

int check_t(char c,char*y)
{
    int i=0;
    while(y[i]!='\0')
    {
        if(y[i]==' ')
        {
        i++;
        continue;
        }
    if(c==y[i])
    return 1;
    i++;
    }
    return 0;
}
int check_y(char* y,int* prey)
{
    int i=0;
    while(y[i]!='\0')
    {
        if(prey[y[i]]!=0)
        {
            int j=0;
            while(y[j]!='\0')
            {
                if(y[j]==prey[y[i]])
                return 1;
                j++;
            }
        }
        i++;
    }
    return 0;
}


int main()
{
    char x[]={'W','G','C','\0'};
 char y[]={ ' ',' ',' ','\0'};
int prey[90];
while(1)
{
     printf("\n%sM<=======================>%s\n",x,y);
    printf("\nCHOOSE FROM LEFT BANK:\n\n");
    char c;
    scanf("%c",&c);
    getchar();
    if(c>=97&&c<=122)
    c-=32;

    if(!check_c(c,x))
    {
        printf("\nNOT PRESENT IN LEFT BANK,CHOOSE AGAIN\n");
    continue;
    }

    if(c==x[0]&&x[1]=='G'&&x[2]=='C')
    {
        y[0]=c;
        x[0]=' ';
        y[1]='\0';
        printf("\n%s<========================>%sM\n",x,y);
        printf("\nGOAT WILL EAT THE CABBAGE,SO YOU LOOSE");
        break;
    }

    if(c==x[2]&&x[0]=='W'&&x[1]=='G')
    {
        y[0]=c;
        y[1]='\0';
        x[2]=' ';
        printf("\n%s<========================>%sM\n",x,y);
        printf("\nTHE WOLF WILL EAT THE GOAT,SO YOU LOOSE");
        break;
    }

    if(c=='W')
    {
        y[0]=c;
        prey[c]='G';
        x[0]=' ';
    }

    if(c=='G')
    {
        y[1]=c;
        prey[c]='C';
        x[1]=' ';
    }

    if(c=='C')
    {
        y[2]=c;
        x[2]=' ';
    }

    if(y[0]=='W'&&y[1]=='G'&&y[2]=='C')
    {
        printf("\nGOAL REACHED:\n");
        printf("\n%s<=======================>%sM\n",x,y);
    break;

    }

    if(check_y(y,prey)==0)
    continue;
    printf("\n%s<==================================>M%s\n",x,y);
     printf("\nREMOVE ANYONE OF THE PREDATOR OR THE PREY FROM THE RIGHT BANK:\n\n");
     char t;
     scanf("%c",&t);
     getchar();
     if(t>=97)
     t-=32;

     if(!check_t(t,y))
     {
         printf("\nNOT PRESENT IN RIGHT BANK,SO U LOOSE");
         break;
     }

     if(t==y[0])
     {
         x[0]=y[0];
         y[0]=' ';

     }

      if(t==y[1])
     {
         x[1]=y[1];
         y[1]=' ';

     }

      if(t==y[2])
     {
         x[2]=y[2];
         y[2]=' ';

     }

}
    return 0;
}
