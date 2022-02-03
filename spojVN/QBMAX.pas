uses    math;
const   fi = '';
        fo = '';
var     n,m,i,j,maxf : integer;
        a,f : array[0..301,0..301] of integer;
 
begin
        assign(input,fi);
        reset(input);
        assign(output,fo);
        rewrite(output);
        readln(m,n);
        for i := 1 to m do
                for j := 1 to n do
                        read(a[i,j]);
        for j := 0 to n+1 do begin
                f[0,j] := -maxint;
                f[m+1,j] := -maxint;
        end;
        for i := 1 to m do f[i,1] := a[i,1];
        for j := 2 to n do
                for i := 1 to m do
                        f[i,j] := max(f[i-1,j-1],max(f[i,j-1],
                                       f[i+1,j-1])) + a[i,j];
        maxf := -maxint;
        for i := 1 to m do
                maxf := max(maxf,f[i,n]);
        writeln(maxf);
        close(input);
        close(output);
end.
