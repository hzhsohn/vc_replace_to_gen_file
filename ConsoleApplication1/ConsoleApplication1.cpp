// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <direct.h>

//����ֵ
//0=�滻ʧ��
//1=�滻�ɹ�
//replace_str(strSrc,"�ұ��滻��","����",strDst);
//���Ҳ��滻�ַ���
int replace_str(const char *pInput,const char *pSrc,const char *pDst,char *pOutput)
{
  const char   *pi;
  char *p;
  int nSrcLen, nDstLen, nLen;
  int ret;
  ret=0;
  // ָ�������ַ������ζ�ָ��.
  pi = pInput;
  // ���㱻�滻�����滻���ĳ���.
  nSrcLen = (int)strlen(pSrc);
  nDstLen = (int)strlen(pDst);
  // ����piָ���ַ����е�һ�γ����滻����λ��,������ָ��(�Ҳ����򷵻�null).
  p = (char*)strstr(pi, pSrc);
  if(p)
  {
    char *po; // ָ������ַ������ζ�ָ��.
    po=(char*)malloc(strlen(pInput)+strlen(pDst)+1);
    // ���㱻�滻��ǰ���ַ����ĳ���.
    nLen = (int)(p - pi);
    // ���Ƶ�����ַ���.
    memcpy(po, pi, nLen);
    memcpy(po+nLen, pDst, nDstLen);
    strcpy(po+nLen+nDstLen, pi+nLen+nSrcLen);
    // ����ʣ���ַ���.
    strcpy(pOutput, po);
    free(po);
    po=NULL;
    ret=1;
  }
  else
  {
    // û���ҵ���ԭ������.
    strcpy(pOutput, pi);
  }
 return ret;
}

char*getCurrentPath(char*filename,char*dst_buf,int dst_buf_len)
{

 #ifdef _WIN32
  GetModuleFileNameA(NULL,dst_buf,dst_buf_len); 
  (strrchr(dst_buf, '\\'))[1] = 0; //ɾ���ļ�����ֻ���·��
 #else
  //ͷ�ļ���direct.h��TC2.0��Ϊdir.h��
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
		printf("��ȡcount.txt����.���������Ӧ�������0������");
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
				printf("a.txt��b.txt�����滻ʧ��\n\n\n",i);
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
			printf("��ȡ0.svg�ļ�ʧ��\n");
			getchar();
			exit(0);
		}

		printf("��������,��%d��\n",i);
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
	printf("�Ѿ����,������%d��\n",i);

	return 0;
}

