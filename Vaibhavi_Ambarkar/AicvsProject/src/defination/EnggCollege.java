package defination;

public class EnggCollege {
	private String college_name;
	private int cutoff_rank_engg;
	private String category;
	private String branch;
	//getters
	public String getCollege_name() {
		return college_name;
	}
	public int getCutoff_rank_engg() {
		return cutoff_rank_engg;
	}
	public String getCategory() {
		return category;
	}
	public String getBranch() {
		return branch;
	}
	//constructor
	public EnggCollege(String college_name, String branch, int cutoff_rank_engg, String category) {
		this.college_name = college_name;
		this.branch = branch;
		this.cutoff_rank_engg = cutoff_rank_engg;
		this.category = category;
		
	}
	
	
	
	

}
