var n,m,d,k,j,r,a:int64;i:longword;
begin
        readln(n,m);
        for i:=n to m do
            begin
                        k:=i;a:=i;
                        while a<> 0 do
                                begin
                                        j:=j*10+a mod 10;
                                        a:=a div 10;
                                end;
                    while j<>0 do
                        begin
                                r:=k mod j;
                                k:=j;
                                j:=r;
                        end;
                if k=1 then d:=d+1;
            end;
        writeln(d);
end.
