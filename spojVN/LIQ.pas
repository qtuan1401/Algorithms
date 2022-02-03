var
    N,i,res,temp,j:longint;
    a,f:array[1..1001]of longint;
begin
    readln(N);
    for i:=1 to N do
        read(a[i]);
    f[1]:=1;
    for i:=2 to N do
        begin
            temp:=0;
            for j:=1 to i-1 do
                if((a[j]<a[i]) and (f[j]>temp)) then
                    temp:=f[j];
            f[i]:=temp+1;
        end;
    res:=0;
    for i:=1 to N do
        if(res<f[i]) then res:=f[i];
    writeln(res);
end.
