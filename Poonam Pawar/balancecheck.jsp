
<%@page import="java.sql.*"%>
<%@page import = "java.util.logging.Logger" %>
      <% Logger logger = Logger.getLogger(this.getClass().getName());%>
<%!
Connection con;
Statement st;
ResultSet rs;
int balance;
String name;
public void jspInit()
{
	try
	{
	 Class.forName("com.mysql.jdbc.Driver"); 
     con= DriverManager.getConnection("jdbc:mysql://localhost:3306/ATM","root","root");
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
int cardnumber=Integer.parseInt(request.getParameter("cardNumber"));
//logger.info("ty"+request.getParameter("cardNumber"));

%>
<%
try
{
	//logger.info("12");
st=con.createStatement();
//logger.info("ty");
rs=st.executeQuery("select Balance from ATM where Cnum="+cardnumber);
if(rs.next())
{
	
	balance=rs.getInt(1);

}
rs.close();
rs=st.executeQuery("select Name from ATM where Cnum="+cardnumber);
if(rs.next())
{
	
	name=rs.getString(1);

}

}
catch(Exception e)
{
	e.printStackTrace();
}
st.close();
%>

<html>
<style><%@include file="balancecheck.css"%></style>
<body bgcolor=cyan>
<div class=balance>


<h1>Welcome <%=name%>,</h1> <h2>Available Balance In Your Saving Account is: <%=balance%> </h2>
</div>
<div class=anchor>
<a href="Atm.html">Click Here To Logout</a>
<br>
</div>
<marquee>Dear Customer,for Security Purpose Always Logout From Your Account While Leaving The Atm.Thank You.</marquee>


</body>
</html>