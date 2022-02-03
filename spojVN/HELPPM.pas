var dp:array[0..500,0..500] of longint;
    i,j,x,y,n,m,x1,y1,x2,y2:integer;
    max,s,a,k:longint;
begin
    readln(n,m,k);
    for i:=1 to n do
        for j:=1 to m do
            begin
                read(dp[i,j]);
                dp[i,j]:=dp[i,j]+dp[i-1,j]+dp[i,j-1]-dp[i-1,j-1];
            end;
    max:=n*m+1;
    if (dp[n,m]<k) then
        begin
            writeln(-1);
            exit;
        end;
    for i:=1 to n do
        for x:=i to n do
            begin
                j:=1;y:=1;
                while (y<=m) and (j<=y) do
                    begin
                        s:=dp[x,y]-dp[i-1,y]-dp[x,j-1]+dp[i-1,j-1];
                        if (s>=k) then
                            begin
                                a:=(x-i+1)*(y-j+1);
                                if (max>a) then
                                    begin
                                        max:=a;
                                        x1:=i;
                                        y1:=j;
                                        x2:=x;
                                        y2:=y;
                                    end;
                                inc(j);
                            end
                        else inc(y);
                    end;
            end;
    if (max=n*m+1) then write(-1)
    else
        begin
            writeln(max);
            write(x1,' ',y1,' ',x2,' ',y2);
        end;
end.
