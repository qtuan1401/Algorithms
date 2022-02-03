var s,s1:ansistring;
	i,n,m,d:longint;
function check(s,s1:ansistring;d:longint):boolean;
var i:longint;
begin
	for i:=d to n do
		begin
			if (i-d+1>m) then exit(false);
			if (s[i]<>s1[i-d+1]) then exit(false);
		end;
	exit(true);
end;
begin
	readln(s);
	readln(s1);
	n:=length(s);m:=length(s1);
	for i:=1 to n do
		if check(s,s1,i) then
			begin
				writeln(copy(s,1,i-1),s1);
				exit;
			end;
	writeln(s,s1);
end.