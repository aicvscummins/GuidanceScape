package client;
import defination.MedObj;
import defination.EnggObj;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); 
		int choice = 0;
		MedObj M = new MedObj();
        M.startPushing();
        EnggObj E= new EnggObj();
        E.startPushing();
		do {
		System.out.print("\n\t1.Medical - NEET\n\t2.Engineering - CET\n\t0.Exit\nEnter your choice : "); 
		choice = sc.nextInt();
		 switch(choice) {
		 case 1 : System.out.println("Enter your ALL INDIA RANK of NEET : ");  
		          int myrank= sc.nextInt();
		          System.out.print("Enter your category : ");  
		          String cat = sc.next();
		          String catgy = cat.toUpperCase();
		          M.searching_med(myrank,catgy);   
		          break;
		 case 2 : System.out.println("Enter your CET Rank : ");
                  myrank = sc.nextInt();
                  System.out.println("Enter your category : ");
                  String cate=sc.next();
                  System.out.println("Enter desired branch : ");
                  String br=sc.next();
                  String categry=cate.toUpperCase();
                  String branch = br.toUpperCase();
                  E.searching_engg(myrank, categry,branch);
                  break;
		 case 0 : System.out.println("\nExiting, Thank You!");  
		          break;
         default :System.out.println("\nInvalid Input");
		}
	}while(choice != 0);
	sc.close();	
  }
}