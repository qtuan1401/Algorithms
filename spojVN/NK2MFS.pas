Uses Math;
const maxn =10000;
var n,r,l,t1,t2,i:longint;
  	a:Array[1..2,1..maxn] of longint;
  	f:Array[1..maxn] of longint;  
procedure QSort(l,r :SmallInt; k :Byte);
var i,j,mid,tmp :SmallInt;
begin
    i:=l; j:=r; mid:=(l+r) div 2;
    repeat
      	while (a[k,f[i]]<a[k,f[mid]]) do inc(i);
      	while (a[k,f[j]]>a[k,f[mid]]) do dec(j);
      	if (i<=j) then
        	begin
          		if (i<j) then
            		begin
              			tmp:=f[i];
              			f[i]:=f[j]; 
              			f[j]:=Tmp;
            		end;
          		inc(i); 
          		dec(j);
        	end;
    until (i>j);
    if l<j then qsort(l,j,k); 
    if i<r then qSort(i,r,k);
end;
procedure Johnson;
var i,t1,t2 :LongInt;
begin
    r:=0; l:=n+1;
    for i:=1 to n do
      if (A[1,i]<=A[2,i]) then
        begin
          inc(r); F[r]:=i;
        end
      else
        begin
          dec(l); f[l]:=i;
        end;
    qsort(1,r,1); qsort(l,n,2);
end;
Begin
  	Readln(n);
    for i:=1 to n do Read(A[1,i]);
    for i:=1 to n do Read(A[2,i]);
  	Johnson;
  	t1:=0; t2:=0;
    for i:=1 to r do
      begin
        Inc(t1,a[1,f[i]]);
        t2:=max(t1,t2)+a[2,f[i]];
      end;
    for i:=n downto l do
      begin
        inc(t1,a[1,f[i]]);
        t2:=max(t1,t2)+a[2,f[i]];
      end;
    writeln(t2);
    for i:=1 to r do write(f[i],' ');
    for i:=n downto l do write(f[i],' ');
End.Uses Math;
const maxn =10000;
var n,r,l,t1,t2,i:longint;
  	a:Array[1..2,1..maxn] of longint;
  	f:Array[1..maxn] of longint;  
procedure QSort(l,r :SmallInt; k :Byte);
var i,j,mid,tmp :SmallInt;
begin
    i:=l; j:=r; mid:=(l+r) div 2;
    repeat
      	while (a[k,f[i]]<a[k,f[mid]]) do inc(i);
      	while (a[k,f[j]]>a[k,f[mid]]) do dec(j);
      	if (i<=j) then
        	begin
          		if (i<j) then
            		begin
              			tmp:=f[i];
              			f[i]:=f[j]; 
              			f[j]:=Tmp;
            		end;
          		inc(i); 
          		dec(j);
        	end;
    until (i>j);
    if l<j then qsort(l,j,k); 
    if i<r then qSort(i,r,k);
end;
procedure Johnson;
var i,t1,t2 :LongInt;
begin
    r:=0; l:=n+1;
    for i:=1 to n do
      if (A[1,i]<=A[2,i]) then
        begin
          inc(r); F[r]:=i;
        end
      else
        begin
          dec(l); f[l]:=i;
        end;
    qsort(1,r,1); qsort(l,n,2);
end;
Begin
  	Readln(n);
    for i:=1 to n do Read(A[1,i]);
    for i:=1 to n do Read(A[2,i]);
  	Johnson;
  	t1:=0; t2:=0;
    for i:=1 to r do
      begin
        Inc(t1,a[1,f[i]]);
        t2:=max(t1,t2)+a[2,f[i]];
      end;
    for i:=n downto l do
      begin
        inc(t1,a[1,f[i]]);
        t2:=max(t1,t2)+a[2,f[i]];
      end;
    writeln(t2);
    for i:=1 to r do write(f[i],' ');
    for i:=n downto l do write(f[i],' ');
End.