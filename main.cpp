//
//  main.cpp
//  ProblemSet7
//
//  Created by Umut Soysal on 17.10.2018.
//  Copyright © 2018 Umut Soysal. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "fssimplewindow.h"
#include "fssimplewindow.h"
#include <string.h>

class CharBitmap{  //The class of Charbitmap
public:
    int wid,hei;
    char *pix;
    char array1;
    unsigned char bttmap;

    CharBitmap();
    ~CharBitmap();
    void CleanUp(void);
    void Create(void);
    void SetPixel(void);
    void GetPixel(void);
    
};
CharBitmap::CharBitmap() // The constructor for protection of the variables of Charbitmap
{
    wid=0;
    hei=0;
    pix=nullptr;
    
}
CharBitmap::~CharBitmap()// The destructor to return the allocated memory
{
    CleanUp(); // Call the cleanup function
}

void CharBitmap::CleanUp(void)
{
    wid=0;
    hei=0;
    if(nullptr!=pix)
    {
        delete [] pix; // empty the string
        pix=nullptr;   // WHY WHY
    }
}

void Create(int wid, int hei)
{
    printf("Create is called");
    printf("What %d",wid);
    printf("Create is called");
    //char bittmap=[40];
}
void CharBitmap::SetPixel(void)
{
    
}
void CharBitmap::GetPixel(void)
{
    
}

char *MyFgets(char str[],int maxn,FILE *fp)
{
    auto r=fgets(str,maxn,fp);
    if(nullptr!=r)
    {
        for(int i=strlen(str)-1; 0<=i; --i)
        {
            if(str[i]<' ')
            {
                str[i]=0;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        str[0]=0;
    }
    return r;
}
int ParseString(int wordTop[],int wordLen[],int maxlen,char input[]) // A function from course notes
{
    if(0==maxlen)  // if the max word length 0, return ( a redundant part of code, might be erased)
    {
        return 0;
    }
    
    int state=0;
    int wordCount=0; // Initialize number of words
    for(int i=0; 0!=input[i]; ++i)
    {
        if(0==state)        { // if a word did not start
            if(' '<input[i])
            {
                wordTop[wordCount]=i; // Words start here
                wordLen[wordCount]=1;
                state=1;    // word is on
                ++wordCount;
            }
        }
        else if(1==state)
        {
            if(input[i]<=' ')
            {
                state=0;
                if(maxlen<=wordCount)
                {
                    break;
                }
            }
            else
            {
                ++wordLen[wordCount-1];
            }
        }
    }
    return wordCount;
}



void ExtractWord(char word[],int maxlen,char input[],int top,int len)  // Another function from course notes
{
    int nChar;
    if(maxlen-1>len)
    {
        nChar=len;
    }
    else
    {
        nChar=maxlen-1;
    }
    
    for(int i=0; i<nChar; ++i)
    {
        word[i]=input[top+i];
    }
    word[nChar]=0;
}


int main (void){

    printf("Enter the dimensions:\n");
    CharBitmap image;
    
    int height;
    char str[256];
    MyFgets(str,255,stdin);
    printf("%s\n",str); // Check if it can read the input string
   
    int wordTop[16],wordLen[16];
    int wc=ParseString(wordTop,wordLen,16,str); // count how many words
    printf("%d words\n",wc); // Print the number of words or variables just for check
    
    
    //for(int i=0; i<wc; ++i)
    //{
     //   printf("%dth word starts at %d length = %d\n",i+1,wordTop[i],wordLen[i]);
    char word1[16];
    ExtractWord(word1,16,str,wordTop[0],wordLen[0]);
    image.wid=atof(word1);
    
    printf("Width: %d\n",image.wid);
    //}
    
    char word2[16];
    ExtractWord(word2,16,str,wordTop[1],wordLen[1]);
    image.hei=atof(word2);
    printf("Height: %d\n",image.hei);
    //}
    Create(image.wid, image.hei);
    //scanf("%d",&userInput);
    //str=fgets( buffer2, 256, stdin );
    //printf("The buffer is: %d",userInput);
    
    //printf("[");
   
    //printf("]");
    
    char deneme[15];
    for (int i=0;i=14;++i)
    {
    printf("Deneme %s neden basmadi",deneme[i]);
    }
    //FsOpenWindow(0,0,800,600,1);
    //glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    
    //int key=FSKEY_NULL;
    //while(FSKEY_ESC!=key)
    //{
     //   FsPollDevice();
      //  key=FsInkey();
       // FsPushOnPaintEvent();
        //FsSleep(50);
    //}
    
    return 0;
    
    
}
