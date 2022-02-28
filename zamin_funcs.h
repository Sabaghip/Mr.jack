//
// Created by parsa on 1/4/2022.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJE_MRJACK_ZAMIN_FUNCS_H
#define PROJE_MRJACK_ZAMIN_FUNCS_H

#endif //PROJE_MRJACK_ZAMIN_FUNCS_H


extern char matn_khaneha[117][10][6];
extern struct character  sh;
extern struct character  jw;
extern struct character  sg;
extern struct character  il;
extern struct character  wg;
extern struct character  jb;
extern struct character  ms;
extern struct character  js;
extern struct character  *Jack;
extern int global_round;
extern int visible;



struct character{
    char name[30];
    char details[150];
    int sh,jw,js,il,ms,sg,wg,jb,JACK,visible,showed,bigonah;
    struct character *next;
    int i,j;
    int played;
};




struct zamin{
    int sakhteman,cheragh_khamoosh,khali,chah_baz,ezafi,cheragh_roshan,chah_baste,khoroji_baz,khoroji_baste,visible;
    struct character *characters;
};

extern struct zamin whitechapel[9][13];


void start_zamin (FILE *fp);
void print_map(char s[][10][6]);
void gozastane_cart(struct zamin *maghsad,struct character *c,int i,int j);
void update_string(struct zamin c[9][13]);
void play();
int menu();
void play_sh();
void play_jw();
void play_sg();
void play_il();
void play_wg();
void play_jb();
void play_ms();
void play_js();
void available_cells(int khaneha[11][2],struct character *c);
int get_n(char str[100],int min,int max);
int select_cell(int khaneha[11][2],int n,int on_x,int *i,int *j);
void move_cart(struct zamin *mabda,struct zamin *maghsad,struct character *c,int i,int j);
void move_3(struct character *c);
void move_4(struct character *c);
void available_cells_new(int khaneha[11][2],struct character *c);
void jack();
void delete_x(int arr[],int i,int size);
void play_x(int randoms[],int size,int o);
int check_visible(struct character c);
void arrest (struct character c);
void available_cells_plus(int khaneha[6][2],struct character *c);
void move_sg(struct character *c);
void check_khoroji();
void load_game(int n);
void save_game(int n);
int first_menu();

