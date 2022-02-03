var d,m,n:qword;
begin
  readln(n,m);
  d:=m*n;
  while (d>n) do d:=d+(d-n-1) div (m-1)-n;
  write(d);
end.