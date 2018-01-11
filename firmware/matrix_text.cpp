#include "matrix_text.h"
#include "times_new_roman_10b.h"
#include "main.h"

//xxxxxxxxxxxxxxx
int matrix_write_char(int x, int xo, int lent){	//su dung y+8
    int i;
    for(i=0; i<lent; i++){
        fill_matrix[x+i][0] = ~Times_new_roman_10B[xo];
        xo++;
        fill_matrix[x+i][1] = ~Times_new_roman_10B[xo];
        xo++;
    }
    return lent;
}
//xxxxxxxxxxxxxxx
int matrix_write_char_(int x, int xo, int lent){	//su dung y+8
    int i;
    for(i=0; i<lent; i++){
        fill_matrix[x+i][0] = fill_matrix[x+i][0] & ~Times_new_roman_10B[xo];
        xo++;
        fill_matrix[x+i][1] = fill_matrix[x+i][1] & ~Times_new_roman_10B[xo];
        xo++;
    }
    return lent;
}
//xxxxxxxxxxxxxxx
int matrix_putchar(int x, char k) {
    if(k=='0') {return matrix_write_char(x,   0,12/2);}
    if(k=='1') {return matrix_write_char(x,  12,12/2);}
    if(k=='2') {return matrix_write_char(x,  24,12/2);}
    if(k=='3') {return matrix_write_char(x,  36,12/2);}
    if(k=='4') {return matrix_write_char(x,  48,12/2);}
    if(k=='5') {return matrix_write_char(x,  60,12/2);}
    if(k=='6') {return matrix_write_char(x,  72,12/2);}
    if(k=='7') {return matrix_write_char(x,  84,12/2);}
    if(k=='8') {return matrix_write_char(x,  96,12/2);}
    if(k=='9') {return matrix_write_char(x, 108,12/2);}
    if(k==' ') {return matrix_write_char(x, 120, 6/2);}	//+4

    if(k=='A') {return matrix_write_char(x, 130,18/2);}
    if(k=='B') {return matrix_write_char(x, 148,16/2);}
    if(k=='C') {return matrix_write_char(x, 164,16/2);}
    if(k=='D') {return matrix_write_char(x, 180,18/2);}
    if(k=='E') {return matrix_write_char(x, 198,16/2);}
    if(k=='F') {return matrix_write_char(x, 214,16/2);}
    if(k=='G') {return matrix_write_char(x, 230,18/2);}
    if(k=='H') {return matrix_write_char(x, 248,20/2);}
    if(k=='I') {return matrix_write_char(x, 268,10/2);}
    if(k=='J') {return matrix_write_char(x, 278,14/2);}
    if(k=='K') {return matrix_write_char(x, 292,18/2);}
    if(k=='L') {return matrix_write_char(x, 310,16/2);}
    if(k=='M') {return matrix_write_char(x, 326,22/2);}
    if(k=='N') {return matrix_write_char(x, 348,20/2);}
    if(k=='O') {return matrix_write_char(x, 368,18/2);}
    if(k=='P') {return matrix_write_char(x, 386,16/2);}
    if(k=='Q') {return matrix_write_char(x, 402,18/2);}
    if(k=='R') {return matrix_write_char(x, 420,18/2);}
    if(k=='S') {return matrix_write_char(x, 438,14/2);}
    if(k=='T') {return matrix_write_char(x, 452,18/2);}
    if(k=='U') {return matrix_write_char(x, 470,18/2);}
    if(k=='V') {return matrix_write_char(x, 488,20/2);}
    if(k=='W') {return matrix_write_char(x, 508,30/2);}
    if(k=='X') {return matrix_write_char(x, 538,20/2);}
    if(k=='Y') {return matrix_write_char(x, 558,18/2);}
    if(k=='Z') {return matrix_write_char(x, 576,16/2);}
    if(k==1)   {return matrix_write_char_(x, 592,16/2);}
    if(k==2)   {return matrix_write_char_(x, 608,14/2);}
    if(k==3)   {return matrix_write_char_(x, 622,16/2);}
    if(k==4)   {return matrix_write_char_(x, 638,16/2);}
    if(k==5)   {return matrix_write_char_(x, 654,10/2);}
    if(k==6)   {return matrix_write_char_(x, 664,12/2);}
    if(k==7)   {return matrix_write_char_(x, 676,16/2);}
    if(k==8)   {return matrix_write_char_(x, 692,12/2);}
    if(k==9)   {return matrix_write_char_(x, 704, 8/2);}	//+8

    if(k=='a') {return matrix_write_char(x, 720,14/2);}
    if(k=='b') {return matrix_write_char(x, 734,12/2);}
    if(k=='c') {return matrix_write_char(x, 746,12/2);}
    if(k=='d') {return matrix_write_char(x, 758,14/2);}
    if(k=='e') {return matrix_write_char(x, 772,12/2);}
    if(k=='f') {return matrix_write_char(x, 784,12/2);}
    if(k=='g') {return matrix_write_char(x, 796,14/2);}
    if(k=='h') {return matrix_write_char(x, 810,12/2);}
    if(k=='i') {return matrix_write_char(x, 822,10/2);}
    if(k=='j') {return matrix_write_char(x, 832,10/2);}
    if(k=='k') {return matrix_write_char(x, 842,12/2);}
    if(k=='l') {return matrix_write_char(x, 854,12/2);}
    if(k=='m') {return matrix_write_char(x, 866,20/2);}
    if(k=='n') {return matrix_write_char(x, 886,14/2);}
    if(k=='o') {return matrix_write_char(x, 900,12/2);}
    if(k=='p') {return matrix_write_char(x, 912,12/2);}
    if(k=='q') {return matrix_write_char(x, 924,12/2);}
    if(k=='r') {return matrix_write_char(x, 936,12/2);}
    if(k=='s') {return matrix_write_char(x, 948,12/2);}
    if(k=='t') {return matrix_write_char(x, 960,12/2);}
    if(k=='u') {return matrix_write_char(x, 972,12/2);}
    if(k=='v') {return matrix_write_char(x, 984,16/2);}
    if(k=='w') {return matrix_write_char(x,1000,24/2);}
    if(k=='x') {return matrix_write_char(x,1024,16/2);}
    if(k=='y') {return matrix_write_char(x,1040,16/2);}
    if(k=='z') {return matrix_write_char(x,1056,12/2);}
    if(k==11)  {return matrix_write_char_(x,1068,14/2);}
    if(k==12)  {return matrix_write_char_(x,1082,12/2);}
    if(k==13)  {return matrix_write_char_(x,1094,12/2);}
    if(k==14)  {return matrix_write_char_(x,1106,14/2);}
    if(k==15)  {return matrix_write_char_(x,1120, 8/2);}
    if(k==16)  {return matrix_write_char_(x,1128,10/2);}
    if(k==17)  {return matrix_write_char_(x,1138,12/2);}
    if(k==18)  {return matrix_write_char_(x,1150,10/2);}
    if(k==19)  {return matrix_write_char_(x,1160,12/2);}	//+8

    if(k=='`') {return matrix_write_char(x,1180, 8/2);}
    if(k=='~') {return matrix_write_char(x,1188,16/2);}
    if(k=='!') {return matrix_write_char(x,1204, 6/2);}
    if(k=='@') {return matrix_write_char(x,1210,24/2);}
    if(k=='#') {return matrix_write_char(x,1234,16/2);}
    if(k=='$') {return matrix_write_char(x,1250,12/2);}
    if(k=='%') {return matrix_write_char(x,1262,20/2);}
    if(k=='^') {return matrix_write_char(x,1282,12/2);}
    if(k=='&') {return matrix_write_char(x,1294,22/2);}
    if(k=='*') {return matrix_write_char(x,1316,12/2);}
    if(k=='(') {return matrix_write_char(x,1328, 8/2);}
    if(k==')') {return matrix_write_char(x,1336, 8/2);}
    if(k=='_') {return matrix_write_char(x,1344,12/2);}
    if(k=='+') {return matrix_write_char(x,1356,12/2);}
    if(k=='-') {return matrix_write_char(x,1368,12/2);}
    if(k=='=') {return matrix_write_char(x,1380,12/2);}
    if(k=='{') {return matrix_write_char(x,1392,10/2);}
    if(k=='}') {return matrix_write_char(x,1402,10/2);}
    if(k=='[') {return matrix_write_char(x,1412, 8/2);}
    if(k==']') {return matrix_write_char(x,1420, 8/2);}
    if(k==':') {return matrix_write_char(x,1428, 6/2);}
    if(k==';') {return matrix_write_char(x,1434, 6/2);}
    if(k== 34) {return matrix_write_char(x,1440,12/2);}	// '"'
    if(k== 39) {return matrix_write_char(x,1452, 6/2);}	// '''
    if(k=='|') {return matrix_write_char(x,1458, 4/2);}
    if(k== 92) {return matrix_write_char(x,1462,12/2);}	// '\'
    if(k=='<') {return matrix_write_char(x,1474,12/2);}
    if(k=='>') {return matrix_write_char(x,1486,12/2);}
    if(k=='?') {return matrix_write_char(x,1498,12/2);}
    if(k==',') {return matrix_write_char(x,1510, 6/2);}
    if(k=='.') {return matrix_write_char(x,1516, 6/2);}
    if(k=='/') {return matrix_write_char(x,1522,12/2);}
                                //1534					//+6=1540
}
//xxxxxxxxxxxxxxx
void matrix_puts(int x, char *str){
    int k,lent;
	while (k=*str++){
        lent=matrix_putchar(x, k);
		x=x+lent;
    }
}
//xxxxxxxxxxxxxxx
unsigned int matrix_puts_vni(unsigned char x, char *str){	//BO DAU NGAY SAU NGUYEN AM
char k,c,lent,i;
unsigned int lent_text = 0;
    while (k=*str++){
        lent=matrix_putchar(x,k);
        lent_text+=lent;
        if(k=='O'){
            if( (*(str+1)>48&&*(str+1)<=54) && (*str==54 || *(str+1)==54) ){	//'1-6','6'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,1);	str++;}
                 if(c=='2') {matrix_putchar(x,2);	str++;}
                 if(c=='3') {matrix_putchar(x,3);	str++;}
                 if(c=='4') {matrix_putchar(x,4);	str++;}
                 if(c=='5') {matrix_putchar(x,5);	str++;}
                 if(c=='6') {matrix_putchar(x,6);	str++;}
            //	 if(c=='7') {matrix_putchar(x,7);	str++;}
                }}
            if( (*(str+1)>48&&*(str+1)<=55) && (*str==55 || *(str+1)==55) ){	//'1-7','7'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x-2,1);	str++;}
                 if(c=='2') {matrix_putchar(x-2,2);	str++;}
                 if(c=='3') {matrix_putchar(x-3,3);	str++;}
                 if(c=='4') {matrix_putchar(x-2,4);	str++;}
                 if(c=='5') {matrix_putchar(x  ,5);	str++;}
            //	 if(c=='6') {matrix_putchar(x  ,6);	str++;}
                 if(c=='7') {matrix_putchar(x  ,7);	str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-2,1);	str++;}
            if(c=='2') {matrix_putchar(x-2,2);	str++;}
            if(c=='3') {matrix_putchar(x-3,3);	str++;}
            if(c=='4') {matrix_putchar(x-2,4);	str++;}
            if(c=='5') {matrix_putchar(x  ,5);	str++;}
            if(c=='6') {matrix_putchar(x  ,6);	str++;}
            if(c=='7') {matrix_putchar(x  ,7);	str++;}
            }
        if(k=='A'){
            if(*(str+1)>48&&*(str+1)<=56&&*(str+1)!=55){	//'1-8','!=7'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,1);	str++;}
                 if(c=='2') {matrix_putchar(x,2);	str++;}
                 if(c=='3') {matrix_putchar(x,3);	str++;}
                 if(c=='4') {matrix_putchar(x,4);	str++;}
                 if(c=='5') {matrix_putchar(x,5);	str++;}
                 if(c=='6') {matrix_putchar(x,6);	str++;}
                 if(c=='8') {matrix_putchar(x,8);	str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-2,1); str++;}
            if(c=='2') {matrix_putchar(x-2,2); str++;}
            if(c=='3') {matrix_putchar(x-3,3); str++;}
            if(c=='4') {matrix_putchar(x-2,4); str++;}
            if(c=='5') {matrix_putchar(x  ,5); str++;}
            if(c=='6') {matrix_putchar(x  ,6); str++;}
            if(c=='8') {matrix_putchar(x  ,8); str++;}
            }
        if(k=='E'){
            if(*(str+1)>48&&*(str+1)<=54){	//'1-6'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,1);	str++;}
                 if(c=='2') {matrix_putchar(x,2);	str++;}
                 if(c=='3') {matrix_putchar(x,3);	str++;}
                 if(c=='4') {matrix_putchar(x,4);	str++;}
                 if(c=='5') {matrix_putchar(x,5);	str++;}
                 if(c=='6') {matrix_putchar(x,6);	str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-2,1); str++;}
            if(c=='2') {matrix_putchar(x-2,2); str++;}
            if(c=='3') {matrix_putchar(x-3,3); str++;}
            if(c=='4') {matrix_putchar(x-2,4); str++;}
            if(c=='5') {matrix_putchar(x  ,5); str++;}
            if(c=='6') {matrix_putchar(x  ,6); str++;}
            }
        if(k=='U'){
            i=2;
            while(i--){
             c=*str;
             if(c=='1') {matrix_putchar(x-2,1); str++;}
             if(c=='2') {matrix_putchar(x-2,2); str++;}
             if(c=='3') {matrix_putchar(x-3,3); str++;}
             if(c=='4') {matrix_putchar(x-2,4); str++;}
             if(c=='5') {matrix_putchar(x  ,5); str++;}
             if(c=='7') {matrix_putchar(x  ,7); str++;}
            }}
        if(k=='I'){
            c=*str;
            if(c=='1') {matrix_putchar(x-4,1); str++;}
            if(c=='2') {matrix_putchar(x-4,2); str++;}
            if(c=='3') {matrix_putchar(x-5,3); str++;}
            if(c=='4') {matrix_putchar(x-4,4); str++;}
            if(c=='5') {matrix_putchar(x-2,5); str++;}
            }
        if(k=='Y'){
            c=*str;
            if(c=='1') {matrix_putchar(x-2,1); str++;}
            if(c=='2') {matrix_putchar(x-2,2); str++;}
            if(c=='3') {matrix_putchar(x-2,3); str++;}
            if(c=='4') {matrix_putchar(x-1,4); str++;}
            if(c=='5') {matrix_putchar(x  ,5); str++;}
            }
        if(k=='D'){
            c=*str;
            if(c=='9') {matrix_putchar(x  ,9); str++;}
            }
        //XXXX//
        if(k=='o'){
            if( (*(str+1)>48&&*(str+1)<=54) && (*str==54 || *(str+1)==54) ){	//'1-6','6'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,11); str++;}
                 if(c=='2') {matrix_putchar(x,12); str++;}
                 if(c=='3') {matrix_putchar(x,13); str++;}
                 if(c=='4') {matrix_putchar(x,14); str++;}
                 if(c=='5') {matrix_putchar(x,15); str++;}
                 if(c=='6') {matrix_putchar(x,16); str++;}
            //	 if(c=='7') {matrix_putchar(x,17); str++;}
                }}
            if( (*(str+1)>48&&*(str+1)<=55) && (*str==55 || *(str+1)==55) ){	//'1-7','7'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x-3,11); str++;}
                 if(c=='2') {matrix_putchar(x-2,12); str++;}
                 if(c=='3') {matrix_putchar(x-2,13); str++;}
                 if(c=='4') {matrix_putchar(x-2,14); str++;}
                 if(c=='5') {matrix_putchar(x  ,15); str++;}
            //	 if(c=='6') {matrix_putchar(x  ,16); str++;}
                 if(c=='7') {matrix_putchar(x  ,17); str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-3,11); str++;}
            if(c=='2') {matrix_putchar(x-2,12); str++;}
            if(c=='3') {matrix_putchar(x-2,13); str++;}
            if(c=='4') {matrix_putchar(x-2,14); str++;}
            if(c=='5') {matrix_putchar(x  ,15); str++;}
            if(c=='6') {matrix_putchar(x  ,16); str++;}
            if(c=='7') {matrix_putchar(x  ,17); str++;}
            }
        if(k=='a'){
            if(*(str+1)>48&&*(str+1)<=56&&*(str+1)!=55){	//'1-8','!=7'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,11);	str++;}
                 if(c=='2') {matrix_putchar(x,12);	str++;}
                 if(c=='3') {matrix_putchar(x,13);	str++;}
                 if(c=='4') {matrix_putchar(x,14);	str++;}
                 if(c=='5') {matrix_putchar(x,15);	str++;}
                 if(c=='6') {matrix_putchar(x,16);	str++;}
                 if(c=='8') {matrix_putchar(x,18);	str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-3,11); str++;}
            if(c=='2') {matrix_putchar(x-2,12); str++;}
            if(c=='3') {matrix_putchar(x-2,13); str++;}
            if(c=='4') {matrix_putchar(x-2,14); str++;}
            if(c=='5') {matrix_putchar(x  ,15); str++;}
            if(c=='6') {matrix_putchar(x  ,16); str++;}
            if(c=='8') {matrix_putchar(x  ,18); str++;}
            }
        if(k=='e'){
            if(*(str+1)>48&&*(str+1)<=54){	//'1-6'
                i=2;
                while(i--){
                 c=*str;
                 if(c=='1') {matrix_putchar(x,11); str++;}
                 if(c=='2') {matrix_putchar(x,12); str++;}
                 if(c=='3') {matrix_putchar(x,13); str++;}
                 if(c=='4') {matrix_putchar(x,14); str++;}
                 if(c=='5') {matrix_putchar(x,15); str++;}
                 if(c=='6') {matrix_putchar(x,16); str++;}
                }}
            c=*str;
            if(c=='1') {matrix_putchar(x-3,11); str++;}
            if(c=='2') {matrix_putchar(x-2,12); str++;}
            if(c=='3') {matrix_putchar(x-2,13); str++;}
            if(c=='4') {matrix_putchar(x-2,14); str++;}
            if(c=='5') {matrix_putchar(x  ,15); str++;}
            if(c=='6') {matrix_putchar(x  ,16); str++;}
            }
        if(k=='u'){
            i=2;
            while(i--){
             c=*str;
             if(c=='1') {matrix_putchar(x-3,11); str++;}
             if(c=='2') {matrix_putchar(x-2,12); str++;}
             if(c=='3') {matrix_putchar(x-2,13); str++;}
             if(c=='4') {matrix_putchar(x-2,14); str++;}
             if(c=='5') {matrix_putchar(x  ,15); str++;}
             if(c=='7') {matrix_putchar(x  ,17); str++;}
            }}
        if(k=='i'){
            c=*str;
            if(c=='1') {matrix_putchar(x-3,11); str++;}
            if(c=='2') {matrix_putchar(x-2,12); str++;}
            if(c=='3') {matrix_putchar(x-3,13); str++;}
            if(c=='4') {matrix_putchar(x-3,14); str++;}
            if(c=='5') {matrix_putchar(x-1,15); str++;}
            }
        if(k=='y'){
            c=*str;
            if(c=='1') {matrix_putchar(x-1,11); str++;}
            if(c=='2') {matrix_putchar(x-1,12); str++;}
            if(c=='3') {matrix_putchar(x-1,13); str++;}
            if(c=='4') {matrix_putchar(x-1,14); str++;}
            if(c=='5') {matrix_putchar(x+2,15); str++;}
            }
        if(k=='d'){
            c=*str;
            if(c=='9') {matrix_putchar(x  ,19); str++;}
            }
        x=x+lent;
        }
    return lent_text;
}
