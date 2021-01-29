function createcalender(){
  var month = document.getElementById("op").value;
  var txt = document.getElementById("Year").value;
  var year = parseInt(txt);
  var n = 1;
  
  var days = no_of_days(year, month); 
  var daynum = firstDay(year, month); 
  
  document.getElementById("tbl").innerHTML = "<tr><th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr>";
	for(var i=0; i<6; i++){
	document.getElementById("tbl").innerHTML += "<tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr>";
	}
	
	var table = document.getElementById("tbl");
	for (var i = 1, row; row = table.rows[i]; i++) {
	
		for (var j = 0, col; col = row.cells[j]; j++) {
				if(daynum>j && i==1){col.innerHTML=""; col.setAttribute("style","background-color: salmon;");}
				else{
					if(n<=days){col.innerHTML = n;}
					else if(n>days){col.setAttribute("style","background-color: salmon;");}
					n++;
				}
				
				
		}	  
	}
}

function is_leap(year) {
 if(year % 4 === 0 && year % 100 !== 0 || year % 400 === 0){return 1;}
 else{return 0;}
}

function no_of_days(year, month){
 if(month == 4 || month == 6 || month == 9 || month ==11){return 30;}
  
  if(month!=2){return 31;}
  
  else if(month == 2){return 28+ is_leap(year);}
}

function new_years_day(year) {
var daynumber = 1;
for (var i=1900; i<year; i++){ 
daynumber+=365+is_leap(i);}
return (daynumber % 7);
}

function firstDay(year, month) {
var daynumber = new_years_day(year); 
for (var i=1; i<month; i++)
daynumber+=no_of_days(year, i);
daynumber %= 7;
return daynumber;
}



