*** 8 bits calculator in brainfuck ***
@0 ****
@1 counter
@2 else conditional
@3 ** array space
@4*6 num1 ascii
@7 ** array space
@8 operator
@9 ** array space
@10*12 num2 ascii
@13 ** array space
@14 num1 dec
@15 num2 dec
@16 result dec
@17 ** array space
@18*20 result ascii

>>@2 + // else conditional

* num1 input
>>@4 , ------------------------------------------------48
>@5 , ------------------------------------------------48
>@6 , ------------------------------------------------48

* operator
>>@8 , -------------------------------------------43

* num2 input
>>@10 , ------------------------------------------------48
>@11 , ------------------------------------------------48
>@12 , ------------------------------------------------48

* num1 to dec
<<<<<<<<@4 // hundreds
[
    - <<<@1
    ++++++++++10
    [
        -
        >>>>>>>>>>>>>@14
        ++++++++++10
        <<<<<<<<<<<<<@1
    ]
    >>>@4
]

>@5 // tens
[
    -
    >>>>>>>>>@14
    ++++++++++10
    <<<<<<<<<@5
]

>@6 // ones
[
    - >>>>>>>>@14 + <<<<<<<<@6
]

* num2 to dec
>>>>@10 // hundreds
[
    - <<<<<<<<<@1
    ++++++++++10
    [
        -
        >>>>>>>>>>>>>>@15
        ++++++++++10
        <<<<<<<<<<<<<<@1
    ]
    >>>>>>>>>@10
]

>@11 // tens
[
    -
    >>>>@15
    ++++++++++10
    <<<<@11
]

>@12 // ones
[
    - >>>@15 + <<<@12
]

* calculations
<<<<@8
[ if operator @8 is not 0 then sub
    [-] <<<<<<@2 [-]

    // @16 recived @14
    >>>>>>>>>>>>@14
    [
        -
        >>@16 + <<@14
    ]

    // @16 removed @15
    >@15
    [
        -
        >@16 - <@15
    ]

    <<<<<<<@8
] <<<<<<@2 [ else do sum
    [-] >>>>>>@8 [-]

    // @16 recived @14
    >>>>>>@14
    [
        -
        >>@16 + <<@14
    ]

    // @16 recive @15
    >@15
    [
        -
        >@16 + <@15
    ]

    <<<<<<<<<<<<<@2
]

* result to ascii
>>>>>>>>>>>>>>@16

[ // hundreds

] [ // tens
    
] [ // units

]

* output
>>>>>>>>>>>>>>@16 .
