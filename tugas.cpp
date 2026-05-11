#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;

public:
    int id;
    string nama;
    string email;

    User(string pNama, string pEmail) {
        nama = pNama;
        email = pEmail;
        id = generateId();
    }

    int generateId() {
        globalId++;
        return globalId;
    }
};

int User::globalId = 0;


class Member : public User {
public:
    bool status;

    Member(string pNama, string pEmail)
        : User(pNama, pEmail)
    {
        status = true;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;

        if(status == true) {
            cout << "Status : Aktif\n";
        }
        else {
            cout << "Status : Nonaktif\n";
        }

        cout << endl;
    }
};


class Admin : public User {
public:
    vector<Member*> daftarMember;

    Admin(string pNama, string pEmail)
        : User(pNama, pEmail)
    {

    }

    void tambahMember(Member* m) {
        daftarMember.push_back(m);
    }

    void showAllMember() {
        cout << "Daftar Member\n";

        for(auto& m : daftarMember) {
            cout << m->id << " - "
                 << m->nama << " - "
                 << m->email << endl;
        }

        cout << endl;
    }

    void toggleActivationMember(Member* m) {
        m->status = !m->status;
    }
};


int main() {

    Admin* admin1 = new Admin("Budi", "admin@gmail.com");

    Member* member1 = new Member("Andi", "andi@gmail.com");
    Member* member2 = new Member("Lia", "lia@gmail.com");

    admin1->tambahMember(member1);
    admin1->tambahMember(member2);

    admin1->showAllMember();

    member1->showProfile();

    admin1->toggleActivationMember(member1);

    member1->showProfile();

    delete admin1;
    delete member1;
    delete member2;

    return 0;
}