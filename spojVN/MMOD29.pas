var t1,t2,t3,n:int64;
function calc (a,b:int64):int64;
begin
	if (b=0) then exit(1);
	if (b mod 2=0) then exit(sqr(calc(a,b div 2)) mod 29)
	else exit((sqr(calc(a,b div 2))*a) mod 29);
end;
begin
	repeat
	    readln(n);
		if (n<>0) then
			begin
				t1:=(calc(2,2*n+1)-1) mod 29;
				t2:=(calc(3,n+1)-1) mod 29;
				t3:=(calc(167,n+1)-1) mod 29;
				writeln((t1*t2*t3*9) mod 29)
			end;
	until n=0;
end.