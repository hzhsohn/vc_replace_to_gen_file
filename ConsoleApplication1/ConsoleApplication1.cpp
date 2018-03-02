// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <direct.h>

//返回值
//0=替换失败
//1=替换成功
//replace_str(strSrc,"我被替换了","靓仔",strDst);
//查找并替换字符串
int replace_str(const char *pInput,const char *pSrc,const char *pDst,char *pOutput)
{
  const char   *pi;
  char *p;
  int nSrcLen, nDstLen, nLen;
  int ret;
  ret=0;
  // 指向输入字符串的游动指针.
  pi = pInput;
  // 计算被替换串和替换串的长度.
  nSrcLen = (int)strlen(pSrc);
  nDstLen = (int)strlen(pDst);
  // 查找pi指向字符串中第一次出现替换串的位置,并返回指针(找不到则返回null).
  p = (char*)strstr(pi, pSrc);
  if(p)
  {
    char *po; // 指向输出字符串的游动指针.
    po=(char*)malloc(strlen(pInput)+strlen(pDst)+1);
    // 计算被替换串前边字符串的长度.
    nLen = (int)(p - pi);
    // 复制到输出字符串.
    memcpy(po, pi, nLen);
    memcpy(po+nLen, pDst, nDstLen);
    strcpy(po+nLen+nDstLen, pi+nLen+nSrcLen);
    // 复制剩余字符串.
    strcpy(pOutput, po);
    free(po);
    po=NULL;
    ret=1;
  }
  else
  {
    // 没有找到则原样复制.
    strcpy(pOutput, pi);
  }
 return ret;
}

char*getCurrentPath(char*filename,char*dst_buf,int dst_buf_len)
{

 #ifdef _WIN32
  GetModuleFileNameA(NULL,dst_buf,dst_buf_len); 
  (strrchr(dst_buf, '\\'))[1] = 0; //删除文件名，只获得路径
 #else
  //头文件：direct.h（TC2.0下为dir.h）
  getcwd(dst_buf, dst_buf_len);
  strcat(dst_buf,"/");
 #endif

 if(filename)
 { strcat_s(dst_buf,dst_buf_len,filename); }
 return dst_buf;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	char filepath[1024]={0};
	char buf[202400]={0};
	char buf2[202400]={0};
	getCurrentPath("svg",filepath,sizeof(filepath));
	_mkdir(filepath);

	char colA[30]={0};
	char colB[30]={0};
	char colC[30]={0};
	char colD[30]={0};
	char colE[30]={0};
	char colF[30]={0};
	char colG[30]={0};
	char colH[30]={0};
	char colI[30]={0};
	char colJ[30]={0};
	char colK[30]={0};

	char txtA[20240]={0};
	char txtB[20240]={0};
	int genCount=0;

	FILE*fp;

	getCurrentPath("count.txt",filepath,sizeof(filepath));
	fp=fopen(filepath,"r");
	if(fp)
	{
		int flen=fread(txtA,1,sizeof(txtA),fp);
		txtA[flen]=0;
		genCount=atoi(txtA);
		fclose(fp);
	}
	if(genCount<=0)
	{
		printf("读取count.txt错误.里面的内容应该填大于0的整数");
		getchar();
		exit(0);
	}

	getCurrentPath("a.txt",filepath,sizeof(filepath));
	fp=fopen(filepath,"r");
	if(fp)
	{
		int flen=fread(txtA,1,sizeof(txtA),fp);
		txtA[flen]=0;
		fclose(fp);
	}

	getCurrentPath("b.txt",filepath,sizeof(filepath));
	fp=fopen(filepath,"r");
	if(fp)
	{
		int flen=fread(txtB,1,sizeof(txtB),fp);
		txtB[flen]=0;
		fclose(fp);
	}

	for(i=0;i<1000;i++)
	{
		sprintf(colA,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colB,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colC,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colD,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colE,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colF,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colG,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colH,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colI,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colJ,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);
		sprintf(colK,"#%02x%02x%02x",rand()%255,rand()%255,rand()%255);


		getCurrentPath("0.svg",filepath,sizeof(filepath));
		fp=fopen(filepath,"r");
		if(fp)
		{
			fread(buf,1,sizeof(buf),fp);
			if(0==replace_str(buf,txtA,txtB,buf2))
			{
				printf("a.txt与b.txt内容替换失败\n\n\n",i);
				printf("-----------a.txt----------\n",i);
				printf("%s",txtA);
				printf("\n\n\n");
				printf("-----------b.txt----------\n",i);
				printf("%s",txtB);
				printf("\n\n\n");
				getchar();
				exit(0);
			}
			replace_str(buf2,"%%S0%%",colA,buf2);
			replace_str(buf2,"%%S1%%",colB,buf2);
			replace_str(buf2,"%%S2%%",colC,buf2);
			replace_str(buf2,"%%S3%%",colD,buf2);
			replace_str(buf2,"%%S4%%",colE,buf2);
			replace_str(buf2,"%%S5%%",colF,buf2);
			replace_str(buf2,"%%S6%%",colG,buf2);
			replace_str(buf2,"%%S7%%",colH,buf2);
			replace_str(buf2,"%%S8%%",colI,buf2);
			replace_str(buf2,"%%S9%%",colJ,buf2);
			replace_str(buf2,"%%S10%%",colK,buf2);
			fclose(fp);
		}
		else
		{
			printf("读取0.svg文件失败\n");
			getchar();
			exit(0);
		}

		printf("正在生成,第%d个\n",i);
		sprintf(buf,"svg/%d.svg",i);
		getCurrentPath(buf,filepath,sizeof(filepath));
		fp=fopen(filepath,"w");
		if(fp)
		{
			fwrite(buf2,1,strlen(buf2),fp);
			fclose(fp);
		}
			
	}

	
	fp=NULL;
	printf("已经完成,共生成%d个\n",i);

	return 0;
}

