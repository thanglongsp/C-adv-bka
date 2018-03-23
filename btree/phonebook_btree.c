#include<stdio.h>
#include"../../lib/libbt/inc/btree.h"
int main()
{
    int i,n,size;
    long sdt;
    char name[40];
    BTA *book; 
    // khoi tao thu vien Btree
    btinit(); 

    // open btree'file
    // 0 thu nhat : mode : = 0  cho phep update, !=0 thi k cho update
    // 0 thu hai  : shared: nếu bằng 0 thì cho phép share, nếu khác 0 thì không cho phép hàm sẽ trả về root, nếu thất bại sẽ trả về NULL
    book=btopn("mybook",0,0); 
    if(!book){

        book=btcrt("mybook",0,0);
        //sdt=123;
        //if(btins(book,"Hien",(char*)&sdt,sizeof(long)))
        //    printf("1Error, can't insert\n");
    }
    do{
        printf("\n*** PHONE BOOK B-TREE ***\n");
        printf("1. Insert a phone\n2. Display\n3. Find\n4. Delete\n5. Exit\n");
        scanf("%d%*c",&n);
        switch(n){
            case 1: {
                printf("name:\t"); gets(name);
                printf("sdt:\t"); scanf("%ld%*c",&sdt); 
                if(btins(book,name,(char*)&sdt,sizeof(long))!=0){ // bttins : chen vao btree file.
                    printf("update data\n");
                    btupd(book,name,(char*)&sdt,sizeof(long));		// btupdate : update for btree'file.
                }
            } break;
            case 2: {
                printf("\nList phone:\n");
                btsel(book,"",(char*)&sdt,sizeof(long),&size);
                while(btseln(book,name,(char*)&sdt,sizeof(long),&size)==0)
                printf("%-30s%-15ld\n",name,sdt);
            }break;
            case 3: {
                printf("name:\t"); gets(name);
                if(btsel(book,name,(char*)&sdt,sizeof(long),&size)==0)
                    printf("%-30s%-15ld\n",name,sdt);
                else
                    printf("not found\n");
            } break;
            case 4: {
                printf("name:\t"); gets(name);
                if(btsel(book,name,(char*)&sdt,sizeof(long),&size)==0) // btsel : xac dinh du lieu cua khoa co san.
                    btdel(book,name);									// btdel : xoa key va data. Tra ve 0 neu thanh cong.
                else printf("not found, can't delete\n");
            }break;
            case 5: {
                btcls(book); // thoat khoi btree file.
            }break;
        }
    }while(n!=5);
}
