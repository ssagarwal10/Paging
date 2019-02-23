

#include <iostream>
using namespace std;
int mini(int,int[]);
int max(int,int,int[]);
int main()
{
	int n,p,i,j,ch,ar,hit=0,miss=0,flag=0,cnt=3;
	cout<<"\nPAGING ALGORITHMS\n\n1. FIFO\n2. LRU\n3. OPTIMAL\n\nENTER YOUR CHOICE";
	cin>>ch;
	cout<<"\nENTER THE NUMBER OF PAGES\n";
	cin>>p;
	cout<<"ENTER THE NUMBER OF FRAMES\n";
	cin>>n;
	int ls[p];
	cout<<"\nENTER THE PAGES\n";
	for(i=0;i<p;i++)
	{
		cin>>ls[i];
	}

	int pg[n];
	for(i=0;i<n;i++)
	{
		pg[i]=-1;
	}

	ar=0;
	j=0;
	cout<<"\nTHE ALGORITHM IS\n";
	switch(ch)
	{
	case 1:
	{
	for(i=0;i<p;i++)
	{
		for(int c=0;c<n;c++)
		{
		if(pg[c]==ls[j])
		{
			hit++;
			flag=1;
		goto l1;
		}
		}

		pg[ar]=ls[j];
		miss++;
		flag=0;
		ar++;

		l1:j++;



			if(ar==n)
			{
			ar=0;
			}
			for(int k=0;k<n;k++)
			{
				if(flag==1)
				{
				cout<<"HIT OCCURED\n";
				break;
				}
				else
				{
				cout<<pg[k]<<"\n";
			}
			}
			cout<<"\n\n";
	}
	cout<<"\n\nNUMBER OF HIT: "<<hit<<"\nNUMBER OF MISS: "<<miss;
	break;
	}

	case 2:
	{
		int lru[n];
		for(i=0;i<n;i++)
		{
			lru[i]=0;
		}
		for(i=0;i<p;i++)
			{
				for(int c=0;c<n;c++)
				{
				if(pg[c]==ls[j])
				{
					hit++;
					lru[c]=cnt+1;
					cnt++;
					flag=1;
				goto l2;
				}
				}
				ar=mini(n,lru);

				pg[ar]=ls[j];
				lru[ar]=cnt;
				cnt++;
				miss++;
				flag=0;


				l2:j++;
					if(ar==n)
					{
					ar=0;
					}
					for(int k=0;k<n;k++)
					{
						if(flag==1)
						{
						cout<<"HIT OCCURED\n";
						break;
						}
						else
						{
						cout<<pg[k]<<"\n";
					}
					}
					cout<<"\n\n";
			}
			cout<<"\n\nNUMBER OF HIT: "<<hit<<"\nNUMBER OF MISS: "<<miss;
			break;
			}
	case 3:
	{
		int indx[n];
		for(i=0;i<n;i++)
		{
			indx[i]=0;
		}
		for(i=0;i<n;i++)
		{
			pg[i]=ls[i];
		}
		for(i=0;i<n;i++)
		{
		cout<<pg[i]<<"\n";
		}
		cout<<"\n\n";
		ar=0;
		j=3;
		for(i=0;i<p-3;i++)
		{

			for(int c=0;c<n;c++)
			{
				if(pg[c]==ls[j])
				{
					hit++;
					flag=1;
					goto l3;
				}
			}
			for(int k=0;k<n;k++)
			{
				for(int l=k+1;l<p;l++)
				{
				if(ls[l]==pg[k])
				{
					indx[k]=l;
				}
				}
				}
			ar=max(n,ar,indx);
			pg[ar]=ls[j];
			flag=0;
			l3:j++;

			if(flag==0)
			{
				for(int z=0;z<n;z++)
				{
				cout<<pg[z]<<"\n";
				}
			}
			else
			{
				cout<<"\nHIT OCCURED\n";
			}
			cout<<"\n\n";


		}



	break;
	}
	}

	return 0;
}

int mini(int n,int pg[])
{
	int pg1[n],r;
	int temp;

	for(int i=0;i<n;i++)
	{
		pg1[i]=pg[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
		if(pg1[j]>pg1[j+1])
		{
			temp=pg1[j];
			pg1[j]=pg1[j+1];
			pg1[j+1]=temp;
		}
	    }
	}
	for(int i=0;i<n;i++)
	{
		if(pg[i]==pg1[0])
		{
			r=i;
			break;
	}
	}
	return(r);
}

int max(int n,int ar,int pg[])
{
	int pg1[n],r,ar1;
	int temp;
	ar1=ar;
	for(int i=0;i<n;i++)
		{
			pg1[i]=pg[i];
		}

	for(int i=0;i<n;i++)
	{
		if(pg1[i]!=0)
		{
			goto l2;
		}
	}
	if(ar1==n-1)
	{
		ar1=0;
		return(ar1);
	}
	else
	{
		ar1++;
		return(ar1);
	}
	goto l3;


	l2:

	for(int i=0;i<n;i++)
	{
		pg1[i]=pg[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
		if(pg1[j]<pg1[j+1])
		{
			temp=pg1[j];
			pg1[j]=pg1[j+1];
			pg1[j+1]=temp;
		}
	    }
	}
	for(int i=0;i<n;i++)
	{
		if(pg[i]==pg1[0])
		{
			r=i;
			break;
	}
	}
	return(r);
l3:cout<<"";
}

