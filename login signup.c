//Simple login/sign-up module
#include <stdio.h>
#include <stdlib.h>

struct details

{
    char name[100];
    char password[50];
    char email[50];
    char phone_no[10];
};
struct details s[100];
int choice,i,a,b,j=0,count=0;
char temp_name[100],temp_pass[50],temp_confirmpass[50],temp_email[50],temp_mobile[10];
int caps=0,small=0,num=0,special_characters=0;
void login();
void signup();
int check_details();
int check();
int validate();

int main()
{
    while(1)
	{
		printf("\n--------------------------------------------------\n");
		printf("\n\t\tWELCOME!!\n");
		printf("\n\tSimple Login/Signup Module\n");
		printf("\n1)LOGIN\n2)SIGNUP\n3)EXIT\nEnter Your Choice.......");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				login();
				break;
			}
			case 2:
			{
				signup();
				break;
			}
			case 3:
			{
				exit(1);
			}
			default:
			{
				printf("\nPlease enter the valid choice\n");
				break;
			}
		}
	}
}
int check_details()
{
    for(i=0;temp_name[i]!='\0';i++)
    {
        if(!((temp_name[i]>='a' && temp_name[i]<='z')|| (temp_name[i]>='A' && temp_name[i]<='Z')))
        {
            printf("\n\nInvalid Name....Please enter the valid name.....\n\n");
            count=1;
            main();
            break;
        }
        else
            count=0;
    }
    if(count==0)
    {
        caps=0;small=0;num=0;special_characters=0;
        for(i=0;temp_pass[i]!='\0';i++)
        {
            if(temp_pass[i]>='A' && temp_pass[i]<='Z')
                caps++;
            else if(temp_pass[i]>='a' && temp_pass[i]<='z')
                small++;
            else if(temp_pass[i]=='@' || temp_pass[i]=='#' || temp_pass[i]=='&' || temp_pass[i]=='*' || temp_pass[i]=='.')
                special_characters++;
            else if(temp_pass[i]>='0' && temp_pass[i]<='9')
                num++;
        }
        if(caps>=1 && small>=3 && special_characters>=1 && num>=3)
        {
            return 1;
        }
        else
        {
            printf("\n\nThe password you enter is weak...Please enter the strong password....\n\n");
            main();
        }
    }
}
int check()
{
    for(i=0;i<100;i++)
    {
        if(!strcmp(s[i].name,temp_name))
        {
            if(!strcmp(s[i].password,temp_pass))
            {
                printf("\nAccount already existed...Please login!!!\n");
                main();
                break;
            }
        }
    }
    if(i==100)
    {
        check_details();
    }
}
int validate()
{
    count=0;
    for(i=0;temp_pass[i]!='\0';i++)
    {
        if(temp_pass[i]!=temp_confirmpass[i])
        {
            count=1;
            printf("\n Password did not match...Please try again!!");
            main();
            break;
        }
        else
            count=0;
    }
    if(count==0)
    {
        int at=0,dot=0;
        small=0,num=0;
        for(i=0;temp_email[i]!='\0';i++)
        {
            if(temp_email[i]=='@')
                at++;
            else if(temp_email[i]=='.')
                dot++;
            else if(temp_email[i]>='a' && temp_email[i]<='z')
                small++;
            else if(temp_email[i]>='0' && temp_email[i]<='9')
                num++;
            else
            {
                printf("\nEnter valid mail address...\n");
                main();
                break;
            }
        }
        if(at==1 && dot==1 && small>=5 && num>=2)
            {
                count=1;
            }
        else
        {
            printf("\nPlease enter the valid mail address...\n");
            main();
        }
    }
    if(count==1)
    {
        num=0;
        for(i=0;temp_mobile[i]!='\0';i++)
        {
            if(temp_mobile[i]>='0' && temp_mobile[i]<='9')
                num++;
        }
        if(num==10 &&temp_mobile[0]!='0')
        {
            return 1;
        }
        else
        {
            printf("\nPlease enter the valid Mobile number...\n");
            main();
        }
    }
}
void signup()
{
    printf("Enter your Name:\t");
    scanf("%s",temp_name);
    printf("Enter your password:\t");
    scanf("%s",temp_pass);
    a=check();
    printf("Confirm your password:\t");
    scanf("%s",temp_confirmpass);
    printf("Enter your Email Address:\t");
    scanf("%s",temp_email);
    printf("Enter your Mobile number:\t");
    scanf("%s",temp_mobile);
    b=validate();
    if(a==1 &&b==1)
    {
        strcpy(s[j].name,temp_name);
        strcpy(s[j].password,temp_pass);
        strcpy(s[j].email,temp_email);
        strcpy(s[j].phone_no,temp_mobile);
        j++;
        printf("\nSign up successfully....Please login to view your details...\n");
    }
}
void login()
{
    printf("Enter the UserName:\t");
    scanf("%s",temp_name);
    printf("Enter the password:\t");
    scanf("%s",temp_pass);
    a=check_details();
    if(a==1)
    {
        for(i=0;i<100;i++)
        {
            if(!strcmp(s[i].name,temp_name))
            {
                if(!strcmp(s[i].password,temp_pass))
                   {
                       printf("\n\nLogin successfully...\n\n");
                       printf("\tWelcome %s!!!\n\n",s[i].name);
                       printf("Username:   %s\n\n",s[i].name);
                       printf("E-mail:\t  %s\n\n",s[i].email);
                       printf("Mobile Number:\t%s\n\n",s[i].phone_no);
                       main();
                       break;
                   }
                else
                   {
                        printf("\n\nInvalid Username or Password\n\n");
                        main();
                        break;
                   }
			}
		}
        printf("\n\nAccount does not exist! Please signup...\n\n");
    }
}









