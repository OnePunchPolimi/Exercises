#include<stdio.h>
#include<math.h>

#define HP 0
#define ATK 1
#define DEF 2
#define SATK 3
#define SDEF 4
#define SPD 5

#define ACC 1
#define TOT 780
#define MIN 20

#define MAX_HP 255
#define MAX_ATK 190
#define MAX_DEF 230
#define MAX_SATK 194
#define MAX_SDEF 230
#define MAX_SPD 180

#define CP_MULTIPIER 0.7903
#define oneE 0.125



int main(){
	printf("Start\n");
	int maxStats[6];
	int h,a,d,sa,sd,sp;
	int scaledDef,scaledAtk;
	double speedMod;
	int baseDef,baseHP,baseAtk;
	int cp;
	int maxCp=10;
	sp=MIN;
	printf("Loop\n");
	for(h=MIN;h<=TOT && h<MAX_HP;++h){//h+=ACC){
		printf("%d\n",h);
		printf("Current max CP: %d\n",maxCp);
		for(a=MIN;h+a<=TOT && a<MAX_ATK;++a){//a+=ACC){
			for(d=MIN;a+h+d<=TOT && d<MAX_DEF;++d){//d+=ACC){
				for(sa=MIN, sp=MIN;a+h+d+sa<=TOT  && sa<MAX_SATK;++sa){//sa+=ACC){
					for(sd=MIN,sp=MIN;sp>0 && sp<MAX_SPD && sd<MAX_SDEF;++sd){//sd+=ACC){
						sp=TOT-(a+h+d+sa+sd);
						scaledAtk=(int) ( 2*(7*oneE*a+ oneE*sa) );
						scaledDef=(int) ( 2*(5*oneE*d+ 3*oneE*sd) );
						speedMod=( 1+(sp-75)/500.0 );
						baseHP=(int) ( (h*1.75+50) );
						baseDef=(int)( scaledDef*speedMod );
						baseAtk=(int)( scaledAtk*speedMod );
						cp=(int) ( ((baseAtk+15)*(sqrt(baseDef+15)*sqrt(baseHP+15))*CP_MULTIPIER*CP_MULTIPIER)/10 );
						if(cp<10){
							cp=10;
						}
						if(cp>maxCp){
							maxCp=cp;
							maxStats[HP]=h;
							maxStats[ATK]=a;
							maxStats[DEF]=d;
							maxStats[SATK]=sa;
							maxStats[SDEF]=sd;
							maxStats[SPD]=sp;
						}
					}
				}
			}
		}			
	}
	printf("Max CP is %d with:\n",maxCp);
	printf("HP: %d\nAKT: %d\nDEF: %d\nSATK: %d\nSDEF: %d\nSPD: %d\n",maxStats[HP],maxStats[ATK],maxStats[DEF],maxStats[SATK],maxStats[SDEF],maxStats[SPD]);
}