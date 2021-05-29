#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  char productname[50];
  int quantity;
  float price;
  int data;
  struct node *next;
};
struct node *heada = NULL;
struct node *headc = NULL;
struct node *head_s;
struct node *taila = NULL;
struct node *tailc = NULL;
struct node *newnode;
void
adminmenu ()
{
  printf ("\t\t\t\t\t1.View total sales\n");
  printf ("\t\t\t\t\t2.Add new items\n");
  printf ("\t\t\t\t\t3.Delete items \n");
  printf ("\t\t\t\t\t4.Display order list\n");
  printf ("\t\t\t\t\t5.Back to main menu\n");
  printf ("\t\t\t\t\tEnter your choice:");
}

void
customermenu ()
{
  printf ("\t\t\t\t\t1.Place your order\n");
  printf ("\t\t\t\t\t2.View your ordered items\n");
  printf ("\t\t\t\t\t3.Delete an item from the order \n");
  printf ("\t\t\t\t\t4.Display final bill\n");
  printf ("\t\t\t\t\t5.Back to main menu\n");
  printf ("\t\t\t\t\tEnter your choice:");
}

struct node *
createadmin (struct node *head, int data, char productname[25], float price)
{
  newnode = (struct node *) malloc (sizeof (struct node));
  newnode->data = data;
  newnode->price = price;
  newnode->quantity = 0;
  strcpy (newnode->productname, productname);
  newnode->next = NULL;
  struct node *temp = head;
  if (temp == NULL)
    {
      heada = taila = newnode;
    }
  else
    {
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = newnode;
      taila = newnode;
    }
  return heada;
}

struct node *
createcustomer (struct node *head, int data, int quantity)
{
  newnode = (struct node *) malloc (sizeof (struct node));
  struct node *temp1 = heada;
  int flag = 0;
  while (temp1 != NULL)
    {
      if (temp1->data == data)
	{
	  flag = 1;
	  break;
	}
      temp1 = temp1->next;
    }
  if (flag == 1)
    {
      newnode->data = data;
      newnode->price = quantity * (temp1->price);
      newnode->quantity = quantity;
      strcpy (newnode->productname, temp1->productname);
      newnode->next = NULL;
      struct node *temp = head;
      if (temp == NULL)
	{
	  headc = tailc = newnode;
	}
      else
	{
	  while (temp->next != NULL)
	    temp = temp->next;
	  temp->next = newnode;
	  tailc = newnode;
	}
    }
  else
    {
      printf ("\n\t\t\t\t\tThis item is not present in menu\n");
    }
  return headc;
}

void
displayList (struct node *head)
{
  struct node *temp1 = head;
  if (temp1 == NULL)
    {
      printf ("\n\t\t\t\t\tList is Empty!!!\n\n");
    }
  else
    {
      printf ("\n");
      while (temp1 != NULL)
	{
	  if (temp1->quantity == 0)
	    {
	      printf ("\t\t\t\t\t%d\t%s\t%0.2f\n", temp1->data,
		      temp1->productname, temp1->price);
	    }
	  else
	    {
	      printf ("\t\t\t\t\t%d\t%s\t%d\t%0.2f\n", temp1->data,
		      temp1->productname, temp1->quantity, temp1->price);
	    }
	  temp1 = temp1->next;

	}
      printf ("\n");

    }
}

struct node *
totalsales (int data, int quantity)
{

  newnode = (struct node *) malloc (sizeof (struct node));
  int flag = 0;
  struct node *temp1 = heada;
  while (temp1->data != data)
    {
      temp1 = temp1->next;
    }
  newnode->data = data;
  newnode->price = quantity * (temp1->price);
  newnode->quantity = quantity;
  strcpy (newnode->productname, temp1->productname);
  newnode->next = NULL;
  struct node *temp = head_s;
  if (temp == NULL)
    {
      head_s = newnode;
    }
  else
    {
      while (temp->next != NULL)
	{
	  if (temp->data == data)
	    {
	      flag = 1;
	      break;
	    }
	  temp = temp->next;
	}
      if (flag == 1)
	{
	  temp->quantity += newnode->quantity;
	  temp->price += newnode->price;
	}
      else
	{
	  temp->next = newnode;
	}
    }
  return head_s;
}

void
calculatetotalsales ()
{

  struct node *temp = heada;
  while (temp != NULL)
    {
      head_s = totalsales (temp->data, temp->quantity);
      temp = temp->next;
    }
}

struct node *
delete (int data, struct node *head, struct node *tail)
{
  if (head == NULL)
    {
      printf ("\nNo items\n");
    }
  else
    {
      struct node *temp;
      if (data == head->data)
	{
	  temp = head;
	  head = head->next;
	  free (temp);
	}

      else
	{
	  temp = head;
	  struct node *temp1 = temp;

	  while (data != temp->data)
	    {
	      temp1 = temp;
	      temp = temp->next;
	    }
	  temp1->next = temp->next;
	  free (temp);
	}
    }
  return head;
}

int
deleteadmin ()
{
  printf ("\n\t\t\t\t\tEnter serial no of item to be deleted:");
  int num;
  scanf ("%d", &num);
  struct node *temp = heada;
  while (temp != NULL)
    {
      if (temp->data == num)
	{
	  heada = delete (num, heada, taila);
	  return 1;
	}
      temp = temp->next;
    }
  return 0;

}

int
deletecustomer ()
{
  printf ("\n\t\t\t\t\tEnter serial no of item to be deleted:");
  int num;
  scanf ("%d", &num);
  struct node *temp = headc;
  while (temp != NULL)
    {
      if (temp->data == num)
	{
	  headc = delete (num, headc, tailc);
	  return 1;
	}
      temp = temp->next;
    }
  return 0;

}

void
displaybill ()
{
  displayList (headc);
  struct node *temp = headc;
  float total_price = 0;
  while (temp != NULL)
    {
      total_price += (temp->quantity) * (temp->price);
      temp = temp->next;
    }
  printf ("\t\t\t\t\tTotal price:%0.02f\n", total_price);
}

struct node *
deleteList (struct node *head)
{
  if (head == NULL)
    {
      return NULL;
    }
  else
    {
      struct node *n, *temp = head;
      while (temp != NULL)
	{
	  n = temp->next;
	  free (temp);
	  temp = n;
	}
      head = NULL;
    }
  return head;
}

void
admin ()
{

  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  printf ("\n\t\t\t\t\t\tADMIN SECTION\n");
  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  while (1)
    {
      adminmenu ();
      int opt;
      scanf ("%d", &opt);
      if (opt == 5)
	{
	  break;
	}
      switch (opt)
	{
	case 1:
	  displayList (head_s);
	  break;
	case 2:
	  printf ("\n\t\t\t\t Enter serial no of item:");
	  int num, flag = 0;
	  char name[50];
	  float price;
	  scanf ("%d", &num);
	  struct node *temp = heada;
	  while (temp != NULL)
	    {
	      if (temp->data == num)
		{
		  printf ("Item with given serial no already exist!!\t\t\n");
		  flag = 1;
		  break;
		}
	      temp = temp->next;

	    }
	  if (flag == 1)
	    {
	      break;
	    }
	  printf ("\t\t\t\t\tEnter product name:");
	  scanf ("%s", name);
	  printf ("\t\t\t\t\tEnter price:");
	  scanf ("%f", &price);
	  heada = createadmin (heada, num, name, price);
	  printf ("New product is added to the list!!!\n");
	  break;
	case 3:
	  if (deleteadmin ())
	    {
	      printf ("\n Updated list of items is\n");
	      displayList (heada);

	    }
	  else
	    printf ("\n Item with given serial no does not exist\n\n");
	  break;

	case 4:
	  printf ("\n\t\t\t\t\t	order menu\n");
	  displayList (heada);
	  break;
	default:
	  printf ("\n\t\tWrong input!! Please choose valid option\n");
	  break;
	}
    }
}

void
customer ()
{
  int flag = 0, j = 1;
  char ch;
  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  printf ("\n\t\t\t\t\t\tCUSTOMER SECTION\n");
  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  while (1)
    {
      customermenu ();
      int opt;
      scanf ("%d", &opt);
      if (opt == 5)
	{
	  break;
	}
      switch (opt)
	{
	case 1:
	  displayList (heada);
	  printf
	    ("\n\t\t\t\t\tEnter number corresponding to the item you want order:");
	  int n;
	  scanf ("%d", &n);
	  printf ("\t\t\t\t\tEnter quantity:");
	  int quantity;
	  scanf ("%d", &quantity);
	  headc = createcustomer (headc, n, quantity);
	  break;
	case 2:
	  printf ("\n\t\t\t\t\tList if ordered items\n");
	  displayList (headc);
	  break;
	case 3:
	  if (deletecustomer ())
	    {
	      printf ("\n Updated list of items is\n");
	      displayList (headc);

	    }
	  else
	    printf
	      ("\n\t\t\t\t\tItem with given serial no does not exist\n\n");
	  break;

	case 4:
	  calculatetotalsales ();
	  printf ("\n\t\t\t\t\tFinal Bill\n");
	  displaybill ();
	  headc = deleteList (headc);
	  printf
	    ("\n\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t");
	default:
	  printf ("\n\t\tWrong input!! Please choose valid option\n");
	  break;
	}
      if (flag == 1)
	break;
    }
}

int
mainmenu ()
{
  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  printf ("\n\t\t\t\t\t\tWELCOME TO SHOP MANAGEMENT SYSTEM\n");
  printf
    ("\n\t\t\t------------------------------------------------------------------------------------\n");
  printf ("1.Admin Section\n");
  printf ("2.Customer Section\n");
  printf ("3.Exit\n");
  printf ("Enter your choice:");
  return 0;
}

int
main ()
{
  heada = createadmin (heada, 1, "toothpaste", 60);
  heada = createadmin (heada, 2, "soap", 80);
  heada = createadmin (heada, 3, "Brush", 20);
  while (1)
    {
      mainmenu ();
      int choice;
      scanf ("%d", &choice);
      if (choice == 3)
	{
	  printf ("\n\t\t\t\t\t*THANK YOU!!!*\n");
	  break;
	}
      switch (choice)
	{
	case 1:
	  admin ();
	  break;
	case 2:
	  customer ();
	  break;
	case 3:
	  break;
	default:
	  printf (" Wrong Input!! Please choose valid option\n");
	  break;
	}
    }
}
