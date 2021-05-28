<%@page import="java.sql.*"%>
<%!
Connection con;
PreparedStatement ps;
ResultSet rs;
int digit=0;
int EncryptPin=0;
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
			ps.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

%>
<%

	

ps=con.prepareStatement("select* from ATM where Cnum=? and Pin=?");


int CardNumber=Integer.parseInt(request.getParameter("t1"));
int DecryptPin=Integer.parseInt(request.getParameter("t2"));



while(DecryptPin!=0)
{
	 digit=DecryptPin % 10;
	 EncryptPin=EncryptPin*10+digit;
	 DecryptPin/=10;
}
boolean flag=false;
try
	{
	ps.setInt(1,CardNumber);
    ps.setInt(2,EncryptPin);
	rs=ps.executeQuery();
    if(rs.next())
	flag=true;
	}
  catch(Exception e)
	{
		e.printStackTrace();
	}




%>
<html>
<style><%@include file="login.css"%></style>
<div class="login">
<body>
<% if (flag) { %>
<div class="form">
<h1 style ="color:black;">login successfully</h1>
<form method="post" action="balancecheck.jsp?cardNumber=<%=CardNumber%>">
<input type=submit value=BalanceCheck>
</form>


<form method="post" action="Withdraw.jsp?cardNumber=<%=CardNumber%>">

<input type=submit value=CashWithdraw>
</form>
</div>
<marquee >
Thank You For Visiting ATM  Select the Appropriate  options that you Want.Never Share Your Pin with Anyone. </marquee>
</body>
</div>
</html>
<% } else { %>
<h1 style ="color:white;">OOPS......Something Went Wrong Enter Correct Password or Atmnumber</h1>
<% } %>




