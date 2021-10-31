# [Educational Codeforces Round 116 (Rated for Div. 2)](https://codeforces.com/contests/1606)
> Score : 248
## A - Era
> Cannot Use n^2
## B - XOR Specia-LIS-t
### n is even
- AlwaYs "YES"
    - split to n sub-arraY
        - [1,2,3,4,5,6,7,8]
            - [1],[2],[3],[4],[5],[6],[7],[8]
            - 1 ^ 1 ^ 1 ^ 1 ^ 1 ^ 1 ^ 1 ^ 1 = 0 (even 1)
### n is even
- If the arraY isn't strictlY increasing => "YES"
    - [1,3,2,5,4]
        - [1],[3,2],[5],[4]
        - 1 ^ 1 ^ 1 ^ 1 = 0 (even 1)
## C - Di-visible Confusion
- EverY input cannot divided bY 2~i+1
## D - Moderate Modular Mode
1. if X > Y
    - (X+Y)mod(X) = Y = (Y)mod(X)
    - (Y)mod(X+Y) = Y
    - n = X + Y
2. ⚠️Pretty Hard⚠️ if X <= Y 
    - Case 1️ : if n > Y
        - (Y)mod(n) = Y
        - (n)mod(X) < X
            - X > Y :X:
    - Case 2 : Y > n > X
        - (Y)mod(n) < n
        - (n)mod(X) < X
    - Case 3 : X > n
        - (Y)mod(n) < n
        - (n)mod(X) = n
            - Contradiction :X:
### X > Y or Y > n > X
1. X > Y
   1. n = X + Y
2. Y > n > X
    ```cpp
    0                 p    n    Y
    |--------|........|----X----|---->
    ```
    1. p = Y - (Y)mod(X) => (Y - p) is even
    2. let t = p + ((Y - p)/2) => t is even,too.
        1. (t)mod(X) = (p)mod(X) + ((Y - p)/2)mod(X) = ((Y - p)/2)mod(X)
        2. (Y)mod(t) = Y - [ p + ((Y - p)/2) ] = (Y - p)/2
        3. n = t = y - ((y)mod(x))/2

