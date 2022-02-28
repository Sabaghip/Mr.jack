
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include <time.h>


#define color_red "\x1b[31m"
#define color_green "\x1b[32m"
#define color_yellow "\x1b[33m"
#define color_blue "\x1b[34m"
#define color_cyan "\x1b[36m"
#define color_reset "\x1b[0m"


struct zamin whitechapel[9][13];
char matn_khaneha[117][10][6];
struct character  sh={"Sherlock Holmes","Move 1 to 3 houses.\nShow an innocent Character.",1,0,0,0,0,0,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  jw={"John H. Watson","Move 1 to 3 houses.\nYou have a light to make Characters visible.",0,1,0,0,0,0,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  sg={"Sergent Goodley","Move 1 to 3 houses.\nMake other Characters get closer to you.",0,0,0,0,0,1,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  il={"Inspecteur Lestrade","Move 1 to 3 houses.\nYou can close an exit and open another one.",0,0,0,1,0,0,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  wg={"Sir William Gull","Move 1 to 3 houses.\nChange your location with another Character.",0,0,0,0,0,0,1,0,0,1,0,0,NULL,-1,-1,0};
struct character  jb={"Jeremy Bert","Move 1 to 3 houses.\nYou can close a hole and open another one.",0,0,0,0,0,0,0,1,0,1,0,0,NULL,-1,-1,0};
struct character  ms={"Miss Stealthy","Move 1 to 4 houses.You can go from unreachable cells.\n",0,0,0,0,1,0,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  js={"John Smith","Move 1 to 3 houses.\nYou can turn a light off and turn another on.",0,0,1,0,0,0,0,0,0,1,0,0,NULL,-1,-1,0};
struct character  *Jack;
int cheragh_haye_khamoosh[2][2];
int cheragh_haye_roshan[6][2];
int khoroji_haye_baste[2][2];
int khoroji_haye_baz[2][2];
int chah_haye_baste[2][2];
int chah_haye_baz[6][2];
int jw_visible[10][2];
int global_round;
int visible;
int randoms[4];
int anti_randoms[4];

//khali=0    sakhteman=1   chah_baz=2   cheragh_khamoosh=3   ezafi=4   chah_baste=5   cheragh_roshan=6   khorooji baste=7  khorooji_baz=8

//-------------------------------------------------------------

void start_zamin (FILE *fp){
    int data;
    int i=0,j=0;
    char m[30];
    int arr_first[9][13];
    while(!feof(fp)){
        data=fgetc(fp);
        if(data=='\n') {
            i++;
            j = 0;
        }
        else{
            arr_first[i][j]=data-'0';
            j++;
        }
    }

        for ( j = 0; j < 13; j++) {
            whitechapel[i][j].khali = 0;
            whitechapel[i][j].chah_baz = 0;
            whitechapel[i][j].cheragh_khamoosh = 0;
            whitechapel[i][j].sakhteman = 0;
            whitechapel[i][j].ezafi = 0;
            whitechapel[i][j].chah_baste=0;
            whitechapel[i][j].cheragh_roshan=0;
            whitechapel[i][j].khoroji_baste=0;
            whitechapel[i][j].khoroji_baz=0;
            whitechapel[i][j].visible=0;
        }

    int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0;
    for(i=0;i<9;i++)
        for(j=0;j<13;j++){
            switch(arr_first[i][j]){
                case 0:
                    whitechapel[i][j].khali++;
                    break;
                case 1:
                    whitechapel[i][j].sakhteman++;
                    break;
                case 2:
                    whitechapel[i][j].chah_baz++;
                    chah_haye_baz[k5][0]=i;
                    chah_haye_baz[k5++][1]=j;
                    break;
                case 3:
                    whitechapel[i][j].cheragh_khamoosh++;
                    cheragh_haye_khamoosh[k1][0]=i;
                    cheragh_haye_khamoosh[k1++][1]=j;
                    break;
                case 4:
                    whitechapel[i][j].ezafi++;
                    break;
                case 5:
                    whitechapel[i][j].chah_baste++;
                    chah_haye_baste[k6][0]=i;
                    chah_haye_baste[k6++][1]=j;
                    break;
                case 6:
                    whitechapel[i][j].cheragh_roshan++;
                    cheragh_haye_roshan[k2][0]=i;
                    cheragh_haye_roshan[k2++][1]=j;
                    break;
                case 7:
                    whitechapel[i][j].khoroji_baste++;
                    khoroji_haye_baste[k3][0]=i;
                    khoroji_haye_baste[k3++][1]=j;
                    break;
                case 8:
                    whitechapel[i][j].khoroji_baz++;
                    khoroji_haye_baz[k4][0]=i;
                    khoroji_haye_baz[k4++][1]=j;
                    break;
            }
        }

}



void print_map(char s[][10][6]){
    system("cls");
    printf("\n    "color_red"ROUND %d"color_reset"\n\n",global_round);
    int k=0,temp1=0,temp2=1;
    char c='A';
    printf(" \t");
    for(int i=0;i<13;i++)
        printf("%8d  ",i);
    printf("\n \t ");
    for (int i = 0; i < 6; i++)
        printf("            ________");


    for(int j=0;j<9;j++) {
        printf("\n \t ");
        k=temp2;

        for (int i = 0; i < 6; i++) {
            k<14 ? printf("\\          /"color_blue"%3s"color_green"%3s"color_reset"%2s", s[k][0],s[k][1],s[k][2]) :printf("\\"color_green"%3s%3s%4s"color_reset"/"color_blue"%3s"color_green"%3s"color_reset"%2s",s[k-14][6],s[k-14][7],s[k-14][8],s[k][0],s[k][1],s[k][2]);
            k = k + 2;
        }
        if(k>16)printf("\\"color_green"%3s%3s%4s"color_reset"/",s[k-14][6],s[k-14][7],s[k-14][8]); else printf("\\");


        k=temp2;
        printf("\n\t  ");
        for (int i = 0; i < 6; i++) {
            printf("\\________/"color_green"%3s"color_reset"%2s"color_yellow"%5s"color_reset, s[k][3],s[k][4],s[k][5]);
            k = k + 2;
        }
        printf("\\________/");

        printf("\n  \t  ");


        k=temp1;
        for (int i = 0; i < 6; i++) {
            k<116 ? printf("/"color_blue"%3s"color_green"%3s"color_reset"%2s\\"color_green"%3s%3s%4s"color_reset, s[k][0],s[k][1],s[k][2],s[k+1][6],s[k+1][7],s[k+1][8]) : printf("/%3s%3s%2s\\", s[k][0],s[k][1],s[k][2]);
            k = k + 2;
        }
        printf("/"color_blue"%3s"color_green"%3s"color_reset"%2s\\", s[k][0],s[k][1],s[k][2]);
        printf("\n\t");

        k=temp1;
        printf("%c",c++);
        for (int i = 0; i < 6; i++) {
            printf("/"color_green"%3s"color_reset"%2s"color_yellow"%5s"color_reset"\\________", s[k][3],s[k][4],s[k][5]);
            k = k + 2;
        }
        printf("/"color_green"%3s"color_reset"%2s"color_yellow"%5s"color_reset"\\", s[k][3],s[k][4],s[k][5]);
        k = k + 2;
        temp2=k;
        temp1=k-1;
    }
    printf("\n \t ");
    k=104;
    for (int i = 0; i < 7; i++) {
        printf("\\"color_green"%3s%3s%4s"color_reset"/        ",  s[k][6], s[k][7],s[k][8]);
        k = k + 2;
    }
    printf("\n \t ");
    for (int i = 0; i < 7; i++)
        printf(" \\________/         ");

}





void gozastane_cart(struct zamin *maghsad,struct character *c,int i,int j){
    add_end(maghsad,c);
    c->i=i;
    c->j=j;
}

void move_cart(struct zamin *mabda,struct zamin *maghsad,struct character *c,int i,int j){
    delete(&mabda,c->name);
    add_end(maghsad,c);
    c->i=i;
    c->j=j;
}


void update_string(struct zamin c[9][13]){
    for (int i = 0; i < 117; i++)
        for (int j = 0; j < 10; j++)
            strcpy(matn_khaneha[i][j], "");
    int k=0;
    for(int i=0;i<9;i++) {
        for (int j = 0; j < 13; j++){
            if(c[i][j].khali)
                strcpy(matn_khaneha[k++][5],"");
            else if(c[i][j].sakhteman)
                strcpy(matn_khaneha[k++][5]," &&& ");
            else if(c[i][j].chah_baz)
                strcpy(matn_khaneha[k++][5],"  @  ");
            else if(c[i][j].cheragh_khamoosh)
                strcpy(matn_khaneha[k++][5],"  0  ");
            else if(c[i][j].ezafi)
                strcpy(matn_khaneha[k++][5]," XXX ");
            else if(c[i][j].chah_baste)
                strcpy(matn_khaneha[k++][5]," |-| ");
            else if(c[i][j].cheragh_roshan)
                strcpy(matn_khaneha[k++][5],"-_0_-");
            else if(c[i][j].khoroji_baz)
                strcpy(matn_khaneha[k++][5],"exit");
            else if(c[i][j].khoroji_baste)
                strcpy(matn_khaneha[k++][5],"exitX");
        }
    }


    k=0;
    for(int i=0;i<9;i++) {
        for (int j = 0; j < 13; j++){
            matn_khaneha[k][0][0]=(char)('A'+i);
            if (j>9){
                matn_khaneha[k][0][2]=(char)(j%10+'0');
                matn_khaneha[k][0][1]=(char)(j/10+'0');
                matn_khaneha[k++][0][3]='\0';
            } else {
                matn_khaneha[k][0][1] = (char) (j + '0');
                matn_khaneha[k++][0][2] = '\0';
            }
        }
    }

    if(sh.i>-1) {
        if(strcmp(matn_khaneha[13 * sh.i + sh.j][8],"")==0) {
            strcpy(matn_khaneha[13 * sh.i + sh.j][8], "sh");
            if(sh.bigonah) {
                matn_khaneha[13 * sh.i + sh.j][8][2] = '*';
                matn_khaneha[13 * sh.i + sh.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sh.i + sh.j][3],"")==0){
            strcpy(matn_khaneha[13 * sh.i + sh.j][3], "sh");
            if(sh.bigonah) {
                matn_khaneha[13 * sh.i + sh.j][3][2] = '*';
                matn_khaneha[13 * sh.i + sh.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sh.i + sh.j][6],"")==0){
            strcpy(matn_khaneha[13 * sh.i + sh.j][6], "sh");
            if(sh.bigonah) {
                matn_khaneha[13 * sh.i + sh.j][6][2] = '*';
                matn_khaneha[13 * sh.i + sh.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sh.i + sh.j][7],"")==0){
            strcpy(matn_khaneha[13 * sh.i + sh.j][7], "sh");
            if(sh.bigonah) {
                matn_khaneha[13 * sh.i + sh.j][7][2] = '*';
                matn_khaneha[13 * sh.i + sh.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sh.i + sh.j][1],"")==0){
            strcpy(matn_khaneha[13 * sh.i + sh.j][1], "sh");
            if(sh.bigonah) {
                matn_khaneha[13 * sh.i + sh.j][1][2] = '*';
                matn_khaneha[13 * sh.i + sh.j][1][3] = '\0';
            }
        }

    }


    if(jw.i>-1) {
        if(strcmp(matn_khaneha[13 * jw.i + jw.j][8],"")==0) {
            strcpy(matn_khaneha[13 * jw.i + jw.j][8], "jw");
            if(jw.bigonah) {
                matn_khaneha[13 * jw.i + jw.j][8][2] = '*';
                matn_khaneha[13 * jw.i + jw.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jw.i + jw.j][3],"")==0){
            strcpy(matn_khaneha[13 * jw.i + jw.j][3], "jw");
            if(jw.bigonah) {
                matn_khaneha[13 * jw.i + jw.j][3][2] = '*';
                matn_khaneha[13 * jw.i + jw.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jw.i + jw.j][6],"")==0){
            strcpy(matn_khaneha[13 * jw.i + jw.j][6], "jw");
            if(jw.bigonah) {
                matn_khaneha[13 * jw.i + jw.j][6][2] = '*';
                matn_khaneha[13 * jw.i + jw.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jw.i + jw.j][7],"")==0){
            strcpy(matn_khaneha[13 * jw.i + jw.j][7], "jw");
            if(jw.bigonah) {
                matn_khaneha[13 * jw.i + jw.j][7][2] = '*';
                matn_khaneha[13 * jw.i + jw.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jw.i + jw.j][1],"")==0){
            strcpy(matn_khaneha[13 * jw.i + jw.j][1], "jw");
            if(jw.bigonah) {
                matn_khaneha[13 * jw.i + jw.j][1][2] = '*';
                matn_khaneha[13 * jw.i + jw.j][1][3] = '\0';
            }
        }

    }


    if(sg.i>-1) {
        if(strcmp(matn_khaneha[13 * sg.i + sg.j][8],"")==0) {
            strcpy(matn_khaneha[13 * sg.i + sg.j][8], "sg");
            if(sg.bigonah) {
                matn_khaneha[13 * sg.i + sg.j][8][2] = '*';
                matn_khaneha[13 * sg.i + sg.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sg.i + sg.j][3],"")==0){
            strcpy(matn_khaneha[13 * sg.i + sg.j][3], "sg");
            if(sg.bigonah) {
                matn_khaneha[13 * sg.i + sg.j][3][2] = '*';
                matn_khaneha[13 * sg.i + sg.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sg.i + sg.j][6],"")==0){
            strcpy(matn_khaneha[13 * sg.i + sg.j][6], "sg");
            if(sg.bigonah) {
                matn_khaneha[13 * sg.i + sg.j][6][2] = '*';
                matn_khaneha[13 * sg.i + sg.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sg.i + sg.j][7],"")==0){
            strcpy(matn_khaneha[13 * sg.i + sg.j][7], "sg");
            if(sg.bigonah) {
                matn_khaneha[13 * sg.i + sg.j][7][2] = '*';
                matn_khaneha[13 * sg.i + sg.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * sg.i + sg.j][1],"")==0){
            strcpy(matn_khaneha[13 * sg.i + sg.j][1], "sg");
            if(sg.bigonah) {
                matn_khaneha[13 * sg.i + sg.j][1][2] = '*';
                matn_khaneha[13 * sg.i + sg.j][1][3] = '\0';
            }
        }

    }



    if(il.i>-1) {
        if(strcmp(matn_khaneha[13 * il.i + il.j][8],"")==0) {
            strcpy(matn_khaneha[13 * il.i + il.j][8], "il");
            if(il.bigonah) {
                matn_khaneha[13 * il.i + il.j][8][2] = '*';
                matn_khaneha[13 * il.i + il.j][8][3] = '\0';
            }

        }
        else if(strcmp(matn_khaneha[13 * il.i + il.j][3],"")==0){
            strcpy(matn_khaneha[13 * il.i + il.j][3], "il");
            if(il.bigonah) {
                matn_khaneha[13 * il.i + il.j][3][2] = '*';
                matn_khaneha[13 * il.i + il.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * il.i + il.j][6],"")==0){
            strcpy(matn_khaneha[13 * il.i + il.j][6], "il");
            if(il.bigonah) {
                matn_khaneha[13 * il.i + il.j][6][2] = '*';
                matn_khaneha[13 * il.i + il.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * il.i + il.j][7],"")==0){
            strcpy(matn_khaneha[13 * il.i + il.j][7], "il");
            if(il.bigonah) {
                matn_khaneha[13 * il.i + il.j][7][2] = '*';
                matn_khaneha[13 * il.i + il.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * il.i + il.j][1],"")==0){
            strcpy(matn_khaneha[13 * il.i + il.j][1], "il");
            if(il.bigonah) {
                matn_khaneha[13 * il.i + il.j][1][2] = '*';
                matn_khaneha[13 * il.i + il.j][1][3] = '\0';
            }
        }

    }
    if(wg.i>-1) {
        if(strcmp(matn_khaneha[13 * wg.i + wg.j][8],"")==0) {
            strcpy(matn_khaneha[13 * wg.i + wg.j][8], "wg");
            if(wg.bigonah) {
                matn_khaneha[13 * wg.i + wg.j][8][2] = '*';
                matn_khaneha[13 * wg.i + wg.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * wg.i + wg.j][3],"")==0){
            strcpy(matn_khaneha[13 * wg.i + wg.j][3], "wg");
            if(wg.bigonah) {
                matn_khaneha[13 * wg.i + wg.j][3][2] = '*';
                matn_khaneha[13 * wg.i + wg.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * wg.i + wg.j][6],"")==0){
            strcpy(matn_khaneha[13 * wg.i + wg.j][6], "wg");
            if(wg.bigonah) {
                matn_khaneha[13 * wg.i + wg.j][6][2] = '*';
                matn_khaneha[13 * wg.i + wg.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * wg.i + wg.j][7],"")==0){
            strcpy(matn_khaneha[13 * wg.i + wg.j][7], "wg");
            if(wg.bigonah) {
                matn_khaneha[13 * wg.i + wg.j][7][2] = '*';
                matn_khaneha[13 * wg.i + wg.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * wg.i + wg.j][1],"")==0){
            strcpy(matn_khaneha[13 * wg.i + wg.j][1], "wg");
            if(wg.bigonah) {
                matn_khaneha[13 * wg.i + wg.j][1][2] = '*';
                matn_khaneha[13 * wg.i + wg.j][1][3] = '\0';
            }
        }

    }
    if(jb.i>-1) {
        if(strcmp(matn_khaneha[13 * jb.i + jb.j][8],"")==0) {
            strcpy(matn_khaneha[13 * jb.i + jb.j][8], "jb");
            if(jb.bigonah) {
                matn_khaneha[13 * jb.i + jb.j][8][2] = '*';
                matn_khaneha[13 * jb.i + jb.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jb.i + jb.j][3],"")==0){
            strcpy(matn_khaneha[13 * jb.i + jb.j][3], "jb");
            if(jb.bigonah) {
                matn_khaneha[13 * jb.i + jb.j][3][2] = '*';
                matn_khaneha[13 * jb.i + jb.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jb.i + jb.j][6],"")==0){
            strcpy(matn_khaneha[13 * jb.i + jb.j][6], "jb");
            if(jb.bigonah) {
                matn_khaneha[13 * jb.i + jb.j][6][2] = '*';
                matn_khaneha[13 * jb.i + jb.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jb.i + jb.j][7],"")==0){
            strcpy(matn_khaneha[13 * jb.i + jb.j][7], "jb");
            if(jb.bigonah) {
                matn_khaneha[13 * jb.i + jb.j][7][2] = '*';
                matn_khaneha[13 * jb.i + jb.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * jb.i + jb.j][1],"")==0){
            strcpy(matn_khaneha[13 * jb.i + jb.j][1], "jb");
            if(jb.bigonah) {
                matn_khaneha[13 * jb.i + jb.j][1][2] = '*';
                matn_khaneha[13 * jb.i + jb.j][1][3] = '\0';
            }
        }

    }


    if(ms.i>-1) {
        if(strcmp(matn_khaneha[13 * ms.i + ms.j][8],"")==0) {
            strcpy(matn_khaneha[13 * ms.i + ms.j][8], "ms");
            if(ms.bigonah) {
                matn_khaneha[13 * ms.i + ms.j][8][2] = '*';
                matn_khaneha[13 * ms.i + ms.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * ms.i + ms.j][3],"")==0){
            strcpy(matn_khaneha[13 * ms.i + ms.j][3], "ms");
            if(ms.bigonah) {
                matn_khaneha[13 * ms.i + ms.j][3][2] = '*';
                matn_khaneha[13 * ms.i + ms.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * ms.i + ms.j][6],"")==0){
            strcpy(matn_khaneha[13 * ms.i + ms.j][6], "ms");
            if(ms.bigonah) {
                matn_khaneha[13 * ms.i + ms.j][6][2] = '*';
                matn_khaneha[13 * ms.i + ms.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * ms.i + ms.j][7],"")==0){
            strcpy(matn_khaneha[13 * ms.i + ms.j][7], "ms");
            if(ms.bigonah) {
                matn_khaneha[13 * ms.i + ms.j][7][2] = '*';
                matn_khaneha[13 * ms.i + ms.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * ms.i + ms.j][1],"")==0){
            strcpy(matn_khaneha[13 * ms.i + ms.j][1], "ms");
            if(ms.bigonah) {
                matn_khaneha[13 * ms.i + ms.j][1][2] = '*';
                matn_khaneha[13 * ms.i + ms.j][1][3] = '\0';
            }
        }

    }
    if(js.i>-1) {
        if(strcmp(matn_khaneha[13 * js.i + js.j][8],"")==0){
            strcpy(matn_khaneha[13 * js.i + js.j][8], "js");
            if(js.bigonah) {
                matn_khaneha[13 * js.i + js.j][8][2] = '*';
                matn_khaneha[13 * js.i + js.j][8][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * js.i + js.j][3],"")==0){
            strcpy(matn_khaneha[13 * js.i + js.j][3], "js");
            if(js.bigonah) {
                matn_khaneha[13 * js.i + js.j][3][2] = '*';
                matn_khaneha[13 * js.i + js.j][3][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * js.i + js.j][6],"")==0){
            strcpy(matn_khaneha[13 * js.i + js.j][6], "js");
            if(js.bigonah) {
                matn_khaneha[13 * js.i + js.j][6][2] = '*';
                matn_khaneha[13 * js.i + js.j][6][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * js.i + js.j][7],"")==0){
            strcpy(matn_khaneha[13 * js.i + js.j][7], "js");
            if(js.bigonah) {
                matn_khaneha[13 * js.i + js.j][7][2] = '*';
                matn_khaneha[13 * js.i + js.j][7][3] = '\0';
            }
        }
        else if(strcmp(matn_khaneha[13 * js.i + js.j][1],"")==0){
            strcpy(matn_khaneha[13 * js.i + js.j][1], "js");
            if(js.bigonah) {
                matn_khaneha[13 * js.i + js.j][1][2] = '*';
                matn_khaneha[13 * js.i + js.j][1][3] = '\0';
            }
        }

    }
}


int first_menu(){
    system("cls");
    int n=get_n("\n\n\n\t\t\t\t\tMain Menu\n\t\t\t\t\t\t1.New game\n\t\t\t\t\t\t2.Load game\n\t\t\t\t\t\t3.Exit\n\t\t\t\t\t\tEnter your choice:", 1, 3);
    switch(n){
        case 1:
            load_game(0);
            jack();
            visible=1;
            global_round=1;
            play();
            break;

        case 2:
            system("cls");
            printf("\n\n\n\t\t\t\t\twhich save do you want to load?\n\t\t\t\t\t1 or 2 or 3 or 4 or 5\n\t\t\t\t\tEnter 6 for Back to menu.\n");
            int c1 = get_n("", 1, 6);
            if (c1 == 6) {
                return first_menu();
            } else {
                load_game(c1);
                play();
                return 2;
            }
            break;

        case 3:
            system("cls");
            printf(color_red"\n\t\t\t\t\tAre you sure ? any unsaved data will be lost.\n\t\t\t\t\t\t\t\t1.exit\n\t\t\t\t\t\t\t\t"color_reset"2.Cancel");
            int c = get_n("", 1, 2);
            if (c == 1)
                exit(0);
            else {
                return first_menu();
            }
            break;
    }
}

int menu() {
    system("cls");
    int n=get_n("\n\n\n\t\t\t\t\tMain Menu\n\t\t\t\t\t\t1.Continue\n\t\t\t\t\t\t2.Save Game\n\t\t\t\t\t\t3.Exit\n\t\t\t\t\t\tEnter your choice:", 1, 3);

    switch (n) {
        case 1:
            return 1;
            break;

        case 2:
            printf("which save do you want to use?\n1 or 2 or 3 or 4 or 5\nEnter 6 for Back to menu.");
            int d = get_n("", 1, 6);
            if (d == 6) {
                return menu();
            } else {
                save_game(d);
                return menu();
            }
            break;
        case 3:
            printf(color_red"\nAre you sure ? any unsaved data will be lost.\n1.exit\n"color_reset"2.Cancel");
            int c = get_n("", 1, 2);
            if (c == 1)
                exit(0);
            else {
                return menu();
            }
            break;



    }
}



void play(){
    update_string(whitechapel);
    print_map(matn_khaneha);
    //[sh , jw , sg ,il ,wg, jb, ms, js]
    if(global_round%2==1) {
        srand(time(NULL));
        int nobat;
        for (int i = 0; i < 4;) {
            int flag = 0;
            int m = rand() % 8 + 1;

            for (int j = 0; j < 4; j++) {
                if (randoms[j] == m)
                    flag = 1;
            }
            if (flag == 0)
                randoms[i++] = m;
        }

        int j = 0;
        for (int i = 0; i < 4;) {
            j++;
            for (j; j < 9; j++) {
                int flag = 0;
                for (int k = 0; k < 4; k++)
                    if (j == randoms[k])
                        flag = 1;
                if (flag == 0) {
                    anti_randoms[i++] = j;
                    break;
                }
            }
        }
    }


    if(global_round%2==1) {
        sh.visible = 0;
        jw.visible = 0;
        sg.visible = 0;
        il.visible = 0;
        wg.visible = 0;
        jb.visible = 0;
        ms.visible = 0;
        js.visible = 0;
        play_x(randoms, 4, 1);
        check_khoroji();
        play_x(randoms, 3, 0);
        check_khoroji();
        play_x(randoms, 2, 0);
        check_khoroji();
        play_x(randoms, 1, 1);
        check_khoroji();
        if (check_visible(sh)) sh.visible = 1;
        if (check_visible(jw)) jw.visible = 1;
        if (check_visible(sg)) sg.visible = 1;
        if (check_visible(il)) il.visible = 1;
        if (check_visible(wg)) wg.visible = 1;
        if (check_visible(jb)) jb.visible = 1;
        if (check_visible(ms)) ms.visible = 1;
        if (check_visible(js)) js.visible = 1;
        if (Jack->visible == 1) {
            visible = 1;
            printf("\nMR.JACK is visible\n");
            if (sh.visible == 0) sh.bigonah = 1;
            if (jw.visible == 0) jw.bigonah = 1;
            if (sg.visible == 0) sg.bigonah = 1;
            if (il.visible == 0) il.bigonah = 1;
            if (wg.visible == 0) wg.bigonah = 1;
            if (jb.visible == 0) jb.bigonah = 1;
            if (ms.visible == 0) ms.bigonah = 1;
            if (js.visible == 0) js.bigonah = 1;
        } else {
            printf("\nMR.JACK is not visible\n");
            visible = 0;
            if (sh.visible == 1) sh.bigonah = 1;
            if (jw.visible == 1) jw.bigonah = 1;
            if (sg.visible == 1) sg.bigonah = 1;
            if (il.visible == 1) il.bigonah = 1;
            if (wg.visible == 1) wg.bigonah = 1;
            if (jb.visible == 1) jb.bigonah = 1;
            if (ms.visible == 1) ms.bigonah = 1;
            if (js.visible == 1) js.bigonah = 1;
        }
        global_round++;
        update_string(whitechapel);
        print_map(matn_khaneha);
    }else{
        sh.visible=0;
        jw.visible=0;
        sg.visible=0;
        il.visible=0;
        wg.visible=0;
        jb.visible=0;
        ms.visible=0;
        js.visible=0;
        play_x(anti_randoms,4,0);
        check_khoroji();
        play_x(anti_randoms,3,1);
        check_khoroji();
        play_x(anti_randoms,2,1);
        check_khoroji();
        play_x(anti_randoms,1,0);
        check_khoroji();
        if(check_visible(sh)) sh.visible=1;
        if(check_visible(jw)) jw.visible=1;
        if(check_visible(sg)) sg.visible=1;
        if(check_visible(il)) il.visible=1;
        if(check_visible(wg)) wg.visible=1;
        if(check_visible(jb)) jb.visible=1;
        if(check_visible(ms)) ms.visible=1;
        if(check_visible(js)) js.visible=1;
        if(Jack->visible==1){
            visible=1;
            printf("\nMR.JACK is visible\n");

            if(sh.visible==0) sh.bigonah=1;
            if(jw.visible==0) jw.bigonah=1;
            if(sg.visible==0) sg.bigonah=1;
            if(il.visible==0) il.bigonah=1;
            if(wg.visible==0) wg.bigonah=1;
            if(jb.visible==0) jb.bigonah=1;
            if(ms.visible==0) ms.bigonah=1;
            if(js.visible==0) js.bigonah=1;
        }
        else{
            visible=0;
            printf("\nMR.JACK is not visible\n");
            if(sh.visible==1) sh.bigonah=1;
            if(jw.visible==1) jw.bigonah=1;
            if(sg.visible==1) sg.bigonah=1;
            if(il.visible==1) il.bigonah=1;
            if(wg.visible==1) wg.bigonah=1;
            if(jb.visible==1) jb.bigonah=1;
            if(ms.visible==1) ms.bigonah=1;
            if(js.visible==1) js.bigonah=1;
        }
        global_round++;
        update_string(whitechapel);
        print_map(matn_khaneha);
    }
    if(global_round==9){
        system("cls");
        printf("Mr.JACK Won!");
        exit(0);
    }
    int choice = get_n("\nEnter 1 for next round and 2 for menu\n", 1, 2);
    if (choice == 2)
        menu();
    play();
}



int check_visible(struct character c){
    int x=c.i,y=c.j;
    if(x>0)
        if(whitechapel[x-1][y].cheragh_roshan==1 || whitechapel[x-1][y].characters!=NULL)
            return 1;
    if(x<8)
        if(whitechapel[x+1][y].cheragh_roshan==1 || whitechapel[x+1][y].characters!=NULL)
            return 1;
    if(y>0)
        if(whitechapel[x][y-1].cheragh_roshan==1 || whitechapel[x][y-1].characters!=NULL)
            return 1;
    if(y<12)
        if(whitechapel[x][y+1].cheragh_roshan==1 || whitechapel[x][y+1].characters!=NULL)
            return 1;
    if(y%2==1){
        if(x>0 && y>0)
            if(whitechapel[x-1][y-1].cheragh_roshan==1 || whitechapel[x-1][y-1].characters!=NULL)
                return 1;
        if(x>0 && y<12)
            if(whitechapel[x-1][y+1].cheragh_roshan==1 || whitechapel[x-1][y+1].characters!=NULL)
                return 1;
    }
    if(y%2==0){
        if(x<8 && y>0)
            if(whitechapel[x+1][y-1].cheragh_roshan==1 || whitechapel[x+1][y-1].characters!=NULL)
                return 1;
        if(x<8 && y<12)
            if(whitechapel[x+1][y+1].cheragh_roshan==1 || whitechapel[x+1][y+1].characters!=NULL)
                return 1;
    }
    if(whitechapel[x][y].characters->next!=NULL)
        return 1;
    for(int i=0;jw_visible[i][0]>-1;i++)
        if(jw_visible[i][0]==x && jw_visible[i][1]==y)
            return 1;
    return 0;
}


void delete_x(int arr[],int i,int size){
    for(i;i<size-1;i++)
        arr[i]=arr[i+1];
}

void play_x(int randoms[],int size,int o){
    int nobat;
    for(int j=0;j<size;j++){
        if(randoms[j]==1)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"sh",sh.name,sh.details);
        if(randoms[j]==2)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"jw",jw.name,jw.details);
        if(randoms[j]==3)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"sg",sg.name,sg.details);
        if(randoms[j]==4)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"il",il.name,il.details);
        if(randoms[j]==5)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"wg",wg.name,wg.details);
        if(randoms[j]==6)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"jb",jb.name,jb.details);
        if(randoms[j]==7)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"ms",ms.name,ms.details);
        if(randoms[j]==8)
            printf("\n"color_cyan"%d.%s"color_reset"\n%s\n%s\n",j+1,"js",js.name,js.details);
    }
    if(o)
        nobat=get_n("\nkaragah turn:\n",1,size);
    else
        nobat=get_n("\nMR.JACK turn:\n",1,size);
    switch(randoms[nobat-1]){
        case 1:
            play_sh();
            if(o)
                arrest(sh);
            break;
        case 2:
            play_jw();
            if(o)
                arrest(jw);
            //jw
            break;
        case 3:
            play_sg();
            if(o)
                arrest(sg);
            //sg
            break;
        case 4:
            play_il();
            if(o)
                arrest(il);
            //il
            break;
        case 5:
            play_wg();
            if(o)
                arrest(wg);
            //wg
            break;
        case 6:
            play_jb();
            if(o)
                arrest(jb);
            //jb
            break;
        case 7:
            play_ms();
            if(o)
                arrest(ms);
            //ms
            break;
        case 8:
            play_js();
            if(o)
                arrest(js);
            //js
            break;
    }

    delete_x(randoms,nobat-1,size);
}

void arrest (struct character c){
    int x=c.i,y=c.j;
    if(whitechapel[x][y].characters->next==NULL)
        return;
    else{
        int choice=get_n("\nDo you want to arrest\n1.No\n2.Yes",1,2);
        if(choice==1)
            return;
        else{
            int k=show_arrest_list(&whitechapel[x][y]);
            choice=get_n("",1,k);
            system("cls");
            if(get_num(&whitechapel[x][y],k)->JACK==1)
                printf("karagah won!");
            else
                printf("mr.jack won!");
            exit(0);
        }
    }
}

void play_sh(){
    sh.played=1;
    move_3(&sh);
    srand(time(NULL));
    int flag=1;
    while(flag){
        int n=rand()%8+1;
        switch(n){
            case 1:
                if(sh.showed==0) {
                    printf("\n%s", sh.name);
                    sh.bigonah = 1;
                    sh.showed = 1;
                    flag=0;
                }
                break;
            case 2:
                if(jw.showed==0) {
                    printf("\n%s", jw.name);
                    jw.bigonah = 1;
                    jw.showed = 1;
                    flag=0;
                    //jw
                }
                    break;
            case 3:
                if(sg.showed==0) {
                    printf("\n%s", sg.name);
                    sg.bigonah = 1;
                    sg.showed = 1;
                    flag=0;
                    //sg
                }
                    break;
            case 4:
                if(il.showed==0) {
                    printf("\n%s", il.name);
                    il.bigonah = 1;
                    il.showed = 1;
                    flag=0;
                    //il
                }
                    break;
            case 5:
                if(wg.showed==0) {
                    printf("\n%s", wg.name);
                    wg.bigonah = 1;
                    wg.showed = 1;
                    flag=0;
                    //wg
                }
                    break;
            case 6:
                if(jb.showed==0) {
                    printf("\n%s", jb.name);
                    jb.bigonah = 1;
                    jb.showed = 1;
                    flag=0;
                    //jb
                }
                    break;
            case 7:
                if(ms.showed==0) {
                    printf("\n%s", ms.name);
                    ms.bigonah = 1;
                    ms.showed = 1;
                    flag=0;
                    //ms
                }
                    break;
            case 8:
                if(js.showed==0) {
                    printf("\n%s", js.name);
                    js.bigonah = 1;
                    js.showed = 1;
                    flag=0;
                    //js
                }
                    break;
        }
    }
    get_n("\nEnter 1 to continue\n",1,1);
    update_string(whitechapel);
    print_map(matn_khaneha);
}


void play_jw(){
    jw.played=1;
    move_3(&jw);
    int direction=get_n("\nwhich direction ?\n1.up\n2.down\n3.up right\n4.up left\n5.down right\n6.down left\n",1,6);
    int x=jw.i,y=jw.j,k=0;
    for(int i=0;i<10;i++){
        jw_visible[i][0]=-1;
        jw_visible[i][1]=-1;
    }
    switch(direction){
        case 1:
            while(x-1>=0){
                if(whitechapel[x-1][y].sakhteman==0 && whitechapel[x-1][y].ezafi==0) {
                    jw_visible[k][0] = x - 1;
                    jw_visible[k++][1] = y;
                    x = x - 1;
                }else break;
            }
            break;
        case 2:
            while(x+1<=8){
                if(whitechapel[x+1][y].sakhteman==0 && whitechapel[x+1][y].ezafi==0 ) {
                    printf("i");
                    jw_visible[k][0] = x + 1;
                    jw_visible[k++][1] = y;
                    x = x + 1;
                } else break;
            }
            printf("uu");
            break;
        case 3:
            while(1){
                if(y%2==1){
                    if(whitechapel[x-1][y+1].sakhteman==0 && whitechapel[x-1][y+1].ezafi==0 && x-1>=0){
                        if(y+1<=12) {
                            jw_visible[k][0] = x - 1;
                            jw_visible[k++][1] = y + 1;
                            x = x - 1;
                            y = y + 1;
                        }else break;
                    }else break;
                }
                else {
                    if (y + 1 <= 12 && x >= 0) {
                        if (whitechapel[x][y + 1].sakhteman == 0 && whitechapel[x][y + 1].ezafi == 0 ) {
                            jw_visible[k][0] = x;
                            jw_visible[k++][1] = y + 1;
                            y = y + 1;
                        } else break;
                    } else break;
                }
            }
            break;
        case 4:
            while(1){
                if(y%2==1) {
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        if (whitechapel[x - 1][y - 1].sakhteman == 0 && whitechapel[x - 1][y - 1].ezafi == 0) {
                            jw_visible[k][0] = x - 1;
                            jw_visible[k++][1] = y - 1;
                            x = x - 1;
                            y = y - 1;
                        } else break;
                    }else break;
                }
                else{
                    if(y-1>=0) {
                        if (whitechapel[x][y - 1].sakhteman == 0 && whitechapel[x][y - 1].ezafi == 0) {
                            jw_visible[k][0] = x;
                            jw_visible[k++][1] = y - 1;
                            y = y - 1;
                        } else break;
                    }else break;
                }
            }
            break;
        case 5:
            while(1){
                if(y%2==1){
                    if(y+1<=12) {
                        if (whitechapel[x][y + 1].sakhteman == 0 && whitechapel[x][y + 1].ezafi == 0) {
                            jw_visible[k][0] = x;
                            jw_visible[k++][1] = y + 1;
                            y = y + 1;
                        } else break;
                    } else break;
                }
                else{
                    if(x+1<=8 && y+1<=12) {
                        if (whitechapel[x + 1][y + 1].sakhteman == 0 && whitechapel[x + 1][y + 1].ezafi == 0) {
                            jw_visible[k][0] = x + 1;
                            jw_visible[k++][1] = y + 1;
                            y = y + 1;
                            x = x + 1;
                        } else break;
                    }else break;
                }
            }
            break;
        case 6:
            while(1){
                if(y%2==1){
                    if(y-1>=0) {
                        if (whitechapel[x][y - 1].sakhteman == 0 && whitechapel[x][y - 1].ezafi == 0) {
                            jw_visible[k][0] = x;
                            jw_visible[k++][1] = y + 1;
                            y = y - 1;
                        } else break;
                    } else break;
                }
                else{
                    if(x+1<=8 && y-1>=0) {
                        if (whitechapel[x + 1][y - 1].sakhteman == 0 && whitechapel[x + 1][y - 1].ezafi == 0) {
                            jw_visible[k][0] = x + 1;
                            jw_visible[k++][1] = y - 1;
                            y = y - 1;
                            x = x + 1;
                        } else break;
                    } else break;
                }
            }
            break;
    }
    update_string(whitechapel);
    print_map(matn_khaneha);
}

void play_sg(){
    int choice=get_n("Which one first?\n1.Move\n2.Ability\n",1,2);
    sg.played=1;
    if(choice==1)
        move_3(&sg);
    for(int i=0;i<3;i++){
        int choice = get_n("\nwhich one do you want to move\n1.sh\n2.jw\n3.il\n4.wg\n5.jb\n6.ms\n7.js\n",1,7);
        switch (choice){
            case 1:
                move_sg(&sh);
                break;
            case 2:
                move_sg(&jw);
                //jw
                break;
            case 3:
                move_sg(&il);
                //il
                break;
            case 4:
                move_sg(&wg);
                //wg
                break;
            case 5:
                move_sg(&jb);
                //jb
                break;
            case 6:
                move_sg(&ms);
                //ms
                break;
            case 7:
                move_sg(&js);
                //js
                break;
        }
        update_string(whitechapel);
        print_map(matn_khaneha);
    }
}

void play_il(){
    int choice=get_n("Which one first?\n1.Move\n2.Ability\n",1,2);
    il.played=1;
    if(choice==1)
        move_3(&il);
    printf("\nchoose an exit to close:\n");
    for(int r=0;r<2;r++)
        printf("%d.%c%d\n",r+1,'A'+khoroji_haye_baz[r][0],khoroji_haye_baz[r][1]);
    int choice1=get_n("\n",1,6);
    printf("\nchoose an exit to open:\n");
    for(int r=0;r<2;r++)
        printf("%d.%c%d\n",r+1,'A'+khoroji_haye_baste[r][0],khoroji_haye_baste[r][1]);
    int choice2=get_n("\n",1,2);
    choice1--;
    choice2--;
    int tempi=khoroji_haye_baste[choice2][0],tempj=khoroji_haye_baste[choice2][1];
    khoroji_haye_baste[choice2][0]=khoroji_haye_baz[choice1][0];
    khoroji_haye_baste[choice2][1]=khoroji_haye_baz[choice1][1];
    khoroji_haye_baz[choice1][0]=tempi;
    khoroji_haye_baz[choice1][1]=tempj;
    whitechapel[khoroji_haye_baz[choice1][0]][khoroji_haye_baz[choice1][1]].khoroji_baz=1;
    whitechapel[khoroji_haye_baz[choice1][0]][khoroji_haye_baz[choice1][1]].khoroji_baste=0;
    whitechapel[khoroji_haye_baste[choice2][0]][khoroji_haye_baste[choice2][1]].khoroji_baz=0;
    whitechapel[khoroji_haye_baste[choice2][0]][khoroji_haye_baste[choice2][1]].khoroji_baste=1;
    update_string(whitechapel);
    print_map(matn_khaneha);
    if(choice==2)
        move_3(&il);
}

void play_wg(){
    wg.played=1;
    printf("\nDo you want to  move or change your place with another character?\n");
    int choice=get_n("1.Move\n2.Change place\n",1,2);

    if(choice==1) {
        move_3(&wg);
    }else{
        int khaneha[7][2];
        khaneha[0][0]=sh.i;
        khaneha[0][1]=sh.j;
        khaneha[1][0]=jw.i;
        khaneha[1][1]=jw.j;
        khaneha[2][0]=sg.i;
        khaneha[2][1]=sg.j;
        khaneha[3][0]=il.i;
        khaneha[3][1]=il.j;
        khaneha[4][0]=jb.i;
        khaneha[4][1]=jb.j;
        khaneha[5][0]=ms.i;
        khaneha[5][1]=ms.j;
        khaneha[6][0]=js.i;
        khaneha[6][1]=js.j;
        printf("1.sh\n2.jw\n3.sg\n4.il\n5.jb\n6.ms\n7.js\n");
        choice=get_n("\nEnter your choice: ",1,7);
        switch(choice){
            case 1:
                move_cart(&whitechapel[sh.i][sh.j],&whitechapel[wg.i][wg.j],&sh,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[0][0]][khaneha[0][1]],&wg,khaneha[0][0],khaneha[0][1]);
                break;
            case 2:
                move_cart(&whitechapel[jw.i][jw.j],&whitechapel[wg.i][wg.j],&jw,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[1][0]][khaneha[1][1]],&wg,khaneha[1][0],khaneha[1][1]);
                break;
            case 3:
                move_cart(&whitechapel[sg.i][sg.j],&whitechapel[wg.i][wg.j],&sg,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[2][0]][khaneha[2][1]],&wg,khaneha[2][0],khaneha[2][1]);
                break;
            case 4:
                move_cart(&whitechapel[il.i][il.j],&whitechapel[wg.i][wg.j],&il,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[3][0]][khaneha[3][1]],&wg,khaneha[3][0],khaneha[3][1]);
                break;
            case 5:
                move_cart(&whitechapel[jb.i][jb.j],&whitechapel[wg.i][wg.j],&jb,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[4][0]][khaneha[4][1]],&wg,khaneha[4][0],khaneha[4][1]);
                break;
            case 6:
                move_cart(&whitechapel[ms.i][ms.j],&whitechapel[wg.i][wg.j],&ms,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[5][0]][khaneha[5][1]],&wg,khaneha[5][0],khaneha[5][1]);
                break;
            case 7:
                move_cart(&whitechapel[js.i][js.j],&whitechapel[wg.i][wg.j],&js,wg.i,wg.j);
                move_cart(&whitechapel[wg.i][wg.j],&whitechapel[khaneha[6][0]][khaneha[6][1]],&wg,khaneha[6][0],khaneha[6][1]);
                break;
        }
    }

    update_string(whitechapel);
    print_map(matn_khaneha);

}

void play_jb(){
    int choice=get_n("Which one first?\n1.Move\n2.Ability\n",1,2);
    jb.played=1;
    if(choice==1)
        move_3(&jb);
    printf("\nchoose a hole to close:\n");
    for(int r=0;r<6;r++)
        printf("%d.%c%d\n",r+1,'A'+chah_haye_baz[r][0],chah_haye_baz[r][1]);
    int choice1=get_n("\n",1,6);
    printf("\nchoose a hole to open:\n");
    for(int r=0;r<2;r++)
        printf("%d.%c%d\n",r+1,'A'+chah_haye_baste[r][0],chah_haye_baste[r][1]);
    int choice2=get_n("\n",1,2);
    choice1--;
    choice2--;
    int tempi=chah_haye_baste[choice2][0],tempj=chah_haye_baste[choice2][1];
    chah_haye_baste[choice2][0]=chah_haye_baz[choice1][0];
    chah_haye_baste[choice2][1]=chah_haye_baz[choice1][1];
    chah_haye_baz[choice1][0]=tempi;
    chah_haye_baz[choice1][1]=tempj;
    whitechapel[chah_haye_baz[choice1][0]][chah_haye_baz[choice1][1]].chah_baz=1;
    whitechapel[chah_haye_baz[choice1][0]][chah_haye_baz[choice1][1]].chah_baste=0;
    whitechapel[chah_haye_baste[choice2][0]][chah_haye_baste[choice2][1]].chah_baz=0;
    whitechapel[chah_haye_baste[choice2][0]][chah_haye_baste[choice2][1]].chah_baste=1;
    update_string(whitechapel);
    print_map(matn_khaneha);
    if(choice==2)
        move_3(&jb);

}

void play_ms(){
    ms.played=1;
    move_4(&ms);
    update_string(whitechapel);
    print_map(matn_khaneha);
}

void play_js(){
    int choice=get_n("Which one first?\n1.Move\n2.Ability\n",1,2);
    js.played=1;
    if(choice==1)
        move_3(&js);
    printf("\nchoose a light to turn off:\n");
    for(int r=0;r<6;r++)
        printf("%d.%c%d\n",r+1,'A'+cheragh_haye_roshan[r][0],cheragh_haye_roshan[r][1]);
    int choice1=get_n("\n",1,6);
    printf("\nchoose a light to turn on:\n");
    for(int r=0;r<2;r++)
        printf("%d.%c%d\n",r+1,'A'+cheragh_haye_khamoosh[r][0],cheragh_haye_khamoosh[r][1]);
    int choice2=get_n("\n",1,2);
    choice1--;
    choice2--;
    int tempi=cheragh_haye_khamoosh[choice2][0],tempj=cheragh_haye_khamoosh[choice2][1];
    cheragh_haye_khamoosh[choice2][0]=cheragh_haye_roshan[choice1][0];
    cheragh_haye_khamoosh[choice2][1]=cheragh_haye_roshan[choice1][1];
    cheragh_haye_roshan[choice1][0]=tempi;
    cheragh_haye_roshan[choice1][1]=tempj;
    whitechapel[cheragh_haye_roshan[choice1][0]][cheragh_haye_roshan[choice1][1]].cheragh_roshan=1;
    whitechapel[cheragh_haye_roshan[choice1][0]][cheragh_haye_roshan[choice1][1]].cheragh_khamoosh=0;
    whitechapel[cheragh_haye_khamoosh[choice2][0]][cheragh_haye_khamoosh[choice2][1]].cheragh_roshan=0;
    whitechapel[cheragh_haye_khamoosh[choice2][0]][cheragh_haye_khamoosh[choice2][1]].cheragh_khamoosh=1;
    update_string(whitechapel);
    print_map(matn_khaneha);
    if(choice==2)
        move_3(&js);
}




int select_cell(int khaneha[11][2],int n,int on_x,int *x,int *y){
    int k=1;
        for(int j=0;khaneha[j][0]>-1;j++)
            printf("%d.%d%c\t",k++,khaneha[j][1],khaneha[j][0]+'A');
        if(n!=1 && on_x!=1)
            printf("%d.finish",k++);
    int choice=get_n("\nEnter your choice:\n",1,k-1);
    if(n!=1 && on_x!=1 && choice==k-1)
        return 1;
    *x=khaneha[choice-1][0];
    *y=khaneha[choice-1][1];
    return 0;
}

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------


void available_cells(int khaneha[11][2],struct character *c){
        for(int d=0;d<11;d++){
            khaneha[d][0]=-1;
            khaneha[d][1]=-1;
        }
    int k=0;
    int x = c->i;
    int y = c->j;

        if(x!=0) {
            if (whitechapel[x - 1][y].sakhteman != 1 && whitechapel[x - 1][y].ezafi != 1 &&
                whitechapel[x - 1][y].cheragh_khamoosh != 1 && whitechapel[x - 1][y].cheragh_roshan != 1) {
                khaneha[k][0] = x - 1;
                khaneha[k++][1] = y;
            }
        }


        if(x!=8) {
            if (whitechapel[x + 1][y].sakhteman != 1 && whitechapel[x + 1][y].ezafi != 1 &&
                whitechapel[x + 1][y].cheragh_khamoosh != 1 && whitechapel[x + 1][y].cheragh_roshan != 1) {
                khaneha[k][0] = x + 1;
                khaneha[k++][1] = y;
            }
        }


        if(y!=0) {
            if (whitechapel[x][y - 1].sakhteman != 1 && whitechapel[x][y - 1].ezafi != 1 &&
                whitechapel[x][y - 1].cheragh_khamoosh != 1 && whitechapel[x][y - 1].cheragh_roshan != 1) {
                khaneha[k][0] = x;
                khaneha[k++][1] = y - 1;
            }
        }


        if(y!=12) {
            if (whitechapel[x][y + 1].sakhteman != 1 && whitechapel[x][y + 1].ezafi != 1 &&
                whitechapel[x][y + 1].cheragh_khamoosh != 1 && whitechapel[x][y + 1].cheragh_roshan != 1) {
                khaneha[k][0] = x;
                khaneha[k++][1] = y + 1;
            }
        }



        if (y % 2 == 1) {
            if(x!=0 && y!=12) {
                if (whitechapel[x - 1][y + 1].sakhteman != 1 && whitechapel[x - 1][y + 1].ezafi != 1 &&
                    whitechapel[x - 1][y + 1].cheragh_khamoosh != 1 && whitechapel[x - 1][y + 1].cheragh_roshan != 1) {
                    khaneha[k][0] = x - 1;
                    khaneha[k++][1] = y + 1;
                }
            }

            if(x!=0 && y!=0) {
                if (whitechapel[x - 1][y - 1].sakhteman != 1 && whitechapel[x - 1][y - 1].ezafi != 1 &&
                    whitechapel[x - 1][y - 1].cheragh_khamoosh != 1 && whitechapel[x - 1][y - 1].cheragh_roshan != 1) {
                    khaneha[k][0] = x - 1;
                    khaneha[k++][1] = y - 1;
                }
            }

        } else {
            if(x!=8 && y!=0) {
                if (whitechapel[x + 1][y - 1].sakhteman != 1 && whitechapel[x + 1][y - 1].ezafi != 1 &&
                    whitechapel[x + 1][y - 1].cheragh_khamoosh != 1  && whitechapel[x + 1][y - 1].cheragh_roshan != 1) {
                    khaneha[k][0] = x + 1;
                    khaneha[k++][1] = y - 1;
                }
            }


            if(x!=8 && y!=12) {
                if (whitechapel[x + 1][y + 1].sakhteman != 1 && whitechapel[x + 1][y + 1].ezafi != 1 &&
                    whitechapel[x + 1][y + 1].cheragh_khamoosh != 1 && whitechapel[x + 1][y + 1].cheragh_roshan != 1) {
                    khaneha[k][0] = x + 1;
                    khaneha[k++][1] = y + 1;
                }
            }

        }
    if(whitechapel[x][y].chah_baz==1){
            for(int i=0;i<6;i++){
                if(x!=chah_haye_baz[i][0] || y!=chah_haye_baz[i][1]){
                    khaneha[k][0]=chah_haye_baz[i][0];
                    khaneha[k++][1]=chah_haye_baz[i][1];
                }
            }
        }
}



void available_cells_new(int khaneha[11][2],struct character *c){
    for(int d=0;d<11;d++){
        khaneha[d][0]=-1;
        khaneha[d][1]=-1;
    }
    int k=0;
    int x = c->i;
    int y = c->j;

    if(x!=0) {
            khaneha[k][0] = x - 1;
            khaneha[k++][1] = y;
    }
    if(x!=8) {
            khaneha[k][0] = x + 1;
            khaneha[k++][1] = y;
    }
    if(y!=0) {
            khaneha[k][0] = x;
            khaneha[k++][1] = y - 1;
    }
    if(y!=12) {
            khaneha[k][0] = x;
            khaneha[k++][1] = y + 1;
    }
    if (y % 2 == 1) {
        if(x!=0 && y!=12) {
                khaneha[k][0] = x - 1;
                khaneha[k++][1] = y + 1;
        }
        if(x!=0 && y!=0) {
                khaneha[k][0] = x - 1;
                khaneha[k++][1] = y - 1;
        }
    } else {
        if(x!=8 && y!=0) {
            khaneha[k][0] = x + 1;
            khaneha[k++][1] = y - 1;
        }
        if(x!=8 && y!=12) {
                khaneha[k][0] = x + 1;
                khaneha[k++][1] = y + 1;
        }
    }
    if(whitechapel[x][y].chah_baz==1){
        for(int i=0;i<6;i++){
            if(x!=chah_haye_baz[i][0] || y!=chah_haye_baz[i][1]){
                khaneha[k][0]=chah_haye_baz[i][0];
                khaneha[k++][1]=chah_haye_baz[i][1];
            }
        }
    }
}



void move_3(struct character *c){
    int first_i=c->i,first_j=c->j;
    int khaneha[11][2];
    available_cells(khaneha,c);
    printf("\nfirst move : %s go from %c %d to ?\n",c->name,(char)((int)'A'+c->i),c->j);
    int i,j;
    select_cell(khaneha,1,0,&i,&j);
    printf("\nyour choice is %d%c",j,'A'+i);

    move_cart(&whitechapel[c->i][c->j],&whitechapel[i][j],c,i,j);
    update_string(whitechapel);
    print_map(matn_khaneha);

    for(int n=2;n<4;n++){
        available_cells(khaneha,c);
        printf("\n%dnd move : %s go from %c %d to ?\n",n,c->name,(char)((int)'A'+c->i),c->j);
        int f=select_cell(khaneha,n,0,&i,&j);
        if(!f)
            move_cart(&whitechapel[c->i][c->j],&whitechapel[i][j],c,i,j);
        update_string(whitechapel);
        print_map(matn_khaneha);
        if(f) {
            if(first_i==c->i && first_j==c->j){
                printf("\nyou cant go to your first place.\n");
                move_3(c);
            }
            return;
        }

    }
    if(first_i==c->i && first_j==c->j){
        printf("\nyou cant go to your first place.\n");
        move_3(c);
    }
}


void move_4(struct character *c){
    int first_i=c->i,first_j=c->j;
    int khaneha[11][2];
    available_cells_new(khaneha,c);
    printf("\nfirst move : %s go from %c %d to ?\n",c->name,(char)((int)'A'+c->i),c->j);
    int i,j;
    select_cell(khaneha,1,0,&i,&j);
    printf("\nyour choice is %d%c",j,'A'+i);
    move_cart(&whitechapel[c->i][c->j],&whitechapel[i][j],c,i,j);
    printf("f");
    update_string(whitechapel);
    print_map(matn_khaneha);

    for(int n=2;n<4;n++) {
        int f;
        available_cells_new(khaneha, c);
        printf("\n%dnd move : %s go from %c %d to ?\n", n, c->name, (char) ((int) 'A' + c->i), c->j);
        if (whitechapel[c->i][c->j].cheragh_roshan == 1 || whitechapel[c->i][c->j].cheragh_khamoosh == 1 ||
            whitechapel[c->i][c->j].ezafi == 1 || whitechapel[c->i][c->j].sakhteman == 1)
            f = select_cell(khaneha, n, 1, &i, &j);
        else
            f = select_cell(khaneha, n, 0, &i, &j);
        if (!f) {
            printf("\nyour choice is %d%c", j, 'A' + i);
            move_cart(&whitechapel[c->i][c->j], &whitechapel[i][j], c, i, j);
        }
        update_string(whitechapel);
        print_map(matn_khaneha);
        if (f) {
            if (first_i == c->i && first_j == c->j) {
                printf("\nyou cant go to your first place.\n");
                move_4(c);
            }
            return;
        }
    }
    available_cells(khaneha,c);
    printf("\nfirst move : %s go from %c %d to ?\n",c->name,(char)((int)'A'+c->i),c->j);
    if(whitechapel[c->i][c->j].cheragh_roshan==1 || whitechapel[c->i][c->j].cheragh_khamoosh==1 || whitechapel[c->i][c->j].ezafi==1 || whitechapel[c->i][c->j].sakhteman==1 )
        select_cell(khaneha,4,1,&i,&j);
    else
        select_cell(khaneha,4,0,&i,&j);
    printf("\nyour choice is %d%c",j,'A'+i);

    move_cart(&whitechapel[c->i][c->j],&whitechapel[i][j],c,i,j);
    update_string(whitechapel);
    print_map(matn_khaneha);
        if(first_i==c->i && first_j==c->j){
            printf("\nyou cant go to your first place.\n");
            move_4(c);
        }

}


int get_n(char str[100],int min,int max){
    int n;
    printf("%s",str);
    scanf("%d",&n);
    while(n>max || n<min){
        printf(color_red"Wrong input"color_reset"\n%s",str);
        scanf("%d",&n);
    }
    return n;
}


void jack(){
    get_n("Enter 1 to show MR.JACK\n",1,1);
    srand(time(NULL));
    int n=rand()%8+1;
    printf("\nMR.JACK is:");
    switch(n){
        case 1:
            printf("\n"color_blue"%s"color_reset,sh.name);
            sh.JACK=1;
            sh.showed=1;
            Jack=&sh;
            break;
        case 2:
            printf("\n"color_blue"%s"color_reset,jw.name);
            jw.JACK=1;
            jw.showed=1;
            Jack=&jw;
            //jw
            break;
        case 3:
            printf("\n"color_blue"%s"color_reset,sg.name);
            sg.JACK=1;
            sg.showed=1;
            Jack=&sg;
            //sg
            break;
        case 4:
            printf("\n"color_blue"%s"color_reset,il.name);
            il.JACK=1;
            il.showed=1;
            Jack=&il;
            //il
            break;
        case 5:
            printf("\n"color_blue"%s"color_reset,wg.name);
            wg.JACK=1;
            wg.showed=1;
            Jack=&wg;
            //wg
            break;
        case 6:
            printf("\n"color_blue"%s"color_reset,jb.name);
            jb.JACK=1;
            jb.showed=1;
            Jack=&jb;
            //jb
            break;
        case 7:
            printf("\n"color_blue"%s"color_reset,ms.name);
            ms.JACK=1;
            ms.showed=1;
            Jack=&ms;
            //ms
            break;
        case 8:
            printf("\n"color_blue"%s"color_reset,js.name);
            js.JACK=1;
            js.showed=1;
            Jack=&js;
            //js
            break;
    }
    get_n("\nEnter 1 to start\n",1,1);
}

void move_sg(struct character *c){
    int x1=sg.i, y1=sg.j, x2=c->i, y2=c->j;
    int khaneha[6][2];
    available_cells_plus(khaneha,c);
    printf("\nfirst move : %s go from %c %d to ?\n",c->name,(char)((int)'A'+c->i),c->j);
    int i,j;
    select_cell(khaneha,1,0,&i,&j);
    printf("\nyour choice is %d%c",j,'A'+i);

    move_cart(&whitechapel[c->i][c->j],&whitechapel[i][j],c,i,j);
    update_string(whitechapel);
    print_map(matn_khaneha);
}


void available_cells_plus(int khaneha[6][2],struct character *c){
    for(int d=0;d<6;d++){
        khaneha[d][0]=-1;
        khaneha[d][1]=-1;
    }
    int k=0;
    int x = c->i;
    int y = c->j;

    if(x!=0) {
        if (whitechapel[x - 1][y].sakhteman != 1 && whitechapel[x - 1][y].ezafi != 1 &&
            whitechapel[x - 1][y].cheragh_khamoosh != 1 && whitechapel[x - 1][y].cheragh_roshan != 1) {
            khaneha[k][0] = x - 1;
            khaneha[k++][1] = y;
        }
    }


    if(x!=8) {
        if (whitechapel[x + 1][y].sakhteman != 1 && whitechapel[x + 1][y].ezafi != 1 &&
            whitechapel[x + 1][y].cheragh_khamoosh != 1 && whitechapel[x + 1][y].cheragh_roshan != 1) {
            khaneha[k][0] = x + 1;
            khaneha[k++][1] = y;
        }
    }


    if(y!=0) {
        if (whitechapel[x][y - 1].sakhteman != 1 && whitechapel[x][y - 1].ezafi != 1 &&
            whitechapel[x][y - 1].cheragh_khamoosh != 1 && whitechapel[x][y - 1].cheragh_roshan != 1) {
            khaneha[k][0] = x;
            khaneha[k++][1] = y - 1;
        }
    }


    if(y!=12) {
        if (whitechapel[x][y + 1].sakhteman != 1 && whitechapel[x][y + 1].ezafi != 1 &&
            whitechapel[x][y + 1].cheragh_khamoosh != 1 && whitechapel[x][y + 1].cheragh_roshan != 1) {
            khaneha[k][0] = x;
            khaneha[k++][1] = y + 1;
        }
    }



    if (y % 2 == 1) {
        if(x!=0 && y!=12) {
            if (whitechapel[x - 1][y + 1].sakhteman != 1 && whitechapel[x - 1][y + 1].ezafi != 1 &&
                whitechapel[x - 1][y + 1].cheragh_khamoosh != 1 && whitechapel[x - 1][y + 1].cheragh_roshan != 1) {
                khaneha[k][0] = x - 1;
                khaneha[k++][1] = y + 1;
            }
        }

        if(x!=0 && y!=0) {
            if (whitechapel[x - 1][y - 1].sakhteman != 1 && whitechapel[x - 1][y - 1].ezafi != 1 &&
                whitechapel[x - 1][y - 1].cheragh_khamoosh != 1 && whitechapel[x - 1][y - 1].cheragh_roshan != 1) {
                khaneha[k][0] = x - 1;
                khaneha[k++][1] = y - 1;
            }
        }

    } else {
        if(x!=8 && y!=0) {
            if (whitechapel[x + 1][y - 1].sakhteman != 1 && whitechapel[x + 1][y - 1].ezafi != 1 &&
                whitechapel[x + 1][y - 1].cheragh_khamoosh != 1  && whitechapel[x + 1][y - 1].cheragh_roshan != 1) {
                khaneha[k][0] = x + 1;
                khaneha[k++][1] = y - 1;
            }
        }


        if(x!=8 && y!=12) {
            if (whitechapel[x + 1][y + 1].sakhteman != 1 && whitechapel[x + 1][y + 1].ezafi != 1 &&
                whitechapel[x + 1][y + 1].cheragh_khamoosh != 1 && whitechapel[x + 1][y + 1].cheragh_roshan != 1) {
                khaneha[k][0] = x + 1;
                khaneha[k++][1] = y + 1;
            }
        }

    }
}

void check_khoroji(){
    if(whitechapel[Jack->i][Jack->j].khoroji_baz==1 && visible==0){
        system("cls");
        printf("mr.Jack won!");
        exit(0);
    }
}


void load_game(int n){
    if(n!=0) {
        char file_save[30];
        sprintf(file_save,"save_%d.bin",n);
        FILE *save = fopen(file_save, "rb");
        fread(whitechapel, sizeof(whitechapel), 1, save);
        fread(&sh,sizeof(sh),1,save);
        fread(&jw,sizeof(jw),1,save);
        fread(&js,sizeof(js),1,save);
        fread(&il,sizeof(il),1,save);
        fread(&ms,sizeof(ms),1,save);
        fread(&sg,sizeof(sg),1,save);
        fread(&wg,sizeof(wg),1,save);
        fread(&jb,sizeof(jb),1,save);
        fread(cheragh_haye_khamoosh,sizeof(cheragh_haye_khamoosh),1,save);
        fread(cheragh_haye_roshan,sizeof(cheragh_haye_roshan),1,save);
        fread(khoroji_haye_baste,sizeof(khoroji_haye_baste),1,save);
        fread(khoroji_haye_baz,sizeof(khoroji_haye_baz),1,save);
        fread(chah_haye_baz,sizeof(chah_haye_baz),1,save);
        fread(chah_haye_baste,sizeof(chah_haye_baste),1,save);
        fread(jw_visible,sizeof(jw_visible),1,save);
        fread(&global_round,sizeof(int),1,save);
        fread(&visible,sizeof(int),1,save);
        fread(randoms,sizeof(randoms),1,save);
        fread(anti_randoms,sizeof(anti_randoms),1,save);
        fclose(save);
        if(sh.JACK)
            Jack=&sh;
        if(jw.JACK)
            Jack=&jw;
        if(js.JACK)
            Jack=&js;
        if(il.JACK)
            Jack=&il;
        if(ms.JACK)
            Jack=&ms;
        if(sg.JACK)
            Jack=&sg;
        if(wg.JACK)
            Jack=&wg;
        if(jb.JACK)
            Jack=&jb;
    } else{
        FILE *zamin = fopen("zamin.txt", "r");
        start_zamin(zamin);
        fclose(zamin);
        FILE *characters = fopen("characters.txt", "r");
        fscanf(characters,"%d %d",&sh.i,&sh.j);
        fscanf(characters,"%d %d",&jw.i,&jw.j);
        fscanf(characters,"%d %d",&js.i,&js.j);
        fscanf(characters,"%d %d",&il.i,&il.j);
        fscanf(characters,"%d %d",&ms.i,&ms.j);
        fscanf(characters,"%d %d",&sg.i,&sg.j);
        fscanf(characters,"%d %d",&wg.i,&wg.j);
        fscanf(characters,"%d %d",&jb.i,&jb.j);
        fclose(characters);
        gozastane_cart(&whitechapel[sg.i][sg.j],&sg,sg.i,sg.j);
        gozastane_cart(&whitechapel[sh.i][sh.j],&sh,sh.i,sh.j);
        gozastane_cart(&whitechapel[il.i][il.j],&il,il.i,il.j);
        gozastane_cart(&whitechapel[wg.i][wg.j],&wg,wg.i,wg.j);
        gozastane_cart(&whitechapel[js.i][js.j],&js,js.i,js.j);
        gozastane_cart(&whitechapel[jb.i][jb.j],&jb,jb.i,jb.j);
        gozastane_cart(&whitechapel[jw.i][jw.j],&jw,jw.i,jw.j);
        gozastane_cart(&whitechapel[ms.i][ms.j],&ms,ms.i,ms.j);
    }
}


void save_game(int n){
    char file_save[30];
    sprintf(file_save,"save_%d.bin",n);
    FILE *save = fopen(file_save, "wb");
    fwrite(whitechapel, sizeof(whitechapel), 1, save);
    fwrite(&sh,sizeof(sh),1,save);
    fwrite(&jw,sizeof(jw),1,save);
    fwrite(&js,sizeof(js),1,save);
    fwrite(&il,sizeof(il),1,save);
    fwrite(&ms,sizeof(ms),1,save);
    fwrite(&sg,sizeof(sg),1,save);
    fwrite(&wg,sizeof(wg),1,save);
    fwrite(&jb,sizeof(jb),1,save);
    fwrite(cheragh_haye_khamoosh,sizeof(cheragh_haye_khamoosh),1,save);
    fwrite(cheragh_haye_roshan,sizeof(cheragh_haye_roshan),1,save);
    fwrite(khoroji_haye_baste,sizeof(khoroji_haye_baste),1,save);
    fwrite(khoroji_haye_baz,sizeof(khoroji_haye_baz),1,save);
    fwrite(chah_haye_baz,sizeof(chah_haye_baz),1,save);
    fwrite(chah_haye_baste,sizeof(chah_haye_baste),1,save);
    fwrite(jw_visible,sizeof(jw_visible),1,save);
    fwrite(&global_round,sizeof(int),1,save);
    fwrite(&visible,sizeof(int),1,save);
    fwrite(randoms,sizeof(randoms),1,save);
    fwrite(anti_randoms,sizeof(anti_randoms),1,save);
    fclose(save);
}
