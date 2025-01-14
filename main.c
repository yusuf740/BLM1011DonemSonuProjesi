#include <stdio.h>

int gecerli_hamle(int x, int y, int n, char board[n][n]) {
           // TAHTANIN SINIRLARI ICINDE MI ?
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return 0; // Gecersiz
    }

          // KOMSU HUCHERELERDEN EN AZ BIRI BOS DEGIL MI ?
    if (((y > 0 && board[x][y - 1] != '#') ||
        (y < n - 1 && board[x][y + 1] != '#') ||
        (x > 0 && board[x - 1][y] != '#') ||
        (x < n - 1 && board[x + 1][y] != '#') ||
        (x > 0 && y > 0 && board[x - 1][y - 1] != '#') ||
        (x > 0 && y < n - 1 && board[x - 1][y + 1] != '#') ||
        (x < n - 1 && y > 0 && board[x + 1][y - 1] != '#') ||
        (x < n - 1 && y < n - 1 && board[x + 1][y + 1] != '#')) &&
        (board[x][y] == '#')
        ){
        return 1; // Gecerli
    }
    return 0; // Gecersiz
}


int main()
{
int n=24,i,j,t=0,x,y,K,S,M,girildi=0,tmpx,tmpy,count=0,flag=0,k=1;
int sayilar[3]={0,0,0};
printf("-----------------------TRIVERSI-----------------------\n");
printf("Triversi oyununa hos geldiniz\nKurallar:\n1-Oyunda sadece koyulan taslarin yanina tas koyabilirsiniz\n2-Dolu olan yerlere tas koyamazsin\n");
while(n>23 || n<3){
    printf("Tahtanin boyutu 3 ile 23 arasinda bir deger  olmalidir\n");
    printf("Tahtanin boyutunu giriniz:\n");
    scanf("%d",&n);
}
 char board[n][n];
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        board[i][j]='#';
    }
 }
 for(i=0;i<n;i++){
        printf("\n");
    for(j=0;j<n;j++){
       printf("%c ",board[i][j]);
    }
 }
printf("\nLutfen ilk kirmizi(K) tasi tahtanin ortasina yerlestiriniz\n");
for(t=0;t<n*n;t++){
        girildi=0;
               //ILK TASIN ORTAYA KONMASI ICIN BIR KONTROL
    while(t==0 && girildi==0){
        printf("\nK`yi oynamak istedigin yeri (x,y) formatinda gir: ");
        scanf("%d,%d",&x,&y);
        if((x==n/2 || x==n/2-1) && (y==n/2 ||  y==n/2-1)){
            board[x][y]='K';
            girildi=1;
        }
        else{
            printf("lutfen ilk kirmizi tasi tahtanin ortasina yerlestiriniz");
        }
    }
    while(t%3==0 && girildi==0){
        printf("\nK`yi oynamak istedigin yeri (x,y) formatinda gir: ");
        scanf("%d,%d",&x,&y);
        if(gecerli_hamle(x, y, n, board)){
            board[x][y]='K';
            girildi=1;
        }
        else{
            printf("Sadece tahtada mevcut olan taslarin yanina tas koyabilirsin\nZaten dolu olan yerlere veya tahta sinirlari disina tas koyamazsin\nLutfen gecerli bir yer girin\n");
        }
    }
    while(t%3==1 && girildi==0){
        printf("\nS`yi oynamak istedigin yeri (x,y) formatinda gir: ");
        scanf("%d,%d",&x,&y);
        if(gecerli_hamle(x, y, n, board)){
            board[x][y]='S';
            girildi=1;
           }
        else{
            printf("Sadece tahtada mevcut olan taslarin yanina tas koyabilirsin\nZaten dolu olan yerlere veya tahta sinirlari disina tas koyamazsin\nLutfen gecerli bir yer girin\n");
        }

    }
    while(t%3==2 && girildi==0){
        printf("\nM`yi oynamak istedigin yeri (x,y) formatinda gir: ");
        scanf("%d,%d",&x,&y);
         if(gecerli_hamle(x, y, n, board)){
            board[x][y]='M';
            girildi=1;
        }
        else{
            printf("Sadece tahtada mevcut olan taslarin yanina tas koyabilirsin\nZaten dolu olan yerlere veya tahta sinirlari disina tas koyamazsin\nLutfen gecerli bir yer girin\n");
        }
}
girildi=1;

            // SAG UST KONTROL VE DONUSUM
tmpx = x - 1; // x > 1 olmalı
tmpy = y + 1;
count = 0;
flag = 0;
k = 1;
    while (tmpx >= 0 && tmpy < n && board[tmpx - count][tmpy + count] != '#' &&
       board[x][y] != board[tmpx - count][tmpy + count] &&
       tmpx - count >= 0 && tmpy + count < n) {
    count++;
    }
    if (tmpx - count >= 0 && tmpy + count < n && board[x][y] == board[tmpx - count][tmpy + count]) {
        flag = 1;
        tmpx -= count;
        tmpy += count;
    }
    while (flag == 1 && count != 0) {
        board[tmpx + k][tmpy - k] = board[x][y];
        count--;
        k++;
    }

                // SAG ALT CAPRAZ KONTROL VE DONUSUMU
tmpx = x + 1;
tmpy = y + 1;
count = 0;
flag = 0;
k = 1;
    while (tmpx < n && tmpy < n && board[tmpx + count][tmpy + count] != '#' &&
       board[x][y] != board[tmpx + count][tmpy + count] &&
       tmpx + count < n && tmpy + count < n) {
       count++;
        }
    if (tmpx + count < n && tmpy + count < n && board[x][y] == board[tmpx + count][tmpy + count]) {
        flag = 1;
        tmpx += count;
        tmpy += count;
        }
    while (flag == 1 && count != 0) {
        board[tmpx - k][tmpy - k] = board[x][y];
        count--;
        k++;
        }

                // SOL ALT CAPRAZ KONTROL VE DONUSUMU
tmpx = x + 1;
tmpy = y - 1; // y 0dan buyuk olmalı
count = 0;
flag = 0;
k = 1;
    while (tmpx < n && tmpy >= 0 && board[tmpx + count][tmpy - count] != '#' &&
       board[x][y] != board[tmpx + count][tmpy - count] &&
       tmpx + count < n && tmpy - count >= 0) {
       count++;
        }
    if (tmpx + count < n && tmpy - count >= 0 && board[x][y] == board[tmpx + count][tmpy - count]) {
        flag = 1;
        tmpx += count;
        tmpy -= count;
        }
    while (flag == 1 && count != 0) {
        board[tmpx - k][tmpy + k] = board[x][y];
        count--;
        k++;
}

            //SOL UST CAPRAZ KONTROL VE DONUSUMU
tmpx = x - 1;
tmpy = y - 1;
count = 0;
flag = 0;
k = 1;
    while (tmpx >= 0 && tmpy >= 0 && board[tmpx - count][tmpy - count] != '#' &&
       board[x][y] != board[tmpx - count][tmpy - count] &&
       tmpx - count >= 0 && tmpy - count >= 0) {
        count++;
        }
    if (tmpx - count >= 0 && tmpy - count >= 0 && board[x][y] == board[tmpx - count][tmpy - count]) {
        flag = 1;
        tmpx -= count;
        tmpy -= count;
        }
    while (flag == 1 && count != 0) {
        board[tmpx + k][tmpy + k] = board[x][y];
        count--;
        k++;
        }

            // SAG KONTROL VE DONUSUMU
tmpx = x + 1;
count = 0;
flag = 0;
k = 1;
    while (tmpx < n && board[tmpx + count][y] != '#' &&
       board[x][y] != board[tmpx + count][y] &&
       tmpx + count < n) {
        count++;
        }
    if (tmpx + count < n && board[x][y] == board[tmpx + count][y]) {
        flag = 1;
        tmpx += count;
        }
    while (flag == 1 && count != 0) {
        board[tmpx - k][y] = board[x][y];
        count--;
        k++;
        }

            //SOL KONTROL VE DONUSUMU
tmpx = x - 1;
count = 0;
flag = 0;
k = 1;
    while (tmpx >= 0 && board[tmpx - count][y] != '#' &&
       board[x][y] != board[tmpx - count][y] &&
       tmpx - count >= 0) {
       count++;
        }
    if (tmpx - count >= 0 && board[x][y] == board[tmpx - count][y]) {
        flag = 1;
        tmpx -= count;
        }
    while (flag == 1 && count != 0) {
        board[tmpx + k][y] = board[x][y];
        count--;
        k++;
        }

                // ALT KONTROL VE DONUSUMU
tmpy = y + 1;
count = 0;
flag = 0;
k = 1;
    while (tmpy < n && board[x][tmpy + count] != '#' &&
       board[x][y] != board[x][tmpy + count] &&
       tmpy + count < n) {
        count++;
        }
    if (tmpy + count < n && board[x][y] == board[x][tmpy + count]) {
        flag = 1;
        tmpy += count;
        }
    while (flag == 1 && count != 0) {
        board[x][tmpy - k] = board[x][y];
        count--;
        k++;
        }

            // UST KONTROL VE DONUSUMU
tmpy = y - 1;
count = 0;
flag = 0;
k = 1;
    while (tmpy >= 0 && board[x][tmpy - count] != '#' &&
       board[x][y] != board[x][tmpy - count] &&
       tmpy - count >= 0) {
       count++;
        }
    if (tmpy - count >= 0 && board[x][y] == board[x][tmpy - count]) {
        flag = 1;
        tmpy -= count;
        }
    while (flag == 1 && count != 0) {
        board[x][tmpy + k] = board[x][y];
        count--;
        k++;
        }


    for(i=0;i<n;i++){
        printf("\n");
    for(j=0;j<n;j++){
       printf("%c ",board[i][j]);

       }
    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(board[i][j]=='K'){
            sayilar[0]++;
        }
         else if(board[i][j]=='S'){
            sayilar[1]++;
        }
        else if(board[i][j]=='M'){
            sayilar[2]++;
        }
    }
}
i=0;
for(j=1;j<3;j++){
    if(sayilar[j]>sayilar[i]){
        i=j;
    }
}

printf("\nkirmizi taslarin sayisi --> %d\n",sayilar[0]);
printf("sari taslarin sayisi --> %d\n",sayilar[1]);
printf("mavi taslarin sayisi --> %d\n",sayilar[2]);
if((sayilar[0]==sayilar[1] && sayilar[0]==sayilar[i]) ||(sayilar[1]==sayilar[2] && sayilar[1]==sayilar[i]) || (sayilar[0]==sayilar[2] && sayilar[0]==sayilar[i])){
    printf("durum berabere");
}
else{
    printf("kazanan oyuncu %d. oyuncu",i+1);
}


    return 0;
}
