#include <iostream>
#include<stdlib.h>
#include<list>
using namespace std;
int yigin_sayisi =0;      // yığın eleman sayısını tutan değişken
int kuyruk_sayisi =0;     // kuyruk eleman sayısını tutan değişken
int liste_sayisi =0;      // liste eleman sayısını tutan değişken
int agac_sayisi =0;       // ağac eleman saısını tutan degisken
int hash_sayisi =0;       // hash table eleman saısını tutan degisken
struct Node {             // yığın için kullanılan node
   int data;              // node'da tutulan veri
   struct Node *next;     // bir sonraki node'un pointer'ı
}; 
struct Node* top = NULL; 
void push(int val) {       //eleman ekleme fonksiyonu
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); // yigin icin memory'de yer açma
   newnode->data = val;   // girilen degeri data'ya ata
   newnode->next = top;   // onceki node'u point et
   top = newnode;         // top elemani guncelle  
   yigin_sayisi++; }      /*yığına eleman eklendiği için eleman                                                                 sayısını tutan değişkeni bir arttırırız*/

void pop() {            //eleman silme fonksiyonu
   if(top==NULL)        //eğer en üstte eleman yoksa yığında silinebilecek eleman yoktur 
  cout<<"Stack Underflow"<<endl;    //kullanıcıya silinebilecek eleman olmadığını bildiririz.
   else {
      cout<<"The popped element is "<< top->data <<endl;  //silinen elemanı kullanıcıya bildiririz
      top = top->next;      // top elemani guncelle 
      yigin_sayisi--;       //eleman silindiği için eleman sayısı bir azalır
   }
}
void display() {       //görüntüleme fonksiyonu
   struct Node* ptr;
   if(top==NULL)     //eğer en üstte eleman yoksa yığında eleman yoktur
      cout<<"stack is empty";   //yığının boş olduğunu bildiririz
   else {   
      ptr = top; // gecici (top) eleman tanimla
      cout<<"Stack elements are: ";
      while (ptr != NULL) { // Yukarıdan asağıya dogru elemanları bastır
         cout<< ptr->data <<" "; // ptr'nin tuttuğu veriyi bastır
         ptr = ptr->next; // ptr'yi bir alttaki eleman olarak güncelle
      } 
   }
   cout<<endl;
}
void yigin_eleman_sayisi(){   //eleman sayısını gösteren fonksiyon
if(top==NULL)                 //eğer en üstte eleman yoksa yığında eleman yoktur
      cout<<"stack is empty\n";   //kullanıcıya yığının boş olduğunu bildiririz.
      else{
      cout<< "Number of elements:" <<yigin_sayisi<<endl ; //yığın eleman sayısını bildiririz
}
}
void delete_all(){  //bütün elemanları silme fonksiyonu
top=NULL;           //eğer en üstte eleman olmazsa yığında eleman olmaz
yigin_sayisi=0;     //eleman sayısını sıfırla
}



struct node {         // Kuyruk icin tanimli node
   int data;          // Kuyruk node'un tuttugu veri
   struct node *next; // bir sonraki node'un pointer'ı
};
struct node* front = NULL; //front'u Null olarak tanımladık
struct node* rear = NULL;  //rear'ı Null olarak tanımladık
struct node* temp;         //temp'i tanımladık
void Insert() {     //eleman ekleme fonksiyonu
   int val;       //değişken tanımlarız
   cout<<"Insert the element in queue : "<<endl;  //eklenecek elemanı isteriz
   cin>>val;    //girdiği değeri tanımladığımız değişkene atarız
   if (rear == NULL) { // kuyrukta eleman yoksa bu devreye girer
      rear = (struct node *)malloc(sizeof(struct node)); // memory'de rear icin yer ac
      rear->next = NULL; // sonraki node'u point et
      rear->data = val;  // girilen degeri data'ya ata
      front = rear;      // front'u guncelle
   } else {     // kuyrukta eleman varsa bu devreye girer
      temp=(struct node *)malloc(sizeof(struct node)); // memory'de temp icin yer ac
      rear->next = temp; // sonraki node'u point et
      temp->data = val;  //  girilen degeri data'ya ata
      temp->next = NULL; // temp'ten sonraki node'u guncelle
      rear = temp;  // rear'ı guncelle
   }
   kuyruk_sayisi++; //eleman eklendiği için kuyruk eleman sayısı bir artar
}
void Delete() {     //Silme fonksiyonu 
   temp = front;    
   if (front == NULL) {    //eğer front'da eleman yoksa silinecek eleman yok
      cout<<"Underflow"<<endl;  //silinecek eleman olmadığını bildiririz 
      return;
   }
   else
   if (temp->next != NULL) { // Eleman sayisi 1'den fazla ise
      temp = temp->next; // temp'ten onraki node;u guncelle
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);  // front'u temizle
      front = temp; // front'u guncelle
      
   } else {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front); // front'u temizle
      front = NULL; //front'u sil
      rear = NULL;  //rear'ı sil
      
   }
   kuyruk_sayisi--;  //kuyruk eleman sayısı bir azalır
}
void Display() {     //görüntüleme fonksiyonu
   temp = front;
   if ((front == NULL) && (rear == NULL)) {   //eğer front(ön) ve rear(arka) boşsa kuyruk boştur
      cout<<"Queue is empty"<<endl;           //kullanıcıya boş olduğunu bildiririz
      return;
   }
   cout<<"Queue elements are: ";     // kuyruktaki elemanları bildiririz
   while (temp != NULL) {            // sagdan sola dogru kuyruktaki elemanları bastır
      cout<<temp->data<<" ";         // veriyi bastir
      temp = temp->next;             // temp'i guncelle
   }
   cout<<endl;
}
void kuyruk_eleman_sayisi(){   //eleman sayısını gösteren fonksiyonu
if((front == NULL) && (rear == NULL)) //eğer front ve rear boşsa kuyruk boştur
      cout<<"Queue is empty\n";       //kullanıcıya boş olduğunu bildiririz
      else{                           //boş değilse
      cout<< "Number of elements:" <<kuyruk_sayisi<<endl ; //kuyruk eleman sayısını bildiririz
}
}
void Delete_All(){    //bütün elemanları silme fonksiyonu
front = NULL;         //front'u sil
rear = NULL;          //rear'ı sil
kuyruk_sayisi=0;      //eleman sayısını sıfırla
}







class Node1 { // bagli liste icin tanimli node
   public : int info; // node'da tutulan veri
   Node1* next; // sonraki node'un pointer'i
};
class List:public Node1
{
 
    Node1 *first,*last; // ilk ve son elemani tutan pointer'lar
public:
    List()
    {
        first=NULL;   //first'ü Null olarak tanımladık
        last=NULL;    //last'ı Null olarak tanımladık
    }
    void create();                    //liste yaratma fonksiyonu
    void insert();                    //ekleme işlemi fonksiyonu
    void delet();                     //silme fonksiyonu
    void display();                   //görüntüleme fonksiyonu
    void search();                    //eleman arama fonksiyonu
    void liste_eleman_sayisi();       //eleman sayısını gösteren fonksiyonu
    void Delet_All();                 //bütün elemanları silme fonksiyonu
};
void List::create()  //liste yaratma fonksiyonu
{
    Node1 *temp;
    temp=new Node1; // gecici node tanimla
    int n;     //değişken tanımlarız
    cout<<"\nEnter an Element:";     //eklenecek elemanı isteriz
    cin>>n;     //girdiği değeri tanımladığımız değişkene atarız
    temp->info=n; // node'un verisini guncelle
    temp->next=NULL; // temp'ten sonraki node;u guncelle
    if(first==NULL) // listede eleman yoksa bu devreye girer (tek eleman temp)
    {
        first=temp; // gecici elemani ilk eleman yap
        last=first; // gecici eleman ayni zamanda son eleman
    }
 
    else // temp'i sona ekle
    {
        last->next=temp; // su anki son elemanin next'ini temp yap
        last=temp; // son elemani temp olarak guncelle 
    }
    liste_sayisi++;    //eleman eklendiği için liste eleman sayısı bir artar
}
void List::insert()   //ekleme işlemi fonksiyonu
{
    Node1 *prev,*cur; // nodelari tanimla
    prev=NULL;
    cur=first;
    int counter=1,pos,ch,n;  //değişkenleri tanımlarız
    Node1 *temp=new Node1; // memory'de yer ac
    cout<<"\nEnter an Element:";  //girilecek elemanı isteriz
    cin>>n;    //girdiği değeri tanımladığımız değişkene atarız
    temp->info=n; // temp'teki veriyi guncelle
    temp->next=NULL; // temp next'ini guncelle
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";  //nereye eklemek istediğini sorarız
    cin>>ch;                       //kullanıcının seçeneğini alırız
    switch(ch)
    {
    case 1: //eğer bire basıp başa eklemeyi seçerse elemanı first'e atarız 
        temp->next=first;  // temp'in next'i first eleman
        first=temp;        // temp artik ilk eleman
        liste_sayisi++;    // eleman eklendiği için liste eleman sayısı artar 
        break;
    case 2: //eğer ikiye basıp sona eklemeyi seçerse elemanı last'a atarız
        last->next=temp;   //last'in next'i temp
        last=temp;          // temp artik son eleman
        liste_sayisi++;     //eleman eklendiği için liste eleman sayısı artar
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";   //eklenecek pozisyonu girmesini isteriz 
        cin>>pos;            // girilen pozisyonu değişkene atarız
        while(counter!=pos)  // counter pos olana kadar ilerle
        {
            prev=cur;      // prev'i 1 ilerlet
            cur=cur->next; // cur'u 1 ilerlet
            counter++;     // counter'i 1 artir
        }
        if(counter==pos)     // counter pos oldugunda elemani ekle
        {
            prev->next=temp; // temp'i prev'den sonra,
            temp->next=cur;  // cur'dan once yerlestir
            liste_sayisi++;  // eleman eklendiği için liste eleman sayısı artar
        }
        

        else
            cout<<"\nNot Able to Insert"; 
        break;
 
    }
}
void List::delet()   //silme fonksiyonu
{
    Node1 *prev=NULL,*cur=first; // nodelari tanimla
    int counter=1,pos,ch;  //değişkenleri tanımlarız
    cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";  //nereden silmek istediğini sorarız
    cin>>ch;                       //kullanıcının seçeneğini alırız
    switch(ch)
    {
    case 1: // Ilk elemani sil                 
        if(first!=NULL)      
        {
            cout<<"\nDeleted Element is "<<first->info;  //silinen elemanı bildiririz
            first=first->next; // first'i guncelle
            liste_sayisi--;  //eleman silindiği için liste eleman sayısı azalır
        }
        else       
            cout<<"\nNot Able to Delete";  //silinecek bir şey olmadığını bildiririz
        break;
    case 2:   //Son elemanı sil                 
        while(cur!=last) // cur last eleman olana kadar
        {
            prev=cur;
            cur=cur->next; // cur'u ilerlet
        }
        if(cur==last)
        {
            cout<<"\nDeleted Element is: "<<cur->info;    //silinen elemanı bildiririz
            prev->next=NULL;        // prev/in next'ini guncelle
            last=prev;              // last elemani guncelle
            liste_sayisi--;         // eleman silindiği için liste eleman sayısı azalır
        }
        else
            cout<<"\nNot Able to Delete";     //silinecek bir şey olmadığını bildiririz
        break;
    case 3:    //İlk ve son elemanlar arasındaki bir elemanı sil   
        cout<<"\nEnter the Position of Deletion:";    //silinecek pozisyonu girmesini isteriz
        cin>>pos;           //girilen pozisyonu değişkene atarız
        while(counter!=pos) // counter pos olana kadar
        {
            prev=cur;      // prev/i guncelle
            cur=cur->next; // cur'u ilerlet
            counter++;     // counter'i artir
        }
        if(counter==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->info; //silinen elemanı bildiririz
            prev->next=cur->next; // prev'in next'ini guncelle
            liste_sayisi--;       // eleman silindiği için liste eleman sayısı azalır
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}
void List::display()  //görüntüleme fonksiyonu
{
    Node1 *temp=first; // node tanimla
    if(temp==NULL)
    {
        cout<<"\nList is Empty"; //listenin boş olduğunu bildiririz
    }
    while(temp!=NULL) // liste'yi bastan sona bastir
    {
        cout<<temp->info; // node'un elemanini abstir
        cout<<"-->"; 
        temp=temp->next; // temp'i ilerlet
    }
    cout<<"NULL";
}
void List::search()  //eleman arama fonksiyonu
{
    int value,pos=0;  //değişkenlerimizi tanımlarız
    bool flag=false;  // flag tanimla
    if(first==NULL)   //eğer first'de eleman yoksa liste boştur
    {
        cout<<"List is Empty"; //listenin boş olduğunu bildiririz
        return;
    }
    cout<<"Enter the Value to be Searched:";  //aranacak değeri isteriz
    cin>>value;  // girilen değeri değişkene atarız
    Node1 *temp; // node tanimla
    temp=first;  // temp'i first'e esitle
    while(temp!=NULL) // temp'i bastan sona ilerlet, NULL oldugunda sona ulasmis demektir
    {
        pos++;  // pos'u arttir
        if(temp->info==value){  //eğer aranan değer'e ulastiysak       
            flag=true; // flag'i set'le 
            cout<<"Element"<<value<<"is Found at "<<pos<<" Position"; // ekrana pos'u  bastir
            return;
        }
        temp=temp->next; // temp'i ilerlet
        
    }

    if(!flag) // eger deger bulunamamis ise 
    { 
        cout<<"Element "<<value<<" not Found in the List";  //değerin olmadığını kullanıcıya
    }                                                       //bildiririz
}

void List::liste_eleman_sayisi()  //eleman sayısını gösteren fonksiyonu
{
  cout<< "Number of elements:" <<liste_sayisi<<endl ; //liste eleman sayısını bildiririz
}

void List:: Delet_All()  //bütün elemanları silme fonksiyonu
{
first=NULL;              //eğer front ve last boş olursa kuyruk boş olur.
last=NULL;
liste_sayisi=0;           //eleman sayısını sıfırla
}


struct node2  //ikili ağaç için tanımlı node
{
    int info;  //node'da tutulan veri
    struct node2 *left;  
    struct node2 *right;
}*root;
 

class BST
{
    public:
        void find(int, node2 **, node2 **); // eleman bulma fonksyonu
        void insert(node2 *, node2 *); // eleman ekleme fonksyonu
        void del(int); // eleman silme fonksyonu
        void case_a(node2 *,node2 *); // delete fonksyonu icin
        void case_b(node2 *,node2 *); // delete fonksyonu icin
        void case_c(node2 *,node2 *); // delete fonksyonu icin
        void preorder(node2 *); //preorder dolaşmafonksiyonu
        void inorder(node2 *);  //inorder dolaşmafonksiyonu
        void postorder(node2 *); //postorder dolaşmafonksiyonu
        void display(node2 *, int);  // eleman gösterme fonksyonu
        void agac_eleman_sayisi(); // eleman sayısı gösterme fonksyonu
        void delete_allagac(node2 *); //ağacı temizleme fonksiyonu
        BST()
        {
            root = NULL; // agac icin root tanimla
        }
};


void BST::find(int item, node2 **par, node2 **loc)
{
    node2 *ptr, *ptrsave;
    if (root == NULL) // agacta eleman yoksa
    {
        *loc = NULL; //loc'ta eleman yoktur
        *par = NULL; //par'ta eleman yoktur
        return;
    }
    if (item == root->info) // eleman root ise
    {
        *loc = root; //loc root'tur
        *par = NULL; //par'ta eleman yoktur
        return;
    }
    if (item < root->info) // eleman root'dan kucukse
        ptr = root->left;  
    else                  // eleman root'dan kucuk degilse
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info) // eleman'i bulduysak
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info) // eleman kucukse soldan devam et
            ptr = ptr->left;
	else // eleman buyukse sagdan devam et
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}
 

void BST::insert(node2 *tree, node2 *newnode2)
{
    if (root == NULL) //eğer root(ilk,kök eleman) boşsa bu işlem gerçekleşir
    {
        root = new node2;
        root->info = newnode2->info;
        root->left = NULL;  //sol boş olur
        root->right = NULL; //sag boş olur
        cout<<"Root node is Added"<<endl; //İlk(kök) elemanın eklediğini bildiririz
        agac_sayisi++; //eleman eklendiği için eleman sayısı artar 
        return;
    }
    if (tree->info == newnode2->info) // eleman agacta var mi kontrol et
    {
        cout<<"Element already in the tree"<<endl; //elemanın zaten ağaçta olduğunu bildiririz
        return;
    }
    if (tree->info > newnode2->info) // eleman buyuk ise
    {
        if (tree->left != NULL) // Sol tarafi kontrol et
        {
            insert(tree->left, newnode2);	// soldan devam et (recursion)
	}
	else
	{
            tree->left = newnode2;  //solda yeni node oluştur
            (tree->left)->left = NULL; //solu boş olur
            (tree->left)->right = NULL; //sagı boş olur
            cout<<"node Added To Left"<<endl; //elemanın sola eklediğini bildiririz
            agac_sayisi++; //eleman eklendiği için eleman sayısı artar 
            return;
        }
    }
    else
    {
        if (tree->right != NULL) // Sag tarafi kontrol et
        {
            insert(tree->right, newnode2); // sagdan devam et
        }
        else
        {
            tree->right = newnode2; //sagda yeni node oluştur
            (tree->right)->left = NULL; //solu boş olur
            (tree->right)->right = NULL; //sagı boş olur
            cout<<"node Added To Right"<<endl; //elemanın sağa eklediğini bildiririz
            agac_sayisi++; //eleman eklendiği için eleman sayısı artar 
            return;
        }	
    }
}
 

void BST::del(int item)
{
    node2 *parent, *location;
    if (root == NULL) //eğer kök boşsa
    {
        cout<<"Tree empty"<<endl; //silenecek eleman yoktur ve agacın boş olduğunu bildiririz.
        return;
    }
    find(item, &parent, &location); // Aranan elemani bulak icin 
    if (location == NULL) // lokasyon bulunamadi ise
    {
        cout<<"Item not present in tree"<<endl; //aranan eleman yoktur
        return;
    }
    if (location->left == NULL && location->right == NULL) //eger location'ın solu ve sagı bossa 
        case_a(parent, location);                          //case a devreye girer
    if (location->left != NULL && location->right == NULL) //eger location'ın solu dolu sagı bossa
        case_b(parent, location);                          //case b devreye girer 
    if (location->left == NULL && location->right != NULL) //eger location'ın solu bos sagı dolu ise
        case_b(parent, location);                          //case b devreye girer
    if (location->left != NULL && location->right != NULL) //eger location'ın solu ve sagı dolu ise
        case_c(parent, location);                          //case c devreye girer
    free(location);
}
 

void BST::case_a(node2 *par, node2 *loc )
{
    if (par == NULL)  //par boş ise
    {
        root = NULL;  //root boş olur
    }
    else
    {
        if (loc == par->left) // item soldaki eleman ise
            par->left = NULL; // elemani sil
        else // item sagdaki eleman ise
            par->right = NULL;  // elemani sil
    }
    agac_sayisi--; // Eleman sayisini azalt
}
 

void BST::case_b(node2 *par, node2 *loc)
{
    node2 *child;
    if (loc->left != NULL) // soldaki eleman bos ise
        child = loc->left; // cocuk elemani sola ata
    else
        child = loc->right; // cocuk elemani saga ata
    if (par == NULL) //parent boşsa
    {
        root = child; // cocugu root'a ata
    }
    else
    {
        if (loc == par->left) // eleman sagdaki ise
            par->left = child; // cocuk elemani sola ata
        else
            par->right = child; // cocuk elemani saga ata
    }
    agac_sayisi--; // Eleman sayisini azalt
}
 

void BST::case_c(node2 *par, node2 *loc)
{
    node2 *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL) // sol oldugu surece
    {
        ptrsave = ptr;
        ptr = ptr->left; // sola ilerle
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL) // suc son eleman ise (cocugu yok ise)
        case_a(parsuc, suc); // case_a yi cagir
    else
        case_b(parsuc, suc); // son eleman degil ise case_b'yi cagir
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left) // eleman soldaki ise
            par->left = suc;  // suc'u dogru parent'a ata
        else
            par->right = suc; // suc'u dogru parent'a ata
    }
    suc->left = loc->left;
    suc->right = loc->right;
    agac_sayisi--; // Eleman sayisini azalt
}
 


void BST::preorder(node2 *ptr)
{
    if (root == NULL) //eger root bossa agacta bostur
    {
        cout<<"Tree is empty"<<endl;  //bos oldugunu bildir
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  "; // preorder sirasi icin su anki elemani bas
        preorder(ptr->left);  // ikinci olarak sol elemani bas
        preorder(ptr->right); // en son sag elemani bas
    }
}


void BST::inorder(node2 *ptr)
{
    if (root == NULL) // root var mi kontrol et
    {
        cout<<"Tree is empty"<<endl; // Agac bos demektir
        return;
    }
    if (ptr != NULL) //ptr Null degilse
    {
        inorder(ptr->left); // inorder sirasi icin once sol'u bas
        cout<<ptr->info<<"  "; // su anki elemani bas
        inorder(ptr->right); // en son sag elemani bas
    }
}
 

void BST::postorder(node2 *ptr)
{
    if (root == NULL) // root varmi kontrol et
    {
        cout<<"Tree is empty"<<endl; // Agac bos demektir
        return;
    }
    if (ptr != NULL) //ptr Null degilse
    {
        postorder(ptr->left); // postorder sirasi icin once sol elemani bas
        postorder(ptr->right); // ikinci olarak sag elemani bas
        cout<<ptr->info<<"  "; // en son su anki elemani bas
    }
}
 

void BST::display(node2 *ptr, int level)
{
    int i; // For icin variable tanimla
    if (ptr != NULL) // node NULL degil ise
    {
        display(ptr->right, level+1); // sag elemani display et
        cout<<endl;
        if (ptr == root) // node root ise
            cout<<"Root->:  "; //yazdır
        else
        {
            for (i = 0;i < level;i++) // Gorsel bosluk icin
                cout<<"       "; //yazdır
	}
        cout<<ptr->info; // elemani bastir
        display(ptr->left, level+1); // sol elemani display et
    }
}
void BST :: agac_eleman_sayisi()  //eleman sayısını gösteren fomksiyon
{
  cout<< "Number of elements:" <<agac_sayisi<<endl ; //agac eleman sayısını bildiririz
}
void BST :: delete_allagac(node2 *)  //ağaçtaki eleamları silen fonksiyon
{
  root = NULL;    //eğer root Null olursa ağaçta eleman olmaz
  agac_sayisi=0;  //eleman olmayacağı için eleman sayısını sıfırlarız
}



class hashclass
{
   int bucket; //bucket'ı tutan değişen
   list<int>*hashtable; //container 
   public:
   hashclass(int a) //constructor
    {
      bucket=a; // bucket'a degeri ata
      hashtable=new list<int>[bucket];// memory'de bucket icin yer ac
    }
    void insert_element(int key)//Hashtable'a eleman ekleme fonksiyonu
    {
        
        int indexkey=hashFunction(key);// indexkey'i belirle
        hashtable[indexkey].push_back(key); // hashtable'a olusturulan key'i ekle
        hash_sayisi++; //eleman sayisini arttır
    }
    void delete_element(int key)///Hashtable'dan eleman silme fonksiyonu
    {
        int indexkey=hashFunction(key); // indexkey'i belirle
        list<int>::iterator i=hashtable[indexkey].begin();
        for(;i!=hashtable[indexkey].end();i++)
        {
            if(*i==key) // key'i bulduysak
                break; // for'dan cik
        }
        if(i!=hashtable[indexkey].end()) 
        {
            hashtable[indexkey].erase(i); // elemani sil
            hash_sayisi--; //eleman silindiği için eleman sayısı azalır
        }
    }

    int hashFunction(int a)
    {
        return (a%bucket); // kacinci bucket'a denk geldigini hesapla (mod islemi)
    }
    void display_table() // hashtable'daki elementleri gösteren fonksiyon
    {
        for(int i=0;i<bucket;i++) // her bucket icin
        {
            cout<<i; // kacinci bucket oldugunu bastir
            list<int>::iterator j=hashtable[i].begin(); // bucket icindeki ilk elemani bastir
        for(;j!=hashtable[i].end();j++)
            {
                cout<<"---->"<<*j; // Gorsel icin siradaki elemanlari ve "ok" bastir
            }
            cout<<endl; // bucket icindeki elemanlar basildi, bir sonraki bucket'a gec
        }
    }
    void search_element(int key)  //eleman arama fonksiyonu
    {
        int a=0;    //aranan eleman varsa 1 olacak yoksa 0 olacak
        int indexkey=hashFunction(key); // key bulunduysa
                list<int>::iterator i=hashtable[indexkey].begin(); // ilk elemandan aramaya basla
        for(;i!=hashtable[indexkey].end();i++)
        {
            if(*i==key) // elemani bulduysak
            {
                a=1;
                break; // for'dan cik
            }
        }
            if(a==1)
            {
                cout<<"The element you wanted to search is present in the hashtable."<<endl;
            } //aranan elemanın tabloda oldugunu bildir
            else
            {
                cout<<"Element not present"<<endl;  //aranan elemanın tabloda olmadıgını bildir
            }

     }
     ~hashclass()  //destructor
     {
         delete[]hashtable; // hashtable'i sil
     }
};


int main() {    
   int ch;                         
   cout<<"1) Stack "<<endl;        //kullanıcıdan seçimini
   cout<<"2) Queue"<<endl;         //isteriz ve alt menüye geçeriz
   cout<<"3) Linked List"<<endl;   //ya da exit seçilirse program kapanır
   cout<<"4) Binary Search Tree"<<endl;
   cout<<"5) Hash Table"<<endl;
   cout<<"6) Exit"<<endl;
do {
   cout<<"Enter your choice : "<<endl;  //seçimini isteriz
   cin>>ch;                             
   switch (ch) {
      case 1:                                 //eğer ilk seçenek seçilirse karşımıza
    int ch, val;                              //6 seçenekli menü çıkar ve seçimini
   cout<<"1) Push in Stack"<<endl;            //isteriz ve seçime göre Node struct'ında
   cout<<"2) Pop from Stack"<<endl;           //tanımladığımız fonksiyon devreye girer
   cout<<"3) Display Stack"<<endl;
   cout<<"4) Number of Elements"<<endl;
   cout<<"5) Delete All"<<endl;
   cout<<"6) Main Menu"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            yigin_eleman_sayisi();
            break;
         }
         case 5: {
            delete_all();
            break;
         }
         case 6: {
            cout<<"Main Menu"<<endl;
            break;
         }
         default: {                         //menüdekiler dışında farklı bir seçenek seçilirse 
            cout<<"Invalid Choice"<<endl;   //geçersiz bir seçim olduğu bildirilir
         }
      }
   }
   while(ch!=6);       //eğer 6. seçenek seçilirse ana menüye dönülür
      return main();
  
  case 2:{
int ch;
   cout<<"1) Insert Element to Queue"<<endl;              //eğer ikinci seçenek seçilirse karşımıza
   cout<<"2) Delete Element from Queue"<<endl;            //6 seçenekli menü çıkar ve seçimini
   cout<<"3) Display All the Elements of Queue"<<endl;    //isteriz ve seçime göre node struct'ında
   cout<<"4) Number of Elements"<<endl;                   //tanımladığımız fonksiyon devreye girer
   cout<<"5) Delete All"<<endl;
   cout<<"6) Main Menu"<<endl;
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: Insert();
         break;
      case 2: Delete();
         break;
      case 3: Display();
         break;
      case 4: kuyruk_eleman_sayisi();
         break;
      case 5: Delete_All();
         break;
      case 6: cout<<"Main Menu"<<endl;

         break;
      
      default: cout<<"Invalid choice"<<endl;  //menüdekiler dışında farklı bir seçenek seçilirse 
   }                                          //geçersiz bir seçim olduğu bildirilir
} while(ch!=6);                               //eğer 6. seçenek seçilirse ana menüye dönülür
   return main();     



  }
  case 3:{              //eğer üçüncü seçenek seçilirse karşımıza 8 seçenekli menü çıkar
    List l;             //ve seçimini isteriz ve seçime göre Node1 class'ında tanımladığımız
    int ch;             //fonksiyon devreye girer
    while(1)
    {
        cout<<"\n1:Create\n2:Insert\n3:Delete\n4:Search\n5:Display\n6:Number of Elements\n7:Delete All\n8:Main Menu\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        case 6:
            l.liste_eleman_sayisi();
         break;
        case 7:
             l.Delet_All();
         break;
         case 8:
            cout<<"Main Menu"<<endl;   
            liste_sayisi =0;
            return main();
         break;
         default: cout<<"Invalid Choice"<<endl;   //menüdekiler dışında farklı bir seçenek
        }                                         //seçilirse geçersiz bir seçim olduğu bildirilir
    }

  
   }while(ch!=8)     //eğer 8. seçenek seçilirse ana menüye dönülür
   return main();
   
   case 4 :{                //eğer dördüncü seçenek seçilirse karşımıza 9 seçenekli menü çıkar
                            //ve seçimini isteriz ve seçime göre BTS class'ında tanımladığımız
                            //fonksiyon devreye girer
     int choice, num;
    BST bst;
    node2 *temp;
    while (1)
    {
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Number of Elements"<<endl;
        cout<<"8.Delete All"<<endl;
        cout<<"9.Main Menu"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node2;
            cout<<"Enter the number to be inserted : ";
	    cin>>temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            bst.del(num);
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
        	case 4:
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 7:
         bst.agac_eleman_sayisi();
         break;
        case 8:
        bst.delete_allagac(root);
        break;
        case 9:
            return main();
            agac_sayisi =0;
        default:
            cout<<"Invalid choice"<<endl;
        }
    }
}
   
  
  case 5:{                  //eğer beşinci seçenek seçilirse karşımıza 7 seçenekli menü çıkar
                            //ve seçimini isteriz ve seçime göre hashclass'ta tanımladığımız
                            //fonksiyon devreye girer
int bucketn,ch,element;

cout<<"enter the number of buckets"<<endl;
cin>>bucketn;
hashclass hashelement(bucketn);
while(1)
{
    cout<<"1.İnsert element to the hashtable"<<endl;
    cout<<"2.Search element from the hashtable"<<endl;
    cout<<"3.Delete element from the hashtable"<<endl;
    cout<<"4.Display elements of the hashtable"<<endl;
    cout<<"5.Number of Elements"<<endl;
    cout<<"6.Main Menu"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"enter the element"<<endl;
        cin>>element;
        hashelement.insert_element(element);
        break;
        case 2:cout<<"enter the element you want to search"<<endl;
        cin>>element;
        hashelement.search_element(element);
        break;
        case 3:cout<<"enter the element to be deleted"<<endl;
        cin>>element;
        hashelement.delete_element(element);
        break;
        case 4:hashelement.display_table();
        break;
       case 5: 
        cout<< "Number of elements:" <<hash_sayisi<<endl;  //eleman sayısını bidirir
        break;
        case 6:
        hash_sayisi=0;  //hash tablosu sıfırlanacağı için eleman sayısı da sıfırlanır
        return main();  //ana menüye dönülür
        
        default:cout<<"Invalid choice"<<endl;
}
}
  }
   }  
} 
while(ch!=6);      //eğer ana menüde 6. seçenek seçilirse program kapanır
   return 0;
}