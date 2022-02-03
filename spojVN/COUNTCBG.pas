const   fi = '';
        fo = '';
var     n,i,res,max : longint;
begin
        assign(input,fi);
        reset(input);
        assign(output,fo);
        rewrite(output);
        while not(eof(input)) do begin
                readln(n);
                max := trunc(sqrt(2*n));
                res := 0;
                for i := 2 to max do
                        if 2*n mod i = 0 then
                                if (i+(2*n div i)-1) mod 2 = 0 
                                then inc(res);
                writeln(res);
        end;
        close(input);
        close(output);
end.