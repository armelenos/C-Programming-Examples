#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




int MyStrlen(char* str)
{
    int i,count=0;
    for(i=0;str[i]!='\0';i++)
        count++;
    return count;
}



int MyStrlenWhile(char* str)
{
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}



int MyStrlenPointer(char* str)
{
    int i=0;
    while(*(str++)!='\0')
        i++;
    return i;
}



int MyStrlenWhileKama(char* str)
{
    int i=-1;
    while(str[++i]!='\0');
    return i;
}



char* MyStrCpy(char* dest,const char* src)
{
    int i;
    for(i=0;src[i]!='\0';i++)
    {
        dest[i]=src[i];
    }

    dest[i]='\0';
    return dest;
}



char* MyStrCpyWhileLoop(char* dest,const char* src)
{
    int i=0;
    while(src[i]!='\0')
    {
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';

    return dest;
}



char* MyStrCpyWhileKama(char* dest,const char* src)
{
    int i=-1;
    while(dest[i]=src[++i]);
    return dest;
}



char* MyStrCpyPointer(char* dest,const char* src)
{
    char* ptr=dest;
    while((*dest++=*src++));
    return ptr;
}




char* MyConcanateTwoString(const char* str1,const char* str2)
{
    char *str3;
    int i;
    int strLength1=strlen(str1);
    int strLength2=strlen(str2);
    int strLength3=strLength1+strLength2;

    str3=malloc(strLength3+1);

    for(i=0;i<strLength1;i++)
        str3[i]=str1[i];

    for(i=0;i<strLength2;i++)
        str3[i+strLength1]=str2[i];

    str3[strLength3]='\0';
    return str3;
}


//a 65
//z 97
int myCompareString(const char* str1,const char *str2)
{
    int i=0;
    while(str1[i]==str2[i])
    {
        if(str1[i]=='\0' && str2[i]=='\0')
            break;
        i++;
    }
    return str1[i]-str2[i];
}





int myCompareStringWhile(const char* str1,const char* str2)
{
    while((*str1 && *str2) && (*str1==*str2))
    {
        str1++;
        str2++;
    }
    return *str1-*str2;
}




char* LowerToUpper(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }
    return str;
}





char* LowerToUpperTernary(char* str)
{
    while(*str)
    {
        *str=(*str>='a' && *str<='z') ? *str-32 : *str;
        str++;
    }
    return str;
}



char* UpperToLower(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        str[i]=str[i]+32;
    }
    return str;
}


char* ToggleCharacter(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]=str[i]-32;
        else
            str[i]=str[i]+32;
    }
    return str;
}




void printCharactersCount(char* str)
{
    int i=0,alphabet=0,digits=0,special=0;
    while(str[i]!='\0')
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            alphabet++;

        else if(str[i]>=48 && str[i]<=57)
            digits++;

        else
            special++;

        i++;
    }

    printf("%d\n",alphabet);
    printf("%d\n",digits);
    printf("%d",special);
}



void countOfVowelsConsonants(char* str)
{
    int wowelCount=0,consonantCount=0;
    while(*str)
    {
        if((*str>='a' && *str<='z') || (*str>='A' && *str<='Z'))
            switch(*str)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                wowelCount++;
                break;
            default:
                consonantCount++;
        }
        str++;
    }

    printf("%d vowel -- %d consonant",wowelCount,consonantCount);
}




int totalNumberWords(const char* str)
{
    int words=0;
    while(*str)
    {
        if(*str==' ' || *str=='\n' || *str=='\t')
            words++;
        str++;
    }
    return words;
}



char* reverseString(const char* str)
{
    char* reverse=malloc(strlen(str)+1);
    int revIndex=0;
    int strIndex=strlen(str)-1;

    while(strIndex>=0)
    {
        reverse[revIndex]=str[strIndex];
        revIndex++;
        strIndex--;
    }

    reverse[revIndex]='\0';
    return reverse;

}


bool isPalindromeString(const char* str)
{
    if(reverseString(str)==str)
        return true;
    return false;
}



int FirstIndexOf(const char* str,char ch)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(ch==str[i])
        {
            return i;
            break;
        }
    }
}



int IndexOfPointer(const char* str,char ch)
{
    int i=0;
    while(*str)
    {
        if(ch==*str)
        {
            return i;
        }
        i++;
        str++;
    }
}


//Mert0
int LastIndexOf(const char* str,char ch)
{
    int i=0;
    int index;
    while(str[i]!='\0')
    {
        if(str[i]==ch)
        {
            index=i;
        }
        i++;
    }
    return index;
}


void printIndexes(char* str,char ch)
{
    int i=0,foundAt;
    while(str[i]!='\0')
    {
        if(str[i]==ch)
        {
            foundAt=i;
            printf("%d",foundAt);
        }
        i++;
    }
}



int totalOccurencesOfCharacter(char* str,char ch)
{
    int count=0;
    while(*str)
    {
        if(*str==ch)
            count++;
        str++;
    }
    return count;
}


char MostOccuredCharacter(const char* str)
{
    int alphabet[255]={0},i=0,index=-1,max=0;
    char mostoccured;
    while(str[i]!='\0')
    {
        char ch=str[i];
        alphabet[ch]++;
        i++;
    }

    for(i=0;i<255;i++)
    {
        if(alphabet[i]>alphabet[max])
        {
            max=i;
        }
    }
    return max;
}





char LeastOccuredCharacter(const char* str)
{
    int alphabet[255]={0},i=0,index=-1,min=0;
    char mostoccured;
    while(str[i]!='\0')
    {
        char ch=str[i];
        alphabet[ch]++;
        i++;
    }

    for(i=0;i<255;i++)
    {
        if(alphabet[i]!=0)
        {
            if(alphabet[min]==0 || alphabet[i]<alphabet[min])
            {
                min=i;
            }
        }
    }
    return min;
}


void printEachCharacterCount(char* str)
{
    int alphabet[26]={0},i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            alphabet[str[i]-97]++;
        }
        else if(str[i]>='A' && str[i]<='Z')
            alphabet[str[i]-65]++;
    }


    for(i=0;i<26;i++)
    {
        if(alphabet[i]!=0)
            printf("%c %d\n",i+97,alphabet[i]);
    }
}



char* RemoveFirstOccurence(char* str,char ch)
{
    int i,firstIndex,j;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==ch)
        {
            firstIndex=i;
            break;
        }
    }


    for(j=firstIndex;str[j]!='\0';j++)
    {
        str[j]=str[j+1];
    }
    return str;
}




char* RemoveLastOccurence(char* str,char ch)
{
    int i,lastIndex,j;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==ch)
        {
            lastIndex=i;
        }
    }


    for(j=lastIndex;str[j]!='\0';j++)
    {
        str[j]=str[j+1];
    }
    return str;
}



char* RemoveAllOccurences(char* str,char ch)
{
    int i,j;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(ch==str[i])
        {
            for(j=i;j<len;j++)
            {
                str[j]=str[j+1];
            }
            len--;
            i--;
        }
    }
    return str;
}



int main()
{
    char str[12]="Codeforwoin";
    printf("%s",RemoveAllOccurences(str,'o'));
    return 0;
}
