#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class Bayar{
	friend ostream& operator<<(ostream&, const Bayar&);
	friend istream& operator>>(istream&, Bayar&);
public:
	Bayar();
	void bayar(){
	(catat.jumlah = ((catat.a * catat.agk) + (catat.b * catat.ag) + (catat.c * catat.ug) + (catat.d * catat.cg) + (catat.e * catat.ab)));

	if (catat.jarak < 3){
		catat.ongkir = 15000;
		}
	else{
		catat.ongkir = 25000;
	}
	
	if (catat.jumlah>=25000 && catat.jumlah<=50000){
		catat.ongkir -= 3000;
	}
	else if(catat.jumlah>50000 && catat.jumlah<=150000){
		catat.ongkir -= 5000;
		catat.diskon = (catat.jumlah*15)/100;	
	}
	else if(catat.jumlah>150000){
		catat.ongkir -= 8000;
		catat.diskon = (catat.jumlah*35)/100;
	}
	(catat.total_harga = (catat.jumlah + catat.ongkir - catat.diskon));
}
private:
	struct catatan{
	int ag = 17000;
	int ab = 25000;
	int agk= 21000;
	int ug = 19000;
	int cg = 20000;
	int a,b,c,d,e;
	int jarak,ongkir,jumlah,total_harga;
	float diskon;
		}catat;
};

Bayar::Bayar(){
	cout<<"Pilihan Menu : \n";
	cout<<"1. Ayam Geprek	Rp. 21.000\n";
	cout<<"2. Ayam Goreng	Rp. 17.000\n";
	cout<<"3. Udang Goreng	Rp. 19.000\n";
	cout<<"4. Cumi Goreng	Rp. 20.000\n";
	cout<<"5. Ayam Bakar	Rp. 25.000\n";
}
istream& operator>>(istream& in, Bayar& masukan){
	cout<<"================================\n";
	cout<<"Masukkan pesanan Ayam Geprek	: ";
	in >>masukan.catat.a;
	cout<<"Masukkan pesanan Ayam Goreng	: ";
	in >>masukan.catat.b;
	cout<<"Masukkan pesanan Udang Goreng	: ";
	in >>masukan.catat.c;
	cout<<"Masukkan pesanan Cumi Goreng	: ";
	in >>masukan.catat.d;
	cout<<"Masukkan pesanan Ayam Bakar	: ";
	in >>masukan.catat.e;
	cout<<"================================\n";
	cout<<"Masukkan Jarak Rumah Anda	: ";
	in >>masukan.catat.jarak;

	return in;
}
ostream& operator<<(ostream& out,const Bayar& keluaran){
	ofstream struk;			//Untuk menulis file
	struk.open("struk.txt", ios::app);
	out<<"================================\n";
	out<<"Rp. 21.000	x "<<keluaran.catat.a<<"	: "<<keluaran.catat.a*keluaran.catat.agk<<endl;
	out<<"Rp. 17.000	x "<<keluaran.catat.b<<"	: "<<keluaran.catat.b*keluaran.catat.ag<<endl;
	out<<"Rp. 19.000	x "<<keluaran.catat.c<<"	: "<<keluaran.catat.c*keluaran.catat.ug<<endl;
	out<<"Rp. 20.000	x "<<keluaran.catat.d<<"	: "<<keluaran.catat.d*keluaran.catat.cg<<endl;
	out<<"Rp. 25.000	x "<<keluaran.catat.e<<"	: "<<keluaran.catat.e*keluaran.catat.ab<<endl;
	out<<"================================\n";
	out<<"Harga			: "<<keluaran.catat.jumlah<<endl;
	out<<"Diskon			: "<<keluaran.catat.diskon<<endl;
	out<<"Ongkir			: "<<keluaran.catat.ongkir<<endl;
	out<<"Total Harga		: "<<keluaran.catat.total_harga<<endl;
	
	struk<<"Struk Pembayaran Makanan\n";
	struk<<"================================\n";
	struk<<"Rp. 21.000	x "<<keluaran.catat.a<<"	: "<<keluaran.catat.a*keluaran.catat.agk<<endl;
	struk<<"Rp. 17.000	x "<<keluaran.catat.b<<"	: "<<keluaran.catat.b*keluaran.catat.ag<<endl;
	struk<<"Rp. 19.000	x "<<keluaran.catat.c<<"	: "<<keluaran.catat.c*keluaran.catat.ug<<endl;
	struk<<"Rp. 20.000	x "<<keluaran.catat.d<<"	: "<<keluaran.catat.d*keluaran.catat.cg<<endl;
	struk<<"Rp. 25.000	x "<<keluaran.catat.e<<"	: "<<keluaran.catat.e*keluaran.catat.ab<<endl;
	struk<<"================================\n";
	struk<<"Harga			: "<<keluaran.catat.jumlah<<endl;
	struk<<"Diskon		: "<<keluaran.catat.diskon<<endl;
	struk<<"Ongkir		: "<<keluaran.catat.ongkir<<endl;
	struk<<"Total Harga		: "<<keluaran.catat.total_harga<<endl;
	
	struk.close();
	return out;
}

int main(){

	Bayar X;
	cin>>X;
	X.bayar();
	cout<<X;
	getch();
	return 0;
}
