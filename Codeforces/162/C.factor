USING: io kernel math strings math.parser sequences ;
IN: program

: divisible-by? ( n m -- ? ) mod 0 = ;

: divide ( n m -- updatedn )
2dup divisible-by?
[ dup number>string write / dup 1 = [ "" write ] [ "*" write ] if ]
[ drop ]
if ;

readln string>number
10005 iota 2 tail [
40 iota [
    drop
    2dup
    divide
    -rot
    swap
    drop
] each
drop
] each
drop
