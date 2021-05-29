package defination;

public class MedCollege {
	private String name;  
	private int cutoff_rank;
	private String category;
	
	//getters
	public String getName() {
		return name;
	}
	public int getCutoff_rank() {
		return cutoff_rank;
	}
	public String getCategory() {
		return category;
	}
	
	//Constructor
	public MedCollege(String name, int cutoff_rank, String category) {  
	    this.name = name;  
	    this.cutoff_rank = cutoff_rank;
	    this.category = category;
	}  


}
