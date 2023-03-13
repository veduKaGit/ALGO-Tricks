// Before Linear Diophantine Equations, some prerequisite:




// 1. Euclidean algorithm (GCD):
  
//   int gcd(int a, int b)
//   {
//       if (a == 0)
//           return b;
//       return gcd(b % a, a);
//   }






// 2. Extended Euclidean Algorithm: 

//   finds integer coefficients x and y such that:
//   ax + by = gcd(a, b) 
//   here-> a,b were given ... we can find gcd(a,b) ... now x and y are unknowns -> find them
    
//   # NOTE: for the above eqn, its GUARANTEED that x,y INTEGERS exist

// How to find (x,y)?
  
//   ax + by = gcd(a, b)  --- 1
//   gcd(a, b) = gcd(b%a, a)   ----2 ----we know this----from euclidean algo
  
//   gcd(b%a, a) = (b%a)x1 + ay1   ----using 1 and 2 --- now we have (x1,y1)
//   ax + by = (b%a)x1 + ay1   ----using 1 and 2
  
//   we know => dividend = divisor*quotient + remanider => use this => b = a*(b/a) + (b%a)

//   ax + by = (b – (b/a)*a)x1 + ay1
//   ax + by = a(y1 – (b/a)*x1) + bx1

//   Comparing LHS and RHS,
//   x = y1 – (b/a)*x1
//   y = x1

// Now, we can get x,y using a base case in recursion => when a==0 => GCD(a,b)==b => thus x==anything, y==1 => necessarily 
    
    
    
