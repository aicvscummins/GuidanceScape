package Travel;

import java.util.Scanner;

public class User extends AgencyProp{

	public static void main(String[] args) {
		
final AgencyProp [] agencies= new AgencyProp[7];
		
		String [] loc0= {"Delhi","Kolkata","Assam","Goa","Kashmir"};
		agencies[0]=new AgencyProp(45623,"Wonderlust",loc0,20000,3.6);
		
		String [] loc1= {"Amritsar","Kolkata","Kanyakumari","Ladakh","Ahmedabad"};
		agencies[1]=new AgencyProp(86032,"Prestige",loc1,25000,4.5);
		
		String [] loc2= {"Varanasi","Indore","Kanyakumari","Goa","Kashmir"};
		agencies[2]=new AgencyProp(23148,"Safar",loc2,20000,3.6);
		
		String [] loc3= {"Delhi","Hrishikesh","Assam","Ladakh","Kashmir"};
		agencies[3]=new AgencyProp(86543,"Starlight",loc3,30000,3.2);
		
		String [] loc4= {"Varanasi","Kolkata","Mysore","Konark","Ahmedabad"};
		agencies[4]=new AgencyProp(34258,"Shree",loc4,35000,4.8);
		
		String [] loc5= {"Delhi","Hrishikesh","Assam","Goa","Kashmir"};
		agencies[5]=new AgencyProp(90085,"Rainbow",loc5,25000,3.8);
		
		String [] loc6= {"Amritsar","Indore","Mysore","Konark","Kashmir"};
		agencies[6]=new AgencyProp(43765,"Kafilaa",loc6,30000,4.4);
		
		
		int opt;
		Scanner scan = new Scanner(System.in);
		System.out.println("WELCOME");
		System.out.println("Browse through travel companies");
		do {
			System.out.println("Filters available-");
			System.out.println("1.Locationwise\n2.Price(from low to high)\n3.Customer ratings\n4.Exit");
			opt= scan.nextInt();
			switch(opt)
			{
			case 1: locwise(agencies);
			        break;
			case 2:pricewise(agencies);
				    break;
			case 3:ratingwise(agencies);
			       break;
			case 4: System.out.println("Thank you for using this application");
			        break;
			}
		}while(opt!=4);
		scan.close();

	}

}
