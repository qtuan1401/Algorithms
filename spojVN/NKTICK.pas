uses math;
const fi='';
      fo='';
var f,f1:text;i,n:longint;a,t,r:array[0..60000] of longint;
begin
    assign(f,fi);
    assign(f1,fo);
    reset(f);
    rewrite(f1);
    readln(f,n);
    for i:=1 to n do read(f,t[i]);
    for i:=1 to n-1 do read(f,r[i]);
    a[1]:=t[1];a[0]:=0;
    for i:=2 to n do
        a[i]:=min(a[i-1]+t[i],a[i-2]+r[i-1]);
    writeln(f1,a[n]);
    close(f);
    close(f1);
end.
