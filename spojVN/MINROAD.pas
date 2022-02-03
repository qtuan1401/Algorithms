uses math;
const maxn =300000;
  	  maxValue =1000000001;
var n,res,a,b,i,j,loc:longint;
    d:array[1..maxn] of longint;
    suma,sumb :array[0..maxn] of longint;
procedure Sort(l,r :LongInt);
var i,j,key,tmp:longint;
begin
    if (l>=r) then exit;
    i:=l;j:=r;key:=d[(l+r) div 2];
    repeat
      while (d[i]<key) do inc(i);
      while (d[j]>key) do dec(j);
      if (i<=j) then
        begin
          if (i<j) then
            begin
              tmp:=d[i];d[i]:=d[j];d[j]:=tmp;
              tmp:=suma[i];suma[i]:=suma[j];suma[j]:=tmp;
              tmp:=sumb[i];Sumb[i]:=sumb[j];sumb[j]:=tmp;
            end;
          inc(i);dec(j);
        end;
    until (i>j);
    sort(l,j); sort(i,r);
end;
begin
  	read(n,a,b);
 	suma[0]:=0; 
	sumb[0]:=0;
    for i:=1 to n do
		begin
        	read(d[i],j);
        	suma[i]:=0; 
			sumb[i]:=0;
        	if (j=1) then suma[i]:=1 else sumb[i]:=1;
      	end; 
	sort(1,n);
  	for i:=1 to n do
      begin
        inc(suma[i],suma[i-1]);
        inc(sumb[i],Sumb[i-1]);
      end;
   res:=maxvalue; loc:=0;
    for i:=a+b to n do
      for j:=loc+1 to i-(a+b)+1 do
        if (suma[i]-suma[j-1]>=a) and (sumb[i]-sumb[j-1]>=b) then
          begin
            res:=min(res,d[i]-d[j]);
            loc:=j;
          end
        else break;
    if (res=maxvalue) then res:=-1;
   write(res);
end.