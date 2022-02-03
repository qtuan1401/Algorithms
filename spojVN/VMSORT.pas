var k,n,c,d:int64;a:array[1..1000] of string;t,s:string;i,j:longint;
begin
        readln(k);
        for i:=1 to k do
                begin
                        readln(n);
                        for j:=1 to n do
                                begin
                                        readln(s);
                                        c:=c+1;
                                        a[c]:=a[c]+s;
                                end;
                end;
        for i:=1 to c do
                for j:=i+1 to c do
                        if a[i]<a[j] then
                                begin
                                        t:=a[i];
                                        a[i]:=a[j];
                                        a[j]:=t;
                                end;
        for i:=1 to c do
                if a[i]<>a[i+1] then d:=d+1;
        writeln(d);
end.
