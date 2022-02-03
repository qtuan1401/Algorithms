var a:array[1..500000] of longint;
	kt:array[0..1000000000] of boolean;
	n,k:longint;
begin
	a[0]:=0;kt[0]:=true;
	for n:=1 to 500000 do 
		begin
			k:=a[n-1]-n;
			if (k<0) or (kt[k]) then
				begin
					kt[a[n-1]+n]:=true;
					a[n]:=a[n-1]+n;
				end
			else
				begin
					kt[k]:=true;
					a[n]:=k;
				end;
		end;
	repeat
		readln(n);
		if (n<>-1) then writeln(a[n]);
	until (n=-1); 
end.
					