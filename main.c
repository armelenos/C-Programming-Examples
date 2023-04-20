#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int Calculator(int num1,int num2,char ch)
{
    switch(ch)
    {
    case '+':
        return num1+num2;
        break;
    case '-':
        return num1-num2;
        break;
    case '*':
        return num1*num2;
        break;
    case '/':
        return num1/num2;
        break;
    default:
        printf("Not supported\n");
        break;
    }
}



int CevreRectangle(int width,int height)
{
    return 2*(width+height);
}



int AreaRectangle(int width,int height)
{
    return width*height;
}



float CevreCircle(int r)
{
    return 2*3.14*r;
}



float AreaCircle(int r)
{
    return 3.14*pow(r,2);
}


//1m 100 cm
float CmToMeter(int cm)
{
    return cm/100.0;
}



float CmToKm(int cm)
{
    return cm/100000.0;
}



float CelciusToFahrenit(int celcius)
{
    return celcius*9/5+32;
}


float FahrenitToCelcius(int fahrenit)
{
    return (fahrenit-32)*5/9.0;
}



void ConverterYearWeekDay(int days)
{
    int year,week;

    year=days/365;
    week=(days%365)/7;
    days=(days%365)%7;

    printf("%d year %d week %d day",year,week,days);
}


void ConverterYearWeekDay2(int days)
{
    int year,week;

    year=days/365;
    week=(days%365)/7;
    days=days-((year*365)+(week*7));

    printf("%d year %d week %d day",year,week,days);
}


int MyPow(int base,int us)
{
    int res=1,i;
    for(i=1;i<=us;i++)
    {
        res*=base;
    }
    return res;
}



int ThirdAngle(int first,int second)
{
    return 180-first-second;
}




float EquilaTeralTriangleArea(int kenar)
{
    return sqrt(3)/4*pow(kenar,2);
}



float SimpleInterest(int amount,int time,float rate)
{
    return amount*time*rate/100.0;
}



float CompundInterest(int amount,int time,float rate)
{
    return amount*pow(1+rate/100,time);
}



int FindMax2(int a,int b)
{
    return (a>b) ? a : b;
}


int FindMax3(int a,int b,int c)
{
    return (a>b && a>c) ? a : (b>c) ? b : c;
}



void LeapYear(int year)
{
    (year%4==0 && year%100!=0) ? printf("LEAP") : (year%400==0) ? printf("LEAP") : printf("Not leap");
}


void OddOrEven(int num)
{
   (num%2==0) ? printf("Even") : printf("Odd");
}


void CheckAlphabetic(char ch)
{
    (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ? printf("Alphabetic character") : printf("Not alphabetic character");
}


void printDay(int input)
{
    switch(input)
    {
    case 1:
        printf("Pazartesi");
        break;
    case 2:
        printf("Sali");
        break;
    case 3:
        printf("Carsamba");
        break;
    case 4:
        printf("Persembe");
        break;
    case 5:
        printf("Cuma");
        break;
    case 6:
        printf("Cumartesi");
        break;
    case 7:
        printf("Pazar");
        break;
    default:
        printf("Enter 1 to 7");
        break;
    }
}



int printMonthDay(int input)
{
    switch(input)
    {
    case 1:
        return 31;
        break;
    case 2:
        return 29;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    default:
        printf("Enter 1 to 12");
        break;
    }
}



void printVowelConsonant(char ch)
{
    switch(ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'u':
        printf("Vowel");
        break;
    default:
        printf("Consonant");
        break;
    }
}



int BigOneUsingSwitch(int num1,int num2)
{
    switch(num1>num2)
    {
    case 0:
        return num2;
        break;
    case 1:
        return num1;
        break;
    }
}



bool IsEvenUsingSwitch(int num)
{
    switch(num%2)
    {
    case 0:
        return true;
        break;
    case 1:
        return false;
        break;
    }
}


bool IsPositiveUsingSwitch(int number)
{
    switch(number>0)
    {
    case 0:
        return false;
        break;
    case 1:
        return true;
        break;
    }
}



void printAllNaturalNumbers(int num1,int num2)
{
    int i;
    for(i=num1;i<=num2;i++)
        printf("%d",i);
}



void printAllNaturalNumbersWhileLoop(int num1,int num2)
{
    while(num1<=num2)
    {
        printf("%d",num1);
        num1++;
    }
}


void printAllNaturalNumbersReverse(int num1,int num2)
{
    int i;
    for(i=num2;i>=num1;i--)
        printf("%d",i);
}

void printAllNaturalNumbersReverseWhile(int num1,int num2)
{
    while(num2>=num1)
    {
        printf("%d",num2);
        num2--;
    }
}


void printAllCharacters()
{
    char ch;
    for(ch='a';ch<='z';ch++)
        printf("%c",ch);
}


void printAllCharacters2()
{
    int i;
    for(i=97;i<=122;i++)
        printf("%c",i);
}


void printAllEvenNumbers(int num1,int num2)
{
    while(num1<=num2)
    {
        if(!(num1%2))
            printf("%d",num1);
        num1++;
    }
}



void printAllOddNumbers(int num1,int num2)
{
    while(num1<=num2)
    {
        if(num1%2==1)
            printf("%d",num1);
        num1++;
    }
}



void multipicationNumber(int number,int carpan)
{
    int i;
    for(i=1;i<=carpan;i++)
    {
        printf("%d * %d = %d\n",number,i,number*i);
    }
}



int countOfDigits(int number)
{
    int digits=0;
    int num=number;
    while(num)
    {
        digits++;
        num/=10;
    }
    return digits;
}



//54321/10000
int FirstDigit(int number)
{
    int first_digit=(int)(number/pow(10,countOfDigits(number)));
    return first_digit;
}


int LastDigit(int number)
{
    int last_digit=number%10;
    return last_digit;
}



int FirstDigit2(int number)
{
    int first_digit;
    while(number)
    {
        first_digit=number%10;
        number/=10;
    }
    return first_digit;
}



int SumOfDigits(int number)
{
    int sum=0,digit;
    while(number)
    {
        digit=number%10;
        sum+=digit;
        number/=10;
    }
    return sum;
}



int ProductDigits(int number)
{
    int product=1,digit;
    while(number)
    {
        digit=number%10;
        product*=digit;
        number/=10;
    }
    return product;
}


//12345
//54321
int reverseNum(int number)
{
    int reversedNum=0;
    int num=number;
    int i=countOfDigits(number)-1;
    while(num)
    {
        reversedNum+=pow(10,i)*(num%10);
        i--;
        num/=10;
    }
    return reversedNum;
}



int reverseNum2(int number)
{
    int reversedNum=0;
    int num=number;
    while(num)
    {
        reversedNum=(reversedNum*10)+(num%10);
        num/=10;
    }
    return reversedNum;
}



bool isPalindrome(int number)
{
    if(reverseNum2(number)==number)
        return true;
    return false;

}

//12345
void frequency(int number)
{
    int freq[10]={0};
    int last_digit;
    while(number)
    {
        last_digit=number%10;
        freq[last_digit]++;
        number/=10;
    }

    int i;
    for(i=0;i<10;i++)
    {
        printf("%d %d\n",i,freq[i]);
    }
}


//12345
int printAlphabetical(int number)
{
    int num=reverseNum2(number);
    int digits;
    while(num)
    {
        digits=num%10;
        switch(digits)
        {
        case 0:
            printf("Zero");
            break;
        case 1:
            printf("One");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        case 6:
            printf("Six");
            break;
        case 7:
            printf("Seven");
            break;
        case 8:
            printf("Eight");
            break;
        case 9:
            printf("Nine");
            break;
        }
        num/=10;
    }
}



void FindFactors(int number)
{
    int i;
    for(i=1;i<=number;i++)
    {
        if(number%i==0)
            printf("%d",i);
    }
}


int LCM(int num1,int num2)
{
    int max=(num1>num2) ? num1 : num2;
    int lcm,i=max;

    while(true)
    {
        if(i%num1==0 && i%num2==0)
        {
            lcm=i;
            break;
        }
        i+=max;
    }
    return lcm;
}



int GCD(int num1,int num2)
{
    int i,res;
    for(i=1;i<=num1;i++)
    {
        if(num1%i==0 && num2%i==0)
            res=i;
    }
    return res;
}


int factorial(int n)
{
    int fact=1,i;
    if(n==0)
        return fact;

    for(i=1;i<=n;i++)
        fact*=i;

    return fact;
}


bool isPrime(int number)
{
    int i;
    for(i=2;i<number;i++)
    {
        if(number%i==0)
            return false;
    }
    return true;
}



void primeNumbers(int num1,int num2)
{
    int i,j;
    for(i=num1;i<=num2;i++)
    {
        bool isPrime=true;
        for(j=2;j<=sqrt(num2);j++)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }

        if(isPrime)
            printf("%d",i);
    }
}



int primeNumbersSum(int num1,int num2)
{
    int i,j,sum=0;
    for(i=num1;i<=num2;i++)
    {
        bool isPrime=true;
        for(j=2;j<=sqrt(num2);j++)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }

        if(isPrime)
            sum+=i;
    }
    return sum;
}



bool isArmStrong(int number)
{
    int last_digit,sum=0;
    int num=number;
    int digitCount=countOfDigits(num);
    while(num)
    {
        last_digit=num%10;
        sum+=pow(last_digit,digitCount);
        num/=10;
    }

    if(number==sum)
        return true;
    return false;
}



bool isPerfectNumber(int number)
{
    int i,sum=0;
    for(i=1;i<number;i++)
    {
        if(number%i==0)
            sum+=i;
    }

    if(number==sum)
        return true;
    return false;
}



void FindPerfectNumbers(int num1,int num2)
{
    int i,j,sum=0;
    bool isPerfect=true;
    for(i=num1;i<=num2;i++)
    {
        sum=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
                sum+=j;
        }

        if(i==sum)
            printf("%d",i);
    }
}



bool isStrongNumber(int number)
{
    int last_digit,sum=0;
    int num=number;
    while(num)
    {
        last_digit=num%10;
        sum+=factorial(last_digit);
        num/=10;
    }

    if(number==sum)
        return true;
    return false;
}


void FindStrongNumbers(int num1,int num2)
{
    int i;
    bool isStrong;
    for(i=num1;i<=num2;i++)
    {
        isStrong=isStrongNumber(i);

        if(isStrong)
            printf("%d",i);
    }
}



void DisplayFibonacciSeries(int n)
{
    int i,a=0,b=1,c=0;
    for(i=0;i<=n;i++)
    {
        printf("%d",c);
        a=b;
        b=c;
        c=a+b;
    }
}



int binaryToDecimal(int binaryNum)
{
    int octalNum=0,last_digit,i=0;
    int binary=binaryNum;
    while(binary)
    {
        last_digit=binary%2;
        octalNum+=pow(2,i)*last_digit;
        i++;
        binary/=10;
    }
    return octalNum;
}



int binaryToOctal(int binaryNum)
{
    int decimalNum=binaryToDecimal(binaryNum);
    int octalNum=0,remainder=0,quotinent;
    int i=0;
    while(decimalNum)
    {
        quotinent=decimalNum/8;
        remainder=decimalNum%8;
        octalNum+=pow(10,i)*remainder;
        i++;
        decimalNum/=8;
    }
    return octalNum;
}



void SquarePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}



void HollowSquarePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}


//0 4
//1 3
//2 2
//3 1
//4 0
void HollowSquareDiagonal(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1 || i==j || j==n-i-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}



void RhoumbusPattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}



void HollowRhoumbusPattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}







void MirroredRhombusPattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}



void HollowMirroredRhombusPattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n;j++)
        {
            if(i==0 || i==n-1 || j==0 || j==n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}



void RightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}


void HollowRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 || i==n-1 || i==j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}



void MirroredRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf(" ");
        }

        for(j=0;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}


void HollowMirroredRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf(" ");
        }

        for(j=0;j<=i;j++)
        {
            if(i==n-1 || j==0 || i==j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}



void InvertedRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}



void HollowInvertedRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(i==0 || j==0 || j==n-i-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}




void InvertedMirroredRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n-i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}



void HollowInvertedMirroredRightTrianglePattern(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" ");
        }

        for(j=0;j<n-i;j++)
        {
            if(i==0 || j==0 || j==n-i-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}



int main()
{
    HollowInvertedMirroredRightTrianglePattern(5);
}
