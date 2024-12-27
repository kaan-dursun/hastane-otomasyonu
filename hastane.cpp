#include <iostream>
#include <string>
using namespace std;

struct Node { // Rehber için Node sınıfı
    string name;
    string phone;
    Node* next;

    Node(string name, string phone) {
        this->name = name;
        this->phone = phone;
        this->next = nullptr;
    }
};

class PhoneBook {
private:
    Node* head;

public:
    PhoneBook() {
        head = nullptr;
    }

    // Kişi ekleme fonksiyonu
    void addContact(string name, string phone) {
        Node* newNode = new Node(name, phone);

        if (head == nullptr || head->name > name) { // Alfabetik sıralı ekleme
            newNode->next = head;
            head = newNode;
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr && tmp->next->name < name) {
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        cout << "doktor eklendi: " << name << " - " << phone << endl;
    }

    // Kişi silme fonksiyonu
    void deleteContact(string name) {
        if (head == nullptr) {
            cout << "hastanede doktor bulunamadi" << endl;
            return;
        }
        if (head->name == name) { // İlk eleman siliniyorsa
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "doktor silindi: " << name << endl;
            return;
        }

        Node* tmp = head;
        while (tmp->next != nullptr && tmp->next->name != name) {
            tmp = tmp->next;
        }

        if (tmp->next == nullptr) {
            cout << "hastanede doktor  bulunamadi: " << name << endl;
        } else {
            Node* temp = tmp->next;
            tmp->next = tmp->next->next;
            delete temp;
            cout << "doktor silindi: " << name << endl;
        }
    }

    // Kişi arama fonksiyonu
    void searchContact(string name) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == name) {
                cout << "doktor bulundu: " << tmp->name << " - " << tmp->phone << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "hastanede doktor bulunamadi: " << name << endl;
    }

    // Tüm kişileri listeleme fonksiyonu
    void displayContacts() {
        if (head == nullptr) {
            cout << "hastanede doktor yok." << endl;
            return;
        }
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->name << " - " << tmp->phone << endl;
            tmp = tmp->next;
        }
    }
  
    // Destructor: Belleği serbest bırakır
    ~PhoneBook() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
     bool searchContact3(string phone) {
        Node* tmp = head;
        while (tmp != nullptr) {
            if (tmp->phone == phone) {
               return true;
            }
            tmp = tmp->next;
        } return false;
        
    }
        
};//hasta doktor eşlesmesi olan liste
struct nNode {
    string hasta;
    string doktor;
    nNode* next;

    nNode(string h, string d) : hasta(h), doktor(d), next(nullptr) {}
};
class randevuList {
public:
    nNode* head;
    randevuList(){head=nullptr;}
        void appendrandevu(string name,string doktor){
             nNode* newNode = new nNode(name, doktor);
        if (!head) {
            head = newNode;
        } else {
            nNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        }
         void randevularigoruntule() {
        if (head == nullptr) {
            cout << "hastanede doktor yok." << endl;
            return;
        }
        nNode* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->hasta << " - " << tmp->doktor << endl;
            tmp = tmp->next;
        }
    }
    bool searchContact2(string hasta,string doktor) {
        nNode* tmp = head;
        while (tmp != nullptr) {
            if (tmp->hasta== hasta && tmp->doktor==doktor) {
                cout<<"ayni randevudan 2 kere alamazsiniz"<<endl;
                return false;
            }
            tmp = tmp->next;
        }
        return true;
    }
    
    
            
        
    
    
    
    
    
    
    
    };
    struct hNode { 
    string hasta;
    hNode* next;

    hNode(string hasta) {
        this->hasta = hasta;
        this->next = nullptr;
    }
};

class hastalist {
private:
    hNode* head;

public:
    hastalist() {
        head = nullptr;
    }
     void addContact(string hasta) {
        hNode* newNode = new hNode(hasta);
          if (!head) {
            head = newNode;
        } else {
            hNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
     }
       void hastalarigoruntule() {
        if (head == nullptr) {
            cout << "hastanede doktor yok." << endl;
            return;
        }
        hNode* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->hasta  << endl;
            tmp = tmp->next;
        }
    }


};

int main() {
    PhoneBook phoneBook;
    randevuList randevulist;
    hastalist hastaList;
    int choice;
    string name, phone;
    string hasta ,doktor;
    do {
        cout << "\n1. doktor Ekleme\n2. doktor Silme\n3. doktor Arama\n4. doktor Listeleme\n5.randevu alma\n6.randevulari listele\n7.hastalari listele\n8. Cikis\nSeciminiz: ";
        cin >> choice;
        cin.ignore(); // Yeni satır karakterini temizlemek için

        switch (choice) {
            case 1:
                cout << "doktor: ";
                getline(cin, name);
                cout << "uzmanlik alani: ";
                getline(cin, phone);
                phoneBook.addContact(name, phone);
                break;
            case 2:
                cout << "Silmek istediginiz doktorun adi: ";
                getline(cin, name);
                phoneBook.deleteContact(name);
                break;
            case 3:
                cout << "Aramak istediginiz doktorun adi: ";
                getline(cin, name);
                phoneBook.searchContact(name);
                break;
            case 4:
                phoneBook.displayContacts();
                break;
            case 5:
                cout<<"hasta adi"<<endl;
                cin>>hasta;
                cout<<"doktor adi"<<endl;
                cin>>doktor;
                cout<<"tekrar doktor adi girniniz"<<endl;
                cin>>name;
                if (phoneBook.searchContact3(name)){
                    name;
                     if(randevulist.searchContact2(hasta,doktor)){
                        randevulist.appendrandevu(hasta,doktor);
                        hastaList.addContact(hasta);
                     }
                    
                }else{
                    cout<<"istediginiz doktor hastanemizde bulunmamaktadir"<<endl;
                }
                break;
            case 6:
                    randevulist.randevularigoruntule();
                    break;
            case 7:
                    hastaList.hastalarigoruntule() ;   
                    break;   
            case 8:
                cout << "Cikis" << endl;
                break;
            default:
                cout << "Gecersiz secim" << endl;
        }
    } while (choice != 8);

    return 0;
}
