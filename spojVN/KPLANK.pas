Uses Math;
Const
  fi='';
  fo='';
Var
  f:text;
  a,L,R:array[0..1000001] of longint;
  n:longint;
Procedure Enter;
 Var i:longint;
 Begin
     Assign(f,fi);reset(f);
      Readln(f,n);
      For i:=1 to n do Readln(f,a[i]);
     Close(f);
 End;
 
Procedure Left;
 Var i,k:longint;
 Begin
    For i:=1 to n do
        Begin
            L[i]:=i;
            k:=i-1;
            While (k>0)and(a[i]<=a[k]) do
              Begin
                  L[i]:=L[k];
                  k:=L[k]-1;
              End;
        End;
 End;
Procedure Right;
  Var i,k:longint;
  Begin
      For i:=n downto 1 do
        Begin
         R[i]:=i;
         k:=i+1;
         While (k<n+1)and(a[i]<=a[k]) do
           Begin
               R[i]:=R[k];
               k:=R[k]+1;
           End;
      End;
  End;
 
Procedure SlovePrint;
 Var i,m,t:longint;
 BEgin
     Left;Right;
     M:=0;
     For i:=1 to n do
       Begin
         t:=R[i]-L[i]+1;
         If t>=a[i] then m:=max(m,a[i]);
       End;
 
     Assign(f,fo);rewrite(f);
      Write(f,m);
     Close(f);
 End;
 
BEGIN
    Enter;
    SlovePrint;
END.