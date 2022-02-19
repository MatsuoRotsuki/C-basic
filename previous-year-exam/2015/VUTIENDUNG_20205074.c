#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>



char aX[1000];
char aY[1000];
int x, y;
int X, Y; //So luong thanh pho;



// Chuc nang 1:
int TuyenDuong(){
    char s[100];
    char sX[] = "X.txt";
    char sY[] = "Y.txt";
    printf("\nNhap ten hang: ");
    gets(s);
    if(strcmp(s,sX) == 0){
        int i = 0;
        FILE *f = fopen("X.txt", "r+");
        fscanf(f, "%d", &X);
        int dem = 0;
        while(!feof(f)){
            fscanf(f,"%c",&aX[i]);
            i++;
        }
        x = i;
        for(int j=0; j < i; j++){
            if(aX[j] < 58 && aX[j] > 47){
                dem++;
            }
        }
        printf("\nTuyen duong cua X la: %d",dem-X);
        fclose(f);

    }else if(strcmp(s,sY) == 0){
        FILE *f = fopen("Y.txt", "r+");
        fscanf(f, "%d", &Y);
        int i = 0;
        while(!feof(f)){
            fscanf(f,"%c",&aY[i]);
            i++;
        }
        y = i;
        int dem = 0;
        for(int j=0; j < i; j++){
            if(aY[j] < 58 && aY[j] > 47){
                dem++;
            }
        }
        printf("\nTuyen duong cua Y la: %d",dem-Y);
        fclose(f);
    }else printf("\nBan da nhap sai ten!\n");
}


//Chuc nang 2;
void Xoaduong(){
    char X1[100];
    char sX[] = "X.txt";
    char sY[] = "Y.txt";
    int  tp;
    int dich;
    char Q;
    while(Q != 'Q'){
        fflush(stdin);
        printf("\nNhap ten hang: ");
        gets(X1);
        if(strcmp(X1,sX) !=0 && strcmp(X1,sY) !=0){
            printf("\nBan nhap ten sai! ");
            break;
        }
        printf("\nNhap ten thanh pho muon dieu chinh: "); scanf("%d",&tp);
        if(tp < 1 || tp > X || tp > Y){
            printf("\nBan da nhap sai!");
            break;
        }
        printf("\nNhap ten thanh pho dich: "); scanf("%d", &dich);
        if(dich < 1 ||dich > X || dich > Y){
            printf("\nBan da nhap sai!");
            break;
        }
        printf("\nAn Q de thoat! neu khong hay an phim bat ki! ");
        fflush(stdin);
        scanf("%c",&Q);
    }
}

//Chuc nang 3;

void ThemDuong(){
    char X1[100];
    char sX[] = "X.txt";
    char sY[] = "Y.txt";
    int  tp;
    int dich;
    char Q;
    while(Q != 'Q'){
        fflush(stdin);
        printf("\nNhap ten hang: ");
        gets(X1);
        if(strcmp(X1,sX) !=0 && strcmp(X1,sY) !=0){
            printf("\nBan nhap ten sai! ");
            break;
        }
        printf("\nNhap ten thanh pho muon dieu chinh: "); scanf("%d",&tp);
        if(tp <= 0 ||tp > X || tp >Y){
            printf("\nBan da nhap sai!");
            break;
        }
        printf("\nNhap ten thanh pho dich: "); scanf("%d", &dich);
        if(dich <= 0 ||dich > X || dich > Y){
            printf("\nBan da nhap sai!");
            break;
        }
        printf("\nAn Q de thoat! neu khong hay an phim bat ki! ");
        fflush(stdin);
        scanf("%c",&Q);
    }
}

int TinhTien(){
    char X1[100];
    char sX[] = "X.txt";
    char sY[] = "Y.txt";
    int N;
    int  tp[100];
    char Q;
    fflush(stdin);
    printf("\nNhap ten hang: ");
    gets(X1);
    if(strcmp(X1,sX) !=0 && strcmp(X1,sY) !=0){
        printf("\nBan nhap ten sai! ");
        return 0;
    }
    printf("\nNhap so thanh pho muon di: "); scanf("%d",&N);
    for(int i = 0; i < N; i++){
        printf("\nNhap thanh pho %d: ", i+1);
        scanf("%d",&tp[i]);
        while(tp[i] <= 0 || tp[i] > X || tp[i] > Y){
            printf("\nBan nhap sai ten thanh pho vui long nhap lai: ");
            scanf("%d",&tp[i]);
        }
    }
    if(strcmp(X1,sX) == 0){
        printf("\nSo tien quy khach phai tra la: %d dollar",50*N);
        return 50*N;
    }
    if(strcmp(X1,sY) == 0){
        if(N >= 10){
            int tien = 6000*N - 6000*N/5 ;
            printf("\nSo tien quy khach phai tra la: %d Yen", tien);
            return tien ;
        }
        if(N >0 && N < 10){
            printf("\nSo tien quy khach phai tra la: %d Yen", 6000*N);
            return 6000*N;
        }
    }
}









int main(){
	int n;
	char n2;
	while(1){
	    printf("\n*---------------------------------------------------------*\n");
	    printf("*  [ 1 ] Xac dinh so luong cac tuyen duong bay cua hang   *\n");
	    printf("*  [ 2 ] Xoa di cac tuyen duong bay cua mot hang          *\n");
	    printf("*  [ 3 ] Them cac tuyen duong bay cua mot hang            *\n");
	    printf("*  [ 4 ] Tinh toan chi phi di lai                         *\n");
	    printf("*  [ 5 ] Thoat                                            *\n");
	    printf("*---------------------------------------------------------*\n");
	    printf("\n\n Nhap lua chon cua ban:   ");
	    scanf("%d",&n);
	    system("cls");
	    if(n == 5){
	    	printf("Good bye! ");
	    	break;
	    }else if(n < 1 || n > 5){
	    	printf("\nLua chon khong hop le nhap lai: \n\n");
	    }else{
	        switch(n){
	        	case 1:
                    printf("\nBan da chon chuc nang 1!");
                    fflush(stdin);
                    TuyenDuong();
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 2:
                    printf("\nBan da chon chuc nang 2!");
                    fflush(stdin);
                    Xoaduong();
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 3:
                    printf("\nBan da chon chuc nang 3!");
                    fflush(stdin);
                    ThemDuong();
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        	case 4:
                    fflush(stdin);
                    int Tien;
                    printf("\nBan da chon chuc nang 4!");
                    Tien = TinhTien();
	        		printf("\n\nNhap ki tu bat ki de ve man hinh chinh. ");
	        		scanf("%s",&n2);
	        		system("cls");
	        		continue;
	        }
        }
    }
    getch();
}
	