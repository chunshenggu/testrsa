#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <NTL/ZZ.h>
//#include <NTL/ZZ_pX.h>
//#include <NTL/ZZX.h>

NTL_CLIENT

long witness(const ZZ& n, const ZZ& x)
{
   ZZ m, y, z;
   long j, k;

   if (x == 0) return 0;

   // compute m, k such that n-1 = 2^k * m, m odd:

   k = 1;
   m = n/2;
   while (m % 2 == 0) {
      k++;
      m /= 2;
   }

   z = PowerMod(x, m, n); // z = x^m % n
   if (z == 1) return 0;

   j = 0;
   do {
      y = z;
      z = (y*y) % n; 
      j++;
   } while (j < k && z != 1);

   return z != 1 || y != n-1;
}


long PrimeTest(const ZZ& n, long t)
{
   if (n <= 1) return 0;

   // first, perform trial division by primes up to 2000

   PrimeSeq s;  // a class for quickly generating primes in sequence
   long p;

   p = s.next();  // first prime is always 2
   while (p && p < 2000) {
      if ((n % p) == 0) return (n == p);
      p = s.next();  
   }

   // second, perform t Miller-Rabin tests

   ZZ x;
   long i;

   for (i = 0; i < t; i++) {
      x = RandomBnd(n); // random number between 0 and n-1

      if (witness(n, x)) 
         return 0;
   }

   return 1;
}


int main()
{


	
   long i,j,k;
    
   ZZ p,q,n,aa,fn,g,e,d,dd,t,m,c,mm;
   
	
	k=1024;
	
	aa=power(to_ZZ(2),k);
	cout<<"aa="<<aa<<endl<<endl;
	
	p=2*RandomBnd(aa)+1;
	while (!PrimeTest(p,10))
		p=p+2;
		
	q=2*RandomBnd(aa)+1;
	while (!PrimeTest(q,10))
		q=q+2;
	

	
	cout<<"p="<<p<<endl<<endl;
	cout<<"q="<<q<<endl<<endl;	
	

	
	n=p*q;
	fn=(p-1)*(q-1);
	
	cout<<"n="<<n<<endl<<endl;
	cout<<"fn="<<fn<<endl<<endl;
	
	

	e=65537;
	
	while (GCD(e,fn) !=1 ){
		
		p=2*RandomBnd(aa)+1;
		while (!PrimeTest(p,10))
			p=p+2;
			
		q=2*RandomBnd(aa)+1;
		while (!PrimeTest(q,10))
			q=q+2;
			
		n=p*q;
		fn=	(p-1)*(q-1);		
	}

	
	
	XGCD(dd, d, t, e, fn);
//  1=dd = gcd(e, fn) = e*d + fn*t.	



	cout<<"e="<<e<<endl<<endl;
	cout<<"d="<<d<<endl<<endl;
	cout<<"fn="<<fn<<endl<<endl;
	cout<<"d mod fn="<<d % fn<<endl<<endl;
	
	cout<<"pk=(e,n)"<<endl<<endl;
	cout<<"sk=(d,n)"<<endl<<endl;
	

	m=RandomBnd(n);  //assume m is a plaintext message
	c=PowerMod(m,e,n); // c is the ciphertext
	mm=PowerMod(c,d,n);
	
	cout<<"The plaintext m="<<endl<<m<<endl<<endl;
	cout<<"The ciphertext c="<<endl<<c<<endl<<endl;
	cout<<"The decrypted plaintext mm="<<endl<<mm<<endl<<endl;
	

		
	cout<<"hello world!";
	return 0;
}


