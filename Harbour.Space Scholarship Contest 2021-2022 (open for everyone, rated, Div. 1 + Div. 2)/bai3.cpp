#include<bits/stdc++.h>
using namespace std;
int demss, demgan, demtoan;
struct DanhSach{
    int a[100];
    int last;
};
void makeNull(DanhSach &l){
    l.last = 0;
}
int emptyList(DanhSach l){
    if (l.last == 0)
        return 0;
    return 1;
}
void insertDanhSach(DanhSach &l){
    cout << "Nhap so phan tu cua day: ";
    cin >> l.last;
    if (l.last > 100){
        cout << "Danh sach day!";
    }else{
        for (int i = 0; i<l.last; i++){
            cout << "Nhap phan tu thu " << i + 1 << ":";
            cin >> l.a[i];
        }
        cout << endl;
    }
}
void hienDanhSach(DanhSach l){
    if (emptyList(l) == 0)
        cout << "Danh sach rong!";
    else{
        for (int i = 0;i <l.last; i++){
            cout << "Phan tu "<< i + 1 << ": " << l.a[i] << endl;
        }
        cout << endl;
    }
}
int sortBase(DanhSach &l, int low, int high)
{
    int pivot = l.a[high];
    int left = low;
    int right = high - 1;
    demgan+=3;
    while(true){
        while(left <= right && l.a[left] < pivot){
            left++;
            demss++;
            demtoan++;
        }
        while(right >= left && l.a[right] > pivot){
            right--;
            demss++;
            demtoan++;
        }
        if (left >= right) {
            demss++;
            break;
        }
        swap(l.a[left], l.a[right]);
        left++;
        right--;
        demgan++;
        demtoan+=2;
    }
    swap(l.a[left], l.a[high]);
    demgan++;
    return left;
}

void quickSort(DanhSach &l, int low, int high)
{
    if (low < high)
    {
        int pi = sortBase(l, low, high);
        quickSort(l, low, pi - 1);
        quickSort(l, pi + 1, high);
    }
}
void cacPhepDem(){
    cout << "So phep so sanh: " << demss << endl;
    cout << "So phep toan: " << demtoan << endl;
    cout << "So phep gan: " << demgan << endl;

}
void menu(DanhSach &l){
    int choose = 0;
    while(choose != 6){
        cout << "1. Khoi tao danh sach so nguyen" << endl;
        cout << "2. Nhap sanh sach" << endl;
        cout << "3. Hien danh sach" << endl;
        cout << "4. Sap xep danh sach" <<endl;
        cout << "5. So phep so sanh, gan, toan" << endl;
        cout << "6. Thoat" << endl;
        cout << "Moi chon chuc nang: ";
        cin >> choose;
        switch(choose){
        case 1:
            makeNull(l);
            break;
        case 2:
            insertDanhSach(l);
            break;
        case 3:
            hienDanhSach(l);
            break;
        case 4:
            quickSort(l, 0, l.last - 1);
            hienDanhSach(l);
            break;
        case 5:
            cacPhepDem();
            break;
        default:
            break;
        }
    }
}
int main()
{
    DanhSach l;
    menu(l);
}
