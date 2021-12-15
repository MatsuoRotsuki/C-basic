/*
Viết chương trình nhập vào dãy n hồ sơ từ các file dữ liệu được sinh ra
trong Bài tập 1 (ở trên), thực hiện sắp xếp các hồ sơ theo thứ tự không
giảm (ưu tiên so sánh họ tên trước, rồi mới đến ngày, tháng, năm sinh)
bằng thuật toán sắp nhanh
Dữ liệu (profile-n.txt)
• Dòng 2i-1 và dòng 2i (i = 1,…) tương ứng ghi họ tên (không dấu) và
ngày, tháng, năm sinh của hồ sơ thứ i. Họ và tên ghi theo định dạng
<họ> <tên đệm> <tên> và ngày, tháng, năm sinh ghi theo định dạng
YYYY-MM-DD
• Dòng cuối cùng: ghi ký tự # thể hiện dấu hiệu kết thúc file
• Kết quả (sorted-profile-n.txt)
• Ghi dãy đã được sắp xếp theo thứ tự với định dạng
• Dòng 2i-1 và dòng 2i (i = 1,…) tương ứng ghi họ tên (không dấu) và
ngày, tháng, năm sinh của hồ sơ thứ i. Họ và tên ghi theo định
dạng <họ> <tên đệm> <tên> và ngày, tháng, năm sinh ghi theo
định dạng YYYY-MM-DD
• Dòng cuối cùng: ghi ký tự # thể hiện dấu hiệu kết thúc file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ELEMENT 20

typedef struct {
    char hovaten[50];
    char ngaysinh[11];
} List;

List data[MAX_ELEMENT];
int count = 0;

void input(FILE *fin){
    char temp[17], date[11];
}

int main (){
    FILE *fin, *fout;
    if ((fin = fopen("profile-n.txt","r")) == NULL) {
        printf("Cannot open read file!\n");
        return 0;
    }
    else if ((fout = fopen("sorted-profile-n.txt", "w")) == NULL){
        printf("Cannot open write file!\n");
        return 0;
    }

    input(fin);
    return 0;
}