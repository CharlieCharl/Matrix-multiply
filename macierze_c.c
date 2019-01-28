//Macierze
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void wys(double tab_c[3][3]){
	int i,j;
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%4.3f ",tab_c[j][i]);
		}
		printf("\n");
	}
}

void wys2(double tab_c[2][2]){
	int i,j;
	printf("\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%4.3f ",tab_c[j][i]);
		}
		printf("\n");
	}
}

void add_3(double tab_a[3][3],double tab_b[3][3]){
	
	double tab_c[3][3];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tab_c[j][i]=tab_a[j][i]+tab_b[j][i];
		}
	}
	wys(tab_c);
}

void add_2(double tab_a[2][2],double tab_b[2][2]){
	
	double tab_c[2][2];
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			tab_c[j][i]=tab_a[j][i]+tab_b[j][i];
		}
	}
	wys2(tab_c);
}



void sub_3(double tab_a[3][3],double tab_b[3][3]){
	
	double tab_c[3][3];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tab_c[j][i]=tab_a[j][i]-tab_b[j][i];
		}
	}	
	wys(tab_c);	
}


void sub_2(double tab_a[2][2],double tab_b[2][2]){
	
	double tab_c[2][2];
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			tab_c[j][i]=tab_a[j][i]-tab_b[j][i];
		}
	}
	wys2(tab_c);
}


void mul_3(double tab_a[3][3],double tab_b[3][3]){
	
	double tab_c[3][3];
	int i,j,k;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tab_c[i][j]=0;
         for(k=0; k<3; k++)
          {
           tab_c[i][j]+=tab_b[i][k]*tab_a[k][j];
         }
		}
	}	
	wys(tab_c);	
}

void mul_2(double tab_a[2][2],double tab_b[2][2]){
	
	double tab_c[2][2];
	int i,j,k;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			tab_c[i][j]=0;
         for(k=0; k<2; k++)
          {
           tab_c[i][j]+=tab_b[i][k]*tab_a[k][j];
         }
		}
	}		
	wys2(tab_c);	
}

void transp_3(double tab_a[3][3]){
	
	double tab_c[3][3];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tab_c[j][i]=tab_a[i][j];
		}
	}	
	wys(tab_c);
}


void transp_2(double tab_a[2][2]){
	
	double tab_c[2][2];
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			tab_c[j][i]=tab_a[i][j];
		}
	}
	wys2(tab_c);	
}

int det_3(double tab_a[3][3]){
	int d;
	d=(tab_a[0][0]*tab_a[1][1]*tab_a[2][2])+
	(tab_a[0][1]*tab_a[1][2]*tab_a[2][0])+
	(tab_a[0][2]*tab_a[1][0]*tab_a[2][1])-
	(tab_a[0][2]*tab_a[1][1]*tab_a[2][0])-
	(tab_a[0][0]*tab_a[1][2]*tab_a[2][1])-
	(tab_a[0][1]*tab_a[1][0]*tab_a[2][2]);
	return d;
}

int det_2(double tab_a[2][2]){
	int d;
	d=(tab_a[0][0]*tab_a[1][1])-(tab_a[0][1]*tab_a[1][0]);
	return d;
}

void dop_3(double tab[3][3]){
	double tab_c[3][3];
	int i,j;
tab_c[0][0]=(tab[1][1]*tab[2][2])-(tab[1][2]*tab[2][1]);
tab_c[0][1]=(tab[0][2]*tab[2][1])-(tab[0][1]*tab[2][2]);
tab_c[0][2]=(tab[0][1]*tab[1][2])-(tab[0][2]*tab[1][1]);

tab_c[1][0]=tab[1][2]*tab[2][0]-(tab[1][0]*tab[2][2]);
tab_c[1][1]=tab[0][0]*tab[2][2]-(tab[0][2]*tab[2][0]);
tab_c[1][2]=tab[0][2]*tab[1][0]-(tab[0][0]*tab[1][2]);

tab_c[2][0]=tab[1][0]*tab[2][1]-tab[1][1]*tab[2][0];
tab_c[2][1]=tab[0][1]*tab[2][0]-tab[0][0]*tab[2][1];
tab_c[2][2]=tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
	
double detr=det_3(tab);
   if(detr!=0){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				tab_c[j][i]*=(1/detr);
			}
		}
	wys(tab_c);
	}
	else
	printf("\nBrak macierzy odwrotnej.\n");

}

void dop_2(double tab[2][2]){
	double tab_c[2][2];
	double swap;
	int i,j;
tab_c[0][0]=tab[1][1];
tab_c[1][1]=tab[0][0];
tab_c[0][1]=(-1)*tab[0][1];
tab_c[1][0]=(-1)*tab[1][0];
	
double detr=det_2(tab);
   if(detr!=0){
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				tab_c[j][i]*=(1/((tab[0][0]*tab[1][1])-(tab[1][0]*tab[0][1])));
			}
		}
	wys2(tab_c);
	}
	else
	printf("\nBrak macierzy odwrotnej.\n");
}


int main(){
	system("chcp 1250");
	printf("Program Macierze\n");
	
	int n,d,c,st,i,j;
	int end=1;
	double tab_a[3][3];
	double tab_b[3][3];
	double tab_a_2[2][2];
	double tab_b_2[2][2];
	printf("Wybierz stopieñ macierzy:\n2-dwuwymiarowa.\n3-trójwymiarowa.\n");
	scanf("%d",&st);
	while(end){
		printf("1. WprowadŸ macierze.\n");
		printf("2. Dodaj (A+B).\n");
		printf("3. Odejmij (A-B).\n");
		printf("4. Odejmij (B-A).\n");
		printf("5. Mno¿enie (A*B).\n");
		printf("6. Mno¿enie (B*A).\n");
		printf("7. Transponuj A.\n");
		printf("8. Transponuj B.\n");
		printf("9. Odwrotnosæ A.\n");
		printf("10. Odwrotnosæ B.\n");
		printf("11. Koniec.\n");
		scanf("%d",&d);
		switch(d){
			case 1: {
				if(st==3){
					for(i=0;i<3;i++){
						printf("Podaj %d kolumnê:\n",i+1);
						for(j=0;j<3;j++){
							scanf("%d",&c);
							tab_a[i][j]=c;
						}
					}
					
					printf("Wprowadzi³eœ macierz: ");
					wys(tab_a);
					printf("\n");
					for(i=0;i<3;i++){
						printf("Podaj %d wiersz:\n",i+1);
						for(j=0;j<3;j++){
							scanf("%d",&c);
							tab_b[j][i]=c;
						}
					}
					
					printf("Wprowadzi³eœ macierz: ");
					wys(tab_b);
					printf("\n");
				}
				else
				{
					for(i=0;i<2;i++){
						printf("Podaj %d kolumnê:\n",i+1);
						for(j=0;j<2;j++){
							scanf("%d",&c);
							tab_a_2[i][j]=c;
						}
					}
					
					printf("Wprowadzi³eœ macierz: \n");
					wys2(tab_a_2);
					printf("\n");
					for(i=0;i<2;i++){
						printf("Podaj %d kolumnê:\n",i+1);
						for(j=0;j<2;j++){
							scanf("%d",&c);
							tab_b_2[i][j]=c;
						}
					}
					
					printf("Wprowadzi³eœ macierz: \n");
					wys2(tab_b_2);
					printf("\n");
				}
				
				break;
			}
			case 2: {
				printf("A+B:\n");
				if(st==3)
					add_3(tab_a, tab_b);	
				else
					add_2(tab_a_2,tab_b_2);
				getch();	
				break;
			}
			case 3: {
				printf("A-B:\n");
				if(st==3)
					sub_3(tab_a, tab_b);
				else
					sub_2(tab_a_2,tab_b_2);
				getch();
				break;
			}
			case 4: {
				printf("B-A:\n");
				if(st==3)
					sub_3(tab_b, tab_a);
				else
					sub_2(tab_b_2,tab_a_2);
				getch();
				break;
			}
			case 5: {
				printf("A*B:\n");
				if(st==3)
					mul_3(tab_a, tab_b);
				else
					mul_2(tab_a_2,tab_b_2);
				getch();
				break;
			}
			case 6: {
				printf("B*A:\n");
				if(st==3)
					mul_3(tab_b, tab_a);
				else
					mul_2(tab_b_2,tab_a_2);
				getch();
				break;
			}
			case 7: {
				printf("A^T:\n");
				if(st==3)
					transp_3(tab_a);
				else
					transp_2(tab_a_2);
				getch();
				break;
			}
			case 8: {
				printf("B^T:\n");
				if(st==3)
					transp_3(tab_b);
				else
					transp_2(tab_b_2);
				getch();
				break;
			}
			case 9: {
				printf("A^-1:\n");
				if(st==3)
					dop_3(tab_a);
				else
					dop_2(tab_a_2);
				getch();
				break;
			}
			case 10: {
				printf("B^-1:\n");
				if(st==3)
					dop_3(tab_b);
				else
					dop_2(tab_b_2);
				getch();
				break;
			}
			case 11: {
				end=0;
				break;
			}
		}
	}
	
	return 0;
}
