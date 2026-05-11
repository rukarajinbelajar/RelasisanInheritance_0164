#ifndef IBU_H
#define IBU_H
#include <vector>

class ibu{
public:
    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) :nama(pNama){
        cout << "Ibu \ "" << nama << "\" tidak ada\n";
    }
    ~ibu(){
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }
    void tambahAnak(anak*);
    void cetakAnak();
};
void ibu::tambahAnak(){
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    /*for (auto& a: daftar_anak){
        cout << a->nama << "\n";
    }*/
    for (int i = 0; i < daftar_anak.size(); i++){
        cout << daftar_anak[i]->nama << endl;
    }
    cout << endl;
}
