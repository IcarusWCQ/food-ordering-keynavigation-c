#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int token=0 ,payment_counter=0;
double tokens[50];

int main();
int main_page();
int menu_order();
void Bill_show(int arID[], int arqty[], int counter);
void Bill_Payment();
void main_page_control(int first,int arrPos);
void menu_order_control(int arrPos);
void burger_meat();
void burger_meat_control(int arrPos);
void burger_sauce();
void burger_sauce_control(int arrPos);

typedef struct 
{
    char Name[100];
} Customer;

Customer customer;

void sleep(long int interval)
{
	for(int i=0;i<interval*1000;i++);
}

void exitprogram() //Kyson
{
	system("cls"); //clear output

	FILE *fptr;
	char c;
	fptr=fopen("Exit.txt","r"); // fopen("textfile,r=read")
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);

	printf("\n                                                                      | |   This session order recieved : %d                              | |",token);
	printf("\n                                                                      | |   This session bill paid      : %d                              | |",payment_counter);
	if(payment_counter<token)
	{
		printf("\n                                                                      | |   Bill yet to pay             : %d                              | |",token-payment_counter);
		fptr=fopen("Border.txt","r");
		c = fgetc(fptr);
		while (c != EOF)
		{
			printf("%c", c);
			c = fgetc(fptr);
		}
		fclose(fptr);
		printf("\n\n                                                                      ");
		system("color 4F");
		system("pause");
		main_page();
	}
	fptr=fopen("Border.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
	printf("\n\n                                                                      ");
	system("pause"); //Press any key to continue . . .
	exit(1);
}

int main_page()
{
	FILE *fptr;
	char c;
    system("cls");
    system("color 0B");
	
	fptr=fopen("Group13.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);sleep(1000);
		c = fgetc(fptr);
	}
	fclose(fptr);

	fptr=fopen("MainPage.txt","r");sleep(300);
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	printf("\n");
	fclose(fptr);
	
	int MAXOPT = 3,i = 1,first=0;
	char ch;
    main_page_control(first,1); //for printing first control.
    while (1) // for infinte loop
    {
		first=1;
        ch = getch();
        switch (ch)
        {
			case 72: // for up arrow key
				Beep(1000, 100);
				if (i != 1)
				{
					i--;
					main_page_control(first,i);
				}
				else{
					i = MAXOPT;
					main_page_control(first,MAXOPT);
				}
				break;
        
			case 80: // for Down arrow key
				Beep(1000, 100);
				if (i != 3)
				{
					i++;
					main_page_control(first,i);
				}
				else{
					i = 1;
					main_page_control(first,1);
				}
				break;
		
			case 13: // for Enter key
				Beep(1000, 100);
				switch (i)
				{
				case 1:
					menu_order();
					break;
				
				case 2:
					Bill_Payment();
					break;

				case 3:
					exitprogram();
					break;
				}
				break;
        }
    }
}

void main_page_control(int first,int arrPos)
{
    int MAXOPT = 3;
    char options[][50] = {"1. I would like to make a new order please.","2. I would like to have the bill please.","3. I am ready to leave."};
	if(first!=0)
	{
		system("cls");
		FILE *fptr;
		char c;
		system("color 0B");
		
		fptr=fopen("Group13.txt","r");
		c = fgetc(fptr);
		while (c != EOF)
		{
			printf("%c", c);
			c = fgetc(fptr);
		}
		fclose(fptr);

		fptr=fopen("MainPage.txt","r");
		c = fgetc(fptr);
		while (c != EOF)
		{
			printf("%c", c);
			c = fgetc(fptr);
		}
		printf("\n");
		fclose(fptr);
	}
	
    for (int i = 0; i < MAXOPT; i++)
    {
        if(arrPos == i+1)
		{
            printf("								--> %s\n",options[i]);
        }
		else
		{
            printf("								  %s\n",options[i]);
        }
    }
}

int menu_order()
{
	int arID[10],arqty[10],counter=0;
	
	loop:
	int MAXOPT = 11,i = 1,decision;
	char ch,con;
    menu_order_control(1);
    while (1) // for infinte loop
    {
        ch = getch();
        switch (ch)
        {
			case 72: // for up arrow key
				Beep(1000, 100);
				if (i != 1)
				{
					i--;
					menu_order_control(i);
				}
				else{
					i = MAXOPT;
					menu_order_control(MAXOPT);
				}
				break;
        
			case 80: // for Down arrow key
				Beep(1000, 100);
				if (i != 11)
				{
					i++;
					menu_order_control(i);
				}
				else{
					i = 1;
					menu_order_control(1);
				}
				break;
		
			case 13: // for Enter key
				Beep(1000, 100);
				switch (i)
				{
				case 1:
					counter++;
					arID[counter-1]=1;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;

				case 2:
					counter++;
					arID[counter-1]=2;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
						
				case 3:
					counter++;
					arID[counter-1]=3;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
						
				case 4:
					counter++;
					arID[counter-1]=4;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
						
				case 5:
					counter++;
					arID[counter-1]=5;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
						
				case 6:
					counter++;
					arID[counter-1]=6;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
						
				case 7:
					counter++;
					arID[counter-1]=7;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
							
				case 8:
					counter++;
					arID[counter-1]=8;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
							
				case 9:
					counter++;
					arID[counter-1]=9;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
							
				case 10:
					counter++;
					arID[counter-1]=10;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
							
				case 11:
					counter++;
					arID[counter-1]=11;
					printf("\n\n                                                                      Enter Quantity: ");
					scanf("%d",&arqty[counter-1]);
					if (arqty[counter - 1] == 0) 
					{
							counter--;
							printf("                                                                      Order canceled!\n");
							goto ifcancel;
					}
					break;
				}
			printf("                                                                      Great Order Added!\n");
			ifcancel:
			printf("\n                                                                      Continue Order(Y/N): ");
			fflush(stdin);
			scanf("%c",&con);
			if(con=='Y'||con=='y')
			{
				goto loop;
			}
			else
			{
				system("cls");
				FILE *fptr;
				char c, name[100];
				fptr=fopen("BillReady.txt","r");
				c = fgetc(fptr);
				while (c != EOF)
				{
					printf("%c", c);
					c = fgetc(fptr);
				}
				fclose(fptr);
				fflush(stdin);
				printf("\n                                                                            Enter Name: ");
				scanf("%[^\n]",&customer.Name);
				fflush(stdin);				
				printf("\n                                                                            Enter Desicion: ");
				scanf("%d",&decision);					
				if(decision==1)
				{
					Bill_show(arID,arqty,counter);
				}
				else if(decision==2)
				{
				   goto loop;
				}
				else if(decision==3)
				{
					main();
				}
			}
			break;
        }
    }
}

void menu_order_control(int arrPos)
{
    int MAXOPT = 11;
    char menu[11][50]={"1. Burger                               ","2. Hotdog                               ","3. Pizza                                ",
					   "1. Strawbery Fanta                      ","2. Coca Cola                            ","3. A&W                                  ","4. Mineral Water                        ",
					   "1. Canestrelli(Italian Egg York Cookies)","2. Lemon Ricotta                        ","3. Chocolate Souffles                   ","4. Chocolate Puts De Creme              "};
	char price[11][10]={" 5.0"," 4.0","15.0"," 2.0"," 2.0"," 3.0"," 1.5","12.0","17.5"," 6.5","14.0"};

	system("cls");
	FILE *fptr;
	char c;
	system("color 0B");
		
	fptr=fopen("MenuOrder1.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);

	fptr = fopen("MenuOrder3.txt", "w");
	
	fprintf(fptr,"\n                                                                      | |   DISHES                                                (RM)   | |");
    for (int i = 0; i < MAXOPT; i++)
    {
		int counter=0;
		printf("\n                                                                      | |   ");
		fprintf(fptr,"\n                                                                      | |   ");
        if(arrPos == i+1)
		{
            printf("--> %s",menu[i]);
			printf("\b\b\b\b");
			fprintf(fptr,"--> %s",menu[i]);
			counter=1;
        }
		else
		{
            printf("%s",menu[i]);
			fprintf(fptr,"%s",menu[i]);
        }
		printf("              ");
		if(counter==1)
		{
			fprintf(fptr,"          ");
		}
		else
		{
			fprintf(fptr,"              ");
		}
		printf("%s",price[i]);
		fprintf(fptr,"%s",price[i]);
		printf("   | |");
		fprintf(fptr,"   | |");
		if(i==2)
		{
			printf("\n                                                                      | |                                                                | |");
			fprintf(fptr,"\n                                                                      | |                                                                | |");
			printf("\n                                                                      | |   DRINKS                                                       | |");
			fprintf(fptr,"\n                                                                      | |   DRINKS                                                       | |");
		}
		if(i==6)
		{
			printf("\n                                                                      | |                                                                | |");
			fprintf(fptr,"\n                                                                      | |                                                                | |");
			printf("\n                                                                      | |   DESSERTS                                                     | |");
			fprintf(fptr,"\n                                                                      | |   DESSERTS                                                     | |");
		}
    }
	fclose(fptr);

	fptr=fopen("MenuOrder2.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
}

void Bill_show(int arID[],int arqty[],int counter)
{
    int n;
    system("cls");
    system("color 0B");

    int i;
	double sum=0;
    double costs[11]={5.0,4.0,15.0,2.0,2.0,3.0,1.5,12.0,17.5,6.5,14.0};
    char items[11][50]={"Burger","Hotdog","Pizza",
						"Strawbery Fanta","Coca Cola","A&W","Mineral Water",
						"Canestrelli(Italian Egg York Cookies)","Lemon Ricotta","Chocolate Souffles","Chocolate Puts De Creme"};
	
	FILE *fptr;
	char c;
	fptr=fopen("Bill1.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
	
	for(i=0;i<counter;i++)
    {
		printf("\n                                                                        |                                                                |.");
		printf("\n                                                                        | Customer Name: %-48s|.",customer.Name);
		printf("\n                                                                        | ");
		printf("%d. ",i+1);
		printf("%-37s ",items[arID[i]-1]);
		printf("%-3dpiece(s)",arqty[i]);
		printf("RM%-8.2lf",arqty[i]*costs[arID[i]-1]);
		printf(" |.");
        sum=sum+(costs[arID[i]-1]*arqty[i]);
    }
	token ++;
    tokens[token]=sum;
	printf("\n                                                                        |                                                                |.");
	printf("\n                                                                        |                                          Total: RM%-8.2lf     |.",sum);
	printf("\n                                                                        |                                          Token: %d              |.",token);
	printf("\n                                                                        |                                                                |.");
	printf("\n                                                                        |                         THANK YOU                              |.");
	printf("\n");
	fptr=fopen("Bill2.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
    scanf("%d",&n);
    if(n==1)
    {
		Bill_Payment();
    }
	else if(n==2)
	{
		menu_order();
	}
    else if(n==3)
    {
       main_page();;
    }
}

void Bill_Payment() //Kyson
{
    int i, k, choice; //k=token/ordernumber
    double cash, changer;
redo:
    payment_counter++;
    system("cls");
    system("color 0B");
	FILE *fptr;
	char c;
	fptr=fopen("Group13.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);

    printf("\n\n\n\t\t\tEnter your token number: ");
    scanf("%d", &k);
	if (tokens[k] == 0)
    {
        printf("\n\t\t\tToken has already been paid or does not exist.");
        system("pause");
		main_page();
    }
loop:
    printf("\t\t\tYour Total Bill is = RM%.2lf", tokens[k]);
    printf("\n\t\t\tPay your bill: RM");
    scanf("%lf", &cash);
    changer = cash - tokens[k];
    if (changer == 0)
    {
        printf("\n\t\t\tThanks for your payment. Have a great day!\n\t\t\t");
		system("pause");
    }
    else if (changer < 0)
    {
        system("cls");
        printf("\n\t\t\tAmount is not sufficient. :(\n\t\t\tPlease pay the fair price of your bill\n");
        goto loop;
    }
    else
    {
        printf("\n\t\t\tHere is your change : (RM%.2lf - RMRM%.2lf) = RM%.2lf\n\t\t\t", cash, tokens[k], changer);

        for (i = 0; i < 20; i++) //decor
        {
            printf("_");
        }

		printf("\n");

        if (changer >= 100) //rm100
        {
            printf("\n\t\t\t RM100 note(s) = %.0lf\n", floor(changer / 100));
            changer = fmod(changer, 100.0);
        }
        if (changer >= 50 && changer < 100)//rm50
        {
            printf("\n\t\t\t RM50  note(s) = %.0lf\n", floor(changer / 50));
            changer = fmod(changer, 50.0);
        }
        if (changer >= 20 && changer < 50)//rm20
        {
            printf("\n\t\t\t RM20  note(s) = %.0lf\n", floor(changer / 20));
            changer = fmod(changer, 20.0);
        }
        if (changer >= 10 && changer < 20)//rm10
        {
            printf("\n\t\t\t RM10  note(s) = %.0lf\n", floor(changer / 10));
            changer = fmod(changer, 10.0);
        }
        if (changer >= 5 && changer < 10)//rm5
        {
            printf("\n\t\t\t RM5   note(s) = %.0lf\n", floor(changer / 5));
            changer = fmod(changer, 5.0);
        }
        if (changer >= 1 && changer < 5)//rm1
        {
            printf("\n\t\t\t RM1   note(s) = %.0lf\n", floor(changer / 1));
            changer = fmod(changer, 1.0);
        }
        if (changer >= 0.5 && changer < 1)//50sen
        {
            printf("\n\t\t\t RM0.5 cent(s) = %.0lf\n", floor(changer / 0.5));
            changer = fmod(changer, 0.5);
        }
        if (changer >= 0.2 && changer < 1)//20sen
        {
            printf("\n\t\t\t RM0.2 cent(s) = %.0lf\n", floor(changer / 0.2));
            changer = fmod(changer, 0.2);
        }
        if (changer >= 0.1 && changer < 1)//10sen
        {
            printf("\n\t\t\t RM0.1 cent(s) = %.0lf\n", floor(changer / 0.1));
            changer = fmod(changer, 0.1);
        }
        if (changer >= 0.05 && changer < 1)//5sen
        {
            printf("\n\t\t\t RM0.05 cent(s) = %.0lf\n", floor(changer / 0.05));
            changer = fmod(changer, 0.05);
        }

        printf("\t\t\t");

        for (i = 0; i < 20; i++) //decor
        {
            printf("_");
        }

		tokens[k] = 0;
		printf("\n\n\t\t\t");
		system("pause");
    }

	system("cls");

	fptr=fopen("AfterPayment.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
	
    scanf("%d", &choice);
    if (choice == 1)
    {
		goto redo;
    }
    else if (choice == 2)
    {
        main_page();
    }
	else if (choice == 3)
    {
        exitprogram();
    }
}

int main()
{
	main_page();
    return 0;
}