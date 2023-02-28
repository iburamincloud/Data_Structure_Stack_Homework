//
//  main.c
//  odev2Vy
//
//  Created by ibrahim dağcı on 26.10.2022.
//

#include <stdio.h>
#include <string.h>

typedef struct stack
{
    char string[10][10];
    int Sayilar[10];
    int index;
}Stack;

Stack stack1,stack2;


int stackCurrentArea(Stack *dataStack)
{
    if (dataStack->index<=8)
    {
        printf("boş %d\n",dataStack->index);
        return 1;
    }
    else
    {
        printf("Stack Over!!");
        return 0;
    }
}

void addToStack(Stack *dataStack, char dataString[10])
{
    if (stackCurrentArea(dataStack)==1)
    {
        dataStack->index++;
        
        strcpy(dataStack->string[dataStack->index], dataString);
            
    }
    else
    {
        printf("Stack doldu ekleme yapilamiyor program hatali calisacaktir");
        
    }
}

void deleteStackIndexAndAddStack1(Stack *dataStack, int multpl){
    // stack2 boş mu değil mi bilgisine göre gelen data katsayılarını günceller
    if (dataStack == &stack1)
    {
        // stack 1 den 1 eleman çıkarılıp adet sayısı güncellenir
        for (int i = 0; i<(int)strlen(dataStack->string[dataStack->index]); i++)
        {
            if (dataStack->string[dataStack->index][i]==':')
            {
                int temp1 = dataStack->string[dataStack->index][i+1] - '0';
                int temp2 = multpl * temp1;
                if (temp2>=10)
                {
                    int k = temp2%10;
                    int b = temp2/10;
                    char ct1 = b + 48;
                    char ct2 = k + 48;
                    dataStack->string[dataStack->index][i+1] = ct1;
                    dataStack->string[dataStack->index][i+2] = ct2;
                }
                else
                {
                    char convertedTemp = temp2 + 48;
                    dataStack->string[dataStack->index][i+1] = convertedTemp;
                    break;
                }
                
            }
        }
    }
    else if (dataStack == &stack2)
    {
        // stack2 den tüm elemanlar çıkarılıp aded sayısı güncellenerek stack 1 e eklenir
        for (; dataStack->index>-1; dataStack->index--)
        {
            for (int i = 0; i<(int)strlen(dataStack->string[dataStack->index]); i++)
            {
                if (dataStack->string[dataStack->index][i]==':')
                {
                    int temp1 = dataStack->string[dataStack->index][i+1] - '0';
                    int temp2 = multpl * temp1;
                    if (temp2>=10)
                    {
                        int k = temp2%10;
                        int b = temp2/10;
                        char ct1 = b + 48;
                        char ct2 = k + 48;
                        dataStack->string[dataStack->index][i+1] = ct1;
                        dataStack->string[dataStack->index][i+2] = ct2;
                    }
                    else
                    {
                        char convertedTemp = temp2 + 48;
                        dataStack->string[dataStack->index][i+1] = convertedTemp;
                        
                    }
                    
                    
                    addToStack(&stack1, dataStack->string[dataStack->index]);
                    break;
                }
            }
        }
    }
    
}
void deleteStackIndexAndAddStack2(Stack *dataStack)
{
    //parantezin içini stack2 ye atar
    for (; dataStack->index>-1; dataStack->index--)
    {
        if (dataStack->string[dataStack->index][0]=='(') {
            dataStack->index--;
            break;
        }
        
        addToStack(&stack2,dataStack->string[dataStack->index]);
    }
    
    
    
}

void readString(char dataString[30])
{
    int dataIndex = 0 ;
    int tempIndex = 0 ;
    char temp[10];
    while(dataIndex<=(int)strlen(dataString))
    {
        if (dataIndex == 0)
        {
            if(dataString[dataIndex] == '(')
            {
                temp[tempIndex] = dataString[dataIndex];
                
                    addToStack(&stack1, temp);
                
                
                for (int i =0; i<10; i++)
                {
                    temp[i] = NULL;
                }
                
            }
            else if(dataString[dataIndex] == ')')
            {
                
            }
            else if (dataString[dataIndex]>=48 && dataString[dataIndex]<=57 )
            {
                
            }
            else
            {
                temp[tempIndex] = dataString[dataIndex];
                tempIndex++;
                
                
            }
            
        }
        else
        {
            if(dataString[dataIndex] == '(')
            {
                if (tempIndex != 0)
                {
                    
                        temp[tempIndex]= ':';
                        temp[tempIndex+1]= '1';
                        
                        addToStack(&stack1, temp);
                        for (int i =0; i<10; i++) {
                            temp[i] = NULL;
                        }
                        tempIndex = 0;
                    
                }
                temp[tempIndex] = dataString[dataIndex];
                
                    addToStack(&stack1, temp);
                
                for (int i =0; i<10; i++) {
                    temp[i] = NULL;
                }
                
            }
            else if(dataString[dataIndex] == ')')
            {
                if (tempIndex != 0)
                {
                    
                        temp[tempIndex]= ':';
                        temp[tempIndex+1]= '1';
                        
                        addToStack(&stack1, temp);
                        for (int i =0; i<10; i++) {
                            temp[i] = NULL;
                        }
                        tempIndex = 0;
                }
                    deleteStackIndexAndAddStack2(&stack1);
            }
            else if (dataString[dataIndex]>=48 && dataString[dataIndex]<=57 )
            {
                if (tempIndex != 0)
                {
                    
                        temp[tempIndex]= ':';
                        temp[tempIndex+1]= '1';
                        
                        addToStack(&stack1, temp);
                        for (int i =0; i<10; i++)
                        {
                            temp[i] = NULL;
                        }
                        tempIndex = 0;
                }
                char temp = dataString[dataIndex];
                int multiple = temp - '0';
                if (stack2.index == -1) {
                    deleteStackIndexAndAddStack1(&stack1,multiple);
                }
                else
                {
                    deleteStackIndexAndAddStack1(&stack2,multiple);
                }
            }
            else if (dataString[dataIndex]>=65 && dataString[dataIndex]<=90 )
            {
                if (tempIndex != 0)
                {
                    
                        temp[tempIndex]= ':';
                        temp[tempIndex+1]= '1';
                        
                        addToStack(&stack1, temp);
                        for (int i =0; i<10; i++)
                        {
                            temp[i] = NULL;
                        }
                        tempIndex = 0;
                    
                }
                temp[tempIndex] = dataString[dataIndex];
                tempIndex++;
            }
            
            else
            {
                temp[tempIndex] = dataString[dataIndex];
                tempIndex++;
                
                
            }
        }
            dataIndex++;
    }
        
}

void PrintStack(Stack *dataStack)
{
    
    if (dataStack ==&stack1)
    {
        printf("Stack1\n");
    }
    else if (dataStack ==&stack2)
    {
        printf("Stack2\n");
    }
    
    int tempCurrentIndex = dataStack->index;
    for (; tempCurrentIndex>-1; tempCurrentIndex--)
    {
        printf("    %s\n",dataStack->string[tempCurrentIndex]);
    }
}

int main()
{
    stack1.index = -1;
    stack2.index = -1;
    char dataString[30];
    printf("Lutfen tam sayilar ve parantezler iceren bir string ifade giriniz\n");
    scanf("%s",dataString);
    
    readString(dataString);
    
    PrintStack(&stack1);
    printf("\n");
    PrintStack(&stack2);
    
    return 0;
}
