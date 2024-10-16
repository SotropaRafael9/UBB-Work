int(a), int(b), int(c)
a -> 1
b -> 10
c -> 4

# p1

function minimum(a,b,c)
[
    iff a <_ b
    (
        iff a <_ c
        (
            put a
        )
        else
        (
            put c
        )
    )
    else
    (
        iff b <_ c
        (
            put b
        )
        else
        (
            put c
        )
    )
]

# p2
function checkprime
[
    iff a <_ 2
    (
        put nil # nil is 0 or none
    )
    else
    (
        forr i in range(2, a)
        [
            iff a /* i == 0  # /* is %
            (
                put nil
            )
        ]
        put 1
    )

]
#p3
function sum of n numbers
[
    sum -> 0
    forr i from 1 to n+1
    (
        sum -> sum /+ i # /+ is + 
    )
    put sum
]

#p1 error


function minimum # here we should mention the parameters
[
    iff a < b # herewe should put _after < 
    (
        iff a <_ c
        (
            put a
        )
        else
        (
            put c
        )
    )
    else
    (
        iff b <_ c
        (
            put b
        )
        else
        (
            put c
        )
    )
]
