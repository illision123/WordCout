#include <stdio.h>
#include <string.h>
int main ()
{
  FILE * f;
  char c;
  char d;
  char s[2];
  scanf("%s",&s);
  getchar();
  char path[100];
  gets(path);
  int n = 0;
  f = fopen(path, "r");//E:\\qwe.txt
  c = fgetc(f);
  if (feof(f)) printf("文件错误");
  else
  {
	if(strcmp(s,"-c")==0)
  	{
	  while (!feof(f))
	  {
		if((c>='a'&&c<='z') || (c>='A'&&c<='Z') || c==' ' || c=='#' || c=='\n') n++;
		c = fgetc(f);
	  }
	  printf("字符数：%d",n);
	}
    else if(strcmp(s,"-w")==0)
    {
	  d=c;
	  while (!feof(f))
	  {
		if(c==' '&&(d!=' '&&d!=',') || c==','&&(d!=' '&&d!=',')) n++;
		d=c;
		c = fgetc(f);
	  }
	    if(c==' '&&(d==' '||d==',') || c==','&&(d==' '||d==','))
		printf("单词数：%d",n);
		else printf("单词数：%d",n++);
	}
	else
	{
		printf("统计类型有误");
	}
    fclose(f); // 一定记得要关闭文件
  }
  return 0;
}