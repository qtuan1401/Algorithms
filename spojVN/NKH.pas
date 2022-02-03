var s1,s2,s3:string;
    n,m,i,j:longint;
    trace:array[0..201] of longint;
procedure print;
var i:longint;
begin
    for i:=1 to n+m do write(trace[i]);
    halt;
end;
procedure try(i,kt1,kt2:longint);
var     j:longint;
begin
    if i>m+n then print
    else
        begin
            if s3[i]=s1[kt1] then
                begin
                    trace[i]:=1;
                    try(i+1,kt1+1,kt2);
                end;
            if s3[i]=s2[kt2] then
                begin
                    trace[i]:=2;
                    try(i+1,kt1,kt2+1);
                end;
        end;
end;

begin
    readln(s1); n:=length(s1);
    readln(s2); m:=length(s2);
    readln(s3);
    try(1,1,1);
end.