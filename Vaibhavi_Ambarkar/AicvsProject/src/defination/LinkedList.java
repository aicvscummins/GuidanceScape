package defination;

import java.util.ArrayList;


public class LinkedList {
	//Represent a node of the singly linked list    
    class Node{   
    	MedCollege data;  
    	EnggCollege dat;
        Node next;    
            
        public Node(MedCollege data) { 
            this.data = data;    
            this.next = null;    
        }    
        public Node(EnggCollege dat) {
			this.dat= dat;
			this.next = null;
		}	
    }    
    
    public Node head = null;    
    public Node tail = null;    
        
    //addNode() will add a new node to the list    
    public void addNode(MedCollege data) {    
        Node newNode = new Node(data);  //Create a new node      
            
        //Checks if the list is empty    
        if(head == null) {       
            head = newNode;    
            tail = newNode;    
        }    
        else {    
            tail.next = newNode;      
            tail = newNode;    
        }    
    }   
    
    public void addNode(EnggCollege data) {    
		Node newNode = new Node(data);//create new node   
        if(head == null) {    
            head = newNode;    
            tail = newNode;    
        }    
        else {    
        tail.next = newNode;       
        tail = newNode;    
      }  
	}
    
    //medical search function
    public void search(int myrank) { 
    	ArrayList<String> myclg = new ArrayList<String>();   
        Node current = head;       
        while(current != null) {
        		if(myrank <= current.data.getCutoff_rank())
        		{
        			myclg.add(current.data.getName());
        		}
            current = current.next; 
          }
        if(myclg.isEmpty()) {
        	System.out.println("Couldn't match a Gov MBBS college with your AIR and category");
        	
        }
        else {
            System.out.println("Applicable clgs are :");
            for(int i=0;i < myclg.size();i++) {
        	   System.out.println( i+1 +" "+ myclg.get(i));
            }
        }
    }
     
    //Engg searching function
     public void search(int myrank,String branch) { 
        	ArrayList<String> myclg = new ArrayList<String>();   
            Node current = head;       
            while(current != null) {
            	if(current.dat.getBranch().equals(branch)) {
            		  if(myrank <= current.dat.getCutoff_rank_engg())
            		   {
            			  myclg.add(current.dat.getCollege_name());
            		   }
            	}
                current = current.next;    
            }
        if(myclg.isEmpty()) {
        	System.out.println("Couldn't match a college with your rank,category with desired branch");
        	
        }
        else {
            System.out.println("Applicable clgs are :");
            for(int i=0;i < myclg.size();i++) {
        	   System.out.println( i+1 +" "+myclg.get(i));
            }
       }
   }
}

