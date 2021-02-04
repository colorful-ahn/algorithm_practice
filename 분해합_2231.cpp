#include <bits/stdc++.h>

int main() {
	long n;
    scanf("%d",n);
    long m = n;
    int digit = 0;
    while (m)
    {
        m /= 10;
        digit++;
    }
    long begin = n - digit * 9;
    char s[10];
    long sum = 0;
	bool find=false;
    for (long i = begin; i <= n; ++i)
    {
        sprintf(s, "%ld", i);
        sum = i;
		for(int j=0;j<strlen(s);++j)
			sum += s[j]-'0';
        if(sum == n )
		{
			find=true;
			printf("%d",i);
			break;
		}
    }
	if(find==false)	printf("0");
}
