#include <stdio.h>
#include <string.h>

char name[40][40];
int balance[40];

int EncryptedStringCmp( char string1[], int len1, int trac1, char string2[], int len2){
	//success 0 ; not -1
	int trac2 = 0;
	while( trac1 < len1 && string1[trac1] != string2[0] ) trac1++;
	if( trac1 == len1 ) return -1;

	int sectrac = trac1;
	while( sectrac < len1 && trac2 < len2 && string1[sectrac] == string2[trac2] ){ 
		sectrac++; trac2++;
	}
	if( trac2 == len2 ) return 0;
	else return EncryptedStringCmp( string1, len1, trac1+1, string2, len2);
}



char tmp_name[40]; char tmp2_name[40];
void Earns( int in, int N){
	int trac = 0;
	while( trac < N && strcmp( name[trac], tmp_name) != 0 ) trac++;
	if( trac < N ) balance[trac] += in;

	//printf("i:%d in:%d\n", trac, in);

	return;
}

void Spends( int out, int N){
	int trac = 0;
	while( trac < N && strcmp( name[trac], tmp_name) != 0 ) trac++;
	if( trac < N && balance[trac] >= out ) balance[trac] -= out;

	//printf("i:%d out:%d\n", trac, out);

	return;
}
void Gives( char tmp2_name[], int transto, int N){
	int trac1 = 0, trac2 = 0;
	while( trac1 < N && strcmp( name[trac1], tmp_name) != 0 ) trac1++;
	while( trac2 < N && strcmp( name[trac2], tmp2_name) != 0 ) trac2++;

	if( trac1 < N && trac2 < N && balance[trac1] >= transto ){
		balance[trac1] -= transto;
		balance[trac2] += transto;
	}

	//printf("i:%d to %d trans:%d\n", trac1, trac2, transto);

	return;
}
void Becomes( int new, int N){
	int trac = 0;
	while( trac < N && strcmp( name[trac], tmp_name) != 0 ) trac++;
	if( trac < N ) balance[trac] = new;

	//printf("i:%d new:%d\n", trac, new);

	return;
}


int main(){
	int N; scanf("%d", &N);
	for( int i = 0 ; i < N ; i++)
		scanf("%s%d", name[i], &balance[i]);

/*
	printf("table\n");
		for( int i = 0 ; i < N ; i++){
			printf("%d : ", i);
			printf("%d", balance[i]);
			printf("\n");
		}*/
	
	while( scanf("%s", tmp_name) != EOF ){
		char intstruction[40];
		scanf("%s", intstruction);


/*
		//printf("%d %s", i, intstruction);
		printf("name:%s\n", tmp_name);
		printf("%s\n", intstruction);
*/


		if( EncryptedStringCmp( intstruction, strlen(intstruction), 0, "earns", 5) == 0 ){
			int in; scanf("%d", &in); //printf("%d\n", in);
			Earns( in, N);
		}
		else if( EncryptedStringCmp( intstruction, strlen(intstruction), 0, "spends", 6) == 0 ){
			int out; scanf("%d", &out); //printf("%d\n", out);
			Spends( out, N);
		}
		else if( EncryptedStringCmp( intstruction, strlen(intstruction), 0, "gives", 5) == 0 ){
			scanf("%s", tmp2_name); //printf("%s", tmp2_name);
			int transto; scanf("%d", &transto);  //printf("%d\n", transto);
			Gives( tmp2_name, transto, N);
		}
		else if( EncryptedStringCmp( intstruction, strlen(intstruction), 0, "becomes", 7) == 0 ){
			int new; scanf("%d", &new); //printf("%d\n", new);
			Becomes( new, N);
		}
		else{
			int amount; scanf("%d", &amount);
		}

/*
		printf("table\n");
		for( int i = 0 ; i < N ; i++){
			printf("%d : ", i);
			printf("%d", balance[i]);
			printf("\n");
		}*/
	}

	for( int i = 0 ; i < N ; i++){
		printf("%s ", name[i]);
		printf("%d", balance[i]);
		if( i != N-1 ) printf("\n");
	}
	
	return 0;
}
