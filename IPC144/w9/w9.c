#include <stdio.h>

struct Player{
	int lvl;
	int str;
	int spd;
	int def;
	int intl;
	int lck;
	int mhp;
	int hp;
};

struct Item{
	int type;
	int power;
};
	
int saveGame(struct Player player, int exp, int nextLvl, float days, struct Item inventory[], int quantities[], int inventorySize){
	char filename[20];
    	char c = ',';

    	printf("Enter filename to write: ");

    	scanf("%s",filename);

    	FILE *fp = fopen(filename,"w");

    	if(fp != NULL) {
        	fprintf(fp,"%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%.1f", player.str, c, player.def, c, player.intl, c, player.spd, 
c, player.lck, c,player.lvl, c, player.hp, c, player.mhp,  c, inventory[0].type, c, inventory[0].power, c, inventory[1].type, c,inventory[1].power, 
c, quantities[0], c,quantities[1], c, exp, c, nextLvl, c, days);
        }
        else {
        printf("Program can not open the file!!!\n");
        return 0;
    	}
    	fclose(fp);
    	return 1;
}

int loadSaveGame(struct Player* player, int *exp, int *nextLvl, float *days, struct Item inventory[], int quantities[], int inventorySize){

	char filename[20];
    	char c = ',';
    	printf("Enter filename to read: ");
    	scanf("%s",filename);
    	FILE *fp = fopen(filename,"r");

    	if(fp != NULL){
        	fscanf(fp,"%d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %d%c %f", &player->str, &c, &player->def, &c, 
&player->intl, &c, &player->spd, &c, &player->lck, &c, &player->lvl, &c, &player->hp, &c, &player->mhp, &c, &inventory[0].type, &c, 
&inventory[0].power, &c, &inventory[1].type, &c, &inventory[1].power, &c, &quantities[0], &c, &quantities[1], &c, exp, &c, nextLvl, &c, days);
    	}

    	else {
        printf("Invalid save file!!\n");
        return 0;
	}
	fclose(fp);
	return 1;
}

int main(void){
	struct Player p1;
	p1.str = 10;
	p1.def = 20;
	p1.spd = 30;
	p1.intl = 40;
	p1.lvl = 5;
	p1.mhp = 50;
	p1.hp = 15;
	p1.lck = 33;

	float days = 12;
	int nextLvl = 15;
	int exp = 24;

	struct Item it[2];

	it[0].type = 3;
	it[1].type = 2;

	it[0].power = 40;
	it[1].power = 20;

	int qnt[2] = {12,34};

	saveGame(p1, exp, nextLvl, days, it, qnt, 2);

	struct Player p2 = {0};
	struct Item i2[2] = {0};
	int q2[2] = {0};

	exp = days = nextLvl= 0;

	while(!loadSaveGame(&p2, &exp, &nextLvl, &days, i2, q2, 2))
;

		printf("\n%d %d %d %d %d %d %d %d \n%d %d \n%d %d \n%d %d \n%d %d %.1f\n", p2.str, p2.def, p2.intl, p2.spd, p2.lck, p2.lvl, p2.hp, p2.mhp, i2[0].type, i2[0].power, i2[1].type,i2[1].power, q2[0],q2[1], exp, nextLvl, days);

}






