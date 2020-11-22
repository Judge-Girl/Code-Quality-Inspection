#include <stdio.h>
#include <string.h>
int main(){
    int i,j;
    char vowel[5]={'a','e','i','o','u'};
    char s[10000];
    int locale[10000];
while(scanf("%s%d%d",s,&i,&j)!=EOF)
{
    int length=strlen(s);
    int sylcnt=0;
    for(int m=0;m<length;m++)
    {
        for(int k=0;k<5;k++)
        {if(s[m]==vowel[k])
            {
                locale[sylcnt]=m;
                sylcnt++;

            }

        }   





    }
    char s1[length+1];
    char s2[length+1];
    char s3[length];
    for(int m=0;m<length;m++)
    {
        if(i==0){
            for(int l=0;l<=locale[i];l++)
            {
                s1[l]=s[l];
                s[l]='+';


            }
            for(int l=locale[i]+1;l<length;l++)
            {
                s1[l]='+';
                
            }
break;
        }
        else if(m>locale[i-1]&&m<=locale[i])
        {
            s1[m]=s[m];
            s[m]='+';

        }        
        else{
            s1[m]='+';


        }

    }
    for(int m=0;m<length;m++)
    {
        if(j==0){
            for(int l=0;l<=locale[j];l++)
            {
                s2[l]=s[l];
                s[l]='+';

            }
            for(int l=locale[j]+1;l<length;l++)
            {
                s2[l]='+';
            }
            break;
        }
        else if(m>locale[j-1]&&m<=locale[j])
        {
            s2[m]=s[m];
            s[m]='+';

        }        
        else{
            s2[m]='+';


        }
    

    }
      s1[length]='\0';
      s2[length]='\0';
            
            



        
printf("%s\n%s\n%s\n",s1,s2,s);




}



    return 0;
}
