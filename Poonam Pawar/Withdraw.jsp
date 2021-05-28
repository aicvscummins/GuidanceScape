<%int cardnumber=Integer.parseInt(request.getParameter("cardNumber"));
%>

<html>

<style><%@include file="withdraw.css"%></style>
<body>
<div class="login" >
<div class="form">
<h1>Enter Amount</h1>
<form method=post action="Withdraw1.jsp?cardNumber=<%=cardnumber%>">
<input type="number" placeholder= Amount name=amount  required>
<input type=submit value=Proceed>
</form>
</div>
</div>
<body>

</body>
</html>