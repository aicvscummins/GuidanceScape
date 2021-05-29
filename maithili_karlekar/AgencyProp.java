package Travel;
import java.util.Scanner;
public class AgencyProp {
	//Attributes to be considered
	public int RegNum;
	public String name;
	public String[] locations;
	public long price;
	public double rating;
	
	
	//default constructor
	AgencyProp(){}
	
	//parameterized constructor
	
	public AgencyProp(int regNum, String name, String[] locations, long price, double rating) {
		super();
		RegNum = regNum;
		this.name = name;
		this.locations = locations;
		this.price = price;
		this.rating = rating;
	}
	

	//getter setters

	public int getRegNum() {
		return RegNum;
	}

	

	public void setRegNum(int regNum) {
		RegNum = regNum;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String[] getLocations() {
		return locations;
	}

	public void setLocations(String[] locations) {
		this.locations = locations;
	}

	public long getPrice() {
		return price;
	}

	public void setPrice(long price) {
		this.price = price;
	}

	public double getRating() {
		return rating;
	}

	public void setRating(double rating) {
		this.rating = rating;
	}
	
	
	public static void locwise(AgencyProp[] agencies)
	{
		Scanner scan= new Scanner(System.in);
		System.out.println("From the given list below, enter the location you wish to visit");
		System.out.println("1.Delhi\n2.Kolkata\n3.Assam\n4.Goa\n5.Kashmir\n6.Amritsar"
				+ "\n7.Kanyakumari\n8.Ladakh\n9.Ahmedabad\n10.Varanasi\n11.Indore\n12.Hrishikesh"
				+ "\n13.Mysore\n14.Konark");
		String s=scan.nextLine();
		System.out.println("Here is the list of travel companies which have location "+s);
		System.out.println(" ");
		for(AgencyProp a: agencies )
		{
			for(int i=0;i<5;i++ )
			{
				if((a.locations[i]).equalsIgnoreCase(s))
				{
					System.out.println("Registrstion no- "+a.RegNum);
					System.out.println("Name- "+a.name+" Travel Company");
					System.out.println("Price Starting from- "+a.price);
					System.out.println("Customer ratings- "+a.rating);
					System.out.println("-----------------------------------");
					break;
				}
			}
		}
	}
	public static void pricewise(AgencyProp [] agencies)
	{
		AgencyProp [] temp=new AgencyProp[7];
		temp=agencies;
		AgencyProp l;
		for(int a=0;a<7;a++)
		{
			for(int i=a+1;i<7;i++)
			{
				if((temp[a].price)>=(temp[i].price))
				{
					l=temp[i];
					temp[i]=temp[a];
					temp[a]=l;
				
				}
				
			}
			
		}
		System.out.println("From low to high:");
		System.out.println(" ");
		for(AgencyProp p: temp)
		{
			System.out.println("Price starting from: "+p.price);
			System.out.println("Registrstion no- "+p.RegNum);
			System.out.println("Name- "+p.name+" Travel Company");
			System.out.println("Customer ratings- "+p.rating);
			System.out.println("-----------------------------------");
		
		}
		
		
	}
	public static void ratingwise(AgencyProp [] agencies)
	{
		AgencyProp [] temp=new AgencyProp[7];
		temp=agencies;
		AgencyProp l;
		for(int a=0;a<7;a++)
		{
			for(int i=a+1;i<7;i++)
			{
				if((temp[a].rating)<=(temp[i].rating))
				{
					l=temp[i];
					temp[i]=temp[a];
					temp[a]=l;
				
				}
				
			}
			
		}
		System.out.println("Customer ratings rom high to low:");
		System.out.println(" ");
		for(AgencyProp p: temp)
		{
			System.out.println("Customer ratings- "+p.rating);
			System.out.println("Registrstion no- "+p.RegNum);
			System.out.println("Name- "+p.name+" Travel Company");
			System.out.println("Price starting from: "+p.price);
			System.out.println("-----------------------------------");
		
		}
	}

}
