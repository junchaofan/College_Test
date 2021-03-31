#include "cachelab.h"
typedef unsigned long long ULL;

typedef struct block_info{
	int byte_width; //地址位数 
	bool valid;   //有效 
	ULL last_used;   //为访问次数计数 
	ULL tag; //标记 
} BI;
int hits=0;
int misses=0;
int evictions=0;
int IN_S=0;
int IN_E=0;
int IN_B=0;
bool IN_V=false;
bool IN_H=false;
BI** cache;
void init_cache();//创建cache模拟器
void travel(FILE *fp); //按照访问轨迹访问 
void hit_cache(ULL tag,ULL index); //尝试命中cache 
void free_cache(); //释放cache


int main(int argc,char *argv[])
{
	char filename[30];
	for(int i=1;i<argc;i++){
		switch(argv[i][1]){
			case 'v':{
				IN_V=true;
				break;
			}
			case 'h':{
				IN_H=true;
				break;
			}
			case 's':{
				IN_S=atoi(argv[i+1]);
				break;
			}
			case 'E':{
				IN_E=atoi(argv[i+1]);
				break;
			}
			case 'b':{
				IN_B=atoi(argv[i+1]);
				break;
			}
			case 't':{
				strcpy(filename,argv[i+1]);
				break;
			}
			default:{
				break;
			}
		}
	}
	if(IN_H){
		printf("Usage: Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
		printf("Options:\n");
		printf("  -h         Print this help message.\n");
		printf("  -s <num>   Number of set index bits.\n");
		printf("  -E <num>   Number of lines per set.\n");
		printf("  -b <num>   Number of block offset bits.\n");
		printf("  -t <file>  Trace file.\n");
	}
	init_cache();
	FILE *fp;
	if((fp=fopen(filename,"r"))==NULL){
		printf("File open failed!\n");
		return 0;
	}
	travel(fp);
    printSummary(hits, misses, evictions);
    free_cache();
    return 0;
}

void init_cache(){
	int s=1<<IN_S;
	int e=IN_E;
	cache=malloc(sizeof(BI *)*s);
	for(int i=0;i<s;i++){
		cache[i]=malloc(sizeof(BI)*e);
		for(int j=0;j<e;j++){
			cache[i][j].byte_width=IN_B;
			cache[i][j].last_used=0;
			cache[i][j].valid=false;
			cache[i][j].tag=0;
		}
	}	
}

void free_cache(){
	int s=1<<IN_S;
	for(int i=0;i<s;i++)
		free(cache[i]);
	free(cache);
}

void travel(FILE *fp){
	int shift=IN_S+IN_B;
	int tag_shift; //标记
	int index_shift; //索引 
	int size;
	char operation;
	ULL address;
	while((fscanf(fp," %c %llx,%d",&operation,&address,&size))!=EOF){
		tag_shift=address>>shift;
		index_shift=address<<(64-shift)>>(64-shift+IN_B);
		switch(operation){
			case 'I':break;
			case 'L':
			case 'S':{
				if(IN_V)
					printf("%c %llx,%d",operation,address,size);
				hit_cache(tag_shift,index_shift);
				if(IN_V)
					printf("\n");
				break;
			}
			case 'M':{
				if(IN_V)
					printf("%c %llx,%d",operation,address,size);
				hit_cache(tag_shift,index_shift);
				hit_cache(tag_shift,index_shift);
				if(IN_V)
					printf("\n");
				break;
			}
			default:{
				break;
			}
		}
	}
	
}

void hit_cache(ULL Tag,ULL Index){
	int i,j,k=0;
	int s=1<<IN_S;
	int e=IN_E;
	bool hit=false;
	bool IF_OK=true;
	for(i=0;i<s;i++){
		for(j=0;j<e;j++){
			cache[i][j].last_used+=1;
		}
	}
	for(i=0;i<e;i++){
		if(cache[Index][i].tag==Tag && cache[Index][i].valid){
			hit=true;
			hits+=1; //命中次数加一
			if(IN_V)
				printf(" hit");
			k=i;  //记录命中的行号 
			cache[Index][i].last_used=0; //计时器清零 
		}
	}
//未命中 
	if(!hit){
		IF_OK=false; //为false表明已满
		for(i=0;i<e;i++){
			if(cache[Index][i].valid==false){
				cache[Index][i].valid=true;
				cache[Index][i].last_used=0;
				cache[Index][i].tag=Tag;
				misses+=1;
				if(IN_V)
				printf(" miss");
				IF_OK=true;
				break;
			}
		}
		if(!IF_OK){
			misses+=1;
			if(IN_V)
				printf(" miss");
			k=0; //记录当前last_used最大行号
			ULL max=cache[Index][0].last_used; //记录当前last_used最大值
			for(i=1;i<e;i++){
				if(cache[Index][i].last_used>max){
					max=cache[Index][i].tag;
					k=i;
				}
			}
			cache[Index][k].valid=true;
			cache[Index][k].last_used=0;
			cache[Index][k].tag=Tag;
			evictions+=1; //淘汰一次 
			if(IN_V)
				printf(" evictions");
		}
	}
	return;
}
