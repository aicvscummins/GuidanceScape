//for add a review page

function checkfname()
{
	var input = document.getElementById("fname").value;
	//regex for validation
	var regex = /^[a-zA-Z]{2,15}$/;

	if (regex.test(input))
	{
		document.getElementById("fnamev").innerHTML = "";
		return true;
	}
	else
	{
		document.getElementById("fnamev").innerHTML = "Input invalid.";
		return false;
	}
}

function checklname()
{
	var input = document.getElementById("lname").value;
	//regex for validation
	var regex = /^[a-zA-Z]{2,15}$/;

	if (regex.test(input))
	{
		document.getElementById("lnamev").innerHTML = "";
		return true;
	}
	else
	{
		document.getElementById("lnamev").innerHTML = "Input invalid.";
		return false;
	}
}

function check()
{
	var f = checkfname();
	var l = checklname();

	if (f && l)
	{
		alert ("Thank you for your feedback!");
		history.back();
	}

}

//for contact us page

function checkmail()
{
	var email = document.getElementById("email").value;
	var emailcheck= /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

	if(emailcheck.test(email))
	{
		document.getElementById("emailv").innerHTML = "";
		return true;
	}
	else
	{
		document.getElementById("emailv").innerHTML = "Invalid email.";
		return false;
	}
}
function checkphone()
{
	var phone = document.getElementById("phone").value;
	var phonecheck= /^(?:(?:\+|0{0,2})91(\s*[\-]\s*)?|[0]?)?[789]\d{9}$/;
	if(phonecheck.test(phone))
	{
		document.getElementById("phonev").innerHTML = "";
		return true;
	}
	else
	{
		document.getElementById("phonev").innerHTML = "Invalid phone.";
		return false;
	}
}

function checkquery() 
{
	var input = document.getElementById("query").value;
	if (input.length == 0)
	{
		document.getElementById("queryv").innerHTML = "Please enter your query.";
		return false;
	}
	else
	{
		document.getElementById("queryv").innerHTML = "";
		return true;
	}
}
function check2()
{
	var e = checkmail();
	var p = checkphone();
	var q = checkquery();

	if (e && p && q)
	{
		alert ("We will contact you soon.");
		goBack();
	}

}

function goBack() {
  window.history.back();
}