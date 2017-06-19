#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH 260

int slen(const char *str) { //размер строки
    int size = 0; 
    while (str[size] != '\0') 
    size += 1;
    return size ; 
}

int stok(char *str, char *ch){//преобразует в последовательность токенов
	int i, idx = -1;
	for(i=0;(str[i] != '\0') && (&str[i] != ch); i++);
	if( &str[i] == ch )
		idx = i;
	return i;
}



char *find_ch(char *str, char c) {//поиск символа
    if(*str == c || !(*str)) {
        return str;
    }
    
    char *cur = str;
    while(*(++cur)) {
        if(*(cur) == c){
            break;
        } 
    }
    
    return cur;
}

int sncmp(char *text1, char *text2, int len){//сравнение строк
	int i;
	for(i = 0; i < len; ++i){
		if(text1[i] != text2[i]){
			return -1;
		}
	}
	return 0;
}

void scpy(char *text1, char *text2){//копирование строки
	int i = slen(text2);
	for(; i >= 0; i--){
		text1[i] = text2[i];
	}
}

void sreplace(char *text, char *sWhat, char *sWith, char *res){//замена подстроки
	char *a = text, *b = res;
	int len = slen(sWhat);
	for(; *b=*a; ++a, ++b){    	
        if(!sncmp(a, sWhat, len)){
            scpy(b, sWith);
            a+=slen(sWhat)-1;
            b+=slen(sWith)-1;
        }
    }
}

int input_delim(int delim){
	printf("Input delim\n");
	int y = scanf("%d", &delim);
	if(!y)
		return -1;
	return delim;
}

char *input(){
	char *path = malloc(sizeof(char) * MAX_PATH);
	if(path == NULL)
	{
	    return NULL;
	}
	fgets(path,MAX_PATH,stdin);
	path[slen(path)] = '\0';
	return path;
}

int check(char *text){
	int len =  0;
	len = slen(text);
	int i;
	for(i = 0; text[i] != '\0'; ++i){
	    if(text[i] == '/')
	    {
	    return -1;
	    }
	}
	return 0;
}

int strindex(char s[], char t[], int i)
{
    int j, k;
    
    for(i; s[i]!='\0'; i++) {
       for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
          ;
       if(k>0 && t[k]=='\0')
          return i;
    }
    return -1;
}
