#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *head; // hen�z bellekte yer kaplam�yor
head = (struct node *)malloc(sizeof(struct node));
// art�k bellekte yer tahsis edilmi�tir.
head -> data = 1;
head -> next = NULL;
/* listeye yeni eleman ekleme */
/* C++'ta head -> next = new node() �eklinde kullan�labilir. */
head -> next = (struct node *)malloc(sizeof(struct node));
head -> next -> data = 3;
head -> next -> next = NULL;

// Tek ba�l� do�rusal listenin ba��na eleman eklemek
struct node *addhead(struct node *head,int key) {
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp -> data = key;
temp -> next = head; // temp�in next�i �u anda head�i g�steriyor.
/* Bazen �nce listenin bo� olup olmad��� kontrol edilir, ama gerekli de�il
asl�nda. ��nk� bo� ise zaten head=NULL olacakt�r ve temp olan ilk d���m�n
next�i NULL g�sterecektir. */
head = temp; /* head art�k temp�in adresini tutuyor yani eklenen d���m
listenin ba�� oldu. */
return head;
}

struct node *addlast(struct node *head,int key) {
struct node *temp = (struct node *)malloc(sizeof(struct node));
/* C++'ta struct node *temp = new node();
* �eklinde kullan�labilece�ini unutmay�n�z. */
temp -> data = key;
temp -> next = NULL;
struct node *temp2 = head;
/* A�a��daki while yap�s� traversal(dola�ma) olarak adland�r�l�r */
while(temp2 -> next != NULL)
temp2 = temp2 -> next;
temp2 -> next = temp;
return head;
}

void listinfo(struct node* head) {
int i = 1;
while(head != NULL) {
printf("%d. Dugumunun Adresi = %p \n", i, head);
printf("%d. Dugumunun verisi = %d \n", i, head -> data);
printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= %p\n\n",i, head->next);
head = head -> next;
i++;
}
}

int count(struct node *head) {
int counter = 0;
while(head != NULL) { // head->next!=NULL ko�ulu olsayd� son d���m say�lmazd�
counter++;
head = head -> next;
}
return counter;
}

struct node *remove(struct node *head, int key) {
if(head == NULL) {
printf("Listede eleman yok\n");
return;
}
struct node *temp = head;
if(head -> data == key) { // ilk d���m silinecek mi diye kontrol ediliyor.
head = head -> next; // head art�k bir sonraki eleman.
free(temp);
}
else if(temp -> next == NULL) { // Listede tek d���m bulunabilir.
printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
return head;
}
else {
while(temp -> next -> data != key) {
if(temp -> next -> next == NULL) {
printf("Silmek istediginiz veri bulunmamaktadir.\n\n");
return head;
}
temp = temp -> next;
}
struct node *temp2 = temp -> next;
temp -> next = temp -> next -> next;
free(temp2);
}
return head;
}

struct node *destroy(struct node *head) {
if(head == NULL) {
printf("Liste zaten bos\n");
return;
}
struct node *temp2;
while(head!= NULL) { // while i�indeki ko�ul temp2 -> next, NULL de�ilse
temp2=head;
head = head->next;
free(temp2);
}
return head;
}

int main(){
int secim,data;
struct node *head = NULL;
while(1){
printf("1-Listenin Basina Eleman Ekle\n");
printf("2-Listenin Sonuna Eleman Ekle\n");
printf("3-Listeyi Gorme\n");
printf("4-Listeden verilen bir degere sahip dugum silmek\n");
printf("5-Listeyi sil\n");
printf("6-Listedeki eleman sayisi\n");
printf("7-Listenin tum eleman bilgileri\n");
printf("8-Programdan Cikma\n");
printf("Seciminiz....?");
scanf("%d",&secim);
switch(secim){
case 1:
printf("Eklemek istediginiz degerini giriniz..?");
scanf("%d",&data);
head=addhead(head,data);
break;
case 2:
printf("Eklemek istediginiz degerini giriniz..?");
scanf("%d",&data);
head=addlast(head,data);
break;
case 3:
print(head);
break;
case 4:
printf("Silmek istediginiz degerini giriniz..?");
scanf("%d",&data);
head=delete(head,data);
break;
case 5:
head=destroy(head);
break;
case 6:
printf("Listede %d eleman vardir\n",count(head));
break;
case 7:
listinfo(head);
break;
case 8:
exit(1);
break;
default: printf("Yanlis secim\n");
}
}
}
