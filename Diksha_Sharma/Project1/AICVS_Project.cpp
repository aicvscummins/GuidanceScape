#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 10

struct Patient
{
	int id ; 
	char name[50] ;
	struct Patient *next ;
};

int menu(void);// menu function declaration
int enqueue(struct Patient **ffront ,struct Patient **frear,struct Patient *p) ;
int dequeue(struct Patient **ffront ,struct Patient **frear,struct Patient *fdelement);
int isfull(struct Patient **ffront ,struct Patient **frear,struct Patient **newnode) ;
int isempty(struct Patient **ffront ,struct Patient **frear) ;
int displayFirst(struct Patient **ffront ,struct Patient **frear,struct Patient *p) ;
int displayAll(struct Patient **ffront1 ,struct Patient **frear1,struct Patient **ffront2 ,struct Patient **frear2,struct Patient **ffront3 ,struct Patient **frear3);

int main(void)
{
	struct Patient *front1 = NULL ;
	struct Patient *rear1 = NULL ;
	struct Patient *front2 = NULL ;
	struct Patient *rear2 = NULL ;
	struct Patient *front3 = NULL ;
	struct Patient *rear3  = NULL ;
	char name[50] = {'\0'} ;
	struct Patient p = {0} ;
	int priority = 0 ;
	int id = 0 ;
	int succ = 0 ;
	int choice = 0;// variable to store the choice given by user
	do
	{
		choice = menu();//menu function call
		switch(choice)
		{
			case 1:	printf("\n Enter Patient name to add \n");
					scanf("%s",p.name);
					p.id = p.id +1 ;
					printf("\nPatient priorities are as follows:");
					printf("\n1. Serious illness");
					printf("\n2. Medium illness");
					printf("\n3. General illness");					
					printf("\n Enter patient's priority\n");					
					scanf("%d",&priority) ;
					if(priority == 1)
					{
						succ = enqueue(&front1 ,&rear1,&p);
					}
					else if(priority == 2)
					{
						succ = enqueue(&front2 ,&rear2,&p);
					}
					else if(priority == 3)
					{
						succ = enqueue(&front3 ,&rear3,&p);
					}
					else
					{
						printf("\n Enter valid priority\n") ;
					}
					
					if(succ == 1)
					{
						printf("\n Patient added successfully\n");
					}
					else
					{
						printf("\n Not able to add the patient\n");
					}
					break;
				
			case 2:	succ = dequeue(&front1,&rear1,&p);
					if(succ == 1)
					{
						printf("\n The patient treated is %s \t\t",p.name);
					}
					else
					{
						succ = dequeue(&front2,&rear2,&p);
						if(succ == 1)
						{
							printf("\n The patient treated is %s \t\t",p.name);
						}
						else
						{
							succ = dequeue(&front3,&rear3,&p);
							if(succ == 1)
							{
								printf("\n The patient treated is %s \t\t",p.name);
							}
							else
							{
								succ = 0 ;
								
							}
						}
					}
					if(succ == 0)
					{
						printf("\n No patients to treat \n");
					}
					break;
				
			case 3:	succ = displayFirst(&front1,&rear1,&p);
					if(succ == 1)
					{
						printf("\nThe first patient to treat is %s \n",p.name);
					}
					else
					{
						succ = displayFirst(&front2,&rear2,&p);
						if(succ == 1)
						{
							printf("\nThe first patient to treat is %s \n",p.name);
						}
						else
						{
							succ = displayFirst(&front3,&rear3,&p);
							if(succ == 1)
							{
								printf("\nThe first patient to treat is %s \n",p.name);
							}
							else
							{
								succ = 0 ;								
							}
						}
					}
					if(succ == 0)
					{
						printf("\n No patients to treat \n");
					}					
					break;
					
			case 4:	succ = displayAll(&front1,&rear1,&front2,&rear2,&front3,&rear3);
					if(succ == 0)
					{
						printf("\n No patients to display\n");
					}
					break;
				
			case 0:	printf("\n exiting.. \n");
			    	break;	
						
		}
	}while(choice!=0);
	return 0;
}

int menu(void)
{
	int choice = 0;
	do
	{
		printf("\n\t Menu operations are as follows :");
		printf("\n\t 1.Add a patient");
		printf("\n\t 2.Treat a patient");
		printf("\n\t 3.Display first patient to be treated");
		printf("\n\t 4.Display all Patients");
		printf("\n\t 0.Exit\n");
		printf("\nEnter your choice\t");
		scanf("%d",&choice);
	}while(choice<0 || choice>4);
	
	return choice;
}

int isfull(struct Patient **ffront ,struct Patient **frear,struct Patient **newnode)
{
	int succ = 0 ;
	(*newnode) = (struct Patient *)calloc(1,sizeof(struct Patient));
	if((*newnode) == NULL)
	{
		succ = 0 ;
	}
	else
	{
		succ = 1 ;
	}
	return succ ;
}

int enqueue(struct Patient **ffront ,struct Patient **frear,struct Patient *p)
{
	struct Patient *newnode = NULL ;
	int succ = 0;
	if(isfull(ffront ,frear,&newnode) == 0)
	{
		succ = 0 ;
	}
	else
	{
		newnode->id = p->id;
		strcpy(newnode->name ,p->name) ;
		if(((*ffront) == NULL) && ((*frear) == NULL))
		{
			(*ffront) = newnode ;
			(*frear) = newnode ;
			succ = 1 ;
		}
		else
		{			
			(*frear)->next = newnode ;
			(*frear) = newnode ;
			succ = 1 ;
		}
		
	}	
	return succ ;
	
}

int isempty(struct Patient **ffront ,struct Patient **frear)
{
	int succ = 0;
	if(((*ffront) == NULL) && ((*frear )== NULL))
	{
		succ = 0 ;
	}
	else
	{
		succ = 1 ;
	}
	return succ ;
	
}
int dequeue(struct Patient **ffront ,struct Patient **frear,struct Patient *fdelement)
{
	struct Patient *front = NULL ;
	struct Patient *rear = NULL ;
	int succ = 0 ;
	front = *ffront ;
	rear = *frear ;
	if(isempty(ffront,frear) == 0)
	{
		succ = 0 ;
	}
	else
	{
		if((*ffront == *frear))
		{
			fdelement->id = front->id ;
			strcpy(((fdelement)->name),((front)->name));
			(*ffront)= (*ffront)->next ;
			(*frear) = NULL ;
		}
		else
		{
			fdelement->id = front->id ;
			strcpy(((fdelement)->name),((front)->name));
			(*ffront )= (*ffront)->next ;
		}
		
		succ = 1 ;
	}
	return succ ;
}


int displayAll(struct Patient **ffront1 ,struct Patient **frear1,struct Patient **ffront2 ,struct Patient **frear2,struct Patient **ffront3 ,struct Patient **frear3)
{
	int succ=0 ;
	int delement = 0 ;
	struct Patient *front = NULL ;
	struct Patient *rear = NULL ;
	struct Patient p = {0};
	printf("\nThe Patients in queue are as follows:\n") ;
	while((*ffront1) != NULL)
	{
		dequeue(ffront1,frear1, &p);
		printf("\n%d",p.id) ;
		printf("\t%s",p.name) ;
		enqueue(&front ,&rear,&p);				
	}	
	*ffront1 = NULL ;	
	*frear1 = NULL ;
	while(front != NULL)
	{
		succ = dequeue(&front,&rear, &p);
		enqueue(ffront1 ,frear1,&p);
		succ = 1 ;			
	}
	
	while((*ffront2) != NULL)
	{
		dequeue(ffront2,frear2, &p);
		printf("\n%d",p.id) ;
		printf("\t%s",p.name) ;
		enqueue(&front ,&rear,&p);				
	}	
	*ffront2 = NULL ;	
	*frear2 = NULL ;
	while(front != NULL)
	{
		succ = dequeue(&front,&rear, &p);
		enqueue(ffront2 ,frear2,&p);
		succ = 1 ;			
	}
	
	while((*ffront3) != NULL)
	{
		dequeue(ffront3,frear3, &p);
		printf("\n%d",p.id) ;
		printf("\t%s",p.name) ;
		enqueue(&front ,&rear,&p);				
	}	
	*ffront3 = NULL ;	
	*frear3 = NULL ;
	while(front != NULL)
	{
		succ = dequeue(&front,&rear, &p);
		enqueue(ffront3 ,frear3,&p);
		succ = 1 ;			
	}
	return succ ;
}


int displayFirst(struct Patient **ffront ,struct Patient **frear,struct Patient *p)
{
	int succ = 0 ;
	struct Patient *front = NULL ;
	front = *ffront ;
	
	if(front != NULL)
	{
		p->id = front->id ;
		strcpy((p->name),((front)->name));
		succ = 1 ;
	}
	return succ ;
}




