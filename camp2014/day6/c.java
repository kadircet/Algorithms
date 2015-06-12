import java.math.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class c
{
	static long fib[];
	public static void main(String args[])
	{
		fib = new long[130];
		fib[0] = 0;
		fib[1] = 1;
		for(int i=2;i<100;i++)
			fib[i] = fib[i-1] + fib[i-2];
		
		long t=0;
		int pos;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try
		{t = Long.parseLong(br.readLine());}
		catch(Exception e){}
		for(pos=2;;pos++)
			if(fib[pos]>t)
			{
				pos-=2;
				break;
			}
		
		BigInteger res = BigInteger.valueOf(0);
		while(pos>=2)
		{
			if(fib[pos]>=t||fib[pos-1]>=t)
			{
				pos--;
				continue;
			}
		
			long a=fib[pos], b=fib[pos-1], x, y, lastx,lasty,temp1,temp2,temp3,q;
			BigInteger A=BigInteger.valueOf(a), B=BigInteger.valueOf(b);
			BigInteger K = BigInteger.valueOf(t);
			x=lasty=0;
			y=lastx=1;
			while(b!=0)
			{
				q=a/b;
				temp1=a%b;
				a=b;
				b=temp1;
			
				temp2=x;
				x=lastx-q*x;
				lastx=temp2;
			
				temp3=y;
				y=lasty-q*y;
				lasty=temp3;
			}
		
			BigInteger x0, y0;
			x0 = BigInteger.valueOf(lastx);
			x0 = x0.multiply(K);
			y0 = BigInteger.valueOf(lasty);
			y0 = y0.multiply(K);
		
			if(x0.compareTo(BigInteger.valueOf(0))<=0)
			{
				BigInteger k=x0.negate().divide(B).add(BigInteger.valueOf(1));
				x0=x0.add(k.multiply(B));
				y0=y0.subtract(k.multiply(A));
			}
			if(y0.compareTo(BigInteger.valueOf(0))<=0)
			{
				BigInteger k=y0.negate().divide(A).add(BigInteger.valueOf(1));
				y0=y0.add(k.multiply(A));
				x0=x0.subtract(k.multiply(B));
			}
			if(x0.compareTo(K)>=0)
			{
				BigInteger k=K.subtract(y0).subtract(BigInteger.valueOf(1)).divide(A);
				x0=x0.subtract(k.multiply(B));
				y0=y0.add(k.multiply(A));
			}
			if(y0.compareTo(K)>=0)
			{
				BigInteger k=K.subtract(x0).subtract(BigInteger.valueOf(1)).divide(B);
				x0=x0.add(k.multiply(B));
				y0=y0.subtract(k.multiply(A));
			}
			
			if(x0.compareTo(K)>=0 || y0.compareTo(K)>=0 || x0.compareTo(BigInteger.ZERO)<=0 || y0.compareTo(BigInteger.ZERO)<=0)
			{
				pos--;
				continue;
			}
		
			BigInteger tmp = y0.subtract(BigInteger.valueOf(1)).divide(A), tmp2=K.subtract(x0).subtract(BigInteger.valueOf(1)).divide(B);
			if(tmp.compareTo(tmp2)==1)
				tmp = tmp2;
			res=res.add(tmp);
		
			tmp = x0.subtract(BigInteger.valueOf(1)).divide(B);
			tmp2=K.subtract(y0).subtract(BigInteger.valueOf(1)).divide(A);
			if(tmp.compareTo(tmp2)==1)
				tmp = tmp2;
			res=res.add(tmp);
			res=res.add(BigInteger.valueOf(1));
			pos--;
		}
		System.out.println(res);
	}
}
