
<%@page import="java.sql.*"%>

<%!
Connection con;
Statement st;
ResultSet rs;
int balance;
int isUpdateSuccess;
public void jspInit()
{
	try
	{
	 Class.forName("com.mysql.jdbc.Driver"); 
     con= DriverManager.getConnection("jdbc:mysql://localhost:3306/ATM","root","root");
     st=con.createStatement();
	}
	catch(Exception e)
	{
		e.printStackTrace();
	}
}
	public void jspDestroy()
	{
		try
		{
			rs.close();
			con.close();
			st.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

%>
<%
int Amount=Integer.parseInt(request.getParameter("amount"));
int cardnumber=Integer.parseInt(request.getParameter("cardNumber"));
%>
<%
try
{
rs=st.executeQuery("select Balance from ATM where Cnum="+cardnumber);
if(rs.next())
{
	 balance=rs.getInt(1);
	 
}
rs.close();

}
catch(Exception e)
{
	e.printStackTrace();
}
%>
<%
if(Amount<balance && Amount>0 && Amount!=0)
{
try
	    {
		 String sql=("Update ATM Set Balance = Balance-"+Amount+ " where Cnum ="+cardnumber);
		
		 isUpdateSuccess= st.executeUpdate(sql);
	    }
	 catch(Exception e)
	 {
		 e.printStackTrace();
	 }
}
%>
<html>
<style><%@include file="balancecheck.css"%></style>
<body>
<% if (isUpdateSuccess==1) { %><div class=balance>
<h1>Transaction is Processing.....Please collect your money</h1></div>
<% } else { %>
<% } if(balance<Amount){ %>
<h1>Requested Amount doesn't exist in your Account.</h1>
<% } if(Amount<0){ %>
<h1>Please Enter Positive Amount.</h1>
<% } if(Amount==0){ %>
<h1>Please Enter Non-Zero Positive Amount.</h1>
<% } %>
<div class=anchor>
<a href="Atm.html">Click Here To Logout</a>
</div>
<marquee>Dear Customer,for Security Purpose Always Logout From Your Account While Leaving The Atm.Thank You.</marquee>
</body>

</html>
