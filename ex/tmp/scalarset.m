type

  a: scalarset(3);

 

var

  arr: a;

 

startstate "foo"

end;

 

ruleset x: boolean do

  rule "bar"

    undefine arr;

  end;

end;
