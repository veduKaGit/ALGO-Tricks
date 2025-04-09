//Sieve of Eratosthenes

// time: n*log(log(n))

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    // i*i => repeated in both loops => beech mei, then left mei
    for (int i = 2; i*i<=n; i++)  //same loop as 09_check_if_prime.cpp => same logic
    {  
        if (prime[i] == true)
        {
            for (int j =i*i; j<=n; j+=i)   // why didn't we run for j = i*1, i*2 ... i*(i-1)? because they were already considered in the outer loop when i was 1, 2, 3... i-1. 
                prime[j] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)   //p = 2 se start
        if (prime[p])
            cout << p << " ";
}
