/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: ziadayman
 */



#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Main_Menu ()
{
	printf ("\n****** Welcome to Booking.com ******\n");
    printf ("\nIf you want to register please enter a\n");
    printf ("\nIf you already have an account please enter b\n");
}

void Register ()
{
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";

	///////////////////////////Mail///////////////////////
	printf ("Please enter your Email \n");
	scanf("%s", mail);
	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

	if (find1)
	{
		if (find2)
		{

		}
	}

	else
	{
		printf ("Invalid Mail\n");
		Register();
	}

	 fp = fopen(file, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file);
	    }

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
	        if (strstr(buffer, mail) != NULL)
	        {
	            printf("This mail is taken\n");
	            fclose(fp);
	            Register();
	            break;
	        }
	    }

	///////////////////////////////////Pass///////////////////////


	printf ("Please enter you Password \n");
	scanf ("%s",pass);

	if (strlen(pass) == 0)
	{
		printf ("Invalid Password\n");
		Register();
	}



	//////////////////////////////////////Adding///////////////////

	fp = fopen(file, "a");

		if (fp == NULL)
		{
		        printf("Error opening file %s\n", file);
		}
		fprintf(fp, "%s:%s\n", mail, pass);

	fclose(fp);

	printf ("\nSign up successful\n");
}

void Log_in ()
{
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";


	printf ("Please enter your Email \n");
	scanf("%s", mail);

	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

	if (find1)
	{
		if (find2)
		{

		}
	}

	else
	{
		printf ("Invalid Mail\n");
		Register();
	}

	 fp = fopen(file, "r");
	    if (fp == NULL)
	    {
	        printf("Error opening file %s\n", file);
	    }

	    while (fgets(buffer, sizeof(buffer), fp) != NULL)
	    {

	        char *e = strtok(buffer, ":");
	        char *p = strtok(NULL, "\n");


	        if (strcmp(e, mail) == 0 && strcmp(p, pass) == 0)
	        {
	            printf("\nLogin successful\n");
	            fclose(fp);
	        }
	    }
}


void forget_pass()
{
	FILE *fp;
	char mail[50];
	char pass[50];
	char buffer[1024];
	char file[256] = "/Users/ziadayman/Desktop/Booking Site/Book1.txt";
	char f;


	printf ("Please enter your Email \n");
	scanf("%s", mail);

	char *find1 = strchr(mail, '@');
	char *find2 = strstr(mail, ".com");

		if (find1)
		{
			if (find2)
			{

			}
		}

		else
		{
			printf ("Invalid Mail\n");
			Register();
		}

		 fp = fopen(file, "r");
		    if (fp == NULL)
		    {
		        printf("Error opening file %s\n", file);
		    }

		    while (fgets(buffer,sizeof(buffer), fp) != NULL)
		    {
		        char *ptr = strtok(buffer, ":");
		        if (strcmp(ptr, mail) == 0)
		        {
		            ptr = strtok(NULL, "\n");
		            strcpy(pass, ptr);
		            f=1;
		            break;
		        }
		    }

		    fclose(fp);

		    if (f)
		    {
		         printf("Your password is: %s\n", pass);
		    }
		    else
		    {
		         printf("Email not found\n");
		    }
}

void Start()
{
	int run =1;
	char input,forget;

	Main_Menu();

	while (run == 1)
	{
		scanf (" %c" , &input);

		switch (input)
		{
		case 'a':
		case 'A': Register();
		          Start();
				break;

		case 'b':
		case 'B': printf ("\nIf you forget the pass enter f if not enter n\n");
		scanf ("%c",&forget);
		if (forget == 'f' || forget == 'F')
		{
			forget_pass();
			Start();
		}
		else if (forget == 'n' || forget == 'N')
		{
			Log_in();
		}
		break;

		}
	}
}


int main()
{
	Start();
}

