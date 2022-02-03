const base=1000000007;
var s,b:ansistring;
    n,i,j:longint;
    a:string;
    hash,pow,hashb,leng:array[0..10001] of int64;
    res:int64;
    f:array[0..10001] of longint;
function kt (c:char):string;
Begin
   if C='A' then exit('.-');
   if C='B' then exit('-...');
   if C='C' then exit('-.-.');
   if C='D' then exit('-..');
   if C='E' then exit('.');
   if C='F' then exit('..-.');
   if C='G' then exit('--.');
   if C='H' then exit('....');
   if C='I' then exit('..');
   if C='J' then exit('.---');
   if C='K' then exit('-.-');
   if C='L' then exit('.-..');
   if C='M' then exit('--');
   if C='N' then exit('-.');
   if C='O' then exit('---');
   if C='P' then exit('.--.');
   if C='Q' then exit('--.-');
   if C='R' then exit('.-.');
   if C='S' then exit('...');
   if C='T' then exit('-');
   if C='U' then exit('..-');
   if C='V' then exit('...-');
   if C='W' then exit('.--');
   if C='X' then exit('-..-');
   if C='Y' then exit('-.--');
   if C='Z' then exit('--..');
End;
function get(i,j:longint):int64;
begin
	get:=(hash[j]-hash[i-1]*pow[j-i+1] + base*base) mod base;
end;
function change(c: Char):int64;
begin
	if c='.' then exit(0) else exit(1);
end;
procedure init(test:longint);
var     i,j:longint;
        hash:int64;
begin
	b:='';
    for i:=1 to length(a) do
    	b:=b+kt(a[i]);
    Leng[test]:=length(b);
    hash:=0;
    for i:=1 to length(b) do
    	hash:=(hash*2+change(b[i])) mod base;
    hashb[test]:=hash;
end;
begin
	readln(s);
	pow[0]:=1;
    for i:=1 to length(s) do
    	pow[i]:=(pow[i-1]*2) mod base;
	hash[0]:=0;
    for i:=1 to length(s) do
    	hash[i]:=(hash[i-1]*2 + change(s[i])) mod base;
    fillchar(f,sizeof(f),0);
    f[0]:=1;
    readln(n);
    res:=0;
    for i:=1 to n do
    	begin
        	readln(a);
            init(i);
        end;
	for i:=1 to length(s) do
    	begin
        	for j:=1 to n do
            	if leng[j]<=i then
                	if get(i-leng[j]+1,i)=hashb[j] then
                    	f[i]:=(f[i]+f[i-leng[j]]) mod 1000000;
        end;
	writeln(f[length(s)]);
end.