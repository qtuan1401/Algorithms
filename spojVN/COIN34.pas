Uses Math;
Const n =34;
      maxX =367980;
Var s1,ans :LongInt;
    a:Array[1..n] of LongInt;
    f:Array[0..maxX] of Byte;
    x:Array[0..n] of Byte;
    test :LongInt;
procedure Init;
  var
    i :LongInt;
  begin
    A[1]:=2; A[2]:=3; A[3]:=5;
    for i:=4 to n do A[i]:=A[i-1]+A[i-2]+A[i-3];
  end;

procedure Back1(k,i,s,d :LongInt);
var j :LongInt;
begin
    for j:=X[i-1]+1 to 20-k+i do
      begin
        X[i]:=j;
        if (i=k) then
          F[s+A[j]]:=Max(F[s+A[j]],d+1)
        else
          Back1(k,i+1,s+A[j],d+1);
      end;
end;

procedure Back2(k,i,s,d :LongInt);
var j :LongInt;
begin
    for j:=X[i-1]+1 to 34-k+i do
      begin
        X[i]:=j;
        if (i=k) then
          begin
            if (s1-s-A[j]>=0) and (s1-s-A[j]<=maxX) then
              begin
                if ((s1-s-A[j]>0) and (F[s1-s-A[j]]>0)) or
                (s1-s-A[j]=0) then ans:=Max(ans,F[s1-s-A[j]]+d+1);
              end;
          end
        else Back2(k,i+1,s+A[j],d+1);
      end;
end;

procedure calc;
var i,t :LongInt;
begin
    FillChar(F,SizeOf(F),0);
    X[0]:=0;
    for i:=1 to 20 do Back1(i,1,0,0);
    X[0]:=20;
    Read(test);
    for t:=1 to test do
      begin
        Read(s1);
        ans:=0;
        if (s1<=maxX) then ans:=F[s1]
        else
          for i:=1 to 14 do Back2(i,1,0,0);
        Write('Case #',t,': ');
        if (ans=0) then WriteLn(-1) else WriteLn(ans);
      end;
end;

Begin
  Assign(Input,''); Reset(Input);
  Assign(Output,''); Rewrite(Output);
  Init;
  calc;
  Close(Input); Close(Output);
End.
