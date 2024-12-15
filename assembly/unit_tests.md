# UNIT TESTS

There isn't some sort of automated unit test, because it's already hard in high-level languages, in assembly it's a shit.

So here is some manual tests.

In the `tests` folder are some (or just one) tests that are literally just a copy from the ones here.


### Initial Test
Code: 
```
++++++++++++++++++++++++++++++++++++++++++++++++.
```
Expected output:
```
0
```


### Ignore characters other than operators
Code: 
```
++++++++++++++++++++++++ this should not modify the output 
++++++++++++++++++++++++ or should it? .
```
Expected output: 
```
0
```


### Cell Overflow (upwards)
Code:
``` 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++.
```
Expected output: 
```
0
```


### Cell Overflow (downwards)
Code:
``` 
-----------------------------------------------------------
-----------------------------------------------------------
----------------.
```
Expected output: 
```
z
```


### Move data pointer
Code: 
```
++++++++++++++++++++++++++++++++++++++++++++++++>++++++++++
+++++++++++++++++++++++++++++++++++++++.<.
```
Expected output: 
```
10
```


### Data pointer overflow
Code: 
```
<++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++
+++++++++++++++++++++++++++++++++++++++++.
```
Expected output: 
```
01
```


### Input test
Code: 
```
,.
```
Input:
```
abc
```
Expected output: 
```
a
```


### Input value test
Code:
``` 
,#
```
Input:
```
0
```
Expected output: 
```
48
```


### Complex input (normal)
Code:
``` 
,,,.
```
Input:
```
aaa
```
Expected output: 
```
a
```


### Complex input (including the null terminator)
Code:
``` 
,,,,.
```
Input:
```
aaa
```
Expected output: 
```
(null value)
```


### Input with multiple calls
Code:
``` 
,.,.,,.
```
Input:
```
abcd
```
Expected output: 
```
abd
```


### Basic loop
Code:
```
+[#+]
```
Expected output:
```
(all numbers from 1 to 255)
```


### Basic math
Code:
```
+++[>++<-]>#
```
Expected output:
```
6
```


### Advanced math (nested loop)
Code:
```
++++[>+++[>++<-]<-]>>#
```
Expected output:
```
24
```


### Loop + Input
Code:
```
,[.,]
```
Input:
```
Some text, doesn't metter much
```
Expected output:
```
Some text, doesn't metter much
```
