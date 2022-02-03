var f,a:array[1..100] of longint;i,n,k,j,c,b:longint;s:string;t:char;
code:integer;
begin
        readln(n);
        if n<24 then
           begin
        f[1]:=1;
                for i:=2 to 23 do
                        begin
                                f[i]:=f[i-1]*2;
                                str(f[i],S);
                                for j:=1 to length(s) do
                                        for k:=j+1 to length(s) do
                                           if s[j]>s[k] then
                                               begin
                                                      t:=s[j];
                                                      s[j]:=s[k];
                                                      s[k]:=t;
                                               end;
                                val(s,f[i],code);
                        end;
        writeln(f[n]);
        end
        else
           begin
            a[1]:=48889;
            a[2]:=77789;
            a[3]:=155578;
            a[4]:=111356;
            a[5]:=122227;
            a[6]:=244445;
            if n mod 6=0 then writeln(a[6])
            else
            writeln(a[n mod 6]);
            end;
end.




