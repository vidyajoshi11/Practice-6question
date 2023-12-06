 class assessment;  
 class student  
 {  
   char name[20],sub[20];  
   int rno,sub_code,in,uni;  
   public:  
   friend assessment;  
 };  
 class assessment  
 {  
   int internal,uni_marks;  
   public:  
   void menu();  
   void input(student *S);  
   void display(student *S);  
   int rlno(student *S);  
   void del(student *S);  
   void modify(student *S);  
 };  
 void assessment::input(student *S)  
 {  
   cout<<"\nEnter name : ";  
   gets(S->name);  
   cout<<"\nEnter Roll no : ";  
   cin>>S->rno;  
   cout<<"\nEnter subject : ";  
   gets(S->sub);  
   cout<<"\nEnter sub code : ";  
   cin>>S->sub_code;  
   cout<<"\nEnter Internal marks : ";  
   cin>>internal;  
   S->in=internal;  
   cout<<"\nEnter University exam marks : ";  
   cin>>uni_marks;  
   S->uni=uni_marks;  
 }  
 void assessment::display(student *S)  
 {  
   cout<<"\n"<rno;  
   cout<<"\t"<name;  
   cout<<"\t"<sub;  
   cout<<"\t"<sub_code;  
   cout<<"\t"<in;  
   cout<<"\t"<uni;  
 }  
 void assessment::menu()  
 {  
   cout<<"\t\t\t"<<"STUDENT DATABASE MANAGENENT"<<endl<<"\n1.create"<<endl; <br="">   cout<<"2.Display"<<endl<<"3.insert"<<endl; <br="">   cout<<"4.Delete"<<endl<<"5.modify"; <br="">   cout<<endl<<"6.search"<<endl<<"7.exit"; <br=""> }  
 int assessment::rlno(student *S)  
 {  
   return (S->rno);  
 }  
 void assessment ::modify(student *S)  
 {  
   int ch;  
   do  
   {  
     clrscr();  
     cout<<"EDIT"<<endl<<"1.roll no"<<endl<<"2.name";="" <br="">     cout<<endl<<"3.subject"<<endl<<"4.sub code"<<endl<<"5.int="" assesment";="" <br="">     cout<<endl<<"6.uni exam"<<endl<<"7.exit";="" <br="">     cin>>ch;  
     switch(ch)  
     {  
       case 1:  
          cout<<endl<<"new roll="" no="" :="" ";="" <br="">          cin>>S->rno;  
          break;  
       case 2:  
          cout<<endl<<"new name="" :="" ";="" <br="">          gets(S->name);  
          break;  
       case 3:  
          cout<<endl<<"new subject="" :="" ";="" <br="">          cin>>S->sub;  
          break;  
       case 4:  
          cout<<endl<<"new code="" :="" ";="" <br="">          cin>>S->sub_code;  
          break;  
       case 5:  
          cout<<endl<<"new int="" assessment="" :="" ";="" <br="">          cin>>internal;  
          break;  
       case 6:  
          cout<<endl<<"new university="" marks="" :="" ";="" <br="">          cin>>uni_marks;  
          break;  
       case 7:  
          break;  
       default:  
           cout<<"Invalid Choice";  
     }  
   }while(ch!=7);  
 }  
 void main()  
 {  
   fstream inoutf;  
   ifstream inf;  
   student S;  
   assessment A;  
   int ch,flag=0,ct=0;  
   int r;  
   char c;  
   do  
   {  
     clrscr();  
     flag=0;  
     A.menu();  
     cout<<"\n\nEnter your choice : ";  
     cin>>ch;  
     clrscr();  
     switch(ch)  
     {  
       case 1:  
          inoutf.open("student.txt",ios::out|ios::binary);  
          do  
          {  
           A.input(&S);  
           inoutf.write((char*) &S,sizeof(S));  
           cout<<"Want to enter again y/n";  
           cin>>c;  
          }while(c=='y');  
          inoutf.close();  
          break;  
       case 2:  
          inf.open("student.txt",ios::in|ios::binary );  
          inf.seekg(0);  
          cout<<"\nRNo\tName\tSub\tCode\tAsmnt\tMarks";  
          //while(!inf.eof())  
          while(inf.read((char*)&S,sizeof(S)))  
          {  
           A.display(&S);  
          }  
          inf.close();  
          break;  
       case 3:  
          inoutf.open("student.txt",ios::out|ios::binary|ios::app);  
          inoutf.clear();  
          A.input(&S);  
          inoutf.write((char*)&S,sizeof(S));  
          inoutf.close();  
          break;  
       case 4:  
          cout<<"Enter Roll no to be deleted : ";  
          cin>>r;  
          inf.open("student.txt",ios::in|ios:: binary);  
          inoutf.open("temp.txt",ios::in|ios::out|ios::binary|ios::app);  
          inf.seekg(0);  
          while(inf.read((char*) & S,sizeof(S)))  
          {  
           if(r==A.rlno(&S))  
           {  
             flag=1;  
             //break;  
           }  
           else  
           {  
             inoutf.write((char*)&S,sizeof(S));  
           }  
          }  
          if(flag!=1)  
           cout<<"\n\nRoll no not found";  
          else  
           cout<<"\n\nDeleted";  
          inf.close();  
          inoutf.close();  
          remove("student.txt");  
          rename("temp.txt","student.txt");  
          break;  
       case 5:  
          ct=0;  
          cout<<"Enter Roll no to be modified : ";  
          cin>>r;  
          inoutf.open("student.txt",ios::in|ios:: binary|ios::out);  
          inoutf.seekg(0);  
          while(inoutf.read((char*) & S,sizeof(S)))  
          {  
           if(r==A.rlno(&S))  
           {  
             flag=1;  
             break;  
           }  
           ct++;  
          }  
          if(flag!=1)  
           cout<<"\n\nRoll no not found";  
          else  
          {  
           ct=ct*sizeof(S);  
           inoutf.seekg(ct,ios::beg);  
           A.modify(&S);  
           inoutf.write((char*)&S,sizeof(S));  
          }  
          inoutf.close();  
          break;  
       case 6:  
          inf.open("student.txt",ios::in |ios::binary );  
          inf.seekg(0);  
          cout<<"Enter Roll no to be searched : ";  
          cin>>r;  
          //while(!inf.eof())  
          while(inf.read((char*)&S,sizeof(S)))  
          {  
           if(r==A.rlno(&S))  
           {  
             flag=1;  
             break;  
           }  
           else  
             flag=0;  
          }  
          if(flag==1)  
          {  
           cout<<"\n\nRecord found";  
           cout<<"\nRNo\tName\tSub\tCode\tAsmnt\tMarks";  
           A.display(&S);  
          }  
          else  
           cout<<"\nRecord not found";  
          inf.close();  
       case 7:  
          break;  
       default:  
           cout<<"Invalid dirn";  
     }  
     getch();  
   }while(ch!=7);  
  inoutf.close();  
}
